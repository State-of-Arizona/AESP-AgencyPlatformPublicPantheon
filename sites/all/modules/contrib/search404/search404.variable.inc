<?php

/**
 * @file
 * Definition of variables for Variable API module.
 */

/**
 * Implements hook_variable_info().
 */
function search404_variable_info($options) {
  $variables['search404_page_title'] = array(
    'type' => 'string',
    'title' => t('Custom page title', array(), $options),
    'default' => '',
    'description' => t('You can enter a value that will be displayed as the title of the webpage e.g. "Page not found".', array(), $options),
    'required' => FALSE,
    'group' => 'search404',
    'localize' => TRUE,
    'multidomain' => TRUE,
  );

  $variables['search404_page_text'] = array(
    'type' => 'string',
    'title' => t('Custom page text', array(), $options),
    'default' => '',
    'description' => t('You can enter a custom text message that can be displayed at the top of the search results, HTML formatting can be used.', array(), $options),
    'required' => FALSE,
    'group' => 'search404',
    'localize' => TRUE,
    'multidomain' => TRUE,
  );
  $variables['search404_custom_search_path'] = array(
    'type' => 'string',
    'title' => t('Custom path', array(), $options),
    'default' => '',
    'description' => t('path you can enter which will be redirected to the custom search page.', array(), $options),
    'required' => FALSE,
    'group' => 'search404',
    'localize' => TRUE,
    'multidomain' => TRUE,
  );

  return $variables;
}

/**
 * Implements hook_variable_group_info().
 */
function search404_variable_group_info() {
  $groups['search404'] = array(
    'title' => t('Search 404'),
    'description' => t('Configure Search 404'),
    'access' => 'admin node search exlusions',
    'path' => array('admin/config/search/search404'),
  );

  return $groups;
}
