(function ($) {
  Drupal.behaviors.wysiwygaccordion = {
    attach: function (context, settings) {
      $('.accordion-content').once(function () {
        var content = this;
        var clickable;

        $(this).siblings(':header').once(function () {
          if ($(this).siblings('.read-more').length > 0) {
            clickable = $(this).siblings('.read-more');
          } else {
            clickable = this;
          }
        });

        $(content).hide();
        $(clickable).prepend('<span class="glyphicon-chevron-right glyphicon" />');
        $(clickable).addClass('accordion-clicker');
        $(clickable).click(function () {
          $(this).toggleClass('open');
          $(this).children('.glyphicon').toggleClass('glyphicon-chevron-right');
          $(this).children('.glyphicon').toggleClass('glyphicon-chevron-down');
          $(this).siblings('.accordion-content').slideToggle('slow');


          if ($(this).hasClass('read-more') && $(this).hasClass('open')) {
            $(this).html('<span class="glyphicon-chevron-down glyphicon" />Close');
          } else if ($(this).hasClass('read-more')) {
            $(this).html('<span class="glyphicon-chevron-right glyphicon" />Read More');
          }
        });
      });
    }
  }
})(jQuery);
