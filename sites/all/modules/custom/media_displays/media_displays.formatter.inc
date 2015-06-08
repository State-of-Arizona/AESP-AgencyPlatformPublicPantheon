<?php
/**
 * @file
 * Defines custom formatters
 */
/**
 * Theme function for the 'direct_download' multiple file formatter.
 *
 * @param $file
 *   File to format.
 * @return
 *   A string containing the HTML ouput.
 */
function theme_media_displays_download_file_alt($variables) {
  $output = '';
//  dpm($variables);

  foreach ($variables['items'] as $delta => $item) {
    if (!empty($item)) {
      $output .= theme('media_displays_download_alt_item',
        array('file' => (object) $item));
    }
  }
  return $output;
}


/**
 * Theme function for the 'direct_download' multiple file formatter.
 *
 * @param $file
 *   File to format.
 * @return
 *   A string containing the HTML ouput.
 */
function theme_media_displays_download_alt_item($variables) {
  $file = $variables['file'];

  // Views may call this function with a NULL value, return an empty string.
  if (empty($file->fid)) {
    return '';
  }

  $json = array(
    'fid' => $file->fid,
    'direct_download' => TRUE,
    'type' => 'media',
    'fields' => array(),
    'attributes' => array(),
);

  // Use the description or the title as the link text if available.
  if (!isset($file->field_alt_text['und']) && empty($file->field_alt_text['und'][0]['value'])) {
    $json['fields']['link_text'] = $file->filename . 'testsa';
  }
  else {
    $json['fields']['link_text'] = $file->field_alt_text['und'][0]['value'];
  }
  // Use the description or the title as the link text if available.
  if (!isset($file->field_document_title['und']) && empty($file->field_document_title['und'][0]['value'])) {
    $json['fields']['title'] = $file->filename;
  }
  else {
    $json['fields']['title'] = $file->field_document_title['und'][0]['value'];
  }

  return '[[' . json_encode($json) . ']]';
}

/**
 * Theme function for the 'image (alt quotes)' multiple file formatter.
 *
 * Note: this is basically a copy of the image format type, with the rules for handling single quotes thrown in
 *
 * @param $items
 *   Information about the image.
 * @return
 *   A string containing the HTML ouput.
 */
function theme_media_displays_image_alt_quotes($variables) {
  $item = $variables['items'][0];
  $image = array(
    'path' => $item['uri'],
  );

  if (array_key_exists('alt', $item)) {
    $image['alt'] = htmlspecialchars(htmlspecialchars_decode($item['alt'], ENT_QUOTES), ENT_COMPAT);
  }

  if (isset($item['attributes'])) {
    $image['attributes'] = $item['attributes'];
  }

  if (isset($item['width']) && isset($item['height'])) {
    $image['width'] = $item['width'];
    $image['height'] = $item['height'];
  }

  // Do not output an empty 'title' attribute.
  if (isset($item['title']) && drupal_strlen($item['title']) > 0) {
    $image['title'] = htmlspecialchars(htmlspecialchars_decode($item['title'], ENT_QUOTES), ENT_COMPAT);

  }

  if ($variables['image_style']) {
    $image['style_name'] = $variables['image_style'];
    $output = theme('image_style', $image);
  }
  else {
    $output = theme('image', $image);
  }

  if (isset($variables['path']['path'])) {
    $path = $variables['path']['path'];
    $options = isset($variables['path']['options']) ? $variables['path']['options'] : array();
    // When displaying an image inside a link, the html option must be TRUE.
    $options['html'] = TRUE;
    $output = l($output, $path, $options);
  }

  return $output;
}
