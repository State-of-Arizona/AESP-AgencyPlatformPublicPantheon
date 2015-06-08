<?php
/**
 * @file
 * Token callbacks for the AET module.
 */

/**
 * Implements hook_token_info().
 *
 * Declaring the AET tokens.
 */
function aet_token_info() {

  // Initializing the $info array.
  $info = array('types' => array(), 'tokens' => array());

  $info['types']['aet'] = array();
  $info['types']['aet']['name'] = t('Advanced Entity Tokens');
  $info['types']['aet']['description'] = t('AET Description');

  // Getting the information arrays on all the entities.
  $entities = entity_get_info();

  // Looping the entity information array to add the token types.
  foreach ($entities as $entity_type => $entity_info) {

    $token_type = !empty($entity_info['token type'])
    ? $entity_info['token type'] : $entity_type;

    if (empty($info['types'])) {
      $info['types'] = array();
    }

    if (empty($info['tokens'])) {
      $info['tokens'] = array();
    }

    $entity_id_key = $entity_info['entity keys']['id'];

    // Adding the entity element token.
    // The token key consists of the entity key id and a question mark
    // to mark this as the place to enter the entity's id.
    $info['tokens']['aet'][$token_type] = array();

    $info['tokens']['aet'][$token_type]['name']
    = 'AET ' . $entity_info['label'] . ' entity';

    $info['tokens']['aet'][$token_type]['description']
    = t("Reference a @entity_name entity by using it's @id_key",
      array(
        '@entity_name' => $entity_info['label'],
        '@id_key' => $entity_id_key
      )
    );

    $info['tokens']['aet'][$token_type]['dynamic']
    = TRUE;

    $info['tokens']['aet'][$token_type]['type']
    = $token_type;

  }

  return $info;
}

/**
 * This is the main implementation of hook_tokens.
 *
 * The main purpose of this hook implementation is to identify the entity type
 * and call aet_entity_token on it.
 *
 * @param string $type
 *   The tokens type.
 * @param array $tokens
 *   A list of tokens to replace.
 * @param array $data
 *   Additional data for this function (e.g. an entity object). This function
 *   doesn't need additional data though.
 * @param array $options
 *   An associative array of options for token replacement; see token_replace()
 *   for possible values.
 */
function aet_tokens($type, $tokens, array $data = array(),
  array $options = array()) {
  // Initiating the $replacements array.
  $replacements = array();
  // TODO Add support $options['callback']
  // TODO Add support $options['sanitize']
  // TODO Add support $options['language']
  $options += array(
    'callback' => NULL,
    'sanitize' => FALSE,
    'language' => NULL,
    'clear' => FALSE,
  );
  // Only tokens from the aet type are supported.
  if ($type === 'aet') {
    // Gets the information array on all the available entities in this drupal
    // site.
    $entities = entity_get_info();

    // Loops the $entities array to check if they exist in the $tokens array.
    foreach ($entities as $entity_type => $entity_info) {

      $token_type = !empty($entity_info['token type'])
      ? $entity_info['token type'] : $entity_type;

      $data += array('entity_type' => $entity_type);

      // The aet_entity_tokens function replaces the next level of the aet
      // tokens.
      // E.G. [aet:node:1], [aet:node:label]
      $replacements += _aet_entity_tokens($token_type,
        token_find_with_prefix($tokens, $token_type),
        $data, $options);
    }
    // Calls aet_clear_tokens to clear unreplaced tokens if the option is
    // flagged.
    aet_clear_tokens($tokens, $replacements, $options['clear']);
  }
  // Returns the $replacements array.
  return $replacements;
}

/**
 * INTERNAL implementation of hook_tokens specified for entities.
 *
 * This function implements the entity level of AET.
 * E.G. [aet:node:1] [aet:file:label]
 *
 * @param string $type
 *   The tokens type. This is also the entity type.
 * @param array $tokens
 *   A list of tokens to replace.
 * @param array $data
 *   Additional data for this function.
 * @param array $options
 *   An associative array of options for token replacement; see token_replace()
 *   for possible values.
 */
function _aet_entity_tokens($type, $tokens, array $data = array(),
  array $options = array()) {

  // Initiating the $replacements array.
  $replacements = array();

  // TODO Add support $options['language']
  // TODO Add support $options['callback']
  // TODO Add support $options['sanitize']
  $options += array(
    'callback' => NULL,
    'sanitize' => FALSE,
    'language' => NULL,
    'clear' => FALSE,
  );

  $entities = entity_get_info();

  $entity_type = '';

  $entity_info = NULL;

  foreach ($entities as $key => $value) {

    // Gets the information array on all the available entities in this drupal
    // site.
    if (isset($value['token type']) && $value['token type'] === $type) {
      $entity_type = $key;
      $entity_info = $value;
    }
  }

  // Checks if $entity_info is not empty.
  if (!empty($entity_info)) {

    // Loops over the $tokens array.
    foreach ($tokens as $key => $original) {

      // The position of the first colon is used for both checking if a secound
      // part to the key exists and to seperate between it (the first part) and
      // the rest of the key.
      $first_colon_pos = strpos($key, ':');

      // The $first_key is the part of the key until the first colon if exist,
      // or the full $key if no colon exists.
      $first_key = $first_colon_pos ? substr($key, 0, $first_colon_pos) : $key;

      // Checks if the $first_key is numeric - the entity id.
      if (is_numeric($first_key)) {

        // Renames the $first_key as $entity_id for better readability.
        $entity_id = (int) $first_key;

        $id_key = $entity_info['entity keys']['id'];

        // Check if the entity to load is currently being viewed or if the
        // the rendered token origins from itself.
        if (aet_entity_is_page($entity_id, $id_key)
          || aet_entity_is_viewed($entity_type, $id_key, $entity_id)) {

          // To avoid recursion we skip this entity.
          drupal_set_message(t('Recursive token use detected.'), 'warning');
          continue;
        }

        // Loads the entity. entity_loads loads the entity into an assosative
        // array with the $entity_id as the array key. we use array_values to
        // move the entities array into a simple array.
        $entities_array
        = array_values(entity_load($entity_type, array($entity_id)));

        // Sometimes there are no instances of the entity type.
        if (count($entities_array)>0) {
          // The entity object.
          $entity = $entities_array[0];

          global $user;

          // Gets the access callback for this entity.
          $access_callback = !empty($entity_info['access callback'])
          ? $entity_info['access callback'] : '_aet_empty_function_';

          // Checks if the user has access to view this entity.
          if (function_exists($access_callback)
            && !$access_callback('view', $entity, $user, $entity_type)) {
            continue;
          }

          // Checks if the $tokens array contain the $entity_id as one of the
          // "to be replaced" tokens.
          if (isset($tokens[$entity_id])) {

            // The $view_mode of the entity will default to token if exists or
            // full if it doesn't. use another chaining level to specify the
            // display.
            $view_mode
            = isset($entity_info['view modes']['token']) ? 'token' : 'full';

            // Get the renderable array of the entity with entity_view.
            $renderable_entity
            = entity_view($entity_type, $entities_array, $view_mode);

            // Render the entity.
            $rendered_entity = render($renderable_entity);

            // Add the rendered entity to the replacements array.
            $replacements[$tokens[$entity_id]] = $rendered_entity;
          }

          $replacements += _aet_entity_view_tokens($type,
            token_find_with_prefix($tokens, $entity_id),
            array($type => $entity), $options);

          // I'm calling the token_generate to the rest of the chaining at this
          // point - after the entity type and nid have been figured out.
          $replacements += token_generate($type,
            token_find_with_prefix($tokens, $entity_id),
            array($type => $entity), $options);
        }
      }
    }

    // Calls aet_clear_tokens to clear unreplaced tokens if the option is
    // flagged.
    aet_clear_tokens($tokens, $replacements, $options['clear']);
  }

  // Returns the $replacements array.
  return $replacements;
}


/**
 * This is the main implementation of hook_tokens.
 *
 * The main purpose of this hook implementation is to identify the entity type
 * and call aet_entity_token on it.
 *
 * @param string $type
 *   The tokens type.
 * @param array $tokens
 *   A list of tokens to replace.
 * @param array $data
 *   Additional data for this function (e.g. an entity object). This function
 *   doesn't need additional data though.
 * @param array $options
 *   An associative array of options for token replacement; see token_replace()
 *   for possible values.
 */
function _aet_entity_view_tokens($type, $tokens, array $data = array(), array $options = array()) {

  // Initiating the $replacements array.
  $replacements = array();

  // TODO Add support $options['language']
  // TODO Add support $options['callback']
  // TODO Add support $options['sanitize']
  $options += array(
    'callback' => NULL,
    'sanitize' => FALSE,
    'language' => NULL,
    'clear' => FALSE,
  );

  // Gets the information array on all the available entities in this drupal
  // site.
  $entities = entity_get_info();

  $entity_type = '';

  $entity_info = NULL;

  foreach ($entities as $key => $value) {


    if (isset($value['token type']) && $value['token type'] === $type) {
      $entity_type = $key;
      $entity_info = $value;
    }
  }
  // Checks if $entity_info is not empty.
  if (!empty($entity_info) && !empty($data[$type])) {

    $entity = $data[$type];

    foreach ($entity_info['view modes'] as $key => $value) {

      if (!empty($tokens['view-' . $key])) {
        // Renames $key to $view_mode for better readability.
        $view_mode = $key;

        // Get the renderable array of the entity with entity_view.
        $renderable_entity
        = entity_view($entity_type, array($entity), $view_mode);

        // Render the entity.
        $rendered_entity = render($renderable_entity);

        // Add the rendered entity to the replacements array.
        $replacements[$tokens['view-' . $key]] = $rendered_entity;
      }
    }
  }

  // Returns the $replacements array.
  return $replacements;
}
