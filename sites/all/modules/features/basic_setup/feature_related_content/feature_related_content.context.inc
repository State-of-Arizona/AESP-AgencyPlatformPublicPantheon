<?php
/**
 * @file
 * feature_related_content.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function feature_related_content_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'related_content_block';
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
        'quicktabs-draggable_views_related_content' => array(
          'module' => 'quicktabs',
          'delta' => 'draggable_views_related_content',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic Setup');
  $export['related_content_block'] = $context;

  return $export;
}
