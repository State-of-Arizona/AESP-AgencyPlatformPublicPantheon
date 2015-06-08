<?php
/**
 * @file
 * agency_platform_profile.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function agency_platform_profile_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'nav_leader';
  $context->description = 'Navigation for a Staff Leader';
  $context->tag = 'Navigation';
  $context->conditions = array();
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Navigation');
  t('Navigation for a Staff Leader');
  $export['nav_leader'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'nav_staff';
  $context->description = 'Navigation for a None Leader Staff Pages';
  $context->tag = 'Navigation';
  $context->conditions = array();
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Navigation');
  t('Navigation for a None Leader Staff Pages');
  $export['nav_staff'] = $context;

  return $export;
}
