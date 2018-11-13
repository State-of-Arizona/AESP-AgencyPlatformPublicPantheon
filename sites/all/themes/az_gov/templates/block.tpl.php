<?php $tag = $block->subject ? 'section' : 'div'; ?>

<?php
  //checks for block title if there is one uses that for the aria-label for screen accessibility"
  $aria_label = empty($block->subject) ? $block_html_id : $block->subject;
?>

<<?php print $tag; ?> id="<?php echo $block_html_id; ?>"  class="<?php echo $classes; ?><?php if(!empty($block->css_class)){ print $block->css_class; }?>" aria-label="<?php echo $aria_label; ?>">
<div class="block-inner clearfix">
  <?php print render($title_prefix); ?>
  <?php if ($block->subject): ?>
    <h2<?php print $title_attributes; ?>><?php print $block->subject; ?></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <div class="content" <?php print $content_attributes; ?>>
    <?php print $content ?>

  </div>
</div>
</<?php print $tag; ?>>
