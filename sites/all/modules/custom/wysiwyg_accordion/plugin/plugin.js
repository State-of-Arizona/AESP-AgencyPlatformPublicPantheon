(function ($) {
  CKEDITOR.plugins.add('wysiwyg_accordion_plugin', {
    init: function (editor) {
      editor.addCommand('add_accordion', {
        exec: function (editor) {
          // Create the wrapper div.
          var accr = editor.document.createElement('div');
          accr.setAttribute('class', 'accordion');

          // Create an h3 element to the title.
          var accr_title = editor.document.createElement('h3');
          accr_title.setText('Accordion Title');

          // Append the title into wrapper div.
          accr.append(accr_title);

          // Create a div element for the content of accordion.
          var accr_content = editor.document.createElement('div');
          accr_content.setAttribute('class', 'accordion-content');

          // Create the first paragraph.
          var accr_content_p1 = editor.document.createElement('p');
          accr_content_p1.setText('Donec ullamcorper nulla non metus auctor fringilla.');

          // Create the second paragraph.
          var accr_content_p2 = editor.document.createElement('p');
          accr_content_p2.setText('Nulla vitae elit libero, a pharetra augue. Nullam quis risus eget urna mollis ornare vel eu leo.');

          // Append the paragraphs into the content div.
          accr_content.append(accr_content_p1);
          accr_content.append(accr_content_p2);


          // Append the content div into accordion wrapper.
          accr.append(accr_content);

          // Create the first paragraph.
          var accr_content_readmore = editor.document.createElement('div');
          accr_content_readmore.setText('Read More');
          accr_content_readmore.setAttribute('class', 'read-more');
          accr.append(accr_content_readmore);

          // Create a hidden paragraph.
          var accr_content_phidden = editor.document.createElement('p');
          accr_content_phidden.setAttribute('class', 'hidden');

          // Append the hidden paragraph into accordion wrapper.
          accr.append(accr_content_phidden);

          editor.insertElement(accr);
        }
      });
      editor.ui.addButton('wysiwyg_accordion_plugin_button', {
        label: 'Insert an Accordion',
        command: 'add_accordion',
        icon: this.path + 'images/button.png'
      });
    }
  });
})(jQuery);
