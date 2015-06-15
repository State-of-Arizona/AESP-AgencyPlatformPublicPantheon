(function ($) {
  Drupal.behaviors.azgov = {
    attach: function (context, settings) {
      // Surrounds image with link if one exists
      $('.media .file-image > a').once(function () {
        if ($(this).attr('href') != "") {
          $(this).parent().wrap('<a>');
          var link = $(this).parent().parent();
          $(this.attributes).each(function () {
            $(link).attr(this.nodeName, this.value);
          });
          $(this).remove();
        }
      });


      $('.quicktabs-tabpage').addClass('clearfix');

      //adds a class to any email input form
      $('input.email').addClass('form-control');

      //Moves image attributes to the container
      $('.media').once(function () {
        var self = this;
        $(this).find('.file-image img').once(function () {
          $(self).attr('style', $(this).attr('style'));
        });
      });

      $(window).load(function () {
        //Fix basic slideshow heights
        var slideshow_heights = function () {
          if ($('.node-basic-slideshow .field-slideshow-slide').length > 1) {
            $('.node-basic-slideshow .field-slideshow-caption').css('max-height', $($('.node-basic-slideshow .field-slideshow-image')[0]).height() - 40);
          } else {
            $('.node-basic-slideshow .field-slideshow-caption').css('max-height', $($('.node-basic-slideshow .field-slideshow-image')[0]).height() - 20);
          }
          $('.node-basic-slideshow .field-slideshow').css('min-height', $('.node-basic-slideshow .field-slideshow img').height());
        };
        //invokes the slideshow height match function above
        slideshow_heights();
        $(window).resize(function () {
          slideshow_heights();
        });
      });

      //expandable page node
      $('.node-expandable-page .field-name-field-expandable-page-text').once(function () {
        $(this).hide();
        $(this).siblings('.field-name-field-expandable-page-link-label').click(function () {
          $(this).siblings('.field-name-field-expandable-page-text').slideToggle('slow');
        });
      });


      //moves the sliver within the page tag for container height fixes
      var sliver = $('.sliver-container');
      if (sliver.length > 0) {
        $('#page').prepend(sliver[0].outerHTML);
        sliver.remove();
      }

      //adds contextual links actions to node pages
      $('.logged-in.page-node #content div.tabs').once(function () {
        //add & removes necessary classes for contextual links
        $(this).removeClass().addClass('contextual-links-wrapper contextual-links-processed');
        $(this).find('ul').removeClass().addClass('contextual-links');

        /**************************************************/
        /* Begin direct copy of js from Contextual Module */
        /**************************************************/
        var $wrapper = $(this);
        var $region = $wrapper.closest('.contextual-links-region');
        var $links = $wrapper.find('ul.contextual-links');
        var $trigger = $('<a class="contextual-links-trigger" href="#" />').text(Drupal.t('Configure')).click(
          function () {
            $links.stop(true, true).slideToggle(100);
            $wrapper.toggleClass('contextual-links-active');
            return false;
          }
        );
        // Attach hover behavior to trigger and ul.contextual-links.
        $trigger.add($links).hover(
          function () {
            $region.addClass('contextual-links-region-active');
          },
          function () {
            $region.removeClass('contextual-links-region-active');
          }
        );
        // Hide the contextual links when user clicks a link or rolls out of the .contextual-links-region.
        /*$region.bind('mouseleave click', Drupal.contextualLinks.mouseleave); Did not work for non-admins, modified the bind reaction as below */
        $region.hover(
          function () {
            $trigger.addClass('contextual-links-trigger-active');
          },
          function () {
            $trigger.removeClass('contextual-links-trigger-active');
          }
        );
        // Prepend the trigger.
        $wrapper.prepend($trigger);

        /***********************************/
        /* End Copy from Contextual Module */
        /***********************************/

        $region.bind('mouseleave click', function () {
          if ($wrapper.hasClass('contextual-links-active')) {
            $trigger.click();
          }
        });
      });


      //glyphicons and click event for right sidebar menu block
      $('.menu-block-wrapper ul.menu li.expanded').once(function () {
        if ($(this).hasClass('active-trail')) {
          $(this).prepend('<span class="glyphicon glyphicon-chevron-down"/>');
        } else {
          $(this).find('ul').hide();
          $(this).prepend('<span class="glyphicon glyphicon-chevron-right"/>');
        }

        $(this).find('.glyphicon').click(function () {
          $(this).siblings('ul').slideToggle('slow');
          $(this).toggleClass('glyphicon-chevron-down');
          $(this).toggleClass('glyphicon-chevron-right');
        });
      });

      //adds the mobile button for main menu
      $('#block-system-main-menu ul.menu li.expanded').once(function () {
        $(this).prepend('<span class="glyphicon glyphicon-plus-sign" />');
        $(this).find('.glyphicon').click(function () {
          $(this).toggleClass('glyphicon-plus-sign');
          $(this).toggleClass('glyphicon-minus-sign');
          $(this).siblings('ul').slideToggle('slow');
        });
      });

      $('#mobile-menu').once(function () {
        if ($(window).width() > 768) {
          $('.region-menu').show();
        } else {
          $('.region-menu').hide();
        }
        $(this).click(function () {
          $('.region-menu').slideToggle('slow');
        });
      });

      //if child menu items are too far to the right in the window, moves them to the left
      var resized = function () {
        $('#zone-branding .region-menu li > ul').each(function () {
          $(this).css('left', '').css('z-index', '');
        });
        $('#zone-branding .region-menu li > ul').each(function () {
          $(this).css('z-index', '10');
          var left = $(this).offset().left;
          var width = $(this).width();
          var windowwidth = $(window).width();
          if (left > windowwidth || left + width > windowwidth) {
            if ($(this).parent().parent().parent('div').length) {
              $(this).css('left', '-180px').css('z-index', $(this).closest('ul').css('z-index') + 1);
              $(this).find('ul').css('left', '-101%');
            } else {
              $(this).css('left', '-101%').css('z-index', $(this).closest('ul').css('z-index') + 1);
              $(this).find('ul').css('left', '-101%');
            }
          }
        });

        if ($(window).width() > 768) {
          $('.region-menu').show();
        } else {
          $('.region-menu').hide();
        }

        if ($(window).width() >= 768) {
          $('.region-menu ul.menu .glyphicon-minus-sign').each(function () {
            $(this).removeClass('glyphicon-minus-sign');
            $(this).addClass('glyphicon-plus-sign');
          });

          $('.region-menu ul.menu').css('display', '');
        }

        //adjusts the padding on the content zone since the footer is an absolute position
        //this helps with a dynamic footer height so that the footer can remain at the bottom even on short pages
        $('#zone-content').css('padding-bottom', $('#zone-footer').height() + 20);
      };

      resized();
      $(window).resize(function () {
        resized();
      });

      $('.views-fieldset.collapsible').once(function () {
        $(this).find('legend').css('cursor', 'pointer');
        var set = $(this);
        $(this).find('legend').click(function () {
          if ($(this).hasClass('open-fieldset')) {
            $(this).removeClass('open-fieldset');
          }
          else {
            $(this).addClass('open-fieldset');
          }
          set.find('.fieldset-wrapper').slideToggle('slow');
        })
      });
    }
  }
})(jQuery);