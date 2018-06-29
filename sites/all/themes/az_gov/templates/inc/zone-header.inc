<?php if ($page['header_first'] || $page['header_second'] || $page['help']): ?>
  <div id="zone-header" class="zone" role="navigation" aria-labelledby="zone-header">
    <?php if ($page['header_first']) : ?>
      <?php print render($page['header_first']); ?>
    <?php endif; ?>
    <?php if ($page['header_second']) : ?>
      <?php print render($page['header_second']); ?>
    <?php endif; ?>
    <?php if ($page['help']) : ?>
      <?php print render($page['help']); ?>
    <?php endif; ?>
  </div>
<?php endif; ?>
