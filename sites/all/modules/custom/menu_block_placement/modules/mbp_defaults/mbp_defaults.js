/**
 * @file
 * Configures newly created contextual links to work with quicktabs.
 */

(function ($) {
  Drupal.behaviors.quicktabsContextual = {
    attach: function (context, settings) {
      $('a.quicktabs-contextual', context).once('init-quicktabs-contextual-processed').click(function () {
        var rel = $(this).attr('rel');
        $('#' + rel).click();
        return false;
      });

      $('.block-mbp-defaults').find('ul.quicktabs-tabs').hide();
    }
  }
})(jQuery);
