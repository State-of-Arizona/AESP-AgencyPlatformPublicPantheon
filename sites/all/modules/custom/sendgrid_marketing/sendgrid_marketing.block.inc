<?php

/**
 * @file
 * Sendgrid Marketing blocks.
 */

/**
 * Implements hook_block_info().
 */
function _sendgrid_marketing_block_info() {
  $blocks = array();
  $deltas = variable_get('sendgrid_marketing_ids', array());
  foreach ($deltas as $delta) {
    $blocks[$delta]['info'] = t('Sendgrid Newsletter: Block !delta', array('!delta' => $delta));
    $blocks[$delta]['cache'] = DRUPAL_NO_CACHE;
  }
  return $blocks;
}

/**
 * Implements hook_block_configure().
 */
function _sendgrid_marketing_block_configure($delta = '') {
  if (!$options = _sendgrid_marketing_fetch_lists()) {
    drupal_set_message(t('Before creating Sendgrid blocks, you must enter an API key.'), 'error');
    drupal_goto('admin/config/services/sendgrid_marketing');
  }
  $fields = _sendgrid_marketing_fetch_fields();
  // Create a pseudo form state.
  $form['sendgrid_marketing_newsletter'] = array(
    '#type' => 'checkboxes',
    '#options' => $options,
    '#title' => t('Sendgrid Newsletters'),
    '#description' => t('Please check all newsletters available for user selection within this block.'),
    '#default_value' => array_keys(variable_get("sendgrid_marketing_{$delta}_contact_lists", array())),
    '#required' => TRUE,
  );
  $form['sendgrid_marketing_fields'] = array(
    '#type' => 'checkboxes',
    '#options' => $fields,
    '#title' => t('Custom Fields'),
    '#description' => t('Please check all custom fields available for user selection within this block.'),
    '#default_value' => array_keys(variable_get("sendgrid_marketing_{$delta}_custom_fields", array())),
  );
  $form['sendgrid_marketing_available_agencies'] = array(
    '#type' => 'textarea',
    '#title' => t('Available Agencies'),
    '#description' => t('Specify available agencies. Enter one agency per line.'),
    '#default_value' => variable_get("sendgrid_marketing_{$delta}_available_agencies", ''),
  );
  return $form;
}

/**
 * Implements hook_block_save().
 */
function _sendgrid_marketing_block_save($delta = '', $edit = array()) {
  if (!empty($delta)) {
    $defaults = _sendgrid_marketing_fetch_lists();
    $contact_lists = array();
    foreach ($edit['sendgrid_marketing_newsletter'] as $newsletter) {
      if (in_array($newsletter, array_keys($defaults))) {
        $contact_lists[$newsletter] = $defaults[$newsletter];
      }
    }
    variable_set("sendgrid_marketing_{$delta}_contact_lists", $contact_lists);
    $default_fields = _sendgrid_marketing_fetch_fields();
    $custom_fields = array();
    foreach ($edit['sendgrid_marketing_fields'] as $field) {
      if (in_array($field, array_keys($default_fields))) {
        $custom_fields[$field] = $default_fields[$field];
      }
    }
    variable_set("sendgrid_marketing_{$delta}_custom_fields", $custom_fields);
    $available_fields = $edit['sendgrid_marketing_available_agencies'];
    variable_set("sendgrid_marketing_{$delta}_available_agencies", $available_fields);
  }
}

/**
 * Menu callback: display the menu block addition form.
 *
 * @see menu_block_add_block_form_submit()
 */
function sendgrid_marketing_add_block_form($form, &$form_state) {
  module_load_include('inc', 'block', 'block.admin');
  $form = block_admin_configure($form, $form_state, 'sendgrid_marketing', NULL);

  // Other modules should be able to use hook_form_block_add_block_form_alter()
  // to modify this form, so add a base form ID.
  $form_state['build_info']['base_form_id'] = 'block_add_block_form';

  // Prevent block_add_block_form_validate/submit() from being automatically
  // added because of the base form ID by providing these handlers manually.
  $form['#validate'] = array();
  $form['#submit'] = array('sendgrid_marketing_add_block_form_submit');

  return $form;
}

/**
 * Save the new menu block.
 */
function sendgrid_marketing_add_block_form_submit($form, &$form_state) {
  // Determine the delta of the new block.
  $block_ids = variable_get('sendgrid_marketing_ids', array());
  $delta = empty($block_ids) ? 1 : max($block_ids) + 1;
  $form_state['values']['delta'] = $delta;

  // Save the new array of blocks IDs.
  $block_ids[] = $delta;
  variable_set('sendgrid_marketing_ids', $block_ids);

  // Save the block configuration.
  sendgrid_marketing_block_save($delta, $form_state['values']);

  $available_fields = $form_state['values']['sendgrid_marketing_available_agencies'];
  variable_set("sendgrid_marketing_{$delta}_available_agencies", $available_fields);

  // Run the normal new block submission (borrowed from block_add_block_form_submit).
  $my_array = array('visibility', 'pages', 'custom', 'title', 'module', 'theme', 'region', 'status', 'weight', 'delta', 'cache');
  $query = db_insert('block')->fields($my_array);
  foreach (list_themes() as $key => $theme) {
    if ($theme->status) {
      $region = !empty($form_state['values']['regions'][$theme->name]) ? $form_state['values']['regions'][$theme->name] : BLOCK_REGION_NONE;
      $query->values(array(
        'visibility' => (int) $form_state['values']['visibility'],
        'pages' => trim($form_state['values']['pages']),
        'custom' => (int) $form_state['values']['custom'],
        'title' => $form_state['values']['title'],
        'module' => $form_state['values']['module'],
        'theme' => $theme->name,
        'region' => ($region == BLOCK_REGION_NONE ? '' : $region),
        'status' => 0,
        'status' => (int) ($region != BLOCK_REGION_NONE),
        'weight' => 0,
        'delta' => $delta,
        'cache' => DRUPAL_NO_CACHE,
      ));
    }
  }
  $query->execute();

  $query = db_insert('block_role')->fields(array('rid', 'module', 'delta'));
  foreach (array_filter($form_state['values']['roles']) as $rid) {
    $query->values(array(
      'rid' => $rid,
      'module' => $form_state['values']['module'],
      'delta' => $delta,
    ));
  }
  $query->execute();

  drupal_set_message(t('The block has been created.'));
  cache_clear_all();
  $form_state['redirect'] = 'admin/structure/block';
}

/**
 * Sendgrid subscription form.
 */
function sendgrid_marketing_subscribe_form($form, &$form_state) {
  $delta = $form_state['build_info']['args'][0]['delta'];
  $options = variable_get("sendgrid_marketing_{$delta}_contact_lists", array());
  $fields = variable_get("sendgrid_marketing_{$delta}_custom_fields", array());
  $custom_options = array();
  if (variable_get("sendgrid_marketing_{$delta}_available_agencies")) {
    $custom_options = explode("\n", variable_get("sendgrid_marketing_{$delta}_available_agencies"));
    $custom_options = array_map('trim', $custom_options);
    $custom_options = drupal_map_assoc($custom_options);
  }
  $form['#tree'] = TRUE;
  $form['subscriber_email_' . $delta] = array(
    '#type' => 'textfield',
    '#title' => 'Email Address',
    '#maxlength' => 254,
    '#required' => TRUE,
    '#element_validate' => array('sendgrid_marketing_subscribe_email_validate'),
    '#id' => 'subscriber_email_' . $delta,
  );

  $form['subscriber_first_' . $delta] = array(
    '#type' => 'textfield',
    '#title' => 'First Name',
    '#maxlength' => 254,
    '#required' => FALSE,
  );

  $form['subscriber_last_' . $delta] = array(
    '#type' => 'textfield',
    '#title' => 'Last Name',
    '#maxlength' => 254,
    '#required' => FALSE,
  );

  foreach ($fields as $key => $field) {
    if ($field == 'Agency' && !empty($custom_options)) {
      $form['subscriber_custom_field'][$field . '_' . $delta] = array(
        '#type' => 'select',
        '#title' => $field,
        '#required' => FALSE,
        '#options' => $custom_options,
      );
    }
    else {
      $form['subscriber_custom_field'][$field . '_' . $delta] = array(
        '#type' => 'textfield',
        '#title' => $field,
        '#required' => FALSE,
      );
    }

  }

  $form['subscriber_list_' . $delta] = array(
    '#type' => 'checkboxes',
    '#title' => 'E-Newsletter',
    '#options' => $options,
    '#required' => TRUE,
  );

  $form['subscriber_captcha'] = array(
    '#type' => 'captcha',
  );

  $form['submit_button_' . $delta] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

/**
 * Sendgrid subscription email validation.
 */
function sendgrid_marketing_subscribe_email_validate($element, &$form_state) {
  $value = $element['#value'];
  if (!valid_email_address($value)) {
    form_error($element, t('Please enter a valid email address.'));
  }
}

/**
 * Sendgrid subscription form submission.
 */
function sendgrid_marketing_subscribe_form_submit($form, &$form_state) {
  $delta = $form_state['build_info']['args'][0]['delta'];
  $contact_list = $form_state['values']['subscriber_list_' . $delta];
  if (empty($contact_list)) {
    return;
  }

  $params = array(
        array(
          'first_name' => $form_state['values']['subscriber_first_' . $delta],
          'last_name' => $form_state['values']['subscriber_last_' . $delta],
          'email' => $form_state['values']['subscriber_email_' . $delta],
        ),
  );
  foreach (variable_get("sendgrid_marketing_{$delta}_custom_fields", array()) as $key => $field) {
    $params['0'][$field] = $form_state['values']['subscriber_custom_field'][$field . '_' . $delta];
  }
  $contact = _sendgrid_marketing_create_contact($params);
  $recipient_id = $contact['persisted_recipients'][0];
  foreach ($contact_list as $list) {
    _sendgrid_marketing_add_contact_to_list($list, $recipient_id, $params);
  }
  drupal_set_message(t("Thank you for subscribing to our newsletter."));
}

/**
 * Menu callback: confirm deletion of menu blocks.
 */
function sendgrid_marketing_delete_form($form, &$form_state, $delta = 0) {
  $form['delta'] = array('#type' => 'hidden', '#value' => $delta);
  return confirm_form($form, t('Are you sure you want to delete the newsletter block?'), 'admin/structure/block', NULL, t('Delete'), t('Cancel'));
}

/**
 * Deletion of menu blocks.
 */
function sendgrid_marketing_delete_form_submit($form, &$form_state) {
  // Remove the menu block configuration variables.
  $delta = $form_state['values']['delta'];
  sendgrid_marketing_delete($delta);
  drupal_set_message(t('The newsletter block has been removed.'));
  cache_clear_all();
  $form_state['redirect'] = 'admin/structure/block';
  return;
}

/**
 * Delete a .
 *
 * @param string $delta
 *   The delta of the menu block.
 */
function sendgrid_marketing_delete($delta) {
  $block_ids = variable_get('sendgrid_marketing_ids', array());
  $index = array_search($delta, $block_ids);
  if ($index !== FALSE) {

    // Remove the delta from the list of custom IDs.
    unset($block_ids[$index]);
    sort($block_ids);
    variable_set('sendgrid_marketing_ids', $block_ids);
    variable_del("sendgrid_marketing_{$delta}_contact_lists");
    variable_del("sendgrid_marketing_{$delta}_custom_fields");
    variable_del("sendgrid_marketing_{$delta}_available_agencies");
    sendgrid_marketing_block_delete($delta);
  }
}

/**
 * Implements hook_block_delete() on behalf of block.module.
 */
function sendgrid_marketing_block_delete($delta) {
  db_delete('block')
    ->condition('module', 'sendgrid_marketing')
    ->condition('delta', $delta)
    ->execute();
  db_delete('block_role')
    ->condition('module', 'sendgrid_marketing')
    ->condition('delta', $delta)
    ->execute();
}
