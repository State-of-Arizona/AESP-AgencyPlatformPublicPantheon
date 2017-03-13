<?php

/**
 * @file
 * All Views hooks except hook_views_api.
 */

/**
 * Implements hook_views_data().
 */
function views_fieldsets_views_data() {
  $data['views']['fieldset'] = array(
    'title' => t('Fieldset'),
    'help' => t('Adds a fieldset to put fields and other fieldsets in.'),
    'field' => array(
      'handler' => 'views_fieldsets_fieldset_field_handler',
    ),
  );

  return $data;
}
