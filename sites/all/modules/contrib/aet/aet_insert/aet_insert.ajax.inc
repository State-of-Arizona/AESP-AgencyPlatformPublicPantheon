<?php
/**
 * @file
 * This file contains all the functions required for the AET Insert ajax.
 */

/**
 * The callback for the AET Insert ajax field.
 */
function aet_insert_field_ajax() {
  if (isset($_GET['entity_type']) && isset($_GET['target'])) {
    $aet_insert_field = array(
      '#type' => 'aet_insert_field',
      '#id' => isset($_GET['id']) ? $_GET['id'] : 'aet_insert_field',
      '#theme' => 'aet_insert_field',
      '#target' =>  $_GET['target'],
      '#entity_type' => $_GET['entity_type'],
      '#entity_id' => isset($_GET['entity_id']) ? $_GET['entity_id'] : FALSE,
      '#data' => isset($_GET['data']) ? $_GET['data'] : array(),
    );
  }

  die(render($aet_insert_field));
}
