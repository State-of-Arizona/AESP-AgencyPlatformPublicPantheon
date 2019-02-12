<?php
/**
 * @file
 * feature_basic_content.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function feature_basic_content_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_basic_page_tabs-field_basic_page_tab_body'.
  $field_instances['field_collection_item-field_basic_page_tabs-field_basic_page_tab_body'] = array(
    'bundle' => 'field_basic_page_tabs',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_basic_page_tab_body',
    'label' => 'Tab Body',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_basic_page_tabs-field_basic_page_tab_label'.
  $field_instances['field_collection_item-field_basic_page_tabs-field_basic_page_tab_label'] = array(
    'bundle' => 'field_basic_page_tabs',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_basic_page_tab_label',
    'label' => 'Tab Label',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_basic_slideshow_images-field_basic_slideshow_caption'.
  $field_instances['field_collection_item-field_basic_slideshow_images-field_basic_slideshow_caption'] = array(
    'bundle' => 'field_basic_slideshow_images',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter some text to give information about the associated image. \'Read More\' links should be included in this area if desired.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_basic_slideshow_caption',
    'label' => 'Image Caption',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_basic_slideshow_images-field_slideshow_image'.
  $field_instances['field_collection_item-field_basic_slideshow_images-field_slideshow_image'] = array(
    'bundle' => 'field_basic_slideshow_images',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_slideshow_image',
    'label' => 'Image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'slideshow',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '1240x460',
      'title_field' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'feed' => 0,
          'http' => 0,
          'https' => 0,
          'public' => 'public',
          'youtube' => 0,
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 'media_default--media_browser_1',
          'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
          'media_internet' => 'media_internet',
          'remote_file' => 0,
          'upload' => 'upload',
          'youtube' => 0,
        ),
      ),
      'type' => 'media_generic',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_basic_slideshow_images-field_slideshow_image_link'.
  $field_instances['field_collection_item-field_basic_slideshow_images-field_slideshow_image_link'] = array(
    'bundle' => 'field_basic_slideshow_images',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter a absolute or relative url that the image will link to. Leave empty for no link on the image.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_slideshow_image_link',
    'label' => 'Image\'s Link',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-basic_block-body'.
  $field_instances['node-basic_block-body'] = array(
    'bundle' => 'basic_block',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => 0,
    'settings' => array(
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 30,
    ),
  );

  // Exported field_instance: 'node-basic_block-field_available_views'.
  $field_instances['node-basic_block-field_available_views'] = array(
    'bundle' => 'basic_block',
    'default_value' => array(
      0 => array(
        'view_select' => 'none',
        'args' => array(
          'arg_1' => '',
          'arg_2' => '',
          'arg_3' => '',
        ),
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => NULL,
        'settings' => array(),
        'type' => 'insert_view_gen_formatter',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_available_views',
    'label' => 'Available Views',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'insert_view_gen',
      'settings' => array(),
      'type' => 'insert_view_gen_widget',
      'weight' => 40,
    ),
  );

  // Exported field_instance:
  // 'node-basic_block-field_basic_block_block_sections'.
  $field_instances['node-basic_block-field_basic_block_block_sections'] = array(
    'bundle' => 'basic_block',
    'default_value' => array(
      0 => array(
        'mlid' => NULL,
      ),
    ),
    'deleted' => 0,
    'description' => 'Select the menu item where this block will live. If the front page is desired, use the checkbox below.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_basic_block_block_sections',
    'label' => 'Block Sections',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'menu_block_placement',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'menu_block_placement_widget',
      'weight' => 20,
    ),
  );

  // Exported field_instance: 'node-basic_page-body'.
  $field_instances['node-basic_page-body'] = array(
    'bundle' => 'basic_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => TRUE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-basic_page-field_available_views'.
  $field_instances['node-basic_page-field_available_views'] = array(
    'bundle' => 'basic_page',
    'default_value' => array(
      0 => array(
        'view_select' => 'none',
        'args' => array(
          'arg_1' => '',
          'arg_2' => '',
          'arg_3' => '',
        ),
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_available_views',
    'label' => 'Available Views',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'insert_view_gen',
      'settings' => array(),
      'type' => 'insert_view_gen_widget',
      'weight' => 5,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'node-basic_page-field_basic_page_tabs'.
  $field_instances['node-basic_page-field_basic_page_tabs'] = array(
    'bundle' => 'basic_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'add' => '',
          'delete' => '',
          'description' => 0,
          'edit' => '',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_basic_page_tabs',
    'label' => 'Tabs',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-basic_page-field_screen_reader_only_title'.
  $field_instances['node-basic_page-field_screen_reader_only_title'] = array(
    'bundle' => 'basic_page',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Select this if you do not want to display the title on the page.  This will make it available for screen readers.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_screen_reader_only_title',
    'label' => 'Screen Reader Only Title',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 2,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance:
  // 'node-basic_slideshow-field_basic_slideshow_assignment'.
  $field_instances['node-basic_slideshow-field_basic_slideshow_assignment'] = array(
    'bundle' => 'basic_slideshow',
    'default_value' => array(
      0 => array(
        'mlid' => NULL,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_basic_slideshow_assignment',
    'label' => 'Slideshow Assignment',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'menu_block_placement',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'menu_block_placement_widget',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'node-basic_slideshow-field_basic_slideshow_effect'.
  $field_instances['node-basic_slideshow-field_basic_slideshow_effect'] = array(
    'bundle' => 'basic_slideshow',
    'default_value' => array(
      0 => array(
        'value' => 'fade',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_basic_slideshow_effect',
    'label' => 'Transition Effect',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'use_select2' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'node-basic_slideshow-field_basic_slideshow_images'.
  $field_instances['node-basic_slideshow-field_basic_slideshow_images'] = array(
    'bundle' => 'basic_slideshow',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Each of these groups acts as a slide in the slideshow. Drag and drop to reorder the slides.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_slideshow',
        'settings' => array(
          'slideshow_caption' => 'field_basic_slideshow_caption',
          'slideshow_caption_link' => '',
          'slideshow_carousel_circular' => 0,
          'slideshow_carousel_follow' => 0,
          'slideshow_carousel_image_style' => '',
          'slideshow_carousel_scroll' => 1,
          'slideshow_carousel_skin' => '',
          'slideshow_carousel_speed' => 500,
          'slideshow_carousel_vertical' => 0,
          'slideshow_carousel_visible' => 3,
          'slideshow_colorbox_image_style' => '',
          'slideshow_colorbox_slideshow' => '',
          'slideshow_colorbox_slideshow_speed' => 4000,
          'slideshow_colorbox_speed' => 350,
          'slideshow_colorbox_transition' => 'elastic',
          'slideshow_content_type' => 'image',
          'slideshow_controls' => 1,
          'slideshow_controls_pause' => 0,
          'slideshow_controls_position' => 'after',
          'slideshow_field_collection_image' => 'field_slideshow_image',
          'slideshow_fx' => 'fade',
          'slideshow_image_style' => 'slideshow_image',
          'slideshow_link' => 'field_slideshow_image_link',
          'slideshow_order' => '',
          'slideshow_pager' => 'number',
          'slideshow_pager_image_style' => '',
          'slideshow_pager_position' => 'after',
          'slideshow_pause' => 1,
          'slideshow_speed' => 2000,
          'slideshow_start_on_hover' => 0,
          'slideshow_timeout' => 10000,
          'slideshow_view_mode' => 'full',
        ),
        'type' => 'slideshow',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_basic_slideshow_images',
    'label' => 'Slideshow Images',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'node-basic_slideshow-field_basic_slideshow_style'.
  $field_instances['node-basic_slideshow-field_basic_slideshow_style'] = array(
    'bundle' => 'basic_slideshow',
    'default_value' => array(
      0 => array(
        'value' => 'basic-slideshow-style-1',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_basic_slideshow_style',
    'label' => 'Style',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'use_select2' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Available Views');
  t('Block Sections');
  t('Body');
  t('Each of these groups acts as a slide in the slideshow. Drag and drop to reorder the slides.');
  t('Enter a absolute or relative url that the image will link to. Leave empty for no link on the image.');
  t('Enter some text to give information about the associated image. \'Read More\' links should be included in this area if desired.');
  t('Image');
  t('Image Caption');
  t('Image\'s Link');
  t('Screen Reader Only Title');
  t('Select the menu item where this block will live. If the front page is desired, use the checkbox below.');
  t('Select this if you do not want to display the title on the page.  This will make it available for screen readers.');
  t('Slideshow Assignment');
  t('Slideshow Images');
  t('Style');
  t('Tab Body');
  t('Tab Label');
  t('Tabs');
  t('Transition Effect');

  return $field_instances;
}
