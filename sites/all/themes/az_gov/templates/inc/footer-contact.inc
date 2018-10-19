<div id="footer-first-contact" class="clearfix ">
  <?php if ($footer_settings['show branding']): ?>
    <div id="footer-branding" class="content clearfix">
      <div class="footer-wrapper">
        <?php if ($logo): ?>
          <img src="<?php echo $logo; ?>" alt="<?php echo $persistent_site_name; ?> Logo">
        <?php endif; ?>
        <div class="site-info">
          <div class="site-name footer-field">
            <?php echo $site_name; ?>
          </div>
          <div class="site-slogan footer-field">
            <?php echo $site_slogan; ?>
          </div>
        </div>
      </div>
    </div>
  <?php endif; ?>
<!--  <div id="footer-spacer"></div>-->
  <?php if ($footer_settings['show contact']): ?>
    <div id="footer-contact">

      <?php if ($footer_settings['title link'] && $footer_settings['title']) : ?>
        <div class="footer-title footer-field">
          <a href="<?php echo $footer_settings['title link']; ?>">
            <?php echo $footer_settings['title']; ?>
          </a>
        </div>
      <?php elseif ($footer_settings['title']) : ?>
        <div class="footer-title footer-field">
          <?php echo $footer_settings['title']; ?>
        </div>
      <?php endif; ?>


      <div class="footer-info clearfix">
        <div class="footer-address clearfix">
          <div class="footer-address-group footer-group">

            <?php if ($footer_settings['agency']): ?>
              <div class="footer-agency footer-field">
                <?php echo $footer_settings['agency']; ?>
              </div>
            <?php endif; ?>

            <?php if ($footer_settings['address 1']): ?>
              <div class="footer-address-1 footer-field">
                <?php echo $footer_settings['address 1']; ?>
              </div>
            <?php endif; ?>

            <?php if ($footer_settings['address 2']): ?>
              <div class="footer-address-2 footer-field">
                <?php echo $footer_settings['address 2']; ?>
              </div>
            <?php endif; ?>

            <?php if ($footer_settings['map link']): ?>
              <div class="footer-map-link footer-field">
                <a href="<?php echo $footer_settings['map link']; ?>">
                  Find in Google Maps
                </a>
              </div>
            <?php endif; ?>

          </div>
          <div class="footer-phone-group footer-group">

            <?php if ($footer_settings['phone']): ?>
              <div class="footer-phone footer-field">
                <strong>Phone: </strong><?php echo $footer_settings['phone']; ?>
              </div>
            <?php endif; ?>

            <?php if ($footer_settings['fax']): ?>
              <div class="footer-fax footer-field">
                <strong>Fax: </strong><?php echo $footer_settings['fax']; ?>
              </div>
            <?php endif; ?>

          </div>
        </div>

        <?php if ($footer_settings['map link'] && isset($footer_settings['map'])): ?>
          <div class="footer-map  footer-group">
            <a href="<?php echo $footer_settings['map link']; ?>">
              <img src="<?php echo $footer_settings['map']; ?>" alt="Map Image">
            </a>
          </div>
        <?php elseif (isset($footer_settings['map'])): ?>
          <div class="footer-map footer-field">
            <img src="<?php echo $footer_settings['map']; ?>" alt="Map Image">
          </div>
        <?php endif; ?>

      </div>
    </div>
  <?php endif; ?>
</div>