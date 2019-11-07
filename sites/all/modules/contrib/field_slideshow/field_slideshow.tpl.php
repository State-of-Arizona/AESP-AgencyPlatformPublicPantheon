<?php
/**
 * @file
 * Template file for field_slideshow
 *
 *
 */

// Should fix issue #1502772
// @todo: find a nicer way to fix this
if (!isset($controls_position)) {
  $controls_position = "after";
}
if (!isset($pager_position)) {
  $pager_position = "after";
}
?>
<div id="field-slideshow-<?php print $slideshow_id; ?>-wrapper" class="field-slideshow-wrapper">
  <?php if ($controls_position == "before")  print(render($controls)); ?>
  <?php if ($pager_position == "before")  print(render($pager)); ?>

  <div class="<?php print $classes; ?>">
    <?php foreach ($items as $num => $item) : ?>
      <div class="<?php print $item['classes']; ?>"<?php if ($num) : ?> style="display:none;"<?php endif; ?>>
        <?php print (empty($item['image']) ? render($item['rendered_entity']) : $item['image']); ?>
        <?php if (isset($item['caption']) && $item['caption'] != '') : ?>
          <div class="field-slideshow-caption">
            <span class="field-slideshow-caption-text"><?php print $item['caption']; ?></span>
          </div>
        <?php endif; ?>
      </div>
    <?php endforeach; ?>
  </div>

  <?php if ($controls_position != "before") print(render($controls)); ?>
  <?php if ($pager_position != "before") print(render($pager)); ?>
</div>
