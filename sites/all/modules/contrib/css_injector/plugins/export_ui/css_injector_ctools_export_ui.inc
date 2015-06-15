<?php

/**
 * Define this Export UI plugin.
 */
$plugin = array(
  'schema' => 'css_injector_rule',  // As defined in hook_schema().
  'access' => 'administer css_injector',  // define a permission users must have to access these pages.

  // define the menu item.
  'menu' => array(
    'menu item' => 'css-injector',
    'menu prefix' => 'admin/config/development',
    'menu title' => 'CSS injector',
    'menu description' => 'Settings for CSS injector rules. Allows for the insertion of arbitrary JavaScript on pages.',
  ),

  // define user interface texts.
  'title singular' => t('rule'),
  'title plural' => t('rules'),
  'title singular proper' => t('CSS injector rule'),
  'title plural proper' => t('CSS injector rules'),

  // define the names of the functions that provide the add/edit forms.
  'form' => array(
    'settings' => 'css_injector_ctools_export_ui_form',
    'validate' => 'css_injector_ctools_export_ui_form_validate',
    'submit' => 'css_injector_ctools_export_ui_form_submit',
  ),
);

/**
 * Define the preset add/edit form.
 */
function css_injector_ctools_export_ui_form(&$form, &$form_state) {
  $rule = $form_state['item'];

  // Alter the name field (this is set by the default export_ui class).
  $form['info']['name']['#title'] = t('Friendly name');
  $form['info']['name']['#description'] = t('This is the unique ID for this rule. Only alphanumeric characters, spaces, underscores and dashes are allowed.');
  $form['info']['name']['#disabled'] = FALSE;
  unset($form['info']['name']['#value']);

  // Alter the admin_description field (this is set by the default export_ui
  // class).
  $form['info']['admin_description']['#title'] = t('Description');
  $form['info']['admin_description']['#type'] = 'textfield';
  $form['info']['admin_description']['#description'] = t('The human readable description of this rule.');
  $form['info']['admin_description']['#required'] = TRUE;

  $form['css'] = array(
    '#type' => 'textarea',
    '#title' => t('CSS code'),
    '#description' => t('The actual CSS code goes in here.'),
    '#rows' => 10,
    '#default_value' => $rule->css,
    '#required' => TRUE,
  );


  // all drupal_add_css options should be settings
  // https://api.drupal.org/api/drupal/includes%21common.inc/function/drupal_add_css/7

  // advanced options fieldset
  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced options'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['advanced']['media'] = array(
    '#type' => 'select',
    '#title' => 'Media',
    '#description' => t('Which media types is the CSS used.'),
    '#options' => array(
      'all' => t('All'),
      'print' => t('Print'),
      'screen' => t('Screen'),
    ),
    '#default_value' => $rule->media,
  );
  $themes = array();
  foreach(list_themes() as $key=>$theme){
    if($theme->status) {
      $themes[$key] = $theme->info['name'];
    }
  }

  $form['advanced']['rule_themes'] = array(
    '#type' => 'select',
    '#title' => 'Theme',
    '#description' => t('Which themes is the CSS used.'),
    '#options' => $themes,
    '#multiple' => TRUE,
    '#default_value' => unserialize($rule->rule_themes),
  );
  $form['advanced']['preprocess'] = array(
    '#type' => 'checkbox',
    '#title' => t('Preprocess CSS'),
    '#description' => t('If the CSS is preprocessed, and CSS aggregation is enabled, the script file will be aggregated. Warning - this means you will require a theme cache clear in order to regenerate new aggregate files.'),
    '#default_value' => $rule->preprocess,
  );
  $form['advanced']['inline'] = array(
    '#type' => 'checkbox',
    '#title' => t('Inline CSS'),
    '#description' => t('The CSS file can also be inline on the page.'),
    '#default_value' => $rule->inline,
    '#states' => array(
      'visible' => array(
        'input[name="preprocess"]' => array('checked' => FALSE),
      ),
    ),
  );

  // page visibility fieldset. Code ported from googleanalytics.module
  $form['pages'] = array(
    '#type' => 'fieldset',
    '#title' => t('Pages'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $title = t('Pages');
  $description = t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>'));
  $options = array(
    0 => t('Every page except the listed pages'),
    1 => t('The listed pages only'),
  );
  if (module_exists('php') && user_access('use PHP for settings')) {
    $options[] = t('Pages on which this PHP code returns <code>TRUE</code> (experts only)');
    $title = t('Pages or PHP code');
    $description .= ' ' . t('If the PHP option is chosen, enter PHP code between %php. Note that executing incorrect PHP code can break your Drupal site.', array('%php' => '<?php ?>'));
  }
  $form['pages']['page_visibility'] = array(
    '#type' => 'radios',
    '#title' => t('Add tracking to specific pages'),
    '#options' => $options,
    '#default_value' => $rule->page_visibility,
  );
  $form['pages']['page_visibility_pages'] = array(
    '#type' => 'textarea',
    '#title' => $title,
    '#title_display' => 'invisible',
    '#default_value' => $rule->page_visibility_pages,
    '#description' => $description,
    '#rows' => 10,
  );
}

/**
 * Validation handler for the preset edit form.
 */
function css_injector_ctools_export_ui_form_validate($form, &$form_state) {
  // if preprocess is ticked, then ensure inline is not (they conflict)
  if ($form_state['values']['preprocess'] == 1) {
    $form_state['values']['inline'] = 0;
  }
  // Ensure the name field only contains URL safe characters.
  if ($form_state['triggering_element']['#value'] != 'Delete' && preg_match('/[^A-Za-z0-9_\-\ ]+/', $form_state['values']['name'])) {
    form_set_error('name', t('Illegal characters found in the friendly name, please remove them.'));
  }

  $existing = db_select('css_injector_rule','c')
    ->fields('c')
    ->condition('name', $form_state['values']['name'])
    ->execute()
    ->fetchAssoc();
  if(!empty($existing) && $form_state['item']->crid != $existing['crid']){
    form_set_error('name', t('Injector already exists with that name'));
  }
}

/**
 * Submit handler for the preset edit form.
 */
function css_injector_ctools_export_ui_form_submit($form, &$form_state) {
  $form_state['values']['rule_themes'] = serialize($form_state['values']['rule_themes']);
}
