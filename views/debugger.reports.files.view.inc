<?php

$view = new view;
$view->name = 'debugger_files';
$view->description = 'Debugger: Files';
$view->tag = 'debugger';
$view->view_php = '';
$view->base_table = 'debugger_files';
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
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
$handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 20, 50, 100, 200, 500';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['grouping'] = 'module';
$handler->display->display_options['style_options']['columns'] = array(
  'fid' => 'fid',
  'filepath' => 'filepath',
  'module' => 'module',
);
$handler->display->display_options['style_options']['default'] = 'fid';
$handler->display->display_options['style_options']['info'] = array(
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
  'module' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
);
$handler->display->display_options['style_options']['override'] = 1;
$handler->display->display_options['style_options']['sticky'] = 0;
/* Field: Debugger: Files: File ID */
$handler->display->display_options['fields']['fid']['id'] = 'fid';
$handler->display->display_options['fields']['fid']['table'] = 'debugger_files';
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
/* Field: Debugger: Files: File Path */
$handler->display->display_options['fields']['filepath']['id'] = 'filepath';
$handler->display->display_options['fields']['filepath']['table'] = 'debugger_files';
$handler->display->display_options['fields']['filepath']['field'] = 'filepath';
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
/* Field: Debugger: Files: Module */
$handler->display->display_options['fields']['module']['id'] = 'module';
$handler->display->display_options['fields']['module']['table'] = 'debugger_files';
$handler->display->display_options['fields']['module']['field'] = 'module';
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
/* Filter: Debugger: Files: Module */
$handler->display->display_options['filters']['module']['id'] = 'module';
$handler->display->display_options['filters']['module']['table'] = 'debugger_files';
$handler->display->display_options['filters']['module']['field'] = 'module';
$handler->display->display_options['filters']['module']['operator'] = '=';
$handler->display->display_options['filters']['module']['exposed'] = TRUE;
$handler->display->display_options['filters']['module']['expose']['label'] = 'Module';
$handler->display->display_options['filters']['module']['expose']['identifier'] = 'module';
$handler->display->display_options['filters']['module']['expose']['single'] = 0;
$handler->display->display_options['filters']['module']['expose']['reduce'] = 0;

/* Display: Debugger: Files */
$handler = $view->new_display('page', 'Debugger: Files', 'page_1');
$handler->display->display_options['path'] = 'admin/reports/debugger/files';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Files';
$handler->display->display_options['menu']['weight'] = '0';

