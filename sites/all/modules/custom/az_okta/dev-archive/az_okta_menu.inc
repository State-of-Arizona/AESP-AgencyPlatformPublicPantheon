 <?php

 /**
 * Implements hook_form().
 * Display the AZ OKTA config editing form.
 */
function _form_az_okta_1($form, &$form_state) {    
  //Assuming afterbuild functions for validation, if required.
  //BELOW FOR FORM STYLING
  // $form['#attached']['css'] = array(
  //   drupal_get_path('module', 'turner_geo') . '/css/geo_config.css'
  //   );
  // $form['#attached']['js'] = array(
  //   drupal_get_path('module', 'turner_geo') . '/js/geo_config.js' => array('type'=>'file','scope'=>'footer', 'weight'=>600)
  //   );  
  $form['okta'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configuration of AZ SSO/OKTA - need copy here'),
    '#prefix' => '<div id="okta-outer"><div id="okta-instruct">',
    '#suffix' => '</div></div>',
    '#tree' => TRUE,
    '#after_build' => array(),
  );
  $form['okta']['description'] = array(
    '#type' => 'item',
    '#title' => 'Description',
    '#markup' => '<div><h3>Enter description here</h3></div>',
  );
  
  //First set
  $form['okta']['0'] = array(
    '#type' => 'fieldset',
    '#title' => t('First set of felds - add a possible text area to test JSON as well.'),
    '#prefix' => '<div class="okta-box"><div class="okta-instruct">',
    '#suffix' => '</div></div>',
    '#description' => t('Description or instructions for ALL fields, if required.'),
    '#tree' => TRUE,
    '#after_build' => array(),
  );
  $form['okta']['0']['entity_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the Entity ID:'),
    '#description' => t('Do not use spaces.'),    
    '#default_value' => variable_get('entity_id', 'http://google.com/'),
  );
  $form['okta']['0']['environment'] = array(
    '#type' => 'select',
    '#options' => array(
      0 => t('Development'),
      1 => t('Test'),
      2 => t('Production'),
    ),
    '#title' => t('Description or Instructions for field.'),
    '#default_value' => variable_get('environment', 'Development'),
  );
  $form['okta']['0']['assertion_url'] = array(
    '#type' => 'textfield',
    '#size' => '80',
    '#title' => t('Verify the assertion URL:'),
    '#description' => t('Is the port necessary below witht https:// protocol included?'),
    '#default_value' => variable_get('assertion_url', 'https://' . $_SERVER['SERVER_NAME'] . ':443/simplesaml/module.php/saml/sp/saml2-acs.php/default-sp'),
  );
  $form['okta']['0']['xml_data'] = array(
    '#type' => 'textarea',
    '#title' => t('Description or Instructions for XML field.'),
    '#default_value' => variable_get('xml_data', 'default value'),
  );
  $form['okta']['0']['json_data'] = array(
    '#type' => 'textarea',
    '#title' => t('Description or Instructions for JSON field.'),
    '#default_value' => variable_get('json_data', 'default value'),
  );
  // Use the #managed_file FAPI element to upload an image file.
  //Change for XML file
  $form['okta']['0']['xml_upload'] = array(
    '#title' => t('XML Upload'),
    '#type' => 'managed_file',
    '#description' => t('TDescription and/or Instruction for this field.'),
    '#default_value' => variable_get('xml_upload_fid', ''),
    '#upload_location' => 'public://okta/xml_files/',
  );
  
  //Second set
  // $form['okta']['1'] = array(
  //   '#type' => 'fieldset',
  //   '#title' => t('For South America Redirection'),
  //   '#prefix' => '<div class="geo-box"><div class="geo-instruct">',
  //   '#suffix' => '</div></div>',
  //   '#description' => t('Do not duplicate IP ranges between regions, redirection will break.  If no values are entered for the IP ranges,
  //                       the user will not be redirected ( user will proceed to myturner.turner.com).'),
  //   '#tree' => TRUE,
  //   '#after_build' => array(),
  // );
  // $form['okta']['1']['url1'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t('Enter URL to which to redirect using the IP ranges below:'),
  //   '#default_value' => variable_get('url1', 'http://myturner.turner.com/'),
  // );
  // $form['okta']['1']['url1-start'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t('Starting IP Value'),
  //   '#default_value' => variable_get('url1s', ''),
  // );
  // $form['okta']['1']['url1-end'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t('Ending IP Value'),
  //   '#default_value' => variable_get('url1e', ''),
  // );
  
  //Third set
  // $form['geo']['2'] = array(
  //   '#type' => 'fieldset',
  //   '#title' => t('For International Redirection'),
  //   '#prefix' => '<div class="geo-box"><div class="geo-instruct">',
  //   '#suffix' => '</div></div>',
  //   '#description' => t('Do not duplicate IP ranges between regions, redirection will break.  If no values are entered for the IP ranges,
  //                       the user will not be redirected ( user will proceed to myturner.turner.com).'),
  //   '#tree' => TRUE,
  //   '#after_build' => array(),
  // );
  // $form['geo']['2']['url2'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t('Enter URL to which to redirect using the IP ranges below:'),
  //   '#default_value' => variable_get('url2', 'http://myturner.turner.com/'),
  // );
  // $form['geo']['2']['url2-start'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t('Starting IP Value'),
  //   '#default_value' => variable_get('url2s', ''),
  // );
  // $form['geo']['2']['url2-end'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t('Ending IP Value'),
  //   '#default_value' => variable_get('url2e', ''),
  // );
  // Adds a simple submit button that refreshes the form and clears its
  // contents. This is the default behavior for forms.
  //of course callback function is required
  $form['okta']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );
  //call any additional functions here
  drupal_set_message(t('This page is strictly for preparation/developer use-it is not yet functional.'), 'warning');
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
  //TODO: save this as array
  $entity_id = $form_state['values']['okta']['0']['entity_id'];
  $environment = $form_state['values']['okta']['0']['environment'];
  $assertion_url = $form_state['values']['okta']['0']['assertion_url'];
  $xml_data = $form_state['values']['okta']['1']['xml_data'];
  $json_data = $form_state['values']['okta']['1']['json_data'];
  $xml_upload = $form_state['values']['okta']['1']['xml_upload'];
  //TODO: save this as array
  variable_set('entity_id', $entity_id);
  variable_set('environment', $environment);
  variable_set('assertion_url', $assertion_url);
  variable_set('xml_data', $xml_data);
  variable_set('json_data', $json_data);
  variable_set('xml_upload', $xml_upload);
  //ordinarily we wouldn't call this, but this is so rarely updated, AND we want immediate updates.
  //drupal_flush_all_caches();
  drupal_set_message(t('Your configuration has been saved.  Please confirm the changes below.'));
  //NEW - write values ot file to share with simplasaml
  $text = "Anything";
  $var_str = var_export($text, true);
  $var = "<?php\n\n\$text = $var_str;\n\n?>";
  //Is there a config file?
  fopen("az_okta_config.php", "w");
  file_put_contents('az_okta_config.php', $var);
}