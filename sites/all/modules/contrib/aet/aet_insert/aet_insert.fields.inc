<?php
/**
 * @file
 * This file contains all the functions required for the creation of the AET
 * Insert field.
 */

/**
 * The internal function of aet_insert_field_pre_render().
 */
function _aet_insert_field_pre_render($element) {

  // Adds another item to the data array which adds the next step in the
  // filtering process.
  $element['#data'][] = null;

  // Add filters according to the received data.
  foreach ($element['#data'] as $key => $data) {
    $filter = aet_insert_get_filter($element, $key);
    // Only add the filter if it has more than one option (NULL).
    if (count($filter['#options']) > 1) {
      $element['#children'][] = $filter;
    }
  }

  // After adding all the filters check if the data had more than two entries
  // and if so than also add the insert button.
  if (count($element['#data']) > 2) {
    $element['#children'][] = array(
      '#type' => 'button',
      '#value' => 'insert',
      '#id' => $element['#id'] . '-insert-button',
      '#attributes' => array(
        'class' => array('aet-insert-button'),
      ),
    );
  }

  $element['#attributes']['class']
  = isset($element['#attributes']['class'])
  ? $element['#attributes']['class'] : array();

  $element['#attributes']['class'][] = 'aet_insert_field';
  $element['#attributes']['class'][] = 'clearfix';

  // The below attributes will be passed to the HTML and will be used again when
  // requesting the filter with different options.
  $element['#attributes']['data-target'] = $element['#target'];
  $element['#attributes']['data-entity-type'] = $element['#entity_type'];
  $element['#attributes']['data-entity-id'] = $element['#entity_id'];

  return $element;
}

/**
 * This function creates the AET Insert field filters.
 *
 * @param array $element
 *   The field element.
 * @param int $i
 *   The number of the filter in the filter queue.
 */
function aet_insert_get_filter($element, $i = 0) {

  // Adds the empty option.
  $options = array(null=>t('- None -'));

  $data = $element['#data'];

  // Getting the information arrays on all the entities.
  $entities_info = entity_get_info();

  // Moves all the entity information to local variables for readability.
  $entity_type = $element['#entity_type'];
  $entity_info = $entities_info[$entity_type];
  $entity_id_key = $entity_info['entity keys']['id'];
  $entity_id = $element['#entity_id'];

  // Sets the token info array and the selected entity type (the first filter
  // will not need this).
  $token_info = array();
  $selected_entity_type = NULL;
  if ($i > 0) {
    $token_info = token_get_info();
    if ($data[$i-1] == 'active_user') {
      $selected_entity_type = 'user';
    }
    elseif ($data[$i-1] == 'this_' . $entity_type) {
      $selected_entity_type = $entity_type;
    }
    elseif (strpos($data[$i-1], 'aet_') === 0) {
      $selected_entity_type = substr($data[$i-1], strlen('aet_'));
    }
    // The aet_ prefix is relevant for the second item after it as much as the
    // first.
    elseif (is_numeric($data[$i-1]) && strpos($data[$i-2], 'aet_') === 0) {
      $selected_entity_type = substr($data[$i-2], strlen('aet_'));
    }
    else {
      // If none of the above checks were true this is probably a normal token
      // (e.g. node, author...).
      $selected_entity_type = $data[$i-1];
    }
  }

  // The first filter only needs to list available entities with the addition
  // of This ENTITY_NAME &  The Active User.
  if ($i == 0) {
    $options['this_' . $entity_type] = t('This @entity_label',
      array('@entity_label' => t($entity_info['label'])));

    $options['active_user'] = t('The active user');

    foreach ($entities_info as $type => $info) {
      $options['aet_' . $type] = t('A @entity_label',
        array('@entity_label' => t($info['label'])));
    }
  }
  elseif ($i > 0) {

    // The below checks if the previously declared selected entity type is part
    // of the entities array and if the previous filter value was a AET Token.
    if (in_array($selected_entity_type, array_keys($entities_info))
      && strpos($data[$i-1], 'aet_') === 0) {
      $entities = entity_load($selected_entity_type);
      $label_key
        = ($selected_entity_type == 'user') ? 'name'
        : $entities_info[$selected_entity_type]['entity keys']['label'];
      foreach ($entities as $id => $entity) {
        if (empty($entity->{$label_key})
          || ($id == $entity_id && $selected_entity_type == $entity_type)) {
          continue;
        }
        $options[$id] = $entity->{$label_key};
      }
    }
    else {
      // Renaming $selected_entity_type to $token_type for better readability.
      $token_type = $selected_entity_type;
      $tokens = $token_info['tokens'][$token_type];

      // If the tokens array is empty than either there isn't anoher layer of
      // filtering or the name of the token is not the name of its type. Note
      // If the queue number of this filter is lower then 2 than the above is
      // not possible and an empty array will be returned.
      if (empty($tokens) && $i >= 2) {

        // First we need to find the parent token. Usually its one step before
        // the token type.
        $parent_token_name = $data[$i-2];
        if (!in_array($parent_token_name, array_keys($token_info['tokens']))) {

          // If the the data one step before the token type is not one of the
          // token types than the only other option is this is one of the
          // special three (active_user, this_ENTITY_NAME, aet_ENTITY_NAME).
          // The special three will exist two steps before.
          if ($data[$i-2] == 'active_user') {
            $parent_token_name = 'user';
          }
          elseif ($data[$i-2] == 'this_' . $entity_type) {
            $parent_token_name = $entity_type;
          }
          elseif ($i > 2 && is_numeric($data[$i-2])
            && strpos($data[$i-3], 'aet_') === 0) {
            $parent_token_name = substr($data[$i-3], strlen('aet_'));
          }
          else {
            return array();
          }
        }
        $parent_token
        = $token_info['tokens'][$parent_token_name][$data[$i-1]];
        $tokens = $token_info['tokens'][$parent_token['type']];
      }
      elseif ($i < 2 && strpos($data[$i-1], 'aet_') === 0) {
        return array();
      }

      // After we made sure we have the right tokens we can proceed with adding
      // the relevant tokens to the options array.
      foreach($tokens as $token_name => $token_info) {
        $options[$token_name] = t($token_info['name']);
      }
    }
  }

  $filter = array(
    '#type' => 'select',
    '#options' => $options,
    '#value' => $data[$i],
  );

  return $filter;
}