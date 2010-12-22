<?php
// $Id$

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
$handler->display->display_options['pager']['options']['items_per_page'] = '50';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['grouping'] = 'module';
$handler->display->display_options['style_options']['columns'] = array(
  'fncid' => 'fncid',
  'name' => 'name',
  'description' => 'description',
  'filepath' => 'filepath',
  'line' => 'line',
  'module' => 'module',
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
  'filepath' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'line' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'module' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
);
$handler->display->display_options['style_options']['override'] = 1;
$handler->display->display_options['style_options']['sticky'] = 1;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['label'] = '';
$handler->display->display_options['header']['area']['empty'] = FALSE;
$handler->display->display_options['header']['area']['content'] = 'Function calls caught by debugger.';
/* Relationship: Debugger: Functions: File ID */
$handler->display->display_options['relationships']['fid']['id'] = 'fid';
$handler->display->display_options['relationships']['fid']['table'] = 'debugger_functions';
$handler->display->display_options['relationships']['fid']['field'] = 'fid';
$handler->display->display_options['relationships']['fid']['required'] = 0;
/* Field: Debugger: Functions: Function ID */
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
/* Field: Debugger: Functions: Function name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'debugger_functions';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = 'Name';
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
/* Field: Debugger: Functions: Description */
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
/* Field: Debugger: Files: File Path */
$handler->display->display_options['fields']['filepath']['id'] = 'filepath';
$handler->display->display_options['fields']['filepath']['table'] = 'debugger_files';
$handler->display->display_options['fields']['filepath']['field'] = 'filepath';
$handler->display->display_options['fields']['filepath']['relationship'] = 'fid';
$handler->display->display_options['fields']['filepath']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['filepath']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['filepath']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['filepath']['alter']['trim'] = 0;
$handler->display->display_options['fields']['filepath']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['filepath']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['filepath']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['filepath']['alter']['html'] = 0;
$handler->display->display_options['fields']['filepath']['hide_empty'] = 0;
$handler->display->display_options['fields']['filepath']['empty_zero'] = 0;
/* Field: Debugger: Functions: Line */
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
/* Field: Debugger: Files: Module */
$handler->display->display_options['fields']['module']['id'] = 'module';
$handler->display->display_options['fields']['module']['table'] = 'debugger_files';
$handler->display->display_options['fields']['module']['field'] = 'module';
$handler->display->display_options['fields']['module']['relationship'] = 'fid';
$handler->display->display_options['fields']['module']['exclude'] = TRUE;
$handler->display->display_options['fields']['module']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['module']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['module']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['module']['alter']['trim'] = 0;
$handler->display->display_options['fields']['module']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['module']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['module']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['module']['alter']['html'] = 0;
$handler->display->display_options['fields']['module']['hide_empty'] = 0;
$handler->display->display_options['fields']['module']['empty_zero'] = 0;

/* Display: Functions */
$handler = $view->new_display('page', 'Functions', 'page_1');
$handler->display->display_options['path'] = 'admin/reports/debugger/functions';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Functions';
$handler->display->display_options['menu']['weight'] = '0';

