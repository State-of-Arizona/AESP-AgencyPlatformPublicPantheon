<div id="zone-content" class="zone">
  <a name="main-content"></a>


  <div id="preface-group" class="clearfix">
    <?php if ($page['preface_first']) : ?>
      <div id="region-preface-first" class="<?php echo $preface_first; ?> preface">
        <?php print render($page['preface_first']); ?>
      </div>
    <?php endif; ?>
    <?php if ($page['preface_second']) : ?>
      <div id="region-preface-second" class="<?php echo $preface_second; ?> preface">
        <?php print render($page['preface_second']); ?>
      </div>
    <?php endif; ?>
    <?php if ($page['preface_third']) : ?>
      <div id="region-preface-third" class="<?php echo $preface_third; ?> preface">
        <?php print render($page['preface_third']); ?>
      </div>
    <?php endif; ?>
  </div>

  <?php if ($messages): ?>
    <div id="messages">
      <?php print render($messages); ?>
    </div>
  <?php endif; ?>

  <div id="content-wrapper" class="clearfix">


    <?php if ($page['sidebar_first']) : ?>
      <aside id="sidebar-first" class="col-sm-3 col-md-2 main-region">
        <?php print render($page['sidebar_first']); ?>
      </aside>
    <?php endif; ?>


    <div id="content" class="<?php echo $content_class; ?> main-region contextual-links-region ">
      <div id="region-content" class="content">

        <h1 id="page-title">
          <?php print $title; ?>
        </h1>

        <?php print render($title_suffix); ?>

        <?php if ($tabs = render($tabs)): ?>
          <div class="tabs"><?php print $tabs; ?></div>
        <?php endif; ?>
        <?php print render($page['content']); ?>

      </div>
    </div>


    <?php if ($page['sidebar_second']) : ?>
      <aside id="sidebar-second" class="col-sm-4 col-md-4 main-region">
        <?php print render($page['sidebar_second']); ?>
      </aside>
    <?php endif; ?>
  </div>

  <div id="postscript-group" class="<?php print $postscript_num; ?> clearfix">
    <?php if ($page['postscript_first']) : ?>
      <div id="region-postscript-first" class="<?php echo $postscript; ?> postscript">
        <?php print render($page['postscript_first']); ?>
      </div>
    <?php endif; ?>
    <?php if ($page['postscript_second']) : ?>
      <div id="region-postscript-second" class="<?php echo $postscript; ?> postscript">
        <?php print render($page['postscript_second']); ?>
      </div>
    <?php endif; ?>
    <?php if ($page['postscript_third']) : ?>
      <div id="region-postscript-third" class="<?php echo $postscript; ?> postscript">
        <?php print render($page['postscript_third']); ?>
      </div>
    <?php endif; ?>
    <?php if ($page['postscript_fourth']) : ?>
      <div id="region-postscript-fourth" class="<?php echo $postscript; ?> postscript">
        <?php print render($page['postscript_fourth']); ?>
      </div>
    <?php endif; ?>
  </div>

</div>