<?php
/*
 * Implements hook_form_install_configure_form_alter().
 *
 * Sets the site configure settings for simplicity.
 */
function agency_platform_distribution_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name and email address.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
  $form['site_information']['site_mail']['#default_value'] = 'admin@asetcms.gov';

  // Account information defaults
  $form['admin_account']['account']['name']['#default_value'] = 'admin-cms';
  $form['admin_account']['account']['mail']['#default_value'] = 'admin@asetcms.gov';

  // Date/time settings
  $form['server_settings']['site_default_country']['#default_value'] = 'US';
  $form['server_settings']['date_default_timezone']['#default_value'] = 'America/Phoenix';
  // Unset the timezone detect stuff
  unset($form['server_settings']['date_default_timezone']['#attributes']['class']);

  // disables updates and notifications
  $form['update_notifications']['update_status_module']['#default_value'] = array(0);
}

/*
 * Implements hook_install_tasks_alter()
 *
 * Skips the language selection screen
 */
function agency_platform_distribution_install_tasks_alter(&$tasks, $install_state){
  global $install_state;

  $tasks['install_select_locale']['display'] = FALSE;
  $tasks['install_select_locale']['run'] = INSTALL_TASK_SKIP;
  $install_state['parameters']['locale'] = 'en';

}