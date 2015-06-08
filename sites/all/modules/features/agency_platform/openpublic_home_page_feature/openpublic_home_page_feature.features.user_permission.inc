<?php
/**
 * @file
 * openpublic_home_page_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function openpublic_home_page_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create home_page_feature content'.
  $permissions['create home_page_feature content'] = array(
    'name' => 'create home_page_feature content',
    'roles' => array(
      'Contributor' => 'Contributor',
      'Editor' => 'Editor',
      'Power User' => 'Power User',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any home_page_feature content'.
  $permissions['delete any home_page_feature content'] = array(
    'name' => 'delete any home_page_feature content',
    'roles' => array(
      'Editor' => 'Editor',
      'Power User' => 'Power User',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own home_page_feature content'.
  $permissions['delete own home_page_feature content'] = array(
    'name' => 'delete own home_page_feature content',
    'roles' => array(
      'Editor' => 'Editor',
      'Power User' => 'Power User',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any home_page_feature content'.
  $permissions['edit any home_page_feature content'] = array(
    'name' => 'edit any home_page_feature content',
    'roles' => array(
      'Editor' => 'Editor',
      'Power User' => 'Power User',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own home_page_feature content'.
  $permissions['edit own home_page_feature content'] = array(
    'name' => 'edit own home_page_feature content',
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
