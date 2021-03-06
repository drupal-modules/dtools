<?php

/**
 * Menu callback for the settings form.
 */
function wsod_admin_form() {

  $form['wsod'] = array(
    '#type' => 'fieldset',
    '#title' => t('Diagnostics Tools for WSOD'),
    '#collapsible' => TRUE,
  ); 

  $form['wsod']['wsod_rebuild'] = array(
    '#type' => 'submit',
    '#value' => t('Rebuild menu'),
    '#submit' => array('wsod_rebuild_submit'),
  ); 

  $form['wsod']['wsod_live_checking'] = array(
    '#type' => 'checkbox',
    '#title' => t('Check for WSOD on every page load (only for debugging purpose).'),
    '#description' => t('WSOD is checked on every page load. Loading performance of your website could be decreased!'),
    '#default_value' => variable_get('wsod_live_checking', FALSE),
  );

  $form['wsod']['wsod_checking_on_post'] = array(
    '#type' => 'checkbox',
    '#title' => t('Check for WSOD on submitted forms as well.'),
    '#description' => t('Activate WSOD checking on submitted forms (by default WSOD are checked only for non-submitted forms).'),
    '#default_value' => variable_get('wsod_checking_on_post', FALSE),
    '#disabled' => !variable_get('wsod_live_checking', FALSE),
  );

  $form['wsod']['wsod_verbose_mode'] = array(
    '#type' => 'checkbox',
    '#title' => t('Activate verbose mode'),
    '#description' => t('Activate verbose mode on WSOD pages (debug messages are sent directly to website output). Please use it only for debug purposes, because it could break your theme!'),
    '#default_value' => variable_get('wsod_verbose_mode', FALSE),
    '#disabled' => !variable_get('wsod_live_checking', FALSE),
  );

  //$form['#validate'] = array('personalized_settings_admin_form_validate');

  return system_settings_form($form); 
}
 
/**
 * Form button submit callback.
 */
function wsod_rebuild_submit($form, &$form_state) {
  $form_state['redirect'] = 'admin/build/dtools/rebuild';
}
 
/**
 * Form API callback to validate the form
 */
function wsod_admin_form_validate($form, &$form_state) {
  $values = &$form_state['values'];
  // TODO: trim - values['personalized_settings_form_id']
  // if something then form_set_error('', t('Some error'));
} 

/**
 * Menu callback: confirm rebuilding of permissions.
 */
function wsod_menu_rebuild_confirm() {
  return confirm_form(array(), t('Are you sure you want to rebuild the menu tables on site content?'),
                  'admin/build/dtools', t('This action rebuilds all permissions on site content, and may be a lengthy process. This action cannot be undone.'), t('Rebuild menu'), t('Cancel'));
} 

/**
 * Handler for wipe confirmation
 */
function wsod_menu_rebuild_confirm_submit($form, &$form_state) {
  wsod_rebuild_menu_router_table(); // Rebuild menu_router, menu_links tables
  drupal_set_message(t('menu tables have been rebuilt.')); 
  $form_state['redirect'] = 'admin/build/dtools';
}
 
/**
 * Form button submit callback.
 */
function wsod_admin_form_submit($form, &$form_state) {
  $form_state['redirect'] = 'admin/build/dtools';
} 

