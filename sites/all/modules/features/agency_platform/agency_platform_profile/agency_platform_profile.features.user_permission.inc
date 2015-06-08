<?php
/**
 * @file
 * agency_platform_profile.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function agency_platform_profile_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create profile content'.
  $permissions['create profile content'] = array(
    'name' => 'create profile content',
    'roles' => array(
      'Contributor' => 'Contributor',
      'Editor' => 'Editor',
      'Power User' => 'Power User',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any profile content'.
  $permissions['delete any profile content'] = array(
    'name' => 'delete any profile content',
    'roles' => array(
      'Editor' => 'Editor',
      'Power User' => 'Power User',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own profile content'.
  $permissions['delete own profile content'] = array(
    'name' => 'delete own profile content',
    'roles' => array(
      'Editor' => 'Editor',
      'Power User' => 'Power User',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any profile content'.
  $permissions['edit any profile content'] = array(
    'name' => 'edit any profile content',
    'roles' => array(
      'Editor' => 'Editor',
      'Power User' => 'Power User',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own profile content'.
  $permissions['edit own profile content'] = array(
    'name' => 'edit own profile content',
    'roles' => array(
      'Contributor' => 'Contributor',
      'Editor' => 'Editor',
      'Power User' => 'Power User',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
