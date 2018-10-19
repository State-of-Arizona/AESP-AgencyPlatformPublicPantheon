<?php


function az_gov_form_system_theme_settings_alter(&$form, &$form_state) {
  //if the user is not an administrator, moves two bootstrap settings and adds a css file to hide certain settings.
  global $user;
  if (!in_array('administrator', $user->roles)) {
    $form['javascript']['#group'] = '';
    $form['advanced']['#group'] = '';
    drupal_add_css(drupal_get_path('theme', 'az_gov') . '/css/non-admin-theme.css');
  }
  drupal_add_css('#edit-color .form-item {height:auto !important;}', 'inline');


  //Custom Background Image
  $form['background'] = array(
    '#type' => 'fieldset',
    '#group' => 'global',
    '#title' => t('Custom Background'),
    '#description' => t('Uplaod the file you would like to use as your background file instead of the default background.'),
  );
  $form['background']['main_background'] = array(
    '#type' => 'managed_file',
    '#title' => t('Custom background'),
    '#default_value' => theme_get_setting('main_background'),
    '#upload_location' => 'public://theme-settings',
    '#upload_validators' => array(
      'file_validate_extensions' => array('gif png jpg jpeg'),
    )
  );

  //Footer Contact Information
  $form['footer_settings'] = array(
    '#type' => 'fieldset',
    '#title' => 'Footer Settings',
    '#group' => 'global',
  );
  //Toggle display of the branding block in the footer
  $form['footer_settings']['display_footer_branding'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display the branding block in the footer'),
    '#default_value' => theme_get_setting('display_footer_branding'),
    '#tree' => FALSE,
    '#description' => t('Check here if you want to display the branding  block in the footer.')
  );


  //Capture the information for the Contact Us section in the footer
  $form['footer_settings']['display_footer_contact'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display the Contact Us block in the footer'),
    '#default_value' => theme_get_setting('display_footer_contact'),
    '#tree' => FALSE,
    '#description' => t('Check here if you want to display the Contact Us block in the footer.')
  );
  $form['footer_settings']['postcard'] = array(
    '#type' => 'container',
    '#states' => array(
      // Hide the settings when not displaying the contact us block.
      'invisible' => array(
        'input[name="display_footer_contact"]' => array('checked' => FALSE),
      ),
    ),
  );
  $form['footer_settings']['postcard']['footer_title'] = array(
    '#type' => 'textfield',
    '#size' => 25,
    '#title' => t('Title'),
    '#description' => t('Title for the Contact Us block.'),
    '#default_value' => theme_get_setting('footer_title'),
  );
  $form['footer_settings']['postcard']['footer_title_link'] = array(
    '#type' => 'textfield',
    '#size' => 25,
    '#title' => t('Title Link'),
    '#description' => t('Link for the title in the Contact Us block. (Recommend linking to the contact form.)'),
    '#default_value' => theme_get_setting('footer_title_link'),
  );
  $form['footer_settings']['postcard']['footer_agency_title'] = array(
    '#type' => 'textfield',
    '#size' => 25,
    '#title' => t('Agency Title'),
    '#description' => t('Agency title for the Contact Us block.'),
    '#default_value' => theme_get_setting('footer_agency_title'),
  );
  $form['footer_settings']['postcard']['footer_address_1'] = array(
    '#type' => 'textfield',
    '#size' => 25,
    '#title' => t('Address Line 1'),
    '#description' => t('Address line 1 for the Contact Us block.'),
    '#default_value' => theme_get_setting('footer_address_1'),
  );
  $form['footer_settings']['postcard']['footer_address_2'] = array(
    '#type' => 'textfield',
    '#size' => 25,
    '#title' => t('Address Line 2'),
    '#description' => t('Address line 2 for the Contact Us block.'),
    '#default_value' => theme_get_setting('footer_address_2'),
  );
  $form['footer_settings']['postcard']['footer_phone'] = array(
    '#type' => 'textfield',
    '#size' => 25,
    '#title' => t('Phone Number'),
    '#description' => t('Phone number for the Contact Us block.'),
    '#default_value' => theme_get_setting('footer_phone'),
  );
  $form['footer_settings']['postcard']['footer_fax'] = array(
    '#type' => 'textfield',
    '#size' => 25,
    '#title' => t('Fax Number'),
    '#description' => t('Fax number for the Contact Us block.'),
    '#default_value' => theme_get_setting('footer_fax'),
  );
  $form['footer_settings']['postcard']['footer_map_link'] = array(
    '#type' => 'textfield',
    '#size' => 25,
    '#title' => t('Map Link'),
    '#description' => t('Link for the map in the Contact Us block.'),
    '#default_value' => theme_get_setting('footer_map_link'),
  );
  $form['footer_settings']['postcard']['footer_map_image'] = array(
    '#type' => 'managed_file',
    '#title' => t('Upload map image'),
    '#description' => t("Use this field to upload your map image. (The image will be resized to 150 x 150)"),
    '#default_value' => theme_get_setting('footer_map_image'),
    '#upload_location' => 'public://theme-settings',
    '#upload_validators' => array(
      'file_validate_extensions' => array('gif png jpg jpeg'),
      'file_validate_image_resolution' => array('150x150'),
    )
  );
  //End Contact Us


  unset($form['#submit']);
  $form['#submit'][] = 'az_gov_settings_form_submit';
  $themes = list_themes();
  $active_theme = $GLOBALS['theme_key'];
  $form_state['build_info']['files'][] = str_replace("/$active_theme.info", '', $themes[$active_theme]->filename) . '/theme-settings.php';


  return $form;
}

function az_gov_settings_form_submit(&$form, $form_state) {
  $image_fid = $form_state['values']['main_background'];
  $image = file_load($image_fid);
  if (is_object($image)) {
    if ($image->status == 0) {
      $image->status = FILE_STATUS_PERMANENT;
      file_save($image);
      file_usage_add($image, 'az_gov', 'theme', 1);
    }
  }

  $image_fid = $form_state['values']['footer_map_image'];
  $image = file_load($image_fid);
  if (is_object($image)) {
    if ($image->status == 0) {
      $image->status = FILE_STATUS_PERMANENT;
      file_save($image);
      file_usage_add($image, 'az_gov', 'theme', 1);
    }
  }
}