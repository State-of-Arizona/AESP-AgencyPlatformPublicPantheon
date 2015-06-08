<?php
/**
 * @file
 * feature_sliver.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function feature_sliver_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sliver_block';
  $context->description = '';
  $context->tag = 'Basic Setup';
  $context->conditions = array(
    'admin_theme' => array(
      'values' => array(
        'non_admin' => 'non_admin',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'feature_sliver-sliver' => array(
          'module' => 'feature_sliver',
          'delta' => 'sliver',
          'region' => 'user_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic Setup');
  $export['sliver_block'] = $context;

  return $export;
}
