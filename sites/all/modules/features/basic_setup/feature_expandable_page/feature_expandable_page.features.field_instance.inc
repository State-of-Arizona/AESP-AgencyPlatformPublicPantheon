<?php
/**
 * @file
 * feature_expandable_page.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function feature_expandable_page_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'field_collection_item-field_expandable_page_groups-field_expandable_page_link_label'
  $field_instances['field_collection_item-field_expandable_page_groups-field_expandable_page_link_label'] = array(
    'bundle' => 'field_expandable_page_groups',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter some text that will act as a link.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_expandable_page_link_label',
    'label' => 'Link Label',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 2,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_expandable_page_groups-field_expandable_page_text'
  $field_instances['field_collection_item-field_expandable_page_groups-field_expandable_page_text'] = array(
    'bundle' => 'field_expandable_page_groups',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This will be expanded and exposed when the user clicks the text from above.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_expandable_page_text',
    'label' => 'Expanded Text',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-expandable_page-body'
  $field_instances['node-expandable_page-body'] = array(
    'bundle' => 'expandable_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Introduction',
    'required' => 0,
    'settings' => array(
      'display_summary' => 1,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 4,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-expandable_page-field_expandable_page_groups'
  $field_instances['node-expandable_page-field_expandable_page_groups'] = array(
    'bundle' => 'expandable_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Drag and drop these groups to reorder them.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'add' => '',
          'delete' => '',
          'description' => 0,
          'edit' => '',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_expandable_page_groups',
    'label' => 'Expandable Groups',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Drag and drop these groups to reorder them.');
  t('Enter some text that will act as a link.');
  t('Expandable Groups');
  t('Expanded Text');
  t('Introduction');
  t('Link Label');
  t('This will be expanded and exposed when the user clicks the text from above.');

  return $field_instances;
}
