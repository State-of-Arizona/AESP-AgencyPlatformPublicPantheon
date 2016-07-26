(function ($) {
Drupal.behaviors.wps_test_method = {
    attach: function(context, settings) {
      if (!Drupal.payment_handler) {
        Drupal.payment_handler = {};
      }
      var self = this;
      for (var pmid in settings.wps_test_method) {
        Drupal.payment_handler[pmid] = function(pmid, $method, submitter) {
          self.validateHandler(pmid, $method, submitter);
        };
      }
    },

    validateHandler: function(pmid, $method, submitter) {
        this.form_id = $method.closest('form').attr('id');

        $('.mo-dialog-wrapper').addClass('visible');
        if (typeof Drupal.clientsideValidation !== 'undefined') {
          $('#clientsidevalidation-' + this.form_id + '-errors ul').empty();
        }

        var getField = function(name) {
            if (name instanceof Array) { name = name.join(']['); }
            return $method.find('[name$="[' + name + ']"]');
        };
        var params = {
            succeed: getField('js_succeed').is(':checked'),
            timeout: getField('js_timeout').val(),
        };

        var self = this;
        setTimeout(function() {
          if (params.succeed) {
            submitter.ready();
          }
          else {
            self.errorHandler('JS validation failed!');
            submitter.error();
          }
        }, 1000 * params.timeout);
    },

    errorHandler: function(error) {
        var self = this;
        var settings, wrapper, child;
        if (typeof Drupal.clientsideValidation !== 'undefined') {
            settings = Drupal.settings.clientsideValidation['forms'][self.form_id];
            wrapper = document.createElement(settings.general.wrapper);
            child = document.createElement(settings.general.errorElement);
            child.className = settings.general.errorClass;
            child.innerHTML = error;
            wrapper.appendChild(child);

            $('#clientsidevalidation-' + self.form_id + '-errors ul')
            .append(wrapper).show()
            .parent().show();
        } else {
                if ($('#messages').length === 0) {
            $('<div id="messages"><div class="section clearfix">' +
              '</div></div>').insertAfter('#header');
                }
                $('<div class="messages error">' + error + '</div>')
            .appendTo("#messages .clearfix");
        }
    },

};
}(jQuery));
