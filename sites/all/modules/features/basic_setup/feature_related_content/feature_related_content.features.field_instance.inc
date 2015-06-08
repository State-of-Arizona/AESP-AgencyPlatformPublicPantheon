<?php
/**
 * @file
 * feature_related_content.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function feature_related_content_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-basic_page-field_basic_related_terms'
  $field_instances['node-basic_page-field_basic_related_terms'] = array(
    'bundle' => 'basic_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_basic_related_terms',
    'label' => 'Related Terms',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 30,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Related Terms');

  return $field_instances;
}
