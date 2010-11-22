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
define('DBT_DEEP', 3);

/**
 * Save trace data into db
 */
function debugger_savetrace() {
  $basedir = getcwd();
  $pfncid = 0; // reset function parent id
  $total_time = 0;
  $total_mem = 0;
  $slow_fncid = array();
  $mem_fncid = array();
// db_query("TRUNCATE TABLE {debugger_files}");
// db_query("TRUNCATE TABLE {debugger_traces}");
// db_query("TRUNCATE TABLE {debugger_functions}");
// db_query("TRUNCATE TABLE {debugger_requests}");
  /* initialize the current HTTP request */
  $post = serialize($_POST);
  $path = $_GET['q'];
  $rpath = menu_get_item();
  // $query = // TODO: What here? All after '?'?
// xdebug_start_trace();
  $request_id = debugger_api_db_register_request($path, $rpath, $query, $post);
  list($backtraces, $num_ticks) = debugger_api_register_backtrace();
// var_dump($backtraces); exit;
  foreach ($backtraces as $c_time_mem => $backtrace) {
    list($counter, $time, $mem_delta) = explode(':', $c_time_mem);
    $total_time += $time;
    $total_mem += $mem_delta;
    /* CALCULATE THE TIME */
    // $time = (float)($microtime_last ? $microtime-$microtime_last : 0);
    // $microtime_last = (float)$microtime;
    $deep = 0;
    $ptid = 0; // reset trace parent id
    foreach ($backtrace as $key => $call_obj) {
      if ($call_obj['function'] == 'debugger_tick') {
        continue; // ignore our tick function
      }
      /* INIT VARIABLES */
      /* REGISTER FILE */
      $file = $call_obj['file'] ? debugger_get_relative_path($call_obj['file']) : '(unknown)';
      $fid = debugger_api_db_register_file($file); // find file id in db, if not - create one
      /* REGISTER FUNCTION */
      $function = $call_obj['function'];
      $args = serialize($call_obj['args']);
      $fncid = debugger_api_db_register_function($function, $fid, $call_obj['line'], count($args), ''); // find function id in db, if not - create one
      /* SAVE TRACE ITEM */
      $tid = debugger_api_db_register_trace($ptid, $fncid, $pfncid, $fid, $request_id, ($ptid == 0 ? $time : 0), ($ptid == 0 ? $mem_delta : 0), $args, $deep);
      $ptid = $tid; // save as parent for the next item
      if ($deep++ > DBT_DEEP) {
        break; // break if we are too deep, probably we have the rest details
      }
    } // end: foreach
    /* CHECK PERFORMANCE */
    $module = debugger_api_module_via_file();
    if ($mem_delta > current($mem_fncid)) { // check how much memory using this line
      $mem_fncid[$fncid] = $mem_delta; // 
    }
    if ($time > current($slow_fncid)) {
      $slow_fncid[$fncid] = $time;
    }
    $pfncid = $fncid; // save as parent for the next item
  }
  // TODO: $rpath = get menu callback via path (menu_router)
  // TODO: $fncid = get responsible function from menu callback (menu_router)
  // TODO: $slow_fncid = get responsible function from menu callback (menu_router)
// TODO: $query = '/* '. $name .' : '. $bt[2]['function'] .' */ '. $query; - check which function run which query and save into debugger_db_queries table
  global $queries;
  $num_sql = count($queries);
  debugger_api_db_update_request($request_id, $fid, $fncid, key($mem_fncid), key($slow_fncid), $slow_qid, $total_time, $total_memory, $num_sql, $num_ticks, $num_err, $num_warn, $num_notices);
}

/**
 * Get relative path of the filepath
 */
function debugger_get_relative_path($filepath) {
  return substr($filepath, strlen(getcwd())+1);
}

