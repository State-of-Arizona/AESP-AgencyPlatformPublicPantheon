<?php

/**
 * @file
 * Password Tab admin page callbacks.
 */

/**
 * Implements the settings page.
 *
 * @return
 *   The form structure.
 */
function password_tab_admin_settings() {
  $form = array();

  // Attachments settings.
  $form['password_tab'] = array('#type' => 'fieldset', '#title' => t('Password tab settings'), '#collapsible' => FALSE, '#collapsed' => FALSE);
  $form['password_tab']['password_tab_redirect'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Redirect path on password change'),
    '#default_value' => variable_get('password_tab_redirect', ''),
    '#description'   => t('Normally, after a user changes their password, they will be taken to their user page. Leave this setting blank if you wish to keep the default behavior. If you wish the user to go to a page of your choosing, then enter the path for it here. For instance, you may redirect them to a static page such as <cite>node/35</cite>, or to the <cite>&lt;front&gt;</cite> page. You may also use <em>%uid</em> as a variable, and the user\'s user ID will be substituted in the path. In the case where users are first creating their own passwords, it is suggested to use <cite>user/%uid/edit</cite> here, so the user may set their over account information immediately after validating their account.'),
  );

  return system_settings_form($form);
}

