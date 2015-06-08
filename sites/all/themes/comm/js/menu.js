jQuery(document).ready(function($) {
	var expand_button = "<div title=\"Click Here to Expand the Menu\" class=\"button expand-menu\"></div>"
	
    var a = $("#region-user-flyout .block-menu .expanded > a");
	a.before(expand_button);
    
    $("#region-user-flyout .block-menu .button").toggle(function() {
    	$(this).removeClass('expand-menu').addClass('contract-menu');
    	$(this).siblings("ul").show(500);
    	$(this).parent().siblings("li").hide(500);
    }, function (){
    	$(this).removeClass('contract-menu').addClass('expand-menu');
    	$(this).siblings("ul").hide(500);
    	$(this).parent().siblings("li").show(500);
    })
});
