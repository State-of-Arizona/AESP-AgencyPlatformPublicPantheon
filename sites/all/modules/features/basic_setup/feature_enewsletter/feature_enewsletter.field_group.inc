<?php
/**
 * @file
 * feature_enewsletter.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feature_enewsletter_field_group_info() {
  $export = array();
  if (module_exists('feature_basic_content')) {
    $field_group = new stdClass();
    $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
    $field_group->api_version = 1;
    $field_group->identifier = 'group_enews_block_settings|node|enewsletter_subscription|form';
    $field_group->group_name = 'group_enews_block_settings';
    $field_group->entity_type = 'node';
    $field_group->bundle = 'enewsletter_subscription';
    $field_group->mode = 'form';
    $field_group->parent_name = '';
    $field_group->data = array(
      'label' => 'Block Settings',
      'weight' => '2',
      'children' => array(
        0 => 'field_basic_block_block_sections',
        1 => 'field_basic_block_front_page',
        2 => 'field_basic_block_region',
        3 => 'field_basic_individual_page',
      ),
      'format_type' => 'fieldset',
      'format_settings' => array(
        'formatter' => 'collapsible',
        'instance_settings' => array(
          'description' => '',
          'classes' => 'group-enews-block-settings field-group-fieldset',
          'required_fields' => 1,
        ),
      ),
    );
    $export['group_enews_block_settings|node|enewsletter_subscription|form'] = $field_group;
  }

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enews_form_settings|node|enewsletter_subscription|form';
  $field_group->group_name = 'group_enews_form_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enewsletter_subscription';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Form Settings',
    'weight' => '5',
    'children' => array(
      0 => 'field_enews_opt_out',
      1 => 'group_opt_in',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Form Settings',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-enews-form-settings field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_enews_form_settings|node|enewsletter_subscription|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enews_name_settings|node|enewsletter_subscription|form';
  $field_group->group_name = 'group_enews_name_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enewsletter_subscription';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_opt_in';
  $field_group->data = array(
    'label' => 'group_enews_name',
    'weight' => '14',
    'children' => array(
      0 => 'field_enews_name',
      1 => 'field_enews_name_format',
      2 => 'field_enews_require_name',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'group_enews_name',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-enews-name-settings field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_enews_name_settings|node|enewsletter_subscription|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enews_name|node|enewsletter_subscription|form';
  $field_group->group_name = 'group_enews_name';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enewsletter_subscription';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_opt_in';
  $field_group->data = array(
    'label' => '',
    'weight' => '15',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-enews-name field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_enews_name|node|enewsletter_subscription|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_opt_in|node|enewsletter_subscription|form';
  $field_group->group_name = 'group_opt_in';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enewsletter_subscription';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_enews_form_settings';
  $field_group->data = array(
    'label' => 'Opt-In Form',
    'weight' => '29',
    'children' => array(
      0 => 'field_enews_confirm',
      1 => 'field_enews_descriptions',
      2 => 'field_enews_double_email',
      3 => 'field_enews_format',
      4 => 'field_enews_link',
      5 => 'field_enews_link_text',
      6 => 'field_enews_list_format',
      7 => 'field_enews_message',
      8 => 'field_enews_password',
      9 => 'field_enews_saluation',
      10 => 'field_enews_update_demo',
      11 => 'field_enews_update_subs',
      12 => 'group_enews_name_settings',
      13 => 'group_enews_name',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Opt-In Form',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-opt-in field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_opt_in|node|enewsletter_subscription|form'] = $field_group;

  return $export;
}
