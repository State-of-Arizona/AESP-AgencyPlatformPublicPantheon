// Handle the color changes and update the preview window.
(function ($) {
    Drupal.color = {
        logoChanged: false,
        callback: function (context, settings, form, farb, height, width) {
            // Background
            $('#preview', form).css('backgroundColor', $('#palette input[name="palette[base]"]', form).val());
            $('#preview-branding', form).css('backgroundColor', $('#palette input[name="palette[branding]"]', form).val());
            $('#preview-main', form).css('backgroundColor', $('#palette input[name="palette[content]"]', form).val());
            $('#preview-footer-first', form).css('backgroundColor', $('#palette input[name="palette[footer]"]', form).val());
            $('#preview-footer-second', form).css('backgroundColor', $('#palette input[name="palette[footersecond]"]', form).val());
            $('#preview-preface-group', form).css('backgroundColor', $('#palette input[name="palette[preface]"]', form).val())
            $('#preview-preface-group .preface-title', form).css('backgroundColor', $('#palette input[name="palette[prefacetitles]"]', form).val())

            $('#preview p', form).css('color', $('#palette input[name="palette[text]"]', form).val());
            $('#preview a', form).css('color', $('#palette input[name="palette[link]"]', form).val());
            $('#preview-footer-first p', form).css('color', $('#palette input[name="palette[footertext]"]', form).val());
        }
    };
})(jQuery);

