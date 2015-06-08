<?php
/**
 * @file
 * commercial_theme.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function commercial_theme_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function commercial_theme_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function commercial_theme_image_default_styles() {
  $styles = array();

  // Exported image style: commercial_slider.
  $styles['commercial_slider'] = array(
    'name' => 'commercial_slider',
    'label' => 'Commercial Slider',
    'effects' => array(
      16 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 950,
          'height' => 430,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
