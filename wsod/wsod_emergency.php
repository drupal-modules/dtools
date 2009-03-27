<?php
/*
	version: $Id$
	author: kenorb@gmail.com
*/

$verbose = TRUE;
$fix_on_fly  = TRUE;
$output = '';

require_once './wsod.module'; // include functions

$drupal_path = wsod_detect_drupal_path($output);
if (!empty($drupal_path)) {
    chdir($drupal_path); // change dir to Drupal path
} else {
    $verbose ? print "Fatal error: Couldn't detect your Drupal installation in:<br>\n".$output : NULL;
    $verbose ? print "Move this module inside your Drupal installation!": NULL;
    exit;
}

/* simulate Drupal boot */
require_once './includes/bootstrap.inc'; // load bootstrap file
wsod_drupal_bootstrap_run(DRUPAL_BOOTSTRAP_FULL); // execute WSOD version of Drupal bootstrap

/* enable wsod module */
if (!module_exists('wsod')) {
    module_enable(array('wsod')); // enable wsod module if it's not enabled
}
if (!function_exists('wsod_check_wsod')) { // if wsod testing function doesn't exist, there is some path problem
    module_rebuild_cache(); // so we need to rebuild path of modules
    drupal_load('module', 'wsod'); // load module files again
} // if this will not help, please check manually in your filesystem if you don't have duplicated wsod modules

print wsod_check_wsod($verbose, $fix_on_fly); // run diagnostic

