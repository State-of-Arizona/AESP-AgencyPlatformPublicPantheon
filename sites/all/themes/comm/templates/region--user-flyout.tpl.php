<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
	<img src="/<?php print(drupal_get_path('theme', 'comm') . '/img/button-close.png'); ?>" alt="Close Button" title="Close Side Menu" class="close" />
  <div class="content"<?php print $content_attributes; ?>>
    <?php print $content; ?>
  </div>
  
  <div class="locations">
  	<div class="contact-us">
	    <?php if($display_flyout_contact):?>
				<?php if ($flyout_contact_title): ?>
					<?php if ($flyout_contact_title_link): ?>
						
						<?php if(substr($flyout_contact_title_link, 0, 4)=="http" || substr($flyout_contact_title_link, 0, 1)=="/"): ?>
							<h2 class="contact-title"><a href="<?php print $flyout_contact_title_link; ?>"><?php print $flyout_contact_title; ?></a></h2>
						<?php else: ?>
							<h2 class="contact-title"><a href="<?php print "/" . $flyout_contact_title_link; ?>"><?php print $flyout_contact_title; ?></a></h2>
						<?php endif; ?>
						
					<?php else: ?>
						<h2 class="contact-title"><?php print $flyout_contact_title; ?></h2>
					<?php endif; ?>
				<?php endif; ?>
				
				<div class="flyout-address-group">
					<?php if($flyout_contact_comm_title): ?>
						<h3 class="contact-comm-title"><?php print $flyout_contact_comm_title ?></h3>
					<?php endif; ?>
				
					<?php if ($flyout_contact_address_1): ?>
						<div class="contact-address-1"><?php print $flyout_contact_address_1; ?></div>
					<?php endif; ?>
					
					<?php if ($flyout_contact_address_2): ?>
						<div class="contact-address-2"><?php print $flyout_contact_address_2; ?></div>
					<?php endif; ?>
					
					<?php if ($flyout_contact_phone): ?>
						<div class="contact-phone">Phone: <?php print $flyout_contact_phone; ?></div>
					<?php endif; ?>
					
					<?php if ($flyout_contact_fax): ?>
						<div class="contact-fax">Fax: <?php print $flyout_contact_fax; ?></div>
					<?php endif; ?>
				</div>
				
				<?php if ($flyout_contact_map_link ): ?>
					<div class="contact-map-link"><a href="<?php print $flyout_contact_map_link; ?>">View in Google Maps</a></div>
				<?php endif; ?>
				
				<?php if ($flyout_contact_map_path ): ?>
					<?php if ($flyout_contact_map_link ): ?>
						<div align="center" class="contact-map-image"><a href="<?php print $flyout_contact_map_link; ?>"><img alt="Image for contact reference" src="<?php print $flyout_contact_map_path; ?>"></a></div>
					<?php endif; ?>
					<?php else: ?>
						<?php if($flyout_contact_map_image): ?>
							<div align="center" class="contact-map-image"><img alt="Image for contact reference" src="<?php print $flyout_contact_map_image; ?>"></div>
						<?php endif; ?>
				<?php endif; ?>
			</div>
		<?php endif; ?>
  </div>
</div>
