 <?php

 /**
 * Implements hook_form().
 * Display the AZ Anti-spam config editing form.
 */
function _form_az_antispam_settings($form, &$form_state) {
  //Assuming afterbuild functions for validation, if required.
  //BELOW FOR FORM STYLING
  $form['#attached']['css'] = array(
    drupal_get_path('module', 'feature_az_antispam') . '/css/antispam_config.css');
  $form['#attached']['js'] = array(
    drupal_get_path('module', 'feature_az_antispam') . '/js/antispam_config.js' => array('type'=>'file','scope'=>'footer', 'weight'=>600)
    );
  $form['antispam'] = array(
    '#type' => 'fieldset',
    '#title' => t('AZ Anti-spam'),
    // '#description' => t('Description here.'),
    '#prefix' => '<div id="antispam-outer"><div id="antispam-instruct">',
    '#suffix' => '</div></div>',
    '#tree' => TRUE,
    '#after_build' => array(),
  );
  $form['antispam']['description'] = array(
    '#type' => 'item',
    '#title' => t('Antispam Settings'),
  );


  //First set - Dev
  $form['antispam']['0'] = array(
    '#type' => 'fieldset',
    // '#title' => t('Configuration title'),
    // '#prefix' => '<div class="dev okta-box"><div class="okta-instruct">',
    // '#suffix' => '</div></div>',
    // '#description' => t('Description or instructions for ALL fields, if required.'),
    '#tree' => TRUE,
    '#after_build' => array(),
  );
  $form['antispam']['0']['foreign_webform_block'] = array(
    '#type' => 'checkbox',
    '#title' => t('Block foreign submissions on all webforms.'),
    '#description' => t('Enabling will block all foreign submissions on all webforms.'),
    '#default_value' => variable_get('feature_az_antispam_foreign_webform_block', 1),
  );
  $form['antispam']['0']['access_denied'] = array(
    '#type' => 'textfield',
    '#prefix' => '<div class="access-denied">',
    '#suffix' => '</div>',
    '#title' => t('Enter the internal URL/Path for the access denied page:<br><div>@baseurl/</div>', array('@baseurl' => $GLOBALS['base_url'])),
    //'#markup' => t('<div>@baseurl</div>', array('@baseurl' => $GLOBALS['base_url'])),
    '#description' => t('Do not include the base URL.  Enter only the internal path or alias, for example, <i>content/access-denied</i>'),
    '#default_value' => variable_get('access_denied', ''),
  );
  $form['antispam']['0']['path_get_ip'][] = array(
    '#type' => 'hidden',
    '#prefix' => '<div class="path-get-ip">',
    '#suffix' => '</div>',
    '#title' => t('Enter a path to include in the foreign IP check'),
    //'#markup' => t('<div>@baseurl</div>', array('@baseurl' => $GLOBALS['base_url'])),
    '#description' => t('Do not include the base URL.  Enter only the internal path or alias.'),
    '#default_value' => variable_get('path_get_ip', ''),
  );
  $form['antispam']['0']['multi_paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Enter the internal URL/Paths to block against foreign visitors:<br><div>@baseurl/</div>', array('@baseurl' => $GLOBALS['base_url'])),
    '#description' => t('<strong>Enter a comma separated list of paths to check against foreign IPs.</strong>'),
    '#default_value' => variable_get('multi_paths', 'contact, contact-us'),
  );
  $form['antispam']['1'] = array(
    '#type' => 'fieldset',
    '#title' => t('Notification and Watchdog Configuration'),
    '#tree' => TRUE,
    '#after_build' => array(),
  );
  $form['antispam']['1']['save_watchdog'] = array(
    '#type' => 'checkbox',
    '#title' => t('Create watchdog entries for foreign IPs detected.'),
    //'#description' => t('Do not use spaces.  Only use lower case and underscores.  For example, "az_doa_okta".'),
    '#default_value' => variable_get('save_watchdog', 1),
  );
  $form['antispam']['1']['save_all_watchdog'] = array(
    '#type' => 'checkbox',
    '#title' => t('Create watchdog entries for <strong>all</strong> traffic hitting designated paths.'),
    //'#description' => t('Do not use spaces.  Only use lower case and underscores.  For example, "az_doa_okta".'),
    '#default_value' => variable_get('save_all_watchdog', 0),
  );
  $form['antispam']['1']['notify_admin'] = array(
    '#type' => 'checkbox',
    '#title' => t('Notify the designated email recipient when foreign IP traffic attempts to access configured paths.'),
    //'#description' => t('Do not use spaces.  Only use lower case and underscores.  For example, "az_doa_okta".'),
    '#default_value' => variable_get('notify_admin', 0),
  );
  $form['antispam']['1']['admin_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the email to notify when foreign IPs are detected:'),
    //'#markup' => t('<div>@baseurl</div>', array('@baseurl' => $GLOBALS['base_url'])),
    // '#description' => t('Do not include the base URL.  Enter only the internal path or alias.'),
    '#default_value' => variable_get('admin_email', ''),
  );

  $form['antispam']['cleanup'] = array(
    '#type' => 'checkbox',
    '#title' => t('Clean up foreign submissions.'),
    '#description' => t(variable_get('feature_az_antispam_cleanup_message', '')),
    '#default_value' => variable_get('feature_az_antispam_cleanup', 0),
  );

  $form['antispam']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save Configuration',
  );

  //call any additional functions here
  if (isset($_SESSION['messages']['warning'])) {
    $_SESSION['messages']['warning'] = array_unique($_SESSION['messages']['warning']);
  }
  return $form;
}

 /**
 * submit handler/function
 *
 * Create a simple array to store these values
 */
function _form_az_antispam_settings_submit($form, &$form_state) {
  drupal_set_message(t('The configuration has been saved.'), 'status');

  //Set values
  $foreign_webform_block = $form_state['values']['antispam']['0']['foreign_webform_block'];
  $access_denied = $form_state['values']['antispam']['0']['access_denied'];
  $path_get_ip = $form_state['values']['antispam']['0']['path_get_ip'];//test this as created as array
  $save_watchdog = $form_state['values']['antispam']['1']['save_watchdog'];
  $save_all_watchdog = $form_state['values']['antispam']['1']['save_all_watchdog'];
  $notify_admin = $form_state['values']['antispam']['1']['notify_admin'];
  $admin_email = $form_state['values']['antispam']['1']['admin_email'];
  $multi_paths = $form_state['values']['antispam']['0']['multi_paths'];
  $cleanup = $form_state['values']['antispam']['cleanup'];

  //TODO:Check for notification setting.  If set, then you must have an email
  if ($notify_admin == 1 && $admin_email == "") {
    drupal_set_message(t('You must enter an email address if notifications are enabled'), 'error', FALSE);
  } else {
    //Save values
    variable_set('feature_az_antispam_foreign_webform_block', $foreign_webform_block);
    variable_set('access_denied', $access_denied);
    variable_set('path_get_ip', $path_get_ip);//test this as created as array
    variable_set('save_watchdog', $save_watchdog);
    variable_set('save_all_watchdog', $save_all_watchdog);
    variable_set('notify_admin', $notify_admin);
    variable_set('admin_email', $admin_email);
    variable_set('multi_paths', $multi_paths);
    variable_set('feature_az_antispam_cleanup', $cleanup);
  }
}



