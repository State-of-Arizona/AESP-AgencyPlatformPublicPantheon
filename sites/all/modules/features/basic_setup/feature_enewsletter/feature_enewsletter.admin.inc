<?php


/**
 * @param $form
 * @param $form_state
 * @param bool $no_js_use
 * @return mixed
 *
 * Module Configuration page with ajax fields
 */
function feature_enewsletter_config($form, &$form_state, $no_js_use = FALSE) {
  drupal_add_css(drupal_get_path('module', 'feature_enewsletter') . '/enewsletter_config.css');
  $settings = variable_get('feature_enewsletter', array());
  if (isset($settings['lists'])) {
    $lists_keys = array_keys($settings['lists']);
  }

  $form['#tree'] = TRUE;
  $form['sid'] = array(
    '#type' => 'textfield',
    '#title' => t('Subscription ID'),
    '#size' => 35,
    '#default_value' => isset($settings['sid']) ? $settings['sid'] : '',
    '#required' => TRUE,
  );
  if (module_exists('chosen')) {
    $form['chosen'] = array(
      '#type' => 'checkbox',
      '#title' => t('Apply "Chosen" module to select lists'),
      '#default_value' => isset($settings['chosen']) ? $settings['chosen'] : 0,
    );
  }

  /**
   * Newsletter lists
   */
  $form['enews_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Enewsletter Pro Subscriptions'),
    '#prefix' => '<div id="list-wrapper">',
    '#suffix' => '</div>',
  );

  if (empty($form_state['num_enews'])) {
    if (isset($settings['lists'])) {
      $form_state['num_enews'] = sizeof($settings['lists']);
    }
    else {
      $form_state['num_enews'] = 1;
    }
  }

  for ($i = 0; $i < $form_state['num_enews']; $i++) {
    $form['enews_fieldset']['lists'][$i] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'enews-list',
        ),
      ),
    );
    $form['enews_fieldset']['lists'][$i]['id'] = array(
      '#type' => 'textfield',
      '#title' => t('Newsletter List ID'),
      '#size' => 5,
      '#default_value' => isset($settings['lists']) ? $lists_keys[$i] : '',
      '#required' => TRUE,
    );
    $form['enews_fieldset']['lists'][$i]['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Newsletter Name'),
      '#size' => 25,
      '#default_value' => isset($settings['lists']) ? $settings['lists'][$lists_keys[$i]]['name'] : '',
      '#required' => TRUE,
    );
    $form['enews_fieldset']['lists'][$i]['description'] = array(
      '#type' => 'textfield',
      '#title' => t('Newsletter Description'),
      '#size' => 25,
      '#default_value' => isset($settings['lists']) ? $settings['lists'][$lists_keys[$i]]['description'] : '',
    );
  }

  $form['enews_fieldset']['buttons'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('enews-buttons'),
    ),
  );
  $form['enews_fieldset']['buttons']['add_list'] = array(
    '#type' => 'submit',
    '#name' => 'add_list',
    '#value' => t('Add one more'),
    '#submit' => array('list_add'),
    '#ajax' => array(
      'callback' => 'list_add_callback',
      'wrapper' => 'list-wrapper',
    ),
  );

  if ($form_state['num_enews'] > 1) {
    $form['enews_fieldset']['buttons']['remove_list'] = array(
      '#type' => 'submit',
      '#name' => 'remove_list',
      '#value' => t('Remove the last one'),
      '#submit' => array('list_remove'),
      '#ajax' => array(
        'callback' => 'list_add_callback',
        'wrapper' => 'list-wrapper',
      ),
    );
  }


  /**
   * Demographics
   */
  $form['demographics_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Demographics'),
    '#prefix' => '<div id="demographics-wrapper">',
    '#suffix' => '</div>',
  );

  if (empty($form_state['num_demos'])) {
    if (isset($settings['demos'])) {
      $form_state['num_demos'] = sizeof($settings['demos']);
    }
    else {
      $form_state['num_demos'] = 1;
    }
  }

  for ($i = 1; $i <= $form_state['num_demos']; $i++) {
    $form['demographics_fieldset']['demos']['OptionalParameter' . $i] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'enews-list',
        ),
      ),
    );
    $form['demographics_fieldset']['demos']['OptionalParameter' . $i]['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Parameter ' . $i . ' Name'),
      '#size' => 25,
      '#default_value' => (isset($settings['demos']) && isset($settings['demos']['OptionalParameter' . $i])) ? $settings['demos']['OptionalParameter' . $i]['name'] : '',
    );
    $form['demographics_fieldset']['demos']['OptionalParameter' . $i]['values'] = array(
      '#type' => 'textfield',
      '#title' => t('Parameter ' . $i . ' Values'),
      '#size' => 25,
      '#default_value' => (isset($settings['demos']) && isset($settings['demos']['OptionalParameter' . $i])) ? $settings['demos']['OptionalParameter' . $i]['values'] : '',
      '#maxlength' => 10000,
    );
    $form['demographics_fieldset']['demos']['OptionalParameter' . $i]['required'] = array(
      '#type' => 'checkbox',
      '#title' => 'Required',
      '#default_value' => (isset($settings['demos']) && isset($settings['demos']['OptionalParameter' . $i])) ? $settings['demos']['OptionalParameter' . $i]['required'] : 0,
    );
    $form['demographics_fieldset']['demos']['OptionalParameter' . $i]['data_type'] = array(
      '#type' => 'select',
      '#title' => 'Data Type',
      '#options' => array(
        'Text Field',
        'Date Field',
        'Integer',
        'Real Number',
      ),
      '#default_value' => (isset($settings['demos']) && isset($settings['demos']['OptionalParameter' . $i])) ? $settings['demos']['OptionalParameter' . $i]['data_type'] : '',
    );
  }

  $form['demographics_fieldset']['buttons'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('enews-buttons'),
    ),
  );
  $form['demographics_fieldset']['buttons']['add_demo'] = array(
    '#type' => 'submit',
    '#name' => 'add_demo',
    '#value' => t('Add one more'),
    '#submit' => array('demographics_add'),
    '#ajax' => array(
      'callback' => 'demographics_add_callback',
      'wrapper' => 'demographics-wrapper',
    ),
  );

  if ($form_state['num_demos'] > 1) {
    $form['demographics_fieldset']['buttons']['remove_demo'] = array(
      '#type' => 'submit',
      '#name' => 'remove_demo',
      '#value' => t('Remove the last one'),
      '#submit' => array('demographics_remove'),
      '#ajax' => array(
        'callback' => 'demographics_add_callback',
        'wrapper' => 'demographics-wrapper',
      ),
    );
  }


  $form['spacer'] = array(
    '#markup' => '</br>',
    '#prefix' => '<div style="height:20px">',
    '#suffix' => '</div>',
  );


  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save',
  );

  $form['spacer2'] = array(
    '#markup' => '</br>',
    '#prefix' => '<div style="height:20px">',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * @param $form
 * @param $form_state
 *
 * Adds another newsletter fieldset
 */
function list_add($form, &$form_state) {
  $form_state['num_enews']++;
  $form_state['rebuild'] = TRUE;
}

/**
 * @param $form
 * @param $form_state
 * @return mixed
 */
function list_add_callback($form, $form_state) {
  return $form['enews_fieldset'];
}

/**
 * @param $form
 * @param $form_state
 *
 * Removes the last newsletter set
 */
function list_remove($form, &$form_state) {
  if ($form_state['num_enews'] > 1) {
    $form_state['num_enews']--;
  }
  $form_state['rebuild'] = TRUE;
}


/**
 * @param $form
 * @param $form_state
 *
 * Adds another demographic fieldset
 */
function demographics_add($form, &$form_state) {
  $form_state['num_demos']++;
  $form_state['rebuild'] = TRUE;

}

/**
 * @param $form
 * @param $form_state
 * @return mixed
 */
function demographics_add_callback($form, &$form_state) {
  return $form['demographics_fieldset'];
}

/**
 * @param $form
 * @param $form_state
 *
 * Removes the last demographic set
 */
function demographics_remove($form, &$form_state) {
  if ($form_state['num_demos'] > 1) {
    $form_state['num_demos']--;
  }
  $form_state['rebuild'] = TRUE;
}


/**
 * @param $form
 * @param $form_state
 * @param $form_id
 *
 * Save function for enewsletter settings
 */
function feature_enewsletter_config_submit(&$form, &$form_state) {
  $lists = array();
  foreach ($form_state['values']['enews_fieldset']['lists'] as $list) {
    $lists[$list['id']] = array(
      'name' => $list['name'],
      'description' => $list['description'],
    );
  }
  $settings = array(
    'sid' => $form_state['values']['sid'],
    'lists' => $lists,
    'demos' => $form_state['values']['demographics_fieldset']['demos'],
    'chosen' => isset($form_state['values']['chosen']) ? $form_state['values']['chosen'] : 0,
  );
  variable_set('feature_enewsletter', $settings);
  drupal_set_message(t('Configuration Settings Saved'));
}
