jQuery(window).load(function () {//window.load instead of document.ready because I need images to have loaded before measuring sizes

});

jQuery(document).ready(function ($) {

  var stickyNav = function () {

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

    if (sticky.length > 0 && flyout.length > 0) {
      if ($('#sticky_nav').hasClass('sticky-desktop-mobile')) {
        if (scrollPos > $('#zone-branding').height() - 20) {
          $('#sticky_nav').show();
        } else {
          $('#sticky_nav').hide();
        }
      } else {
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
      } else if ($('#sticky_nav').is(":visible") && $('#toolbar').length > 0) {
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
    var num_fields = new Array();
    prefaces[0] = $('#region-preface-first');
    prefaces[1] = $('#region-preface-second');
    prefaces[2] = $('#region-preface-third');

    //this resets the heights to auto so they can be recalculated. Helpful for window size change
    //also counts the number of fields in each region.
    for (var i = 0; i < 3; i++) {
      for (var j = 0; j < prefaces[i].find('.views-field').length; j++) {
        $(prefaces[i].find('.views-field')[j]).css('height', '');
      }
      $(prefaces[i]).css('height', '');
      num_fields[i] = prefaces[i].find('.views-field').length;
    }

    if (winWidth > 600 && prefaces[0].html() != null && prefaces[1].html() != null && prefaces[2].html() != null) {
      //calls the field height match function if the blocks contain the same number of views fields.
      if (num_fields[0] == num_fields[1] && num_fields[0] == num_fields[2] && num_fields[0] > 0) {
        field_match(prefaces);
      } else if (num_fields[0] == num_fields[1] && num_fields[0] > 0) {
        field_match([prefaces[0], prefaces[1]]);
      } else if (num_fields[0] == num_fields[2] && num_fields[0] > 0) {
        field_match([prefaces[0], prefaces[2]]);
      } else if (num_fields[1] == num_fields[2] && num_fields[1] > 0) {
        field_match([prefaces[1], prefaces[2]]);
      }

      //matches the containers of all three preface regions.
      var tallest_preface = 0;
      for (var i = 0; i < prefaces.length; i++) {
        if (prefaces[i].height() > tallest_preface) {
          tallest_preface = prefaces[i].height();
        }
      }
      for (var i = 0; i < 3; i++) {
        prefaces[i].height(tallest_preface);
      }
    }
  };

  function field_match(regions) {
    for (var j = 0; j < regions[0].find('.views-field').length; j++) {//loop to go into each field
      var tallest_field = 0;
      for (var i = 0; i < regions.length; i++) {//loop through each region
        if ($(regions[i].find('.views-field')[j]).innerHeight() > tallest_field) {
          tallest_field = $(regions[i].find('.views-field')[j]).height();
        }
      }

      for (var i = 0; i < regions.length; i++) {
        $(regions[i].find('.views-field')[j]).height(tallest_field);
      }
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

  $(window).scroll(function () {
    stickyNav();
  });

  $(window).resize(function () {
    stickyNav();
    prefaces();
  });

  $("#sticky_nav .button").toggle(function () {
    $("#region-user-flyout").animate({
      left: "-10px"
    });
  }, function () {
    $("#region-user-flyout").animate({
      left: "-999px"
    });
  });

  $("#region-user-flyout .close").click(function () {
    $("#sticky_nav .button").trigger("click");
  });
});
