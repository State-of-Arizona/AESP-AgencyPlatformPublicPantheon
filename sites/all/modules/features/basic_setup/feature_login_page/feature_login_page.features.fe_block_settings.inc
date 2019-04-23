<?php
/**
 * @file
 * feature_login_page.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function feature_login_page_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['user-login'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'login',
    'module' => 'user',
    'node_types' => array(),
    'roles' => array(),
    'themes' => array(
      'az_branded' => array(
        'pages' => 'login',
        'region' => 'content',
        'status' => 1,
        'theme' => 'az_branded',
        'title' => '',
        'visibility' => 1,
        'weight' => 0,
      ),
      'az_commercial' => array(
        'pages' => 'login',
        'region' => 'content',
        'status' => 1,
        'theme' => 'az_commercial',
        'title' => '',
        'visibility' => 1,
        'weight' => 0,
      ),
      'az_gov' => array(
        'pages' => 'login',
        'region' => 'content',
        'status' => 1,
        'theme' => 'az_gov',
        'title' => '',
        'visibility' => 1,
        'weight' => 0,
      ),
    ),
  );

  return $export;
}
