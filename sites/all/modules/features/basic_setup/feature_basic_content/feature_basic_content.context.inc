<?php
/**
 * @file
 * feature_basic_content.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function feature_basic_content_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'basic_content_blocks';
  $context->description = '';
  $context->tag = 'Basic Setup';
  $context->conditions = array(
    'admin_theme' => array(
      'values' => array(
        'non_admin' => 'non_admin',
      ),
    ),
  );
  $id = 8;
  foreach(variable_get('mbp_defaults') as $field){
      if($field == 'field_basic_slideshow_assignment'){
          $field = field_info_field($field);
          $id = $field['id'];
      }
  }
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mbp_defaults-mbp-' . $id => array(
          'module' => 'mbp_defaults',
          'delta' => 'mbp-' . $id,
          'region' => 'header_second',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '0',
        ),
        'menu_block-3' => array(
          'module' => 'menu_block',
          'delta' => '3',
          'region' => 'sidebar_second',
          'weight' => '-99',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic Setup');
  $export['basic_content_blocks'] = $context;

  return $export;
}
