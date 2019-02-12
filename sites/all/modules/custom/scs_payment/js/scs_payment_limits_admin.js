/**
 * @file
 * JS functions for the Payment limits component.
 */

(function ($) {
    Drupal.behaviors.payment_limits = {
        attach: function (context, settings) {
        	
        	// Hide the $ prefixes based on the current options
        	hide_prefixes();
        	
        	// Call the hide_prefix function when a new limit type is selected
        	$('select[name="extra[payment_limits][cc_limit_type]"],select[name="extra[payment_limits][ach_limit_type]"]').change(function() {
        		hide_prefix($(this));
        	});
        	
        	/**
        	 * Get the current limit types and call the hide_prefix function for each type
        	 */
        	function hide_prefixes() {
        		var $cc_value = $('select[name="extra[payment_limits][cc_limit_type]"]');
        		var $ach_value = $('select[name="extra[payment_limits][ach_limit_type]"]');
        		
        		var $values = [$cc_value, $ach_value];
        		$.each($values, function() {
        			hide_prefix($(this));
        		});
        	}
        	
        	/**
        	 * Hide the $ prefix based on the limit type of the $ele passed in
        	 */
        	function hide_prefix($ele) {
        		var val = $ele.val();
    			var $group = $ele.parents('.payment-limits-group');
    			$group.find('.prefix').hide();
    			if (val == 0) {
    				$group.find('.limits-prefix-min .prefix').show();
    			}
    			else if (val == 1) {
    				$group.find('.limits-prefix-max .prefix').show();
    			}
    			else if (val == 2) {
    				$group.find('.prefix').show();
    			}
        	}
        }
    };

})(jQuery);