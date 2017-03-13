<?php

/**
 * Implements hook_theme().
 *
 * @see views_fieldsets_theme()
 * @see views-fieldsets-fieldset.tpl.php
 */
function test_theme() {
  return array(
    // Hook name format = views_fieldsets_TYPE.
    'views_fieldsets_simple' => array(
      // Label, as seen in Views Field edit screen.
      'views_fieldsets_label' => 'Super simple, func, no tpl',

      // Only 'fieldset_fields' is mandatory, but you can add anything you
      // want. 'legend' is optional, but always filled.
      'variables' => array('fieldset_fields' => array(), 'legend' => ''),

      // If your hook is a template, you'll need these, but our example isn't.
      // 'template' => 'views-fieldsets-simple',
      // 'path' => $path,
    ),
  );
}

/**
 * Default preprocessor for views_fieldsets_simple.
 */
function template_preprocess_views_fieldsets_simple(&$variables) {
  $variables['legend'] = 'OVERRIDE YO!';
}

/**
 * Theme function for 'views_fieldsets_simple'.
 */
function theme_views_fieldsets_simple($variables) {
  $content = implode("\n", array_map(function($field) {
    return @$field->separator . $field->wrapper_prefix . $field->label_html . $field->content . $field->wrapper_suffix;
  }, $variables['fieldset_fields']));

  $html  = '<fieldset>';
  $html .= '<legend>' . check_plain(strip_tags($variables['legend'])) . '</legend>';
  $html .= check_plain(strip_tags($content));
  $html .= '</fieldset>';

  return $html;
}
