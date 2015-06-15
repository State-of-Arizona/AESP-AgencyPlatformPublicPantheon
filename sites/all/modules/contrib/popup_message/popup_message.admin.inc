<?php

/**
 * @file
 * Settings.
 */

/**
 * Settings form.
 *
 * @return array
 *   Form array.
 */
function popup_message_settings() {
  $form = array();
  $form['popup_message_enable'] = array(
    '#type' => 'radios',
    '#title' => t('Enable Popup'),
    '#default_value' => variable_get('popup_message_enable', 1),
    '#options' => array(
      1 => t('Enabled'),
      0 => t('Disabled'),
    ),
  );
  $form['popup_message_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Popup message settings'),
    '#collapsed' => FALSE,
    '#collapsible' => TRUE,
  );
  $form['popup_message_fieldset']['popup_message_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Message title'),
    '#required' => TRUE,
    '#default_value' => variable_get('popup_message_title'),
  );
  $popup_message_body = variable_get('popup_message_body');
  $form['popup_message_fieldset']['popup_message_body'] = array(
    '#type' => 'text_format',
    '#base_type' => 'textarea',
    '#title' => t('Message body'),
    '#default_value' => $popup_message_body['value'],
    '#format' => isset($popup_message_body['format']) ? $popup_message_body['format'] : NULL,
  );
  $form['popup_message_fieldset']['popup_message_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Window width'),
    '#required' => TRUE,
    '#default_value' => variable_get('popup_message_width', 300),
  );
  $form['popup_message_fieldset']['popup_message_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Window height'),
    '#required' => TRUE,
    '#default_value' => variable_get('popup_message_height', 300),
  );
  $form['popup_message_fieldset']['popup_message_check_cookie'] = array(
    '#type' => 'radios',
    '#title' => t('Check cookie'),
    '#description' => t('If enabled message will be displayed only once per browser session'),
    '#default_value' => variable_get('popup_message_check_cookie', 1),
    '#options' => array(
      1 => t('Enabled'),
      0 => t('Disabled'),
    ),
  );
  $form['popup_message_fieldset']['popup_message_delay'] = array(
    '#type' => 'textfield',
    '#title' => t('Delay'),
    '#description' => t('Message will show after this number of seconds. Set to 0 to show instantly.'),
    '#default_value' => variable_get('popup_message_delay', 0),
  );

  // Styles.
  // Find styles in module directory.
  $directory = drupal_get_path('module', 'popup_message') . '/styles';
  $subdirectories = scandir($directory);
  $styles = array();
  foreach ($subdirectories as $subdir) {
    if (is_dir($directory . '/' . $subdir)) {
      if (file_exists($directory . '/' . $subdir . '/' . POPUP_MESSAGE_CSS_NAME)) {
        $path = $directory . '/' . $subdir . '/' . POPUP_MESSAGE_CSS_NAME;
        $styles[$path] = $path;
      }
    }
  }
  // Find styles in every themes.
  $themes = list_themes();
  foreach ($themes as $theme) {
    if ($theme->status) {
      $directory = drupal_get_path('theme', $theme->name) . '/' . POPUP_MESSAGE_THEME_STYLE_DIR;
      if (file_exists($directory)) {
        $subdirectories = scandir($directory);
        foreach ($subdirectories as $subdir) {
          if (is_dir($directory . '/' . $subdir)) {
            if (file_exists($directory . '/' . $subdir . '/' . POPUP_MESSAGE_CSS_NAME)) {
              $path = $directory . '/' . $subdir . '/' . POPUP_MESSAGE_CSS_NAME;
              $styles[$path] = $path;
            }
          }
        }
      }
    }
  }
  $form['popup_message_fieldset']['popup_message_style'] = array(
    '#type' => 'select',
    '#title' => t('Popup style'),
    '#default_value' => variable_get('popup_message_style', drupal_get_path('module', 'popup_message') . '/styles/' . POPUP_MESSAGE_CSS_NAME),
    '#options' => $styles,
    '#description' => t('To add custom styles create directory and file "[my_default_theme]/popup_message_styles/mystyle/popup.css" and set in this file custom CSS code.'),
  );
  $form['popup_message_fieldset']['visibility']['path'] = array(
    '#type' => 'fieldset',
    '#title' => t('Pages'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#group' => 'visibility',
    '#weight' => 0,
  );
  $options = array(
    POPUP_MESSAGE_VISIBILITY_NOTLISTED => t('All pages except those listed'),
    POPUP_MESSAGE_VISIBILITY_LISTED => t('Only the listed pages'),
  );
  $description = t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array(
    '%blog' => 'blog',
    '%blog-wildcard' => 'blog/*',
    '%front' => '<front>')
  );
  $access = user_access('use PHP for settings');
  $visibility = variable_get('popup_message_visibility', POPUP_MESSAGE_VISIBILITY_NOTLISTED);
  if (isset($visibility) && $visibility == POPUP_MESSAGE_VISIBILITY_PHP && !$access) {
    $form['popup_message_fieldset']['visibility']['path']['popup_message_visibility'] = array(
      '#type' => 'value',
      '#value' => POPUP_MESSAGE_VISIBILITY_PHP,
    );
    $form['popup_message_fieldset']['visibility']['path']['popup_message_visibility_pages'] = array(
      '#type' => 'value',
      '#value' => variable_get('popup_message_visibility_pages', ''),
    );
  }
  else {
    if (module_exists('php') && $access) {
      $options += array(POPUP_MESSAGE_VISIBILITY_PHP => t('Pages on which this PHP code returns <code>TRUE</code> (experts only)'));
      $title = t('Pages or PHP code');
      $description .= ' ' . t('If the PHP option is chosen, enter PHP code between %php. Note that executing incorrect PHP code can break your Drupal site.', array('%php' => '<?php ?>'));
    }
    else {
      $title = t('Pages');
    }

    $form['popup_message_fieldset']['visibility']['path']['popup_message_visibility'] = array(
      '#type' => 'radios',
      '#title' => t('Show block on specific pages'),
      '#options' => $options,
      '#default_value' => $visibility,
    );

    $form['popup_message_fieldset']['visibility']['path']['popup_message_visibility_pages'] = array(
      '#type' => 'textarea',
      '#default_value' => variable_get('popup_message_visibility_pages', ''),
      '#description' => $description,
      '#title' => '<span class="element-invisible">' . $title . '</span>',
    );
  }
  return system_settings_form($form);
}
