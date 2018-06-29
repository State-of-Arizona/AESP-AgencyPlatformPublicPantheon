<?php
/**
 * @file
 * feature_basic_content.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feature_basic_content_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic_block_assignment|node|basic_block|form';
  $field_group->group_name = 'group_basic_block_assignment';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'basic_block';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Block Assignment',
    'weight' => '1',
    'children' => array(
      0 => 'field_basic_block_block_sections',
      1 => 'field_basic_block_front_page',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-basic-block-assignment field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_basic_block_assignment|node|basic_block|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_basic|node|basic_page|form';
  $field_group->group_name = 'group_tabs_basic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'basic_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Basic Page',
    'weight' => '6',
    'children' => array(
      0 => 'body',
      1 => 'title',
      2 => 'field_screen_reader_only_title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tabs-basic field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_tabs_basic|node|basic_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_quicktabs|node|basic_page|form';
  $field_group->group_name = 'group_tabs_quicktabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'basic_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => '"Quicktabs"',
    'weight' => '7',
    'children' => array(
      0 => 'field_basic_page_tabs',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tabs-quicktabs field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_tabs_quicktabs|node|basic_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|basic_page|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'basic_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs Group',
    'weight' => '0',
    'children' => array(
      0 => 'group_tabs_basic',
      1 => 'group_tabs_quicktabs',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs field-group-htabs',
      ),
    ),
  );
  $field_groups['group_tabs|node|basic_page|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('"Quicktabs"');
  t('Basic Page');
  t('Block Assignment');
  t('Tabs Group');

  return $field_groups;
}
