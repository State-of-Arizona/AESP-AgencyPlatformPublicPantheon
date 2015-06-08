(function ($) {
  Drupal.behaviors.moderngov = {
    attach: function (context, settings) {

      $('.menu-block-wrapper ul.menu li.expanded').once(function () {
        $(this).find('ul').hide();
        $(this).prepend('<span class="glyphicon glyphicon-chevron-right"/>');
        $(this).find('.glyphicon').click(function () {
          $(this).siblings('ul').slideToggle('slow');
          $(this).toggleClass('glyphicon-chevron-down');
          $(this).toggleClass('glyphicon-chevron-right');
        });
      });

    }
  }
})(jQuery);