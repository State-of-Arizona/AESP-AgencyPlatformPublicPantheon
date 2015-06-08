jQuery(document).ready(function($) {
    var blockWrapper = function() {
        var blocks = $('.block');
        var page = $('#block-system-main');
        var pageTitle = $('#page-title');
        var i = 0, loc = 0;
        var wrapString = '';

        if (page.html() != null) {
            var outerString = page.html();

            loc = outerString.indexOf('theme-icon-');
            if (loc != -1) {
                var a = outerString.indexOf(' ', loc + 1);
                var b = outerString.indexOf('"', loc + 1);
                if (b < a) {
                    a = b;
                }
                wrapString = outerString.substring(loc, a).replace(/\s/g, '');
            }
            if (pageTitle != null) {
                $(pageTitle).addClass(wrapString);
            }
        }
        wrapString = '';

        while (i < blocks.length) {
            innerString = blocks[i].innerHTML;
            loc = innerString.indexOf('theme-icon');
            var a = innerString.indexOf(' ', loc + 1);
            var b = innerString.indexOf('"', loc + 1);
            if (b < a) {
                a = b;
            }
            if (loc != -1) {
                wrapString = innerString.substring(loc, a).replace(/\s/g, '');
            }
            $(blocks[i]).find('.block-title').addClass(wrapString);
            i++;
            wrapString = ' ';
        }
    }
    function prefaces() {
        var winWidth = jQuery(window).width();
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
        for (var j = 0; j < item1.length; j++) {
            if (item1[j].clientHeight > item2[j].clientHeight) {
                itemHeight = item1[j].clientHeight.toString().concat('px');
            } else {
                itemHeight = item2[j].clientHeight.toString().concat('px');
            }

            item1[j].style.height = itemHeight;
            item2[j].style.height = itemHeight;
        }
    }

    function footer() {
        var winWidth = jQuery(window).width();
        var contactBlock = document.getElementById('block-nodeblock-contact-us');
        var footerInfo = document.getElementsByClassName('footer-branding')[0];
        if (contactBlock != null && footerInfo != null && winWidth >= 980) {
            if ($('.footer-branding').height() + 30 < $('#block-nodeblock-contact-us').height()) {

                $('.footer-branding').css('height', ($('#block-nodeblock-contact-us').height() - 30).toString().concat('px'));
            }
        } else {
            $('.footer-branding').css('height', 'auto');
        }
    }


    jQuery(window).resize(function() {
        footer();
    });

    footer();
    prefaces();
    blockWrapper();
});
