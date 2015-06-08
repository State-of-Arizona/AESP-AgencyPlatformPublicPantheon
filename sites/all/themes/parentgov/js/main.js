(function ($) {
    Drupal.behaviors.test = {
        attach: function (context, settings) {
            //Fix basic slideshow heights
            if ($('.node-basic-slideshow .field-slideshow-slide').length > 1) {
                $('.node-basic-slideshow .field-slideshow-caption').css('max-height', $($('.node-basic-slideshow .field-slideshow-image')[0]).height() - 40);
            } else {
                $('.node-basic-slideshow .field-slideshow-caption').css('max-height', $($('.node-basic-slideshow .field-slideshow-image')[0]).height() - 20);
            }
            $('.node-basic-slideshow .field-slideshow').css('min-height', $('.node-basic-slideshow .field-slideshow img').height());
            $(window).resize(function () {
                if ($('.node-basic-slideshow .field-slideshow-slide').length > 1) {
                    $('.node-basic-slideshow .field-slideshow-caption').css('max-height', $($('.node-basic-slideshow .field-slideshow-image')[0]).height() - 40);
                } else {
                    $('.node-basic-slideshow .field-slideshow-caption').css('max-height', $($('.node-basic-slideshow .field-slideshow-image')[0]).height() - 20);
                }
                $('.node-basic-slideshow .field-slideshow').css('min-height', $('.node-basic-slideshow .field-slideshow img').height());
            });


            //expandable page node
            $('.node-expandable-page .field-name-field-expandable-page-link-label').click(function () {
                $(this).toggleClass('open-text');
                $(this).siblings('.field-name-field-expandable-page-text').slideToggle('slow');
            });


            //Move the tabs into the contextual links gear and hides the actual tabs from view.
            $("[id^=block-quicktabs-draggable-views-]").each(function () {
                var links = $(this).find('.item-list .quicktabs-tabs').contents();
                $(this).find('.contextual-links-wrapper:first ul').append(links);
                $(this).find('.contextual-links-wrapper:first').css('right', '50px');
                $(this).find('h2.block-title').hide();
                $(this).find('.item-list:first').hide();
            });
        }
    }
})(jQuery);
