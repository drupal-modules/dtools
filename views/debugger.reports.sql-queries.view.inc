<?php
// $Id$

$view = new view;
$view->name = 'debugger_sql_queries';
$view->description = 'Debugger: SQL Queries';
$view->tag = 'debugger';
$view->view_php = '';
$view->base_table = 'debugger_sql_queries';
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
  'qid' => 'qid',
  'fncid' => 'fncid',
  'time' => 'time',
);
$handler->display->display_options['style_options']['default'] = 'qid';
$handler->display->display_options['style_options']['info'] = array(
  'qid' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'fncid' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'time' => array(
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
/* Field: Debugger: SQL Queries: Query ID */
$handler->display->display_options['fields']['qid']['id'] = 'qid';
$handler->display->display_options['fields']['qid']['table'] = 'debugger_sql_queries';
$handler->display->display_options['fields']['qid']['field'] = 'qid';
$handler->display->display_options['fields']['qid']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['qid']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['qid']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['qid']['alter']['trim'] = 0;
$handler->display->display_options['fields']['qid']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['qid']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['qid']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['qid']['alter']['html'] = 0;
$handler->display->display_options['fields']['qid']['hide_empty'] = 0;
$handler->display->display_options['fields']['qid']['empty_zero'] = 0;
/* Field: Debugger: SQL Queries: Function ID */
$handler->display->display_options['fields']['fncid']['id'] = 'fncid';
$handler->display->display_options['fields']['fncid']['table'] = 'debugger_sql_queries';
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
/* Field: Debugger: SQL Queries: Execution time */
$handler->display->display_options['fields']['time']['id'] = 'time';
$handler->display->display_options['fields']['time']['table'] = 'debugger_sql_queries';
$handler->display->display_options['fields']['time']['field'] = 'time';
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
$handler->display->display_options['fields']['time']['format_plural'] = 0;

/* Display: Debugger: SQL Queries */
$handler = $view->new_display('page', 'Debugger: SQL Queries', 'page_1');
$handler->display->display_options['path'] = 'admin/reports/debugger/sql_queries';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'SQL';
$handler->display->display_options['menu']['weight'] = '0';

