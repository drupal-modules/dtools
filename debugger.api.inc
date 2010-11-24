<?php

/**
 * @file
 *   Include file for API functions
 *
 * @version
 *   $Id$
 *
 * @developers
 *   Rafal Wieczorek <kenorb@gmail.com>
 */

/**
 * Register new filepath into database
 */
function debugger_api_db_register_file($file) {
  static $fids;
  if ($file && !$fids[$file] && ($file_relative = debugger_api_get_relative_path($file)) && !($fids[$file] = db_result(db_query("SELECT fid FROM {debugger_files} WHERE filepath = '%s'", $file_relative)))) {
    db_query("INSERT INTO {debugger_files} SET `filepath` = '%s', `module` = '%s'", $file_relative, debugger_api_module_via_file($file_relative));
    $fids[$file] = db_last_insert_id('debugger_files', 'fid');
  }
  return $fids[$file];
}

/**
 * Get relative path of the filepath
 */
function debugger_api_get_relative_path($filepath) {
  // var_dump($filepath, getcwd(), substr($filepath, strlen(getcwd())+1)); exit;
  return substr($filepath, strlen(getcwd())+1);
}

/**
 * Register new function into database
 */
function debugger_api_db_register_function($name, $fid = 0, $line = 0, $args = '', $desc = '') {
  static $fncs;
  $s = ':'; // separator
  $key = $name . $s . $fid . $s . $line; // generate the unique key
  if (!$fncs[$key] && !($fncs[$key] = db_result(db_query("SELECT fncid FROM {debugger_functions} WHERE name = '%s' AND fid = '%s' AND line = '%d'", $name, $fid, $line)))) {
    db_query("INSERT INTO {debugger_functions} SET `name` = '%s', `fid` = '%s', `line` = '%d', `args` = '%s', `description` = '%s'", $name, $fid, $line, $args, $desc);
    $fncs[$name] = db_last_insert_id('debugger_functions', 'fncid');
  }
  return $fncs[$name];
}

/**
 * Register new request into database
 * 
 * Note: should be executed before register_tick_function
 */
function debugger_api_db_register_request() {
  global $user;
  static $request_id = 0;
  // $query = // TODO: What here? All after '?'?
  if (!$request_id) {
    $post = serialize($_POST);
    $path = $_GET['q'];
    $query = '';
    $rpath = menu_get_item(); // FIXME: Doesn't work?
    $timestamp = time();
    db_query("INSERT INTO {debugger_requests}
      SET
        `path` = '%s',
        `rpath` = '%s',
        `query` = '%s',
        `post` = '%s',
        `uid` = '%d',
        `timestamp` = '%d'
        ", $path, $rpath, $query, $post, $user->uid, time());
    $request_id = db_last_insert_id('debugger_requests', 'rid');
    timer_start('debugger');
  }
  return $request_id;
}

/**
 * Update already registered request with new details
 */
function debugger_api_db_finish_request($options = array()) {
  global $user, $queries;
  $request_id = debugger_api_db_register_request();
  // $fid = TODO: // file of router menu callback
  // $fncid = TODO: // function id of menu router callback
  // $mem_fncid = // function used the most memory
  // $slow_fncid = // function which was the slowest
  // $slow_qid = // SQL query which was the slowest
  $time = timer_stop('debugger');
  $total_memory = function_exists('memory_get_peak_usage') ? memory_get_peak_usage() : memory_get_usage();
  $num_sql = count($queries);
  $num_ticks = debugger_tick(TRUE);
  // $num_err = // total Drupal errors
  // $num_warn = // total Drupal warnings
  // $num_notices = // total Drupal notices

  return db_query("UPDATE {debugger_requests}
    SET
      `fid` = '%d',
      `fncid` = '%d',
      `mem_fncid` = '%d',
      `slow_fncid` = '%d',
      `slow_qid` = '%d',
      `time` = %f,
      `memory` = '%d',
      `num_sql` = '%d',
      `num_ticks` = '%d',
      `num_err` = '%d',
      `num_warn` = '%d',
      `num_notices` = '%d',
      `options` = '%s'
    WHERE `rid` = '%d'
      ", $fid, $fncid, $mem_fncid, $slow_fncid, $slow_qid, $time, $memory, $num_sql, $num_ticks, $num_err, $num_warn, $num_notices, serialize($options), $request_id);
}

/**
 * Register new trace item
 */
function debugger_api_db_register_trace($ptid, $fncid, $pfncid, $fid, $line, $rid, $time_delta, $mem_delta, $args = '', $options = '') {
  static $traces;
  $s = ':'; // separator
  $key = $rid . $s . $fncid . $s . $pfncid . $s . $fid . $s . $line; // generate the unique key
  if (!$traces[$key]) {
   // && !($fncs[$key] = db_result(db_query("SELECT CONCAT('fncid', '$s', 'pfncid', '$s', 'fid', '$s', 'line') FROM {debugger_functions} WHERE name = '%s'", $name))))
    db_query("REPLACE INTO {debugger_traces}
              SET
                  `ptid` = %d,
                  `fncid` = %d,
                  `pfncid` = %d,
                  `fid` = %d,
                  `line` = %d,
                  `rid` = %d,
                  `time_delta` = %f,
                  `mem_delta` = %f,
                  `args` = '%s',
                  `options` = '%s'
    ", $ptid, $fncid, $pfncid, $fid, $line, $rid, $time_delta, $mem_delta, $args, $options);
    $traces[$key] = db_last_insert_id('debugger_traces', 'tid');
  }
  return $traces[$key];
}

/**
 * Detect module name by file
 */
function debugger_api_module_via_file($file) {
  static $mods;
  if (isset($mods[$file])) { // if already saved...
    return $mods[$file]; // ...get from cache
  }
  $mods[$file] = '(unknown)';
  if (!strpos($file, '/') !== FALSE || strpos($file, 'includes/') === 0) {
    $mods[$file] = 'Drupal';
  } else if (($extension = end(explode('.', ($filename = basename($file))))) == 'module') { // check for .module extension and get the name
      $mods[$file] = substr($filename, 0, -1-strlen($extension));
  } else {
    $dirname = $file;
    do {
      if (($dirname = dirname($dirname)) && (strpos($dirname, '/') === FALSE)) {
        $mods[$file] = '(unknown)';
        break;
      }
    } while(!($mods[$file] = db_result(db_query("SELECT name FROM {system} WHERE filename LIKE '%s%%'", $dirname))));
  } // end: else
  return $mods[$file];
}

/**
 * Register backtrace into db
 */
function debugger_api_register_backtrace($backtrace = NULL, $time = NULL, $memory = NULL, $tick_counter = NULL, $start = 2) {
  static $debugger_trace = array(), $ptid = 0, $pfncid = 0;
  static $slow_fncid = 0, $mem_fncid = 0;
  if (!is_null($backtrace)) {
    // $debugger_trace[$tick_counter . ':' . $time . ':' . $memory]  = $backtrace;
    $curr_thread = $backtrace[1];
    $line = $curr_thread['line'];
    $args = serialize($curr_thread['args']);
    $options = '';
    if (!($fid = debugger_api_db_register_file($curr_thread['file']))) {
      $fid = -debugger_api_db_register_file($backtrace[2]['file']); // if not found, use minus for parent
      $line = $backtrace[2]['line'];
    };
    $fncid = debugger_api_db_register_function($curr_thread['function'], $fid, $line, count($args));
    $rid = debugger_api_db_register_request();
    $tid = debugger_api_db_register_trace($ptid, $fncid, $pfncid, $fid, $rid, $time, $memory, $args, $options);
    // array_walk($backtrace, 'debugger_api_db_register_trace_callback');
    // $backtrace = '(' . implode("),\n(", array_map('implode', array_fill(0, count($backtrace), ','), $backtrace)) . ')';
    unset($backtrace[0], $backtrace[1]); // remove first two elements
    $sql = "REPLACE INTO debugger_traces (ptid, fncid, fid, args) VALUES ";
    $sql_values = "('" . array_reduce($backtrace, '_debugger_api_gen_values', $ptid) . "')";
    // var_dump($sql . $sql_values); exit;
/*
    if (!db_query($sql . $sql_values)) {
      var_dump($backtrace, $sql . $sql_values); exit;
    }
*/
/*
    (0, 0, 0, 0, 0, 0, 0, 0, 0),
    (0, 0, 0, 0, 0, 0, 0, 0, 0)
*/
    /* CHECK PERFORMANCE */
    $module = debugger_api_module_via_file();
    if ($mem_delta > current($mem_fncid)) { // check how much memory using this line
      $mem_fncid[$tid] = $mem_delta; // 
    }
    if ($time > current($slow_fncid)) {
      $slow_fncid[$tid] = $time;
    }

    /* SAVE PARENTS */
    $ptid = $tid;
    $pfncid = $fncid;
  } else {
    return $debugger_trace;
  }
}

function _debugger_api_gen_values($values, $curr) {
  static $ptid = NULL;
  is_null($ptid) ? ($ptid = $values || $values = '') : 0;
  if ($values) {
    $values .= "'),\n('";
  }
  list($file, $line, $function, $args) = array(debugger_api_db_register_file($curr['file']), $curr['line'], debugger_api_db_register_function($curr['function']), count($curr['args']));
  $values .= "$ptid','" . implode("','", array($file, $function, $args));
  return $values;
}

/**
 * Clear debugger related data from tables
 */
function debugger_api_clear_data() {
  db_query("TRUNCATE TABLE {debugger_files}");
  db_query("TRUNCATE TABLE {debugger_traces}");
  db_query("TRUNCATE TABLE {debugger_functions}");
  db_query("TRUNCATE TABLE {debugger_requests}");
}

