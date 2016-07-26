<?php

/**
 * Implements hook_drush_command().
 */
function little_helpers_drush_command() {
  $items['permission-matrix'] = array(
    'description' => 'Show the permission matrix for this installation.',
    'arguments'   => array(),
    'options' => array(),
    'aliases' => array('perm-matrix'),
  );

  return $items;
}

function drush_little_helpers_permission_matrix() {
  $matrix = \Drupal\little_helpers\c2c\PermissionMatrix::createFromSystem();
  $matrix->printEmptyTable();
}

