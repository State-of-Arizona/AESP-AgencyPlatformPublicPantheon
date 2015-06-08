    <section class="clearfix">

    </section>
    <section id="footer-branding" class="clearfix">
      <?php if ($footer_logo) : ?> 
        <div id="footer-logo"><img class='footer-logo-image' src='<?php print $footer_logo; ?>' /></div>
      <?php endif; ?>
      <div id="footer-text">
      <?php if ($site_name) : ?>
        <div class = 'footer-site-name'><?php print $site_name ?></div>
      <?php endif; ?>
      <?php if ($site_slogan) : ?>
        <div class = 'footer-site-slogan'><?php print $site_slogan ?></div>
      <?php endif; ?>
      </div>
    </section>
