<?php

/**
 * @file
 *   Include file
 *
 * @version
 *   $Id$
 *
 * @developers
 *   Rafal Wieczorek <kenorb@gmail.com>
 */

define('DEBUG', TRUE);

/**
 * Save trace data into db
 */
function debugger_savetrace() {
  global $debugger_trace, $user;
  $pid = 0;
  $unixtime_last = NULL;
  foreach ($debugger_trace as $unixtime => $backtrace) {
    $post = serialize($_POST);
    $time = $unixtime_last ? $unixtime-$unixtime_last : 0;
    foreach ($backtrace as $key => $call_obj) {
      $file = $call_obj['file'] ? $call_obj['file'] : '(unknown)';
      $function = $call_obj['function'];
      $args = $call_obj['args'];
      if (!$fid = debugger_db_get_fid($file) || debugger_db_register_file($file)) { // if not found, register new file
        empty($file) ? watchdog('debugger', 'Empty %value variable: %data', array('%value' => 'file', '%data' => print_r($call_obj, TRUE)), 'error') : NULL;
        $fid = debugger_db_get_fid($file); // and get the fid
      }
      if ($fid && (!$fncid = debugger_db_get_fcnid_via_name($function) || debugger_db_register_function($function, $fid, $line, NULL, NULL))) {
        empty($function) ? watchdog('debugger', 'Empty %value variable: %data', array('%value' => 'function', '%data' => print_r($call_obj, TRUE)), 'error') : NULL;
        $fncid = debugger_db_get_fcnid_via_name($function);
      }
      if ($fid && $fncid) {
        db_query("REPLACE INTO {debugger_traces}
                  SET
                      `fid` = %d, 
                      `fncid` = %d, 
                      `pid` = %d, 
                      `time` = %4.4f, 
                      `path` = %s, 
                      `args` = '%s', 
                      `post` = '%s',
                      `uid` = %d, 
                      `updated` = %d
        ", $fid, $fncid, $pid, $time, $_GET['q'], $args, $post, $user->uid, $unixtime);
      } else {
      }
    }
  }
}

/**
 * Get function ID from database via pathfile
 */
function debugger_db_get_fcnid_via_name($name) {
  return db_result(db_query("SELECT fid FROM {debugger_functions} WHERE name = '%s'", $name));
}

/**
 * Register new function into database
 */
function debugger_db_register_function($function, $fid, $line, $args = NULL, $desc = NULL) {
  return db_query("INSERT INTO {debugger_functions} SET `name` = '%s', `module` = '%s', `line` = '%d', `args` = '%s'", $function, $fid, $line, $args, $desc);
}

/**
 * Get file ID from database via pathfile
 */
function debugger_db_get_fid($file) {
  return db_result(db_query("SELECT fid FROM {debugger_files} WHERE filepath = '%s'", $file));
}

/**
 * Register new filepath into database
 */
function debugger_db_register_file($file) {
  return db_query("INSERT INTO {debugger_files} SET `filepath` = '%s', `module` = '%s'", $file, debugger_module_via_file($file));
}

/**
 * Detect module name by file
 */
function debugger_module_via_file($file) {
  return 'test';
}
