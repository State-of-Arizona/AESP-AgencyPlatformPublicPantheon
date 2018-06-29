<?php if ($page['user_first'] || $page['user_second']): ?>
  <div id="zone-users" class="zone">

    <?php if ($page['user_first']) : ?>
      <?php print render($page['user_first']); ?>
    <?php endif; ?>

    <?php if ($page['user_second']) : ?>
      <?php print render($page['user_second']); ?>
    <?php endif; ?>

  </div>
<?php endif; ?>
