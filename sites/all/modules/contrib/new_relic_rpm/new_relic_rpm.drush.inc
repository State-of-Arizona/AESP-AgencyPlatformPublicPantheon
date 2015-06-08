<?php
/**
 * @file
 * New Relic RPM Drush integration.
 */

/**
 * Implements hook_drush_init().
 */
function new_relic_rpm_drush_init() {
  if (function_exists('module_exists') && module_exists('new_relic_rpm')) {

    // Make sure we have access to the needed functions.
    require_once dirname(__FILE__) . '/new_relic_rpm.module';

    if (!new_relic_rpm_extension_installed()) {
      return;
    }

    // Add custom paramter, telling the drush command executed.
    $command = drush_get_command();
    $drush_command = array_merge(array($command['command']), $command['arguments']);
    newrelic_add_custom_parameter('Drush command', implode(' ', $drush_command));

    // Set job state.
    new_relic_rpm_set_job_state(variable_get('new_relic_rpm_track_drush', 'norm'));
  }
}
