<div id="zone-footer" class="zone">
  <?php if ($page['footer_first']): ?>
    <div id="footer-first">
      <?php print render($page['footer_first']); ?>
    </div>
  <?php endif; ?>
  <?php if ($footer_settings['show branding'] || $footer_settings['show contact']) : ?>
    <?php include_once('footer-contact.inc'); ?>
  <?php endif; ?>
  <?php if ($page['footer_second']) : ?>
    <div id="region-footer-second">
      <?php print render($page['footer_second']); ?>
    </div>
  <?php endif; ?>
</div>