<?php

/**
 * @file
 *   Form with Settings
 *
 * @version
 *   $Id$
 *
 * @developers
 *   Rafal Wieczorek <kenorb@gmail.com>
 */


/**
 * Menu callback for the settings form.
 */
function debugger_admin_form() {
  $form['debugger'] = array(
    '#type' => 'fieldset',
    '#title' => t('General Drupal debugger settings.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['debugger']['debugger_enable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable debugger'),
    '#description' => t('Be careful, it could diametrically decrease your website performance.'),
    '#default_value' => variable_get('debugger_enable', FALSE),
  );
  $form['debugger']['debugger_enable_error_handler'] = array(
    '#type' => 'checkbox',
    '#title' => t('Track number of errors.'),
    '#description' => t('Replace Drupal error handler to monitor notices, warnings and errors.'),
    '#default_value' => variable_get('debugger_enable_error_handler', TRUE),
    '#disabled' => !variable_get('debugger_enable', FALSE),
  );
  $form['debugger']['debugger_enable_sql_queries'] = array(
    '#type' => 'checkbox',
    '#title' => t('Track database queries.'),
    '#description' => t('Debug database queries and check execution times and which module run it.'),
    '#default_value' => variable_get('debugger_enable_sql_queries', FALSE),
    '#disabled' => !variable_get('debugger_enable', FALSE),
  );
  $form['debugger']['debugger_enable_admin'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable debugger on admin pages'),
    '#description' => t('Run debugger on admin pages. Note: If you enable this and something goes wrong, you could have problem disabling this module. Please test it on normal pages, before enabling it.'),
    '#default_value' => variable_get('debugger_enable_admin', FALSE),
    '#disabled' => !variable_get('debugger_enable', FALSE),
  );
  $form['debugger']['debugger_auto_disable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto disable debugger on fatal errors.'),
    '#description' => t('When page will crash or timeout accured, debugger will be disabled for stability reasons. You have to enable it manually again.'),
    '#default_value' => variable_get('debugger_auto_disable', TRUE),
    '#disabled' => !variable_get('debugger_enable', FALSE),
  );

  $form['debugger_advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced Drupal debugger settings.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
/*
  $form['debugger_advanced']['debugger_enable'] = array(
    '#type' => 'input',
    '#title' => t(''),
    '#description' => t('Be careful, it could diametrically decrease your website performance.'),
    '#default_value' => variable_get('debugger_enable', FALSE),
  );
*/

  return system_settings_form($form); 
}

