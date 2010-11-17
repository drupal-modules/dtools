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

  $form['debugger']['debugger_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable debugger'),
    '#description' => t('Be careful, it could diametrically decrease your website performance.'),
    '#default_value' => variable_get('debugger_enabled', FALSE),
  );

  $form['debugger']['debugger_enabled_admin'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable debugger for admin pages'),
    '#description' => t('Be careful, it could diametrically decrease your website performance.'),
    '#default_value' => variable_get('debugger_enabled_admin', FALSE),
    '#disabled' => !variable_get('debugger_enabled_admin', FALSE),
  );

  return system_settings_form($form); 
}

