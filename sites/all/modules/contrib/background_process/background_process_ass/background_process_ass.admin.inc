<?php
/**
 * @file
 */

/**
 * FAPI definition for settings page.
 */
function background_process_ass_settings_form() {
  $form = array();
  $form['background_process_ass_max_age'] = array(
    '#type' => 'textfield',
    '#title' => t('Max age'),
    '#description' => t('Time in seconds to wait before considering a process dead.'),
    '#default_value' => variable_get('background_process_ass_max_age', BACKGROUND_PROCESS_ASS_MAX_AGE),
  );
  return system_settings_form($form);
}

