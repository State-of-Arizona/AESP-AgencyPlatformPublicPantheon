<?php
/**
 * @file
 * feature_search_scs_purchase.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function feature_search_scs_purchase_user_default_roles() {
  $roles = array();

  // Exported role: Cash and Check.
  $roles['Cash and Check'] = array(
    'name' => 'Cash and Check',
    'weight' => 3,
  );

  // Exported role: View Webform Results.
  $roles['View Webform Results'] = array(
    'name' => 'View Webform Results',
    'weight' => 2,
  );

  return $roles;
}
