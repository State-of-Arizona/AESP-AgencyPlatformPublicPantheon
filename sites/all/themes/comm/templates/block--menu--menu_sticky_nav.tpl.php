<?php
if ($sticky_nav_mobile == 1) {
  $sticky_mobile = 'sticky-only-mobile ';
}
else {
  $sticky_mobile = 'sticky-desktop-mobile ';
}
?>
<div id="sticky-nav-spacer"></div>

<div id="sticky_nav" class="<?php echo $sticky_mobile; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
 
	<div class="wrapper content"<?php print $content_attributes; ?>>
		<div id="sticky-controls">
			<img src="/<?php echo(drupal_get_path('theme', 'comm') . '/img/button-menu.png'); ?>" alt="Open Side Menu" title="Open Side Menu" class="button" />
			
			<?php if ($use_sticky_logo): ?>
			<?php if ($sticky_logo) :?>
			<a href="/"><img alt="<?php print $site_name; ?>" class='logo' src='<?php print $sticky_logo; ?>' /> </a>
			<?php endif; ?>
			<?php else: ?>
			<a class='logo' href="/"><?php print $site_name; ?></a>
			<?php endif; ?> 
		</div>
			<div id="sticky_nav_menu_wrapper">
			<?php print $content; ?>
		</div>
	</div>
</div>
