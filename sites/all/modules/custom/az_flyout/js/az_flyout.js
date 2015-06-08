(function ($) {
  Drupal.behaviors.azflyout = {
    attach: function (context, settings) {
      $('#slide-nav li.expanded').once(function () {
        $(this).prepend('<i class="fa fa-chevron-circle-left"></i>');
        $(this).children('ul').hide();
        $(this).find('i').click(function () {
          $(this).parent().siblings().slideToggle('slow');
          $(this).siblings('ul').toggle('slow');
          $(this).toggleClass('fa-chevron-circle-left');
          $(this).toggleClass('fa-chevron-circle-down');
        });
      });
      if (Drupal.settings.azflyout.hidemain) {
        $('.region-menu').addClass('hide-mobile');
      }

      $('#top-nav').find('.fa-bars').once(function () {
        $(this).click(function () {
          $('#slide-nav').toggle('slide');
        });
      });

      $('.close-slide-nav').once(function () {
        $(this).click(function () {
          $('#slide-nav').toggle('slide');
        })
      });

      var scrolled = function () {
        if ($('#top-nav').length > 0) {
          if ($('#top-nav').hasClass('desktop-and-mobile')) {
            if ($(window).width() > 768) {
              if (-$('#top-nav').height() + $(window).scrollTop() < 0) {
                $('#top-nav').css('top', -$('#top-nav').height() + $(window).scrollTop());
                $('#slide-nav').css('height', $(window).height() - ($('#top-nav').position().top + $('#top-nav').height()) / 2).css('top', $('#top-nav').position().top + $('#top-nav').height());
                $('.region-menu.hide-mobile').show('slow');
              } else {
                $('#top-nav').css('top', 0);
                $('#slide-nav').css('height', $(window).height() - $('#top-nav').height()).css('top', $('#top-nav').position().top + $('#top-nav').height());
                $('.region-menu.hide-mobile').hide('slow');
              }
            } else {
              $('.region-menu.hide-mobile').hide('slow');
              if ($('.sliver-container').height() - $(window).scrollTop() < 0) {
                $('#top-nav').css('top', Math.abs($('.sliver-container').height() - $(window).scrollTop()));
                $('#slide-nav').css('top', $('#top-nav').height() - 1);
              } else {
                $('#top-nav').css('top', '');
                $('#slide-nav').css('top', $('#top-nav').position().top + $('#top-nav').height() - $(window).scrollTop());
              }
              $('#slide-nav').height($(window).height() - parseInt($('#slide-nav').css('top')));
            }
          } else {
            if ($(window).width() <= 768) {
              $('.region-menu.hide-mobile').hide('slow');
              if ($('.sliver-container').height() - $(window).scrollTop() < 0) {
                $('#top-nav').css('top', Math.abs($('.sliver-container').height() - $(window).scrollTop()));
                $('#slide-nav').css('top', $('#top-nav').height() - 1);
              } else {
                $('#top-nav').css('top', '');
                $('#slide-nav').css('top', $('#top-nav').position().top + $('#top-nav').height() - $(window).scrollTop());
              }
              $('#slide-nav').height($(window).height() - parseInt($('#slide-nav').css('top')));
            } else {
              $('#top-nav').hide();
            }
          }
        }
      };
      scrolled();
      $(window).scroll(function () {
        scrolled();
      });
      $(window).resize(function () {
        scrolled();
      });
    }
  }
})(jQuery);