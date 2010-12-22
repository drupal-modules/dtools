<?php
// $Id$

$view = new view;
$view->name = 'debugger_traces';
$view->description = 'Debugger: Traces';
$view->tag = 'debugger';
$view->view_php = '';
$view->base_table = 'debugger_traces';
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
$handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
$handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 20, 50, 100, 200, 500';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['grouping'] = 'name_2';
$handler->display->display_options['style_options']['columns'] = array(
  'tid' => 'tid',
  'ptid' => 'ptid',
  'name_1' => 'name_1',
  'name' => 'name',
  'pfncid' => 'pfncid',
  'fid' => 'fid',
  'filepath' => 'filepath',
  'line' => 'line',
  'rid' => 'rid',
  'time_delta' => 'time_delta',
  'mem_delta' => 'mem_delta',
  'name_2' => 'name_2',
);
$handler->display->display_options['style_options']['default'] = 'time_delta';
$handler->display->display_options['style_options']['info'] = array(
  'tid' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'ptid' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'name_1' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'name' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'pfncid' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'fid' => array(
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
  'rid' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'time_delta' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'mem_delta' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'name_2' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
);
$handler->display->display_options['style_options']['override'] = 1;
$handler->display->display_options['style_options']['sticky'] = 1;
$handler->display->display_options['style_options']['order'] = 'desc';
/* Empty text: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['label'] = 'Empty data';
$handler->display->display_options['empty']['area']['empty'] = FALSE;
$handler->display->display_options['empty']['area']['content'] = 'No traces found.';
/* Relationship: Debugger: Traces: Request ID */
$handler->display->display_options['relationships']['rid']['id'] = 'rid';
$handler->display->display_options['relationships']['rid']['table'] = 'debugger_traces';
$handler->display->display_options['relationships']['rid']['field'] = 'rid';
$handler->display->display_options['relationships']['rid']['required'] = 0;
/* Relationship: Debugger: Traces: File ID */
$handler->display->display_options['relationships']['fid']['id'] = 'fid';
$handler->display->display_options['relationships']['fid']['table'] = 'debugger_traces';
$handler->display->display_options['relationships']['fid']['field'] = 'fid';
$handler->display->display_options['relationships']['fid']['required'] = 0;
/* Relationship: Debugger: Traces: Function ID */
$handler->display->display_options['relationships']['fncid']['id'] = 'fncid';
$handler->display->display_options['relationships']['fncid']['table'] = 'debugger_traces';
$handler->display->display_options['relationships']['fncid']['field'] = 'fncid';
$handler->display->display_options['relationships']['fncid']['required'] = 0;
/* Relationship: Debugger: Traces: Function ID of parent */
$handler->display->display_options['relationships']['pfncid']['id'] = 'pfncid';
$handler->display->display_options['relationships']['pfncid']['table'] = 'debugger_traces';
$handler->display->display_options['relationships']['pfncid']['field'] = 'pfncid';
$handler->display->display_options['relationships']['pfncid']['required'] = 0;
/* Relationship: Debugger: Requests: Function ID of the menu router callback */
$handler->display->display_options['relationships']['fncid_1']['id'] = 'fncid_1';
$handler->display->display_options['relationships']['fncid_1']['table'] = 'debugger_requests';
$handler->display->display_options['relationships']['fncid_1']['field'] = 'fncid';
$handler->display->display_options['relationships']['fncid_1']['relationship'] = 'rid';
$handler->display->display_options['relationships']['fncid_1']['label'] = 'Debugger: Function of menu callback';
$handler->display->display_options['relationships']['fncid_1']['required'] = 0;
/* Field: Debugger: Traces: Trace ID */
$handler->display->display_options['fields']['tid']['id'] = 'tid';
$handler->display->display_options['fields']['tid']['table'] = 'debugger_traces';
$handler->display->display_options['fields']['tid']['field'] = 'tid';
/* Field: Debugger: Traces: Trace ID of parent */
$handler->display->display_options['fields']['ptid']['id'] = 'ptid';
$handler->display->display_options['fields']['ptid']['table'] = 'debugger_traces';
$handler->display->display_options['fields']['ptid']['field'] = 'ptid';
/* Field: Debugger: Functions: Function name */
$handler->display->display_options['fields']['name_1']['id'] = 'name_1';
$handler->display->display_options['fields']['name_1']['table'] = 'debugger_functions';
$handler->display->display_options['fields']['name_1']['field'] = 'name';
$handler->display->display_options['fields']['name_1']['relationship'] = 'fncid';
$handler->display->display_options['fields']['name_1']['label'] = 'Function';
$handler->display->display_options['fields']['name_1']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['name_1']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['name_1']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['name_1']['alter']['trim'] = 0;
$handler->display->display_options['fields']['name_1']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['name_1']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['name_1']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['name_1']['alter']['html'] = 0;
$handler->display->display_options['fields']['name_1']['hide_empty'] = 0;
$handler->display->display_options['fields']['name_1']['empty_zero'] = 0;
/* Field: Debugger: Functions: Function name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'debugger_functions';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'pfncid';
$handler->display->display_options['fields']['name']['label'] = 'Function parent';
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
/* Field: Debugger: Traces: Function ID */
$handler->display->display_options['fields']['fncid']['id'] = 'fncid';
$handler->display->display_options['fields']['fncid']['table'] = 'debugger_traces';
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
/* Field: Debugger: Traces: Function ID of parent */
$handler->display->display_options['fields']['pfncid']['id'] = 'pfncid';
$handler->display->display_options['fields']['pfncid']['table'] = 'debugger_traces';
$handler->display->display_options['fields']['pfncid']['field'] = 'pfncid';
/* Field: Debugger: Traces: File ID */
$handler->display->display_options['fields']['fid']['id'] = 'fid';
$handler->display->display_options['fields']['fid']['table'] = 'debugger_traces';
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
$handler->display->display_options['fields']['fid']['empty_zero'] = 1;
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
/* Field: Debugger: Traces: Line */
$handler->display->display_options['fields']['line']['id'] = 'line';
$handler->display->display_options['fields']['line']['table'] = 'debugger_traces';
$handler->display->display_options['fields']['line']['field'] = 'line';
/* Field: Debugger: Requests: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'debugger_requests';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['relationship'] = 'rid';
$handler->display->display_options['fields']['path']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['path']['alter']['make_link'] = 1;
$handler->display->display_options['fields']['path']['alter']['path'] = '[path]';
$handler->display->display_options['fields']['path']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['path']['alter']['trim'] = 0;
$handler->display->display_options['fields']['path']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['path']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['path']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['path']['alter']['html'] = 0;
$handler->display->display_options['fields']['path']['hide_empty'] = 0;
$handler->display->display_options['fields']['path']['empty_zero'] = 0;
/* Field: Debugger: Traces: Request ID */
$handler->display->display_options['fields']['rid']['id'] = 'rid';
$handler->display->display_options['fields']['rid']['table'] = 'debugger_traces';
$handler->display->display_options['fields']['rid']['field'] = 'rid';
$handler->display->display_options['fields']['rid']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['rid']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['rid']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['rid']['alter']['trim'] = 0;
$handler->display->display_options['fields']['rid']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['rid']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['rid']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['rid']['alter']['html'] = 0;
$handler->display->display_options['fields']['rid']['hide_empty'] = 0;
$handler->display->display_options['fields']['rid']['empty_zero'] = 1;
/* Field: Debugger: Traces: Time Delta */
$handler->display->display_options['fields']['time_delta']['id'] = 'time_delta';
$handler->display->display_options['fields']['time_delta']['table'] = 'debugger_traces';
$handler->display->display_options['fields']['time_delta']['field'] = 'time_delta';
$handler->display->display_options['fields']['time_delta']['label'] = 'Time Delta (ms)';
$handler->display->display_options['fields']['time_delta']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['time_delta']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['time_delta']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['time_delta']['alter']['trim'] = 0;
$handler->display->display_options['fields']['time_delta']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['time_delta']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['time_delta']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['time_delta']['alter']['html'] = 0;
$handler->display->display_options['fields']['time_delta']['hide_empty'] = 0;
$handler->display->display_options['fields']['time_delta']['empty_zero'] = 0;
$handler->display->display_options['fields']['time_delta']['separator'] = ' ,';
$handler->display->display_options['fields']['time_delta']['format_plural'] = 0;
/* Field: Debugger: Traces: Memory delta */
$handler->display->display_options['fields']['mem_delta']['id'] = 'mem_delta';
$handler->display->display_options['fields']['mem_delta']['table'] = 'debugger_traces';
$handler->display->display_options['fields']['mem_delta']['field'] = 'mem_delta';
/* Field: Debugger: Functions: Function name */
$handler->display->display_options['fields']['name_2']['id'] = 'name_2';
$handler->display->display_options['fields']['name_2']['table'] = 'debugger_functions';
$handler->display->display_options['fields']['name_2']['field'] = 'name';
$handler->display->display_options['fields']['name_2']['relationship'] = 'fncid_1';
$handler->display->display_options['fields']['name_2']['label'] = 'Menu callback function';
$handler->display->display_options['fields']['name_2']['exclude'] = TRUE;
$handler->display->display_options['fields']['name_2']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['name_2']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['name_2']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['name_2']['alter']['trim'] = 0;
$handler->display->display_options['fields']['name_2']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['name_2']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['name_2']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['name_2']['alter']['html'] = 0;
$handler->display->display_options['fields']['name_2']['hide_empty'] = 0;
$handler->display->display_options['fields']['name_2']['empty_zero'] = 0;
/* Filter: Debugger: Files: Module */
$handler->display->display_options['filters']['module']['id'] = 'module';
$handler->display->display_options['filters']['module']['table'] = 'debugger_files';
$handler->display->display_options['filters']['module']['field'] = 'module';
$handler->display->display_options['filters']['module']['relationship'] = 'fid';
$handler->display->display_options['filters']['module']['operator'] = 'not in';
$handler->display->display_options['filters']['module']['exposed'] = TRUE;
$handler->display->display_options['filters']['module']['expose']['operator'] = 'module_op';
$handler->display->display_options['filters']['module']['expose']['label'] = 'Module';
$handler->display->display_options['filters']['module']['expose']['use_operator'] = 1;
$handler->display->display_options['filters']['module']['expose']['identifier'] = 'module';
$handler->display->display_options['filters']['module']['expose']['single'] = 0;
$handler->display->display_options['filters']['module']['expose']['reduce'] = 0;

/* Display: Debugger: Traces */
$handler = $view->new_display('page', 'Debugger: Traces', 'page_1');
$handler->display->display_options['path'] = 'admin/reports/debugger/traces';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Traces';
$handler->display->display_options['menu']['weight'] = '0';

/* Display: Traces by function */
$handler = $view->new_display('page', 'Traces by function', 'page_2');
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Argument: Debugger: Functions: Function name */
$handler->display->display_options['arguments']['name']['id'] = 'name';
$handler->display->display_options['arguments']['name']['table'] = 'debugger_functions';
$handler->display->display_options['arguments']['name']['field'] = 'name';
$handler->display->display_options['arguments']['name']['relationship'] = 'fncid';
$handler->display->display_options['arguments']['name']['style_plugin'] = 'default_summary';
$handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['name']['glossary'] = 0;
$handler->display->display_options['arguments']['name']['ignorecase'] = 0;
$handler->display->display_options['arguments']['name']['limit'] = '0';
$handler->display->display_options['arguments']['name']['transform_dash'] = 0;
$handler->display->display_options['path'] = 'admin/reports/debugger/traces/function';

/* Display: Traces by path */
$handler = $view->new_display('page', 'Traces by path', 'page_3');
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Argument: Debugger: Requests: Path */
$handler->display->display_options['arguments']['path']['id'] = 'path';
$handler->display->display_options['arguments']['path']['table'] = 'debugger_requests';
$handler->display->display_options['arguments']['path']['field'] = 'path';
$handler->display->display_options['arguments']['path']['relationship'] = 'rid';
$handler->display->display_options['arguments']['path']['style_plugin'] = 'default_summary';
$handler->display->display_options['arguments']['path']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['path']['glossary'] = 0;
$handler->display->display_options['arguments']['path']['ignorecase'] = 0;
$handler->display->display_options['arguments']['path']['limit'] = '0';
$handler->display->display_options['arguments']['path']['transform_dash'] = 0;
$handler->display->display_options['path'] = 'admin/reports/debugger/traces/path';

