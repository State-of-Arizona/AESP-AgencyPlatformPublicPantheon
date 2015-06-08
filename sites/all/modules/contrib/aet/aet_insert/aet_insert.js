(function($) {
  Drupal.behaviors.aet_insert = {
    attach: function(context, settings) {
      Drupal.aet_insert.settings = settings.aet_insert;
      Drupal.aet_insert.fields = $('.aet_insert_field');
      $('.aet_insert_field select').change(function() {
        var $this = $(this);
        var $aet_insert_field = $($this.parents('.aet_insert_field'));
        Drupal.aet_insert.disable($aet_insert_field);
        $.ajax({
          url: Drupal.aet_insert.settings.ajax_path,
          data: {
            id: $aet_insert_field.attr('id'),
            target: $aet_insert_field.data('target'),
            entity_type: $aet_insert_field.data('entity-type'),
            entity_id: $aet_insert_field.data('entity-id'),
            data: Drupal.aet_insert.getData($aet_insert_field, $this),
          },
          context: $aet_insert_field,
          error: function() {
            Drupal.aet_insert.enable(this);
          },
          success: function(data, textStatus, XMLHttpRequest) {
            Drupal.aet_insert.enable(this);
            this.replaceWith(data);
            Drupal.behaviors.aet_insert.attach(Drupal.aet_insert.context,
              {aet_insert: Drupal.aet_insert.settings});
          },
        });
      });

      $('.aet_insert_field .aet-insert-button').click(function(event) {
        event.preventDefault();
        var $this = $(this);
        var $aet_insert_field = $($this.parent());
        var data = Drupal.aet_insert.getData($aet_insert_field, $this);
        var token = '[';
        if (data[0] === 'active_user') {
          token += 'user';
        }
        else if (data[0].indexOf('this_') === 0) {
          token += data[0].slice('this_'.length);
        }
        else {
          token += 'aet:' + data[0].slice('aet_'.length);
        }
        data.shift();

        for (i in data) {
          if (data[i].length > 0) {
            token += ':' + data[i];
          }
        }
        token += ']';
        Drupal.aet_insert.insertAtCaret($aet_insert_field.data('target'), token);
      });
    }
  };

  Drupal.aet_insert = {
    settings: {},
    fields: null,
  };

  Drupal.aet_insert.insertAtCaret = function(areaId,text) {
    var txtarea = document.getElementById(areaId);
    var scrollPos = txtarea.scrollTop;
    var strPos = 0;
    var br = ((txtarea.selectionStart || txtarea.selectionStart == '0') ?
        "ff" : (document.selection ? "ie" : false ) );
    if (br == "ie") {
        txtarea.focus();
        var range = document.selection.createRange();
        range.moveStart ('character', -txtarea.value.length);
        strPos = range.text.length;
    }
    else if (br == "ff") strPos = txtarea.selectionStart;

    var front = (txtarea.value).substring(0,strPos);
    var back = (txtarea.value).substring(strPos,txtarea.value.length);
    txtarea.value=front+text+back;
    strPos = strPos + text.length;
    if (br == "ie") {
        txtarea.focus();
        var range = document.selection.createRange();
        range.moveStart ('character', -txtarea.value.length);
        range.moveStart ('character', strPos);
        range.moveEnd ('character', 0);
        range.select();
    }
    else if (br == "ff") {
        txtarea.selectionStart = strPos;
        txtarea.selectionEnd = strPos;
        txtarea.focus();
    }
    txtarea.scrollTop = scrollPos;
  };

  Drupal.aet_insert.getData = function($target, $selector) {
    var data = [];
    var children = $target.children('.form-item');
    for (var i=0; i< children.length; i++) {
      $child = $(children[i]);
      $child_selector = $child.find('select');
      data[i] = $child_selector.find(':selected').attr('value');
      if ($child_selector[0] === $selector[0]) {
        break;
      }
    }

    return data;
  };

  Drupal.aet_insert.disable = function($target) {
    $target.find('select').attr('disabled', 'disabled');
  };

  Drupal.aet_insert.enable = function($target) {
    $target.find('select').removeAttr('disabled');
  };
})(jQuery);