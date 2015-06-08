<?php /*
$site_slogan = variable_get('site_slogan');
$footer_logo_img = theme_get_setting('logo'); 
*/
?>
<div<?php print $attributes; ?>>
  <div<?php print $content_attributes; ?>>
    <div id="footer-expand" style="clear:both;">
      <nav id="footer-nav" style="margin: 0px; padding: 0px;" class="footer-nav clearfix">
        <section id="footer-info" class="clearfix">


<?php /* if() :?>







<?php /* //////////////////////////////////////////////////////// CONTACT US BLOCK ///////////////////////////////////////////////////////////////////// ?>
<?php if (isset($display_footer_contact)): ?>
<section class="block block-nodeblock block-contact-us block-nodeblock-contact-us odd" id="block-nodeblock-contact-us">
  <div class="block-inner clearfix">
  <?php if ($footer_contact_us_title): ?>
    <?php if ($footer_contact_us_title_link): ?>
    <h2 class="block-title"><a href="<?php echo $footer_contact_us_title_link; ?>"><?php echo $footer_contact_us_title; ?></a></h2>
    <?php else: ?>
    <h2 class="block-title"><?php echo $footer_contact_us_title; ?></h2>
    <?php endif; ?>
  <?php endif; ?>
    <div class="content clearfix">
      <div class="node node-promoted node-lottery-contact-card node-published node-not-sticky odd clearfix" id="node-lottery-contact-card">
        <div class="content clearfix">
          <div class="field-group-format group_address field-group-div group-address  speed-fast effect-none">
            <div class="field-group-format group_column1 field-group-div group-column1 speed-fast effect-none">
  <?php if ($footer_contact_us_lottery1_title): ?>
              <div class="field field-name-field-address-name field-type-text field-label-hidden">
                <div class="field-items">
                  <div class="field-item even"><?php echo $footer_contact_us_lottery1_title; ?></div>
                </div>
              </div>
  <?php endif; ?>
  <?php if ($footer_contact_us_address_1): ?>
              <div class="field field-name-field-address- field-type-text field-label-hidden">
                <div class="field-items">
                  <div class="field-item even"><?php echo $footer_contact_us_address_1; ?></div>
                </div>
              </div>
  <?php endif; ?>
  <?php if ($footer_contact_us_address_2): ?>
              <div class="field field-name-field-address-line-2 field-type-text field-label-hidden">
                <div class="field-items">
                  <div class="field-item even"><?php echo $footer_contact_us_address_2; ?></div>
                </div>
              </div>
  <?php endif; ?>
  <?php if ($footer_contact_us_map_link): ?>
              <div class="field field-name-field-google-maps-link field-type-link-field field-label-hidden">
                <div class="field-items">
                  <div class="field-item even"><a href="<?php echo $footer_contact_us_map_link; ?>" target="_blank">View in Google Maps</a></div>
                </div>
              </div>
  <?php endif; ?>
            </div>
            <div class="field-group-format field-group-div group_column2 speed-fast effect-none">
  <?php if ($footer_contact_us_phone): ?>
              <div class="field field-name-field-phone-number field-type-text field-label-inline clearfix">
                <div class="field-label">phone:&nbsp;</div>
                <div class="field-items">
                  <div class="field-item even"><?php echo $footer_contact_us_phone; ?></div>
                </div>
              </div>
  <?php endif; ?>
  <?php if ($footer_contact_us_fax): ?>
              <div class="field field-name-field-fax field-type-text field-label-inline clearfix">
                <div class="field-label">fax:&nbsp;</div>
                <div class="field-items">
                  <div class="field-item even"><?php echo $footer_contact_us_fax; ?></div>
                </div>
              </div>
  <?php endif; ?>
            </div>
          </div>
  <?php if($footer_contact_us_map_path): ?>
          <div class="field field-name-field-map-image field-type-image field-label-hidden">
            <div class="field-items">
    <?php if($footer_contact_us_map_link): ?>
              <div class="field-item even"><a href="<?php echo $footer_contact_us_map_link; ?>" target="_blank"><img src="<?php echo $footer_contact_us_map_path; ?>" alt="" /></a></div>
    <?php else: ?>
              <div class="field-item even"><img src="<?php echo $footer_contact_us_map_path; ?>" alt="" /></div>
    <?php endif; ?>
            </div>
          </div>
  <?php endif; ?>
        </div>
      </div>
    </div>
  </div>
</section>
<?php endif; */ ?>
<?php //////////////////////////////////////////////////////  END CONTACT US CARD ////////////////////////////////////////////////////////////////////////////////// ?>

          <?php print $content; ?>
        </section>
	<?php /*
        <div id="footer-tab-icon">
          <img id="footer-tab" alt="Expand Footer" src="<?php print '/' . drupal_get_path('theme', 'lottery_1') . '/img/icons/icon-tab-plus.png'; ?>" style="display: block; height:21px;">
        </div>
	*/
	?>
        <!--section id="footer-menu" class="clearfix">
          <div class="footer-menu-wrapper">
            <div id="footer-nav-wrapper">
              <?php //print render($footer_menu); ?>
            </div>
            <div id="follow-wrapper">
              <?php
                $block = module_invoke('follow', 'block_view', 0);
                //print $block['content'];
              ?>
            </div>
            <br class="clearfix" />
          </div>
        </section-->

      </nav>
    </div>
  </div>   
</div>
