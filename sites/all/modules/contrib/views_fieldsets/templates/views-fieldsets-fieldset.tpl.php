
<fieldset class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <legend>
    <span class="fieldset-legend"><?php print $legend; ?></span>
  </legend>

  <div class="fieldset-wrapper">
    <?php foreach ($fieldset_fields as $name => $field): ?>
      <?php print @$field->separator . $field->wrapper_prefix . $field->label_html . $field->content . $field->wrapper_suffix; ?>
    <?php endforeach; ?>
  </div>

</fieldset>
