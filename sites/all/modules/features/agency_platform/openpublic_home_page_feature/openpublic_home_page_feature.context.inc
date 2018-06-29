<?php
/**
 * @file
 * openpublic_home_page_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function openpublic_home_page_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home';
  $context->description = 'Context for the Home page';
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
  t('Context for the Home page');
  t('Front Page');
  $export['home'] = $context;

  return $export;
}
