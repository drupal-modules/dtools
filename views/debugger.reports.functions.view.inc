<?php
// $Id$

/**
 * Exported View in Reports
 *
 */

$view = new view;
$view->name = 'debugger_functions';
$view->description = 'Debugger: Functions';
$view->tag = 'debugger';
$view->view_php = '';
$view->base_table = 'debugger_functions';
$view->is_cacheable = FALSE;
$view->api_version = '3.0-alpha1';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Defaults */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'fncid' => 'fncid',
  'name' => 'name',
  'description' => 'description',
  'fid' => 'fid',
  'line' => 'line',
);
$handler->display->display_options['style_options']['default'] = 'fncid';
$handler->display->display_options['style_options']['info'] = array(
  'fncid' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'name' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'description' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'fid' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'line' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
);
$handler->display->display_options['style_options']['override'] = 1;
$handler->display->display_options['style_options']['sticky'] = 0;
/* Empty text: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['label'] = 'Empty data';
$handler->display->display_options['empty']['area']['empty'] = FALSE;
$handler->display->display_options['empty']['area']['content'] = 'No data.';
/* Field: Debugger Functions: Function ID */
$handler->display->display_options['fields']['fncid']['id'] = 'fncid';
$handler->display->display_options['fields']['fncid']['table'] = 'debugger_functions';
$handler->display->display_options['fields']['fncid']['field'] = 'fncid';
$handler->display->display_options['fields']['fncid']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['fncid']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['fncid']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['fncid']['alter']['trim'] = 0;
$handler->display->display_options['fields']['fncid']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['fncid']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['fncid']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['fncid']['alter']['html'] = 0;
$handler->display->display_options['fields']['fncid']['hide_empty'] = 0;
$handler->display->display_options['fields']['fncid']['empty_zero'] = 0;
/* Field: Debugger Functions: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'debugger_functions';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['name']['alter']['trim'] = 0;
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['name']['alter']['html'] = 0;
$handler->display->display_options['fields']['name']['hide_empty'] = 0;
$handler->display->display_options['fields']['name']['empty_zero'] = 0;
/* Field: Debugger Functions: Description */
$handler->display->display_options['fields']['description']['id'] = 'description';
$handler->display->display_options['fields']['description']['table'] = 'debugger_functions';
$handler->display->display_options['fields']['description']['field'] = 'description';
$handler->display->display_options['fields']['description']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['description']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['description']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['description']['alter']['trim'] = 0;
$handler->display->display_options['fields']['description']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['description']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['description']['alter']['html'] = 0;
$handler->display->display_options['fields']['description']['hide_empty'] = 0;
$handler->display->display_options['fields']['description']['empty_zero'] = 0;
/* Field: Debugger Functions: File ID */
$handler->display->display_options['fields']['fid']['id'] = 'fid';
$handler->display->display_options['fields']['fid']['table'] = 'debugger_functions';
$handler->display->display_options['fields']['fid']['field'] = 'fid';
$handler->display->display_options['fields']['fid']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['fid']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['fid']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['fid']['alter']['trim'] = 0;
$handler->display->display_options['fields']['fid']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['fid']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['fid']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['fid']['alter']['html'] = 0;
$handler->display->display_options['fields']['fid']['hide_empty'] = 0;
$handler->display->display_options['fields']['fid']['empty_zero'] = 0;
/* Field: Debugger Functions: Line */
$handler->display->display_options['fields']['line']['id'] = 'line';
$handler->display->display_options['fields']['line']['table'] = 'debugger_functions';
$handler->display->display_options['fields']['line']['field'] = 'line';
$handler->display->display_options['fields']['line']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['line']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['line']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['line']['alter']['trim'] = 0;
$handler->display->display_options['fields']['line']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['line']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['line']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['line']['alter']['html'] = 0;
$handler->display->display_options['fields']['line']['hide_empty'] = 0;
$handler->display->display_options['fields']['line']['empty_zero'] = 0;

/* Display: Functions */
$handler = $view->new_display('page', 'Functions', 'page_1');
$handler->display->display_options['path'] = 'admin/reports/debugger/functions';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Debugger: Functions';
$handler->display->display_options['menu']['weight'] = '0';

