<?php
/**
 * @file
 * agency_platform_defaults.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function agency_platform_defaults_user_default_roles() {
  $roles = array();

  // Exported role: Contributor.
  $roles['Contributor'] = array(
    'name' => 'Contributor',
    'weight' => 3,
  );

  // Exported role: Editor.
  $roles['Editor'] = array(
    'name' => 'Editor',
    'weight' => 4,
  );

  // Exported role: Power User.
  $roles['Power User'] = array(
    'name' => 'Power User',
    'weight' => 5,
  );

  return $roles;
}
