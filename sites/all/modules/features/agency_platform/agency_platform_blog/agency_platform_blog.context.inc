<?php
/**
 * @file
 * agency_platform_blog.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function agency_platform_blog_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'nav_blog';
  $context->description = 'Navigation Individual Blog Entries';
  $context->tag = 'Navigation';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog_entry' => 'blog_entry',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Navigation');
  t('Navigation Individual Blog Entries');
  $export['nav_blog'] = $context;

  return $export;
}
