<?php
// $Id$

/**
 * Implementation of hook_views_default_views().
 *
 * @return
 *   array    Default views for the cql module
 */
function debugger_views_default_views() {
  $views = array();
  $modulename = 'debugger';
  // Include all files in the views/ directory ending with .inc
  $path = drupal_get_path('module', $modulename) . '/views';
  $files = drupal_system_listing('view.inc$', $path, 'name', 0);
  foreach ($files as $file) {
    include_once "$file->filename";
    // if someone forgot add the created view into the $views array, add it now
    if (!array_key_exists($view->name, $views)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}

