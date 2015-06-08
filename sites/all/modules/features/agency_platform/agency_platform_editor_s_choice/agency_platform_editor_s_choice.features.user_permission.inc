<?php
/**
 * @file
 * agency_platform_editor_s_choice.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function agency_platform_editor_s_choice_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create editor_s_choice content'.
  $permissions['create editor_s_choice content'] = array(
    'name' => 'create editor_s_choice content',
    'roles' => array(
      'Contributor' => 'Contributor',
      'Editor' => 'Editor',
      'Power User' => 'Power User',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any editor_s_choice content'.
  $permissions['delete any editor_s_choice content'] = array(
    'name' => 'delete any editor_s_choice content',
    'roles' => array(
      'Editor' => 'Editor',
      'Power User' => 'Power User',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own editor_s_choice content'.
  $permissions['delete own editor_s_choice content'] = array(
    'name' => 'delete own editor_s_choice content',
    'roles' => array(
      'Editor' => 'Editor',
      'Power User' => 'Power User',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any editor_s_choice content'.
  $permissions['edit any editor_s_choice content'] = array(
    'name' => 'edit any editor_s_choice content',
    'roles' => array(
      'Editor' => 'Editor',
      'Power User' => 'Power User',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own editor_s_choice content'.
  $permissions['edit own editor_s_choice content'] = array(
    'name' => 'edit own editor_s_choice content',
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
