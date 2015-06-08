(function ($) {
  Drupal.behaviors.test = {
    attach: function (context, settings) {
      var gen_code = function () {
        var args = '';
        var view = $('.field-type-insert-view-generator select').val();
        if (view != 'none') {
          if ($('.form-item-include-args input').is(":checked")) {
            $('.field-type-insert-view-generator .form-wrapper input').each(function () {
              if ($(this).val() != '') {
                args = args.concat('/').concat($(this).val());
              }
            });
            if (args.length != 0) {
              args = args.substr(1);
              args = '='.concat(args);
            }
          }
          var code = '[view:'.concat(view).concat(args).concat(']');

          $('.insert-view-gen-code').html(code);
          $('.insert-view-code').show('slow');
        }
        else {
          $('.insert-view-code').hide('slow');
        }
      };

      gen_code();
      $('.field-type-insert-view-generator select, .form-item-include-args input').change(function () {
        gen_code();
      });
      $('.field-type-insert-view-generator .form-wrapper input').keyup(function () {
        gen_code();
      });

    }
  }
})(jQuery);
