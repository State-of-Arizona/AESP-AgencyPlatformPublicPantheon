<div id="zone-footer" class="zone" role="contentinfo" aria-labelledby="footer-first">
    <?php if ($page['footer_first']): ?>
        <div id="footer-first">
            <?php print render($page['footer_first']); ?>
        </div>
    <?php endif; ?>

    <?php include_once('footer-contact.inc'); ?>

    <?php if ($page['footer_second']) : ?>
        <div id="region-footer-second">
            <?php print render($page['footer_second']); ?>
        </div>
    <?php endif; ?>
</div>
