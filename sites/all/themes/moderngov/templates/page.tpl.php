<?php 
/**
 * @file
 * Alpha's theme implementation to display a single Drupal page.
 */
/**
drupal_add_js(drupal_get_path('theme', 'agency_1') . '/js/agency.js');
 */
if ($is_front) {
  drupal_set_title($site_name);
}
?>

<div<?php print $attributes; ?>>
  <?php if (isset($page['header'])) : ?>
    <?php if (theme_get_setting('show_sliver')) : ?>
      <script src="https://static.az.gov/sliver/sliver.js" type="text/javascript"></script>
    <?php endif; ?>


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




