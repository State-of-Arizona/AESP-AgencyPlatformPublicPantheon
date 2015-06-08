<?php
/**
 * @file
 * agency_platform_resource.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function agency_platform_resource_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'resources';
  $context->description = 'Resources settings';
  $context->tag = 'Front Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Front Page');
  t('Resources settings');
  $export['resources'] = $context;

  return $export;
}
