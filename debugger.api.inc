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
  static $fids = array();
  if ($file && !array_key_exists($file, $fids) && ($file_relative = debugger_api_get_relative_path($file)) && !($fids[$file] = db_result(db_query("SELECT fid FROM {debugger_files} WHERE filepath = '%s'", $file_relative)))) {
    db_query("INSERT INTO {debugger_files} SET `filepath` = '%s', `module` = '%s'", $file_relative, debugger_api_module_via_file($file_relative));
    $fids[$file] = db_last_insert_id('debugger_files', 'fid');
  }
  return array_key_exists($file, $fids) ? $fids[$file] : FALSE;
}

/**
 * Get relative path of the filepath
 */
function debugger_api_get_relative_path($filepath) {
  return substr($filepath, strlen(getcwd())+1);
}

/**
 * Register new function into database
 */
function debugger_api_db_register_function($name, $fid = 0, $line = 0, $args = '', $desc = '') {
  static $fncs = array();
  $s = ':'; // separator
  $key = $name . $s . $fid . $s . $line; // generate the unique key
  if (!array_key_exists($key, $fncs) && !($fncs[$key] = db_result(db_query("SELECT fncid FROM {debugger_functions} WHERE name = '%s' AND fid = '%s' AND line = '%d'", $name, $fid, $line)))) {
    db_query("INSERT INTO {debugger_functions} SET `name` = '%s', `fid` = '%s', `line` = '%d', `args` = '%s', `description` = '%s'", $name, $fid, $line, $args, $desc);
    $fncs[$key] = db_last_insert_id('debugger_functions', 'fncid');
  }
  return array_key_exists($key, $fncs) ? $fncs[$key] : FALSE;
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
    $rpath = function_exists('menu_get_item') ? menu_get_item() : ''; // FIXME: Doesn't work?
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
  $errors = debugger_api_drupal_error_handler();
  // $fid = TODO: // file of router menu callback
  // $fncid = TODO: // function id of menu router callback
  // $mem_fncid = // function used the most memory
  // $slow_fncid = // function which was the slowest
  // $slow_qid = // SQL query which was the slowest
  // var_dump($errors['errors']); exit;
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
  static $traces = array();
  $s = ':'; // separator
  $key = $rid . $s . $fncid . $s . $pfncid . $s . $fid . $s . $line; // generate the unique key
  if (!array_key_exists($key, $traces)) {
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
  return array_key_exists($key, $traces) ? $traces[$key] : FALSE;
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
  static $slow_fncid = array(), $mem_fncid = array();
  if (!is_null($backtrace)) {
    // $debugger_trace[$tick_counter . ':' . $time . ':' . $memory]  = $backtrace;
    if ($curr_thread = $backtrace[1]) {
      $file = array_key_exists('file', $curr_thread) ? $curr_thread['file'] : '(unknown)';
      $line = array_key_exists('line', $curr_thread) ? $curr_thread['line'] : 0;
      $args = serialize($curr_thread['args']);
    }
    $options = '';
    if (!($fid = debugger_api_db_register_file($file))) {
      // $fid = -debugger_api_db_register_file($backtrace[2]['file']); // if not found, use minus for parent
      // $line = $backtrace[2]['line']; // if not found, use minus for parent
    };
    $fncid = debugger_api_db_register_function($curr_thread['function'], $fid, $line, count($args));
    $rid = debugger_api_db_register_request();
    $tid = debugger_api_db_register_trace($ptid, $fncid, $pfncid, $fid, $rid, $time, $memory, $args, $options);
    // array_walk($backtrace, 'debugger_api_db_register_trace_callback');
    // $backtrace = '(' . implode("),\n(", array_map('implode', array_fill(0, count($backtrace), ','), $backtrace)) . ')';
    unset($backtrace[0], $backtrace[1]); // remove first two elements
    foreach ($backtrace as $key => $tobj) {
    }
    /* CHECK PERFORMANCE */
    $module = debugger_api_module_via_file(debugger_api_get_relative_path($file));
    if ($memory > current($mem_fncid)) { // check how much memory using this line
      $mem_fncid = array($tid => $memory); // 
    }
    if ($time > current($slow_fncid)) {
      $slow_fncid = array($tid => $time);
    }

    /* SAVE PARENTS */
    $ptid = $tid;
    $pfncid = $fncid;
  } else {
    return $debugger_trace;
  }
}

/* TODO: Do we need this function?
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
 */

/**
 * Log errors as defined by administrator.
 *
 * Error levels:
 * - 0 = Log errors to database.
 * - 1 = Log errors to database and to screen.
 */
function debugger_api_drupal_error_handler($errno, $message, $filename, $line, $context) {
  static $errors = array();
  if (error_reporting() == 0 || !isset($errno, $message, $filename, $line, $context)) {
    return $errors;
  }
  drupal_error_handler($errno, $message, $filename, $line, $context); // execute original callback
  $types = array(1 => 'error', 2 => 'warning', 4 => 'parse error', 8 => 'notice', 16 => 'core error', 32 => 'core warning', 64 => 'compile error', 128 => 'compile warning', 256 => 'user error', 512 => 'user warning', 1024 => 'user notice', 2048 => 'strict warning', 4096 => 'recoverable fatal error');
  $errors[$types[$errno]][] = array($message, $filename, $line, $context);
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

