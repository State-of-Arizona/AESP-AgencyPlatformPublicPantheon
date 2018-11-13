<?php

function az_commercial_form_system_theme_settings_alter(&$form, &$form_state) {
  unset($form['footer_settings']);
  unset($form['#submit']);
  //Toggle between black and white logos in the footer
  $form['footer_settings']['black_footer_logo'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display a black state seal logo in the footer.'),
      '#default_value' => theme_get_setting('black_footer_logo'),
      '#tree' => FALSE,
      '#description' => t('Check here if you want to use a black logo instead of white.')
  );
  $form['#submit'][] = 'az_commercial_settings_form_submit';
  $themes = list_themes();
  $active_theme = $GLOBALS['theme_key'];
  $form_state['build_info']['files'][] = str_replace("/$active_theme.info", '', $themes[$active_theme]->filename) . '/theme-settings.php';

  return $form;
}

function az_commercial_settings_form_submit(&$form, $form_state) {
  $image_fid = $form_state['values']['main_background'];
  $image = file_load($image_fid);
  if (is_object($image)) {
    if ($image->status == 0) {
      $image->status = FILE_STATUS_PERMANENT;
      file_save($image);
      file_usage_add($image, 'az_gov', 'theme', 1);
    }
  }
}