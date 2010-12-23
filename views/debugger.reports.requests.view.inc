<?php
// $Id$

$view = new view;
$view->name = 'Requests';
$view->description = 'Debugger: Requests';
$view->tag = 'debugger';
$view->view_php = '';
$view->base_table = 'debugger_requests';
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
$handler->display->display_options['style_options']['columns'] = array(
  'rid' => 'rid',
  'path' => 'path',
  'rpath' => 'rpath',
  'name' => 'name',
  'query' => 'query',
  'name_1' => 'name_1',
  'name_2' => 'name_2',
  'slow_qid' => 'slow_qid',
  'uid' => 'uid',
  'time' => 'time',
  'memory' => 'memory',
  'num_sql' => 'num_sql',
  'num_ticks' => 'num_ticks',
  'num_err' => 'num_err',
  'num_warn' => 'num_warn',
  'num_notices' => 'num_notices',
  'timestamp' => 'timestamp',
);
$handler->display->display_options['style_options']['default'] = 'rid';
$handler->display->display_options['style_options']['info'] = array(
  'rid' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'path' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'rpath' => array(
    'align' => '',
    'separator' => '',
  ),
  'name' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'query' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'name_1' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'name_2' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'slow_qid' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'uid' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'time' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'memory' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'num_sql' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'num_ticks' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'num_err' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'num_warn' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'num_notices' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'timestamp' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
);
$handler->display->display_options['style_options']['override'] = 1;
$handler->display->display_options['style_options']['sticky'] = 0;
$handler->display->display_options['style_options']['order'] = 'desc';
/* Relationship: Debugger: Requests: Function ID of the menu router callback */
$handler->display->display_options['relationships']['fncid']['id'] = 'fncid';
$handler->display->display_options['relationships']['fncid']['table'] = 'debugger_requests';
$handler->display->display_options['relationships']['fncid']['field'] = 'fncid';
$handler->display->display_options['relationships']['fncid']['label'] = 'Debugger: Function ID of menu callback';
$handler->display->display_options['relationships']['fncid']['required'] = 0;
/* Relationship: Debugger: Requests: Function ID which used the most memory */
$handler->display->display_options['relationships']['mem_fncid']['id'] = 'mem_fncid';
$handler->display->display_options['relationships']['mem_fncid']['table'] = 'debugger_requests';
$handler->display->display_options['relationships']['mem_fncid']['field'] = 'mem_fncid';
$handler->display->display_options['relationships']['mem_fncid']['required'] = 0;
/* Relationship: Debugger: Requests: Function ID which was the slowest */
$handler->display->display_options['relationships']['slow_fncid']['id'] = 'slow_fncid';
$handler->display->display_options['relationships']['slow_fncid']['table'] = 'debugger_requests';
$handler->display->display_options['relationships']['slow_fncid']['field'] = 'slow_fncid';
$handler->display->display_options['relationships']['slow_fncid']['required'] = 0;
/* Field: Debugger: Requests: Request ID */
$handler->display->display_options['fields']['rid']['id'] = 'rid';
$handler->display->display_options['fields']['rid']['table'] = 'debugger_requests';
$handler->display->display_options['fields']['rid']['field'] = 'rid';
$handler->display->display_options['fields']['rid']['label'] = 'rid';
$handler->display->display_options['fields']['rid']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['rid']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['rid']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['rid']['alter']['trim'] = 0;
$handler->display->display_options['fields']['rid']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['rid']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['rid']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['rid']['alter']['html'] = 0;
$handler->display->display_options['fields']['rid']['hide_empty'] = 0;
$handler->display->display_options['fields']['rid']['empty_zero'] = 0;
/* Field: Debugger: Requests: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'debugger_requests';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['path']['alter']['make_link'] = 1;
$handler->display->display_options['fields']['path']['alter']['path'] = 'admin/reports/debugger/path/[path]';
$handler->display->display_options['fields']['path']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['path']['alter']['trim'] = 1;
$handler->display->display_options['fields']['path']['alter']['max_length'] = '15';
$handler->display->display_options['fields']['path']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['path']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['path']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['path']['alter']['html'] = 0;
$handler->display->display_options['fields']['path']['hide_empty'] = 0;
$handler->display->display_options['fields']['path']['empty_zero'] = 0;
/* Field: Debugger: Requests: Router path */
$handler->display->display_options['fields']['rpath']['id'] = 'rpath';
$handler->display->display_options['fields']['rpath']['table'] = 'debugger_requests';
$handler->display->display_options['fields']['rpath']['field'] = 'rpath';
$handler->display->display_options['fields']['rpath']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['rpath']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['rpath']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['rpath']['alter']['trim'] = 1;
$handler->display->display_options['fields']['rpath']['alter']['max_length'] = '15';
$handler->display->display_options['fields']['rpath']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['rpath']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['rpath']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['rpath']['alter']['html'] = 0;
$handler->display->display_options['fields']['rpath']['hide_empty'] = 0;
$handler->display->display_options['fields']['rpath']['empty_zero'] = 0;
/* Field: Debugger: Functions: Function name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'debugger_functions';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'fncid';
$handler->display->display_options['fields']['name']['label'] = 'Function page callback';
$handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['name']['alter']['make_link'] = 1;
$handler->display->display_options['fields']['name']['alter']['path'] = 'admin/reports/debugger/traces/function/[name]';
$handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['name']['alter']['trim'] = 1;
$handler->display->display_options['fields']['name']['alter']['max_length'] = '20';
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['name']['alter']['html'] = 0;
$handler->display->display_options['fields']['name']['empty'] = '(non-existing)';
$handler->display->display_options['fields']['name']['hide_empty'] = 0;
$handler->display->display_options['fields']['name']['empty_zero'] = 1;
/* Field: Debugger: Requests: Query path */
$handler->display->display_options['fields']['query']['id'] = 'query';
$handler->display->display_options['fields']['query']['table'] = 'debugger_requests';
$handler->display->display_options['fields']['query']['field'] = 'query';
$handler->display->display_options['fields']['query']['label'] = 'Query';
$handler->display->display_options['fields']['query']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['query']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['query']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['query']['alter']['trim'] = 1;
$handler->display->display_options['fields']['query']['alter']['max_length'] = '15';
$handler->display->display_options['fields']['query']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['query']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['query']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['query']['alter']['html'] = 0;
$handler->display->display_options['fields']['query']['hide_empty'] = 0;
$handler->display->display_options['fields']['query']['empty_zero'] = 0;
/* Field: Debugger: Functions: Function name */
$handler->display->display_options['fields']['name_1']['id'] = 'name_1';
$handler->display->display_options['fields']['name_1']['table'] = 'debugger_functions';
$handler->display->display_options['fields']['name_1']['field'] = 'name';
$handler->display->display_options['fields']['name_1']['relationship'] = 'mem_fncid';
$handler->display->display_options['fields']['name_1']['label'] = 'Function (the most memory)';
$handler->display->display_options['fields']['name_1']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['name_1']['alter']['make_link'] = 1;
$handler->display->display_options['fields']['name_1']['alter']['path'] = 'admin/reports/debugger/traces/function/[name_1]';
$handler->display->display_options['fields']['name_1']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['name_1']['alter']['trim'] = 1;
$handler->display->display_options['fields']['name_1']['alter']['max_length'] = '20';
$handler->display->display_options['fields']['name_1']['alter']['word_boundary'] = 0;
$handler->display->display_options['fields']['name_1']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['name_1']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['name_1']['alter']['html'] = 0;
$handler->display->display_options['fields']['name_1']['hide_empty'] = 0;
$handler->display->display_options['fields']['name_1']['empty_zero'] = 0;
/* Field: Debugger: Functions: Function name */
$handler->display->display_options['fields']['name_2']['id'] = 'name_2';
$handler->display->display_options['fields']['name_2']['table'] = 'debugger_functions';
$handler->display->display_options['fields']['name_2']['field'] = 'name';
$handler->display->display_options['fields']['name_2']['relationship'] = 'slow_fncid';
$handler->display->display_options['fields']['name_2']['label'] = 'Function (the slowest)';
$handler->display->display_options['fields']['name_2']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['name_2']['alter']['make_link'] = 1;
$handler->display->display_options['fields']['name_2']['alter']['path'] = 'admin/reports/debugger/traces/function/[name_2]';
$handler->display->display_options['fields']['name_2']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['name_2']['alter']['trim'] = 1;
$handler->display->display_options['fields']['name_2']['alter']['max_length'] = '20';
$handler->display->display_options['fields']['name_2']['alter']['word_boundary'] = 0;
$handler->display->display_options['fields']['name_2']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['name_2']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['name_2']['alter']['html'] = 0;
$handler->display->display_options['fields']['name_2']['hide_empty'] = 0;
$handler->display->display_options['fields']['name_2']['empty_zero'] = 0;
/* Field: Debugger: Requests: Query ID which was the slowest */
$handler->display->display_options['fields']['slow_qid']['id'] = 'slow_qid';
$handler->display->display_options['fields']['slow_qid']['table'] = 'debugger_requests';
$handler->display->display_options['fields']['slow_qid']['field'] = 'slow_qid';
$handler->display->display_options['fields']['slow_qid']['label'] = 'Query ID (the slowest)';
$handler->display->display_options['fields']['slow_qid']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['slow_qid']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['slow_qid']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['slow_qid']['alter']['trim'] = 0;
$handler->display->display_options['fields']['slow_qid']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['slow_qid']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['slow_qid']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['slow_qid']['alter']['html'] = 0;
$handler->display->display_options['fields']['slow_qid']['hide_empty'] = 0;
$handler->display->display_options['fields']['slow_qid']['empty_zero'] = 0;
/* Field: User: Uid */
$handler->display->display_options['fields']['uid']['id'] = 'uid';
$handler->display->display_options['fields']['uid']['table'] = 'users';
$handler->display->display_options['fields']['uid']['field'] = 'uid';
$handler->display->display_options['fields']['uid']['relationship'] = 'uid';
$handler->display->display_options['fields']['uid']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['uid']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['uid']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['uid']['alter']['trim'] = 0;
$handler->display->display_options['fields']['uid']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['uid']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['uid']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['uid']['alter']['html'] = 0;
$handler->display->display_options['fields']['uid']['hide_empty'] = 0;
$handler->display->display_options['fields']['uid']['empty_zero'] = 0;
$handler->display->display_options['fields']['uid']['link_to_user'] = 1;
/* Field: Debugger: Requests: Total time */
$handler->display->display_options['fields']['time']['id'] = 'time';
$handler->display->display_options['fields']['time']['table'] = 'debugger_requests';
$handler->display->display_options['fields']['time']['field'] = 'time';
$handler->display->display_options['fields']['time']['label'] = 'Time';
$handler->display->display_options['fields']['time']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['time']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['time']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['time']['alter']['trim'] = 0;
$handler->display->display_options['fields']['time']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['time']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['time']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['time']['alter']['html'] = 0;
$handler->display->display_options['fields']['time']['hide_empty'] = 0;
$handler->display->display_options['fields']['time']['empty_zero'] = 0;
$handler->display->display_options['fields']['time']['set_precision'] = 1;
$handler->display->display_options['fields']['time']['precision'] = '0';
$handler->display->display_options['fields']['time']['format_plural'] = 0;
$handler->display->display_options['fields']['time']['suffix'] = 'ms';
/* Field: Debugger: Requests: Memory used */
$handler->display->display_options['fields']['memory']['id'] = 'memory';
$handler->display->display_options['fields']['memory']['table'] = 'debugger_requests';
$handler->display->display_options['fields']['memory']['field'] = 'memory';
$handler->display->display_options['fields']['memory']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['memory']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['memory']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['memory']['alter']['trim'] = 0;
$handler->display->display_options['fields']['memory']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['memory']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['memory']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['memory']['alter']['html'] = 0;
$handler->display->display_options['fields']['memory']['hide_empty'] = 0;
$handler->display->display_options['fields']['memory']['empty_zero'] = 0;
$handler->display->display_options['fields']['memory']['format_plural'] = 0;
$handler->display->display_options['fields']['memory']['suffix'] = 'b';
/* Field: Debugger: Requests: Number of SQL queries */
$handler->display->display_options['fields']['num_sql']['id'] = 'num_sql';
$handler->display->display_options['fields']['num_sql']['table'] = 'debugger_requests';
$handler->display->display_options['fields']['num_sql']['field'] = 'num_sql';
$handler->display->display_options['fields']['num_sql']['label'] = 'SQL queries';
$handler->display->display_options['fields']['num_sql']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['num_sql']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['num_sql']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['num_sql']['alter']['trim'] = 0;
$handler->display->display_options['fields']['num_sql']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['num_sql']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['num_sql']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['num_sql']['alter']['html'] = 0;
$handler->display->display_options['fields']['num_sql']['hide_empty'] = 0;
$handler->display->display_options['fields']['num_sql']['empty_zero'] = 0;
$handler->display->display_options['fields']['num_sql']['format_plural'] = 0;
/* Field: Debugger: Requests: Number of ticks */
$handler->display->display_options['fields']['num_ticks']['id'] = 'num_ticks';
$handler->display->display_options['fields']['num_ticks']['table'] = 'debugger_requests';
$handler->display->display_options['fields']['num_ticks']['field'] = 'num_ticks';
$handler->display->display_options['fields']['num_ticks']['label'] = 'Ticks';
$handler->display->display_options['fields']['num_ticks']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['num_ticks']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['num_ticks']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['num_ticks']['alter']['trim'] = 0;
$handler->display->display_options['fields']['num_ticks']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['num_ticks']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['num_ticks']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['num_ticks']['alter']['html'] = 0;
$handler->display->display_options['fields']['num_ticks']['hide_empty'] = 0;
$handler->display->display_options['fields']['num_ticks']['empty_zero'] = 0;
$handler->display->display_options['fields']['num_ticks']['format_plural'] = 0;
/* Field: Debugger: Requests: Number of error messages */
$handler->display->display_options['fields']['num_err']['id'] = 'num_err';
$handler->display->display_options['fields']['num_err']['table'] = 'debugger_requests';
$handler->display->display_options['fields']['num_err']['field'] = 'num_err';
$handler->display->display_options['fields']['num_err']['label'] = 'No of errors';
$handler->display->display_options['fields']['num_err']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['num_err']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['num_err']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['num_err']['alter']['trim'] = 0;
$handler->display->display_options['fields']['num_err']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['num_err']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['num_err']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['num_err']['alter']['html'] = 0;
$handler->display->display_options['fields']['num_err']['hide_empty'] = 0;
$handler->display->display_options['fields']['num_err']['empty_zero'] = 0;
$handler->display->display_options['fields']['num_err']['format_plural'] = 0;
/* Field: Debugger: Requests: Number of warning messages */
$handler->display->display_options['fields']['num_warn']['id'] = 'num_warn';
$handler->display->display_options['fields']['num_warn']['table'] = 'debugger_requests';
$handler->display->display_options['fields']['num_warn']['field'] = 'num_warn';
$handler->display->display_options['fields']['num_warn']['label'] = 'No of warnings';
$handler->display->display_options['fields']['num_warn']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['num_warn']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['num_warn']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['num_warn']['alter']['trim'] = 0;
$handler->display->display_options['fields']['num_warn']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['num_warn']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['num_warn']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['num_warn']['alter']['html'] = 0;
$handler->display->display_options['fields']['num_warn']['hide_empty'] = 0;
$handler->display->display_options['fields']['num_warn']['empty_zero'] = 0;
$handler->display->display_options['fields']['num_warn']['format_plural'] = 0;
/* Field: Debugger: Requests: Number of notice messages */
$handler->display->display_options['fields']['num_notices']['id'] = 'num_notices';
$handler->display->display_options['fields']['num_notices']['table'] = 'debugger_requests';
$handler->display->display_options['fields']['num_notices']['field'] = 'num_notices';
$handler->display->display_options['fields']['num_notices']['label'] = 'No of notices';
$handler->display->display_options['fields']['num_notices']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['num_notices']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['num_notices']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['num_notices']['alter']['trim'] = 0;
$handler->display->display_options['fields']['num_notices']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['num_notices']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['num_notices']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['num_notices']['alter']['html'] = 0;
$handler->display->display_options['fields']['num_notices']['hide_empty'] = 0;
$handler->display->display_options['fields']['num_notices']['empty_zero'] = 0;
$handler->display->display_options['fields']['num_notices']['format_plural'] = 0;
/* Field: Debugger: Requests: Timestamp */
$handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['table'] = 'debugger_requests';
$handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['label'] = 'Date';
$handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['timestamp']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['timestamp']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['timestamp']['alter']['trim'] = 0;
$handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['timestamp']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['timestamp']['alter']['html'] = 0;
$handler->display->display_options['fields']['timestamp']['hide_empty'] = 0;
$handler->display->display_options['fields']['timestamp']['empty_zero'] = 0;

/* Display: Requests */
$handler = $view->new_display('page', 'Requests', 'page_1');
$handler->display->display_options['path'] = 'admin/reports/debugger/requests';
$handler->display->display_options['menu']['type'] = 'default tab';
$handler->display->display_options['menu']['title'] = 'Requests';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['tab_options']['type'] = 'normal';
$handler->display->display_options['tab_options']['title'] = 'Debugger Data';
$handler->display->display_options['tab_options']['weight'] = '0';

