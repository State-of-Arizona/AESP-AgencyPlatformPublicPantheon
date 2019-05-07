 <?php

 /**
 * Implements hook_form().
 * Display the AZ OKTA config editing form.
 */
function _form_az_okta_1($form, &$form_state) {    
  //Assuming afterbuild functions for validation, if required.
  //BELOW FOR FORM STYLING
  $form['#attached']['css'] = array(
    drupal_get_path('module', 'az_okta') . '/css/okta_config.css'
    );
  // $form['#attached']['js'] = array(
  //   drupal_get_path('module', 'az_okta') . '/js/okta_config.js' => array('type'=>'file','scope'=>'footer', 'weight'=>600)
  //   );  
  $form['okta'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configuration of AZ SSO/Okta'),
    '#description' => t('<span class="alert">WARNING:</span> Entering incorrect values in this configuration can lead to the site breaking or potential security issues. Please follow the following process document of how to set up your website with Okta: <a href="https://docs.google.com/document/d/17hXbfBL501I7lSDVws01bf55TNEGLJhG92ddZyugysA/edit">https://docs.google.com/document/d/17hXbfBL501I7lSDVws01bf55TNEGLJhG92ddZyugysA/edit</a>'),
    '#prefix' => '<div id="okta-outer"><div id="okta-instruct">',
    '#suffix' => '</div></div>',
    '#tree' => TRUE,
    '#after_build' => array(),
  );
  $form['okta']['description'] = array(
    '#type' => 'item',
    '#title' => 'Assertion URLs',
    '#markup' => t('Assertion URL Information:'),
    '#markup' => t('The assertion URL for this site is given as @baseurl:443/simplesaml/module.php/saml/sp/saml2-acs.php/default-sp', array('@baseurl' => $GLOBALS['base_url'])),
  );
  
  //First set - Dev
  $form['okta']['0'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configuration for DEVELOPMENT environment'),
    '#prefix' => '<div class="dev okta-box"><div class="okta-instruct">',
    '#suffix' => '</div></div>',
    //'#description' => t('Description or instructions for ALL fields, if required.'),
    '#tree' => TRUE,
    '#after_build' => array(),
  );
  $form['okta']['0']['save_dev_config'] = array(
    '#type' => 'checkbox',
    '#title' => t('Save this environment\'s configuration'),
    //'#description' => t('Do not use spaces.  Only use lower case and underscores.  For example, "az_doa_okta".'),    
    '#default_value' => variable_get('save_dev_config', 0),
  );
  $form['okta']['0']['entity_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the Entity ID:'),
    '#description' => t('Do not use spaces.  Only use lower case and underscores.  For example, "az_doa_okta".'),    
    '#default_value' => variable_get('entity_id', ''),
  );
  $form['okta']['0']['environment'] = array(
    '#type' => 'hidden',
    // '#options' => array(
    //   'development' => t('Development'),
    //   'test' => t('Test'),
    //   'production' => t('Production'),
    // ),
    '#title' => t('Description or Instructions for field.'),
    '#value' => variable_get('environment', 'Development'),
  );
  $form['okta']['0']['assertion_url'] = array(
    '#type' => 'hidden',
    '#size' => '80',
    '#title' => t('Verify the assertion URL:'),
    '#description' => t('The assertion URL for this site is given as @baseurl:443/simplesaml/module.php/saml/sp/saml2-acs.php/default-sp', array('@baseurl' => $GLOBALS['base_url'])),
    '#default_value' => variable_get('assertion_url', $GLOBALS['base_url'] . ':443/simplesaml/module.php/saml/sp/saml2-acs.php/default-sp'),
  );
  $form['okta']['0']['xml_data'] = array(
    '#type' => 'textarea',
    '#title' => t('Enter your XML:'),
    '#description' => t('Provide the XML provided by SI and Okta\'s Application. If you do not have this, please reach out to <a href="http://servicedesk@azdoa.gov">http://servicedesk@azdoa.gov</a> and create a ticket to get the XML for your site\'s XML'),
    '#default_value' => variable_get('xml_data', ''),
  );
  // $form['okta']['0']['json_data'] = array(
  //   '#type' => 'textarea',
  //   '#title' => t('Description or Instructions for JSON field.'),
  //   '#default_value' => variable_get('json_data', 'default value'),
  // );

  //TEST SET
  $form['okta']['1'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configuration for TEST environment'),
    '#prefix' => '<div class="test okta-box"><div class="okta-instruct">',
    '#suffix' => '</div></div>',
    //'#description' => t('Description or instructions for ALL fields, if required.'),
    '#tree' => TRUE,
    '#after_build' => array(),
  );
  $form['okta']['1']['save_test_config'] = array(
    '#type' => 'checkbox',
    '#title' => t('Save this environment\'s configuration'),
    //'#description' => t('Do not use spaces.  Only use lower case and underscores.  For example, "az_doa_okta".'),    
    '#default_value' => variable_get('save_test_config', 0),
  );
  $form['okta']['1']['test_entity_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the Entity ID:'),
    '#description' => t('Do not use spaces.  Only use lower case and underscores.  For example, "az_doa_okta".'),    
    '#default_value' => variable_get('test_entity_id', ''),
  );
  $form['okta']['1']['test_environment'] = array(
    '#type' => 'hidden',
    // '#options' => array(
    //   'development' => t('Development'),
    //   'test' => t('Test'),
    //   'production' => t('Production'),
    // ),
    '#title' => t('Description or Instructions for field.'),
    '#value' => variable_get('test_environment', 'Test'),
  );
  $form['okta']['1']['test_assertion_url'] = array(
    '#type' => 'hidden',
    '#size' => '80',
    '#title' => t('Verify the assertion URL:'),
    '#description' => t('The assertion URL for this site is given as @baseurl:443/simplesaml/module.php/saml/sp/saml2-acs.php/default-sp', array('@baseurl' => $GLOBALS['base_url'])),
    '#default_value' => variable_get('test_assertion_url', $GLOBALS['base_url'] . ':443/simplesaml/module.php/saml/sp/saml2-acs.php/default-sp'),
  );
  $form['okta']['1']['test_xml_data'] = array(
    '#type' => 'textarea',
    '#title' => t('Enter your XML:'),
    '#description' => t('Provide the XML provided by SI and Okta\'s Application. If you do not have this, please reach out to <a href="http://servicedesk@azdoa.gov">http://servicedesk@azdoa.gov</a> and create a ticket to get the XML for your site\'s XML'),
    '#default_value' => variable_get('test_xml_data', ''),
  );

  //LIVE SET
  $form['okta']['2'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configuration for LIVE environment'),
    '#prefix' => '<div class="live okta-box"><div class="okta-instruct">',
    '#suffix' => '</div></div>',
    //'#description' => t('Description or instructions for ALL fields, if required.'),
    '#tree' => TRUE,
    '#after_build' => array(),
  );
  $form['okta']['2']['save_live_config'] = array(
    '#type' => 'checkbox',
    '#title' => t('Save this environment\'s configuration'),
    //'#description' => t('Do not use spaces.  Only use lower case and underscores.  For example, "az_doa_okta".'),    
    '#default_value' => variable_get('save_live_config', 0),
  );
  $form['okta']['2']['live_entity_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the Entity ID:'),
    '#description' => t('Do not use spaces.  Only use lower case and underscores.  For example, "az_doa_okta".'),    
    '#default_value' => variable_get('live_entity_id', ''),
  );
  $form['okta']['2']['live_environment'] = array(
    '#type' => 'hidden',
    // '#options' => array(
    //   'development' => t('Development'),
    //   'test' => t('Test'),
    //   'production' => t('Production'),
    // ),
    '#title' => t('Description or Instructions for field.'),
    '#value' => variable_get('live_environment', 'Production'),
  );
  $form['okta']['2']['live_assertion_url'] = array(
    '#type' => 'hidden',
    '#size' => '80',
    '#title' => t('Verify the assertion URL:'),
    '#description' => t('The assertion URL for this site is given as @baseurl:443/simplesaml/module.php/saml/sp/saml2-acs.php/default-sp', array('@baseurl' => $GLOBALS['base_url'])),
    '#default_value' => variable_get('live_assertion_url', $GLOBALS['base_url'] . ':443/simplesaml/module.php/saml/sp/saml2-acs.php/default-sp'),
  );
  $form['okta']['2']['live_xml_data'] = array(
    '#type' => 'textarea',
    '#title' => t('Enter your XML:'),
    '#description' => t('Provide the XML provided by SI and Okta\'s Application. If you do not have this, please reach out to <a href="http://servicedesk@azdoa.gov">http://servicedesk@azdoa.gov</a> and create a ticket to get the XML for your site\'s XML'),
    '#default_value' => variable_get('live_xml_data', ''),
  );
  // Use the #managed_file FAPI element to upload an image file.
  //Change for XML file
  //$form['okta']['0']['xml_upload'] = array(
  //   '#title' => t('XML Upload'),
  //   '#type' => 'managed_file',
  //   '#description' => t('TDescription and/or Instruction for this field.'),
  //   //note the file ID
  //   '#default_value' => variable_get('xml_upload_fid', ''),
  //   '#upload_location' => 'public://okta/xml_files/',
  //   //Check for extensions
  //   '#upload_validators' => array(
  //     'file_validate_extensions' => array('xml'),
  //   ),
  // );

  // Adds a simple submit button that refreshes the form and clears its
  // contents. This is the default behavior for forms.
  $form['okta']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save Configuration',
  );
  //call any additional functions here
  //drupal_set_message(t('This page is strictly for preparation/developer use-it is not yet functional.'), 'warning');
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
function _form_az_okta_1_submit($form, &$form_state) {
  //Dev Values
  $save_dev_config = $form_state['values']['okta']['0']['save_dev_config'];
  $entity_id = $form_state['values']['okta']['0']['entity_id'];
  $environment = $form_state['values']['okta']['0']['environment'];
  $assertion_url = $form_state['values']['okta']['0']['assertion_url'];
  $xml_data = $form_state['values']['okta']['0']['xml_data'];

  //Test Values
  $save_test_config = $form_state['values']['okta']['1']['save_test_config'];
  $test_entity_id = $form_state['values']['okta']['1']['test_entity_id'];
  $test_environment = $form_state['values']['okta']['1']['test_environment'];
  $test_assertion_url = $form_state['values']['okta']['1']['test_assertion_url'];
  $test_xml_data = $form_state['values']['okta']['1']['test_xml_data'];

  //Live Values
  $save_live_config = $form_state['values']['okta']['2']['save_live_config'];
  $live_entity_id = $form_state['values']['okta']['2']['live_entity_id'];
  $live_environment = $form_state['values']['okta']['2']['live_environment'];
  $live_assertion_url = $form_state['values']['okta']['2']['live_assertion_url'];
  $live_xml_data = $form_state['values']['okta']['2']['live_xml_data'];

  //Dev Values
  variable_set('save_dev_config', $save_dev_config);
  if ($save_dev_config == 1 && ($entity_id != '' && $xml_data != '')) {
  variable_set('entity_id', $entity_id);
  variable_set('environment', $environment);
  variable_set('assertion_url', $assertion_url);
  variable_set('xml_data', $xml_data);
  drupal_set_message(t('Your <strong>Development</strong> configuration has been saved.  Configuration files have been created.  Please confirm the changes below.'), 'status');
} else {
  drupal_set_message(t('<strong>You must enter values in all fields to save the Development configuration.</strong>'), 'warning');
}

  //Test Values
  variable_set('save_test_config', $save_test_config);
  if ($save_test_config == 1 && ($test_entity_id != '' && $test_xml_data != '')) {
  variable_set('test_entity_id', $test_entity_id);
  variable_set('test_environment', $test_environment);
  variable_set('test_assertion_url', $test_assertion_url);
  variable_set('test_xml_data', $test_xml_data);
  drupal_set_message(t('Your <strong>Test</strong> configuration has been saved.  Configuration files have been created.  Please confirm the changes below.'), 'status');
} else {
  drupal_set_message(t('<strong>YYou must enter values in all fields to save the Test configuration.</strong>'), 'warning');
}

  //Live Values
  variable_set('save_live_config', $save_live_config);
  if ($save_live_config == 1 && ($live_entity_id != '' && $live_xml_data != '')) {
  variable_set('live_entity_id', $live_entity_id);
  variable_set('live_environment', $live_environment);
  variable_set('live_assertion_url', $live_assertion_url);
  variable_set('live_xml_data', $live_xml_data);
  drupal_set_message(t('Your <strong>Live</strong> configuration has been saved.  Configuration files have been created.  Please confirm the changes below.'), 'status');
} else {
  drupal_set_message(t('<strong>You must enter values in all fields to save the Live configuration.</strong>'), 'warning');
}

  //XML certifcate wrapping tags
  $start = '<ds:X509Certificate>';
  $end = '</ds:X509Certificate>';

  //DEV INFO
  if ($save_dev_config == 1 && ($entity_id != '' && $xml_data != '')) {
  $az_okta_array = array();
  $az_okta_array['entity_id'] = $entity_id;
  $az_okta_array['environment'] = $environment;
  //$az_okta_array['assertion_url'] = $assertion_url;
  $az_okta_array['xml_data'] = $xml_data;
  //Get the certifcate value
  $az_okta_array['certifcate'] = _az_okta_get_string_between ($xml_data, $start, $end);
  $az_okta_xml_data = _az_okta_parse_xml ();
  $dev_var_str = var_export($az_okta_array, true);
  $dev_var_xml = var_export($az_okta_xml_data, true);
  $dev_var = "<?php\n\n\$az_okta_array = $dev_var_str;\n\n\$az_okta_xml = $dev_var_xml" . ";\n\n";
  //Is there a config file?
  fopen("private://az_okta_config.php", "w");
  file_put_contents('private://az_okta_config.php', $dev_var);
}

  //Test INFO
  if ($save_test_config == 1 && ($test_entity_id != '' && $test_xml_data != '')) {
  $test_az_okta_array = array();
  $test_az_okta_array['entity_id'] = $test_entity_id;
  $test_az_okta_array['environment'] = $test_environment;
  //$test_az_okta_array['assertion_url'] = $test_assertion_url;
  $test_az_okta_array['xml_data'] = $test_xml_data;
  //Get the certifcate value
  $test_az_okta_array['certifcate'] = _az_okta_get_string_between ($test_xml_data, $start, $end);
  $test_az_okta_xml_data = _az_okta_parse_xml_2 ('test');
  $test_var_str = var_export($test_az_okta_array, true);
  $test_var_xml = var_export($test_az_okta_xml_data, true);
  $test_var = "<?php\n\n\$test_az_okta_array = $test_var_str;\n\n\$test_az_okta_xml = $test_var_xml" . ";\n\n";
  //Is there a config file?
  fopen("private://test_az_okta_config.php", "w");
  file_put_contents('private://test_az_okta_config.php', $test_var);
}

  //Live INFO
if ($save_live_config == 1 && ($live_entity_id != '' && $live_xml_data != '')) {
  $live_az_okta_array = array();
  $live_az_okta_array['entity_id'] = $live_entity_id;
  $live_az_okta_array['environment'] = $live_environment;
  //$live_az_okta_array['assertion_url'] = $live_assertion_url;
  $live_az_okta_array['xml_data'] = $live_xml_data;
  //Get the certifcate value
  $live_az_okta_array['certifcate'] = _az_okta_get_string_between ($live_xml_data, $start, $end);
  $live_az_okta_xml_data = _az_okta_parse_xml_2 ('live');
  $live_var_str = var_export($live_az_okta_array, true);
  $live_var_xml = var_export($live_az_okta_xml_data, true);
  $live_var = "<?php\n\n\$live_az_okta_array = $live_var_str;\n\n\$live_az_okta_xml = $live_var_xml" . ";\n\n";
  //Is there a config file?
  fopen("private://live_az_okta_config.php", "w");
  file_put_contents('private://live_az_okta_config.php', $live_var);
}

  //drupal_set_message(t('Your configuration has been saved.  Please confirm the changes below.'), 'status');
}