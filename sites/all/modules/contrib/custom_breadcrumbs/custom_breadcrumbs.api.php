<?php

/**
 * Implements hook_custom_breadcrumbs_taxonomy_node_terms_alter().
 *
 * Ensures that only taxonomy from the field_category field are used to
 * construct breadcrumbs built by the Custom Breadcrumbs Taxonomy module.
 */
function xyz_breadcrumbs_custom_breadcrumbs_taxonomy_node_terms_alter(&$terms, $node, $key) {
  // Construct an array of term IDs from the node's Category field.
  $category_tids = array();
  if (!empty($node->field_category[LANGUAGE_NONE])) {
    foreach ($node->field_category[LANGUAGE_NONE] as $term_data) {
      $category_tids[] = $term_data['tid'];
    }
  }
  // Loop through the terms found by the Custom Breadcrumbs Taxonomy query. If
  // a given term is not assigned to the node via the Category field (such as
  // those assigned to the Second Category field), remove it from results. The
  // Custom Breadcrumbs Taxonomy module will do the rest of the work to
  // construct the breadcrumb from the remaining Category field results.
  foreach (array_keys($terms[$node->vid][$key]) as $tid) {
    if (!in_array($tid, $category_tids)) {
      unset($terms[$node->vid][$key][$tid]);
    }
  }
}
