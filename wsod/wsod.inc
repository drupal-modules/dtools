<?php

/**
 * @file
 *   Include file contain additional functions
 *
 * @version
 *
 * @developers:
 *   Rafal Wieczorek <kenorb@gmail.com>
 */

if (!defined('NL')) {
    define('NL', "<br>\n"); // new line in messages
} 

/** 
 * Validate hooks which should returns the data, but they don't
 * 
 * @param string $router_item
 * @return array or false 
 */ 
function wsod_validate_return_hooks($verbose = FALSE, &$output) {
  /* TODO
  if (module_exists('views')) {
    $views = views_get_all_views();
    $view = current($views); // get any of first view for testing
    // Let modules modify the view output after it is rendered.
    $view->execute();
    module_invoke_all('views_pre_render', $view);
    foreach (module_implements('views_post_render') as $module) {
      $function = $module . '_views_post_render';
      $res = $function($view, $view->display_handler->output);
    }
  }
  */
  return TRUE;
}

/** 
 * Validate theme hook files and callbacks
 * 
 * @param string $router_item
 * @return array or false 
 */ 
function wsod_validate_theme_hooks($verbose = FALSE, &$output) {
    $hooks = theme_get_registry(); // get list of theme hook
    $output .= t("Validating theme registry...") . NL;
    if (!empty($hooks)) {
        foreach ($hooks as $hook_name => $hook) {
          $theme_test = FALSE;
          $file = $hook['file'];
          $paths = array('.');
          $paths[] = $hook['path'] ? $hook['path'] : '.';
          $paths[] = $hook['theme path'] ? $hook['theme path'] : '.';
          foreach ($hook['theme paths'] as $key => $path) {
            $paths[] = $path;
          }
          // check for correct path in theme paths
          foreach ($paths as $key => $path) {
            $filepath = $path . '/' . $file;
            if (file_exists($filepath)) {
              $theme_test = TRUE;
              break;
            }
          }
          if (isset($hook['access_callback']) && !function_exists($hook['access_callback'])) {
              $output .= sprintf("ERROR: Access callback doesn't exist (callback: %s)", $hook['access_callback']) . NL;
              $theme_test = FALSE;
          }
          if (!$theme_test) {
            $output .= sprintf("ERROR: File or path doesn't exist (file: %s, path: %s; theme callback: %s)", $file, print_r($paths, TRUE), $hook_name) . NL;
            $output .= print_r($hook, TRUE) . NL;
          }
        }
    } else {
        $output .= "Theme registry is empty!" . NL;
        $theme_test = FALSE;
    }
    return $theme_test;
}

/** 
 * Get menu items and simulate menu router callback
 * 
 * @param string $router_item
 * @return array or false 
 */ 
function wsod_check_page_callback($router_item, $verbose = FALSE, &$messages, &$content_output) {
    $res = FALSE;
    ob_start(); // start output buffering
    if ($router_item) {
        if ($router_item['access']) {
            if ($router_item['file']) {
                require_once($router_item['file']);
                $file = basename($router_item['file']);
                $messages .= sprintf(t("Included render file: %s"), $file) . NL; // PRINT included file
            }
            $messages .= sprintf(t("Checking %s() page callback (path: %s)... (change it with q param in URL)"), $router_item['page_callback'], $_GET['q']) . NL; // PRINT included file
            $res = call_user_func_array($router_item['page_callback'], $router_item['page_arguments']);
        } else {
            $messages .= sprintf(t("User permission denied to execute %s() page callback..."), $router_item['page_callback']) . NL;
        }
    }
    $content_output = ob_get_clean(); // get output
    return $res;
}

