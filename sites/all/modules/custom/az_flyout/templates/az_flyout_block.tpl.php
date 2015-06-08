<div id="top-nav" class="<?php print $displays ?>">
  <div class="wrapper clearfix">
    <div class="fa fa-bars" title="Open Side Menu"></div>

    <?php if (isset($image) && $image): ?>
      <div class="logo">
        <a href="/">
          <img src="<?php print $image; ?>" alt="Top Image Logo"/>
        </a>
      </div>
    <?php else: ?>
      <div class="site-name">
        <h2>
          <a href="/">
            <?php print variable_get('site_name'); ?>
          </a>
        </h2>
      </div>
    <?php endif; ?>
    <div class="top-menu">
      <?php print render($header); ?>
    </div>
  </div>
</div>
<div id="slide-nav">
  <div class="close-slide-nav fa fa-times-circle-o">

  </div>
  <div class="slide-nav-menu">
    <?php print render($menu); ?>
  </div>
  <div class="contact-info">
    <?php if (isset($contact_title) && $contact_title): ?>
      <?php if (isset($contact_title_link) && $contact_title_link): ?>
        <h3 class="contact-title">
          <a href="<?php print $contact_title_link; ?>"><?php print $contact_title; ?></a>
        </h3>
      <?php else: ?>
        <h3 class="contact-title">
          <?php print $contact_title; ?>
        </h3>
      <?php endif; ?>
    <?php endif; ?>
    <?php if (isset($contact_name) && $contact_name): ?>
      <div class="agency-name">
        <?php print $contact_name; ?>
      </div>
    <?php endif; ?>
    <?php if (isset($contact_address1) && $contact_address1): ?>
      <div class="agency-address1">
        <?php print $contact_address1; ?>
      </div>
    <?php endif; ?>
    <?php if (isset($contact_address2) && $contact_address2): ?>
      <div class="agency-address2">
        <?php print $contact_address2; ?>
      </div>
    <?php endif; ?>
    <?php if (isset($contact_phone) && $contact_phone): ?>
      <div class="agency-phone">
        Phone: <?php print $contact_phone; ?>
      </div>
    <?php endif; ?>
    <?php if (isset($contact_fax) && $contact_fax): ?>
      <div class="agency-fax">
        Fax: <?php print $contact_fax; ?>
      </div>
    <?php endif; ?>
    <?php if (isset($contact_map_link) && $contact_map_link): ?>
      <div class="contact-map-link">
        <a href="<?php print $contact_map_link; ?>">View in Google Maps</a>
      </div>
    <?php endif; ?>

    <?php if (isset($contact_map_image) && $contact_map_image): ?>
      <?php if (isset($contact_map_link) && $contact_map_link): ?>
        <div class="contact-map">
          <a href="<?php print $contact_map_link; ?>">
            <img src="<?php print $contact_map_image; ?>" alt="Map Image"/>
          </a>
        </div>
      <?php else: ?>
        <div class="contact-map">
          <img src="<?php print $contact_map; ?>" alt="Map Image"/>
        </div>
      <?php endif; ?>
    <?php endif; ?>
  </div>
</div>