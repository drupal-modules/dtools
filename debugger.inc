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
  $basedir = getcwd();
  $pid = 0;
  $unixtime_last = NULL;
  $post = serialize($_POST);
  $uri = $_GET['q'];
// db_query("TRUNCATE TABLE {debugger_files}");
// db_query("TRUNCATE TABLE {debugger_traces}");
// db_query("TRUNCATE TABLE {debugger_functions}");
  $backtraces = debugger_tick(TRUE);
  foreach ($backtraces as $c_time_mem => $backtrace) {
    list($counter, $time, $memory) = explode(':', $c_time_mem);
    /* CALCULATE THE TIME */
    // $time = (float)($microtime_last ? $microtime-$microtime_last : 0);
    // $microtime_last = (float)$microtime;
    foreach ($backtrace as $key => $call_obj) {
      /* INIT VARIABLES */
      $file = $call_obj['file'] ? debugger_get_relative_path($call_obj['file']) : '(unknown)';
      $module = debugger_module_via_file($file);
      $function = $call_obj['function'];
      $line = $call_obj['line'];
      $args = serialize($call_obj['args']);
      /* FIND FILE RECORD IN DB, IF NOT CREATE ONE */
      if (!($fid = debugger_db_get_fid($file))) { // if not found, register new file
        empty($file) ? watchdog('debugger', 'Empty %value variable: %data', array('%value' => 'file', '%data' => print_r($call_obj, TRUE)), 'error') : NULL;
        debugger_db_register_file($file);
        $fid = debugger_db_get_fid($file); // and get the fid
      }
      /* FIND FUNCTION RECORD IN DB, IF NOT CREATE ONE */
      if (!($fncid = debugger_db_get_fcnid_via_name($function))) {
        empty($function) ? watchdog('debugger', 'Empty %value variable: %data', array('%value' => 'function', '%data' => print_r($call_obj, TRUE)), 'error') : NULL;
        debugger_db_register_function($function, $fid, $line, count($args), '');
        $fncid = debugger_db_get_fcnid_via_name($function);
      }
      /* SAVE TRACE ITEM */
      debugger_db_register_trace($fid, $fncid, $pid, $time, $time_delta, $uri, 0, $args, $post);
    }
  }
}

/**
 * Register new trace item
 */
function debugger_db_register_trace($fid, $fncid, $pid, $time, $time_delta, $uri, $unixtime, $args = '', $post = '') {
  global $user;
  db_query("REPLACE INTO {debugger_traces}
            SET
                `fid` = %d, 
                `fncid` = %d, 
                `pid` = %d, 
                `time` = %f, 
                `path` = '%s', 
                `args` = '%s', 
                `post` = '%s',
                `uid` = %d, 
                `updated` = %d
  ", $fid, $fncid, $pid, $time, $uri, $args, $post, $user->uid, $unixtime);
                // `time_delta` = %4.4f, 
}

/**
 * Get function ID from database via pathfile
 */
function debugger_db_get_fcnid_via_name($name) {
  return db_result(db_query("SELECT fncid FROM {debugger_functions} WHERE name = '%s'", $name));
}

/**
 * Register new function into database
 */
function debugger_db_register_function($function, $fid, $line, $args = '', $desc = '') {
  return db_query("INSERT INTO {debugger_functions} SET `name` = '%s', `fid` = '%s', `line` = '%d', `args` = '%s', `description` = '%s'", $function, $fid, $line, $args, $desc);
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
 * Get relative path of the filepath
 */
function debugger_get_relative_path($filepath) {
  return substr($filepath, strlen(getcwd())+1);
}
/**
 * Detect module name by file
 */
function debugger_module_via_file($file) {
  $module = '(unknown)';
  if (!strpos($file, '/') !== FALSE || strpos($file, 'includes/') === 0) {
    $module = 'Drupal';
  } else if (($extension = end(explode('.', ($filename = basename($file))))) == 'module') { // check for .module extension and get the name
      $module = substr($filename, 0, -1-strlen($extension));
  } else {
    $module = '(todo)';
  } // end: else
  return $module;
}
