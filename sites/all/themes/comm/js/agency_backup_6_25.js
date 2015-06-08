jQuery(window).load(function() {//window.load instead of document.ready because I need images to have loaded before measuring sizes

});

jQuery(document).ready(function($) {

    var stickyNav = function() {
        var flyout = $('#region-user-flyout');
        var sticky = $('#sticky_nav');
        var winHeight = $(window).height();
        var winWidth = $(window).width();

        if (jQuery.browser.safari) {
            var bodyelem = $('.html');
        } else {
            var bodyelem = $('html');
        }
        var scrollPos = $(bodyelem).scrollTop();

        //var scrollPos = $(document).scrollTop();
        if (sticky.length > 0 && flyout.length > 0) {
            if ($('#sticky_nav').hasClass('sticky-desktop-mobile')) {
                if (scrollPos > 50) {
                    $('#sticky_nav').show();
                    $('#zone-branding').hide();
                } else {
                    $('#zone-branding').show();
                    $('#sticky_nav').hide();
                }
            } else {
                $('#zone-branding').show();
                $('#sticky_nav').hide();
            }
            if (winWidth < 831) {
                $('#sticky_nav').show();
            }

            var sliver = $('.sliver-container').height();

            //changes classes on the sticky nav and positions flyout based on scrolling location
            if (scrollPos <= sliver) {
                $('#sticky_nav').removeClass('top-sliver');
                $('#sticky_nav').addClass('below-sliver');
                $('#region-user-flyout').css('top', sliver - scrollPos + $('#sticky_nav').height());
            } else {
                $('#sticky_nav').removeClass('below-sliver');
                $('#sticky_nav').addClass('top-sliver');
                $('#region-user-flyout').css('top', $('#sticky_nav').height());
            }

            //manipulates the height of an empty div to give space to prevent sudden window shift.
            if (winWidth < 830 && scrollPos > sliver && $('#toolbar').length == 0) {
                $('#sticky-nav-spacer').css('height', $('#sticky_nav').height());
            } else {
                $('#sticky-nav-spacer').css('height', '');
            }

            //corrects the flyout navigigation while in desktop view
            if ($('#sticky_nav').is(":hidden")) {
                $('#region-user-flyout').css('top', '');
                $('#region-user-flyout').css('position', 'absolute');
            } else {
                $('#region-user-flyout').css('position', '');
            }

            //manipulation of the sticky nav while logged in
            if ($('#sticky_nav').is(":visible") && $('#toolbar').length > 0 && winWidth > 830) {
                $('#sticky_nav').css('top', $('#toolbar').height());
                $('#region-user-flyout').css('top', $('#toolbar').height() + $('#sticky_nav').height());
            } else if ($('#sticky_nav').is(":visible") && $('#toolbar').length > 0){
            	$('#sticky_nav').css('top', '');
                $('#region-user-flyout').css('top', $('#toolbar').height() + $('#sticky_nav').height());
            }

			
            if (scrollPos - $('#region-user-flyout').position().top < 0) {
                $('#region-user-flyout').height(winHeight - $('#region-user-flyout').position().top + scrollPos);
            } else {
            	$('#region-user-flyout').height(winHeight);
            }
        }
    };

    function prefaces() {
        var winWidth = $(window).width();
        var prefaces = new Array();
        prefaces[0] = document.getElementById('region-preface-first');
        prefaces[1] = document.getElementById('region-preface-second');
        prefaces[2] = document.getElementById('region-preface-third');

        if (prefaces[0] != null && prefaces[1] != null && prefaces[2] != null && winWidth > 600) {
            var i, j = 0, w1, w2, w3, itemHeight = 0, fields = new Array();

            for ( i = 0; i < 3; i++) {
                fields[i] = prefaces[i].querySelectorAll('.views-field');
            }

            w1 = fields[0].length;
            w2 = fields[1].length;
            w3 = fields[2].length;

            if (w2 == w1 && w3 == w1) {
                while (j < w1) {//j is the number of fields for each region
                    itemHeight = 0;

                    for ( i = 0; i < 3; i++) {
                        fields[i][j].style.height = 'auto';
                    }

                    for ( i = 0; i < 3; i++) {//i is the counter to go through each of the 3 regions
                        if (fields[i][j].clientHeight > itemHeight) {
                            itemHeight = fields[i][j].clientHeight - 5;
                        }
                    }

                    itemHeight = itemHeight.toString().concat('px');
                    for ( i = 0; i < 3; i++) {
                        fields[i][j].style.height = itemHeight;
                    }

                    j++;

                }

            } else {
                if (w1 == w2) {
                    heightMatch(fields[0], fields[1]);
                } else if (w1 == w3) {
                    heightMatch(fields[0], fields[2]);
                } else if (w2 == w3) {
                    heigthMatch(fields[1], fields[2]);
                }
            }

            itemHeight = 0;
            for ( i = 0; i < 3; i++) {
                prefaces[i].style.height = 'auto';
            }

            for ( i = 0; i < 3; i++) {
                if (itemHeight < prefaces[i].clientHeight) {
                    itemHeight = prefaces[i].clientHeight
                }
            }
            itemHeight = itemHeight.toString().concat('px');
            for ( i = 0; i < 3; i++) {
                prefaces[i].style.height = itemHeight;
            }

        }
    };

    function heightMatch(item1, item2) {
        var itemHeight;
        for (var j = 0; j < item1.length; j++) {
            if (item1[j].clientHeight > item2[j].clientHeight) {
                itemHeight = item1[j].clientHeight.toString().concat('px');
            } else if (item1[j].clientHeight < item2[j].clientHeight) {
                itemHeight = item2[j].clientHeight.toString().concat('px');
            }

            item1[j].style.height = itemHeight;
            item2[j].style.height = itemHeight;
        }
    }

    function frontSlider() {
        if ($(".front-slider .slides li").size() <= 3) {
            $(".front-slider .flex-direction-nav").css("display", "none");
        }

        var $quote = $(".front-slider .text-foreground");
        for (var i = 0; i < $quote.size(); i++) {
            var numChars = $quote[i].innerHTML.length;
            $element = $quote[i];
            if (numChars < 70) {
                $element.style.fontSize = "2.3em";
            } else if ((numChars >= 70) && (numChars < 120)) {
                $element.style.fontSize = "2em";
            } else if ((numChars >= 120) && (numChars < 170)) {
                $element.style.fontSize = "1.7em";
            } else if ((numChars >= 170) && (numChars < 220)) {
                $element.style.fontSize = "1.4em";
            } else if ((numChars >= 220) && (numChars < 270)) {
                $element.style.fontSize = "1.2em";
            } else {
                $element.style.fontSize = "1em";
            }
        }
    }

    frontSlider();
    stickyNav();
    prefaces();

    $(window).scroll(function() {
        stickyNav();
    });

    $(window).resize(function() {
        stickyNav();
        prefaces();
    });

    $("#sticky_nav .button").toggle(function() {
        $("#region-user-flyout").animate({
            left : "-10px"
        });
    }, function() {
        $("#region-user-flyout").animate({
            left : "-999px"
        });
    });

    $("#region-user-flyout .close").click(function() {
        $("#sticky_nav .button").trigger("click");
    });
});
