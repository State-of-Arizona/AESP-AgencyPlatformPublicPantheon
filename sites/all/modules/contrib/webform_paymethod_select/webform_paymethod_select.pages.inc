<?php

/**
 * Page callback for continuing a webform submission after payment.
 */
function webform_paymethod_select_continue($node, $submission, $page_num) {
  // We can't use a simple drupal_get_form() because we wan't to enter the form
  // at a specific $page_num.
  $form_state = array();

  $args = array($node, $submission, TRUE, TRUE);
  $form_state['build_info']['args'] = $args;

  $form_state['storage']['component_tree'] = array();
  $form_state['storage']['page_count'] = 1;
  $form_state['storage']['preview'] = !empty($node->webform['preview']);
  _webform_components_tree_build($node->webform['components'], $form_state['storage']['component_tree'], 0, $form_state['storage']['page_count']);
  $form_state['storage']['page_num'] = $page_num;
  if (module_exists('webform_steps')) {
    $form_state['steps_finished'] = $page_num - 1;
  }

  return drupal_build_form('webform_client_form_' . $node->nid, $form_state);
}
