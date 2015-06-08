<?php
/**
 * @file
 * feature_basic_config.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_basic_config_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'Contributor' => 'Contributor',
      'Editor' => 'Editor',
      'Power User' => 'Power User',
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  return $permissions;
}
