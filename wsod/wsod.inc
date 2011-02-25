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

/** 
 * Validate theme hook files and callbacks
 * 
 * @param string $router_item
 * @return array or false 
 */ 
function wsod_validate_theme_hooks($verbose = FALSE, &$output) {
    $hooks = theme_get_registry(); // get list of theme hook
    $theme_test = TRUE;
    $nl = t('<br>');
    $output .= t("Validating theme registry...") . $nl;
    if (!empty($hooks)) {
        foreach ($hooks as $hook_name => $hook) {
            /* TODO: convert t() to sprintf() if t() is in bootstrap mode */
            if (isset($hook['path']) && !file_exists($hook['path'])) {
                $output .= sprintf("ERROR: File or path doesn't exist (path: %s; theme callback: %s)", $hook['path'], $hook_name) . $nl;
                $theme_test = FALSE;
            }
            $filepath = $hook['path'] ? $hook['path'].'/'.$hook['file'] : $hook['file'];
            if (isset($hook['file']) && !file_exists($filepath)) {
                $output .= sprintf("ERROR: File or path doesn't exist (path: %s; theme callback: %s)", $hook['path'], $hook_name) . $nl;
                $theme_test = FALSE;
            }
            if (isset($hook['theme path']) && !file_exists($hook['theme path'])) {
                $output .= sprintf("ERROR: File or path doesn't exist (path: %s; theme callback: %s)", $hook['theme path'], $hook_name) . $nl;
                $theme_test = FALSE;
            }
            if (isset($hook['access_callback']) && !function_exists($hook['access_callback'])) {
                $output .= sprintf("ERROR: Access callback doesn't exist (callback: %s)", $hook['access_callback']) . $nl;
                $theme_test = FALSE;
            }
        }
    } else {
        $output .= t("Theme registry is empty!") . $nl;
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
    $nl = t('<br>');
    if ($router_item) {
        if ($router_item['access']) {
            if ($router_item['file']) {
                require_once($router_item['file']);
                $file = basename($router_item['file']);
                $messages .= sprintf(t("Included render file: %s"), $file) . $nl; // PRINT included file
            }
            $messages .= sprintf(t("Checking %s() page callback (path: %s)... (change it with q param in URL)"), $router_item['page_callback'], $_GET['q']) . $nl; // PRINT included file
            $res = call_user_func_array($router_item['page_callback'], $router_item['page_arguments']);
        } else {
            $messages .= sprintf(t("User permission denied to execute %s() page callback..."), $router_item['page_callback']) . $nl;
        }
    }
    $content_output = ob_get_clean(); // get output
    return $res;
}

