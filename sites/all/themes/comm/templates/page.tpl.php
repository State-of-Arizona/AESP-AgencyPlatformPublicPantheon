<?php
/**
 * @file
 * Alpha's theme implementation to display a single Drupal page.
 */
/**
drupal_add_js(drupal_get_path('theme', 'lottery_1') . '/js/lottery.js');
 */
$element = array(
  '#tag' => 'meta', // The #tag is the html tag - <link />
  '#attributes' => array( // Set up an array of attributes inside the tag
    'name' => 'format-detection',
    'content' => 'telephone=no'
  ),
);
drupal_add_html_head($element, 'disable_meta');
$element = array(
  '#tag' => 'meta', // The #tag is the html tag - <link />
  '#attributes' => array( // Set up an array of attributes inside the tag
    'http-equiv' => 'X-UA-Compatible',
    'content' => 'IE=edge'
  ),
);
drupal_add_html_head($element, 'ie_meta');

drupal_add_js(drupal_get_path('theme', 'comm') . '/js/jquery.bxslider.min.js');
drupal_add_css(drupal_get_path('theme', 'comm') . '/css/jquery.bxslider.css');

if ($is_front) {
  drupal_set_title($site_name);
}

?>

<div<?php print $attributes; ?>>
  <?php if (isset($page['header'])) : ?>
    <?php if (theme_get_setting('show_sliver')) : ?>
      <script src="https://static.az.gov/sliver/sliver.js" type="text/javascript"></script>
    <?php endif; ?>
<?php print render($page['user_second']); ?>

<?php ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////// ?>

<?php ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////// ?>
    <?php print render($page['header']); ?>
  <?php endif; ?>

  <?php if (isset($page['content'])) : ?>
    <?php print render($page['content']); ?>
  <?php endif; ?>

  <?php if (isset($page['footer'])) : ?>
    <?php print render($page['footer']); ?>
  <?php endif; ?>
</div>

<script type="text/javascript">
    jQuery(document).ready(function (){
        jQuery('.view-home-page-feature-rotator ul').bxSlider({
            auto: true,
            pause: 6000,
            pager: false,
            responsive: true,
            touchEnabled: true,
            slideWidth: 960,
            useCSS: false
        });
    });
</script>
