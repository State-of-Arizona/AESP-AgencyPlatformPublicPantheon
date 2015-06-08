<?php
/**
 * @file
 * feature_related_content.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function feature_related_content_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_basic_related_terms'
  $field_bases['field_basic_related_terms'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_basic_related_terms',
    'foreign keys' => array(
      'tid' => array(
        'columns' => array(
          'tid' => 'tid',
        ),
        'table' => 'taxonomy_term_data',
      ),
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'basic_related_terms',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
