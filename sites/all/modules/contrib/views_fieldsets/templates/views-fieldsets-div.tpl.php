
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php foreach ($fieldset_fields as $name => $field): ?>
    <?php print @$field->separator . $field->wrapper_prefix . $field->label_html . $field->content . $field->wrapper_suffix; ?>
  <?php endforeach; ?>

</div>
