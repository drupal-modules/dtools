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
require_once './includes/menu.inc'; // load menu file (needed for Menu flags)
wsod_drupal_bootstrap_run(DRUPAL_BOOTSTRAP_FULL); // execute WSOD version of Drupal bootstrap
drupal_page_footer();

/* enable wsod module */
if (!module_exists('wsod')) {
    module_enable(array('wsod')); // enable wsod module if it's not enabled
}
if (!function_exists('wsod_check_wsod')) { // if wsod testing function doesn't exist, there is some path problem
    module_rebuild_cache(); // so we need to rebuild path of modules
    drupal_load('module', 'wsod'); // load module files again
} // if this will not help, please check manually in your filesystem if you don't have duplicated wsod modules

print wsod_check_wsod($verbose, $fix_on_fly, TRUE); // run diagnostic

/** 
 * Detect Drupal path by scanning each level of current path
 * 
 */ 
function wsod_detect_drupal_path(&$output, $start_dir = __FILE__) {
    $drupal_path = FALSE; // set init variable
    $path_arr = wsod_pathposall(dirname($start_dir));
    $bootstrap_file = '/includes/bootstrap.inc';
    $buff_output = '';
    foreach ($path_arr as $path) {
        if (file_exists($path.$bootstrap_file)) {
            $drupal_path = $path;
            return $drupal_path;
        } else {
            $buff_output .= "Couldn't find $path$bootstrap_file!<br>\n";
        }
        // FIXME: file_exists() [function.file-exists]: open_basedir restriction in effect. File(//includes/bootstrap.inc) is not within the allowed path(s)
    }
    $output .= $buff_output;
    return NULL;
}

/** 
 * pathposall 
 * 
 * Find all occurrences of a subdirs in a path
 * 
 * @param string $dir
 * @return array
 */ 
function wsod_pathposall($dir){ 
    $slash = wsod_detect_filesystem_slash();
    $pos = wsod_strposall($dir,$slash);
    foreach ($pos as $no) {
        $subdir[] = substr($dir, 0, $no);
    }
    if (is_array($subdir)) {
        rsort($subdir); // make list in reverse
        return $subdir; // return array of available subdir paths
    } else {
        return array();
    }
} 

/** 
 * Detect slash type of filesystem
 * 
 */ 
function wsod_detect_filesystem_slash() {
    if (strpos(__FILE__, '/') !== FALSE) { // detect filesystem
        return '/'; // Unix style
    } else {
        return '\\'; // Windows style
    }
}

/** 
 * Find all occurrences of a needle in a haystack 
 * 
 * @param string $haystack 
 * @param string $needle 
 * @return array or false 
 */ 
function wsod_strposall($haystack,$needle){ 
    $s=0; $i=0; 
    while (is_integer($i)){ 
        $i = strpos($haystack,$needle,$s); 
        if (is_integer($i)) { 
            $aStrPos[] = $i; 
            $s = $i+strlen($needle); 
        } 
    } 
    if (isset($aStrPos)) { 
        return $aStrPos; 
    } else { 
        return false; 
    } 
} 
