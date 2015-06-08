<?php
/**
 * @file
 * agency_platform_document.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function agency_platform_document_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create document content'.
  $permissions['create document content'] = array(
    'name' => 'create document content',
    'roles' => array(
      'Contributor' => 'Contributor',
      'Editor' => 'Editor',
      'Power User' => 'Power User',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any document content'.
  $permissions['delete any document content'] = array(
    'name' => 'delete any document content',
    'roles' => array(
      'Editor' => 'Editor',
      'Power User' => 'Power User',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own document content'.
  $permissions['delete own document content'] = array(
    'name' => 'delete own document content',
    'roles' => array(
      'Editor' => 'Editor',
      'Power User' => 'Power User',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in document_terms'.
  $permissions['delete terms in document_terms'] = array(
    'name' => 'delete terms in document_terms',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any document content'.
  $permissions['edit any document content'] = array(
    'name' => 'edit any document content',
    'roles' => array(
      'Editor' => 'Editor',
      'Power User' => 'Power User',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own document content'.
  $permissions['edit own document content'] = array(
    'name' => 'edit own document content',
    'roles' => array(
      'Contributor' => 'Contributor',
      'Editor' => 'Editor',
      'Power User' => 'Power User',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in document_terms'.
  $permissions['edit terms in document_terms'] = array(
    'name' => 'edit terms in document_terms',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
