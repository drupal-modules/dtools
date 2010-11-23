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
  if (!$fids[$file] && !($fids[$file] = db_result(db_query("SELECT fid FROM {debugger_files} WHERE filepath = '%s'", $file)))) {
    db_query("INSERT INTO {debugger_files} SET `filepath` = '%s', `module` = '%s'", $file, debugger_api_module_via_file($file));
    $fids[$file] = db_last_insert_id('debugger_files', 'fid');
  }
  return $fids[$file];
}

/**
 * Register new function into database
 */
function debugger_api_db_register_function($name, $fid = 0, $line = 0, $args = '', $desc = '') {
  static $fncs;
  if (!$fncs[$name] && !($fncs[$name] = db_result(db_query("SELECT fncid FROM {debugger_functions} WHERE name = '%s'", $name)))) {
    db_query("INSERT INTO {debugger_functions} SET `name` = '%s', `fid` = '%s', `line` = '%d', `args` = '%s', `description` = '%s'", $name, $fid, $line, $args, $desc);
    $fncs[$name] = db_last_insert_id('debugger_functions', 'fncid');
  }
  return $fncs[$name];
}

/**
 * Register new request into database
 */
function debugger_api_db_register_request($path = '', $rpath = '', $query = '', $post = '') {
  global $user, $request_id;
  if ($path) {
    db_query("INSERT INTO {debugger_requests}
      SET
        `path` = '%s',
        `rpath` = '%s',
        `query` = '%s',
        `post` = '%s',
        `uid` = '%d'
        ", $path, $rpath, $query, $post, $user->uid);
    $request_id = db_last_insert_id('debugger_requests', 'rid');
  }
  return $request_id;
}

/**
 * Register new request into database
 */
function debugger_api_db_update_request($request_id, $fid, $fncid, $mem_fncid, $slow_fncid, $slow_qid, $total_time, $total_memory, $num_sql, $num_ticks, $num_err, $num_warn, $num_notices, $options = '') {
  global $user;
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
      ", $fid, $fncid, $mem_fncid, $slow_fncid, $slow_qid, $time, $memory, $num_sql, $num_ticks, $num_err, $num_warn, $num_notices, ($options ? serialize($options) : ''), $request_id);
}

/**
 * Register new trace item
 */
function debugger_api_db_register_trace($ptid, $fncid, $pfncid, $fid, $rid, $time_delta, $mem_delta, $args = '', $options = '') {
  db_query("REPLACE INTO {debugger_traces}
            SET
                `ptid` = %d,
                `fncid` = %d,
                `pfncid` = %d,
                `fid` = %d,
                `rid` = %d,
                `time_delta` = %f,
                `mem_delta` = %f,
                `args` = '%s',
                `options` = '%s'
  ", $ptid, $fncid, $pfncid, $fid, $rid, $time_delta, $mem_delta, ($args ? serialize($args) : ''), ($options ? serialize($options) : ''));
  return $tid = db_last_insert_id('debugger_traces', 'tid');
}

/**
 * Detect module name by file
 */
function debugger_api_module_via_file($file) {
  static $mods;
  if (isset($mods[$file])) {
    return $mods[$file];
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
  if (!is_null($backtrace)) {
    // $debugger_trace[$tick_counter . ':' . $time . ':' . $memory]  = $backtrace;
    $curr_thread = $backtrace[1];
    $args = serialize($curr_thread['args']);
    $fid = debugger_api_db_register_file($curr_thread['file']);
    $fncid = debugger_api_db_register_function($curr_thread['function'], $fid, $curr_thread['line'], count($args));
    $rid = debugger_api_db_register_request();
    $tid = debugger_api_db_register_trace($ptid, $fncid, $pfncid, $fid, $rid, $time, $memory, $args, $options = '');
    $sql = "REPLACE INTO debugger_traces (ptid, fncid, fid, args) VALUES ";
    // array_walk($backtrace, 'debugger_api_db_register_trace_callback');
    // $backtrace = '(' . implode("),\n(", array_map('implode', array_fill(0, count($backtrace), ','), $backtrace)) . ')';
    unset($backtrace[0], $backtrace[1]); // remove first two elements
    $sql_values = "('" . array_reduce($backtrace, '_debugger_api_gen_values', $ptid) . "')";
/*
    if (!db_query($sql . $sql_values)) {
      var_dump($backtrace, $sql . $sql_values); exit;
    }
*/
/*
    (0, 0, 0, 0, 0, 0, 0, 0, 0),
    (0, 0, 0, 0, 0, 0, 0, 0, 0)
*/
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

