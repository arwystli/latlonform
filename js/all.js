
/**
 * @file jquery.latlonfield.js
 * @author Bob Hutchinson hutch@arwystli.net
 * Derived from .numberField() by nikita.vanyasin@gmail.com
 * https://github.com/nikita-vanyasin/jquery.numberfield.js.git
 *
 * @copyright GNU GPL
 * Adds method to jQuery object
 *
 */

;(function( $ ) {

  $.fn.latlonField = function( options ) {
    if ( !options ) {
      options = {};
    }
    var defaultOptions = {ints: 3, floats: 6, separator: "."};
    options = $.extend( defaultOptions, options );
    var intNumAllow = options.ints;
    var floatNumAllow = options.floats;
    var separator = options.separator;
    $( this ).on( 'keydown keypress keyup paste input', function() {
      while ( (this.value.split( separator ).length - 1) > 1 ) {
        this.value = this.value.slice( 0, -1 );
        if ( (this.value.split( separator ).length - 1) <= 1 ) {
          return false;
        }
      }
      var re = new RegExp('[^0-9' + options.separator + '-' + ']', 'g');
      this.value = this.value.replace(re, '');

      var allowedLength;
      var iof = this.value.indexOf( separator );
      if ( (iof != -1) && (this.value.substring( 0, iof ).length > intNumAllow) ) {
        allowedLength = 0;
      }
      else if ( iof != -1 ) {
        allowedLength = iof + floatNumAllow + 1;
      }
      else {
        allowedLength = intNumAllow;
      }
      this.value = this.value.substring( 0, allowedLength );
      return true;
    });
    return $( this );
  };

})( jQuery );

/**
 * @file main.js
 * @author Bob Hutchinson hutch@arwystli.net
 * @copyright GNU GPL
 *
 * An example structure in PHP, provide js
 */

;(function($) {
  // latlonField prevents the entry of anything except number, minus and dot into a html form text element.
  var options = {};
  if ( $("#lat").is('input')) {
    $("input#lat").latlonField(options);
    $("input#lon").latlonField(options);
  }
  else if ( $("#lat1").is('input')) {
    $("input#lat1").latlonField(options);
    $("input#lon1").latlonField(options);
    $("input#lat2").latlonField(options);
    $("input#lon2").latlonField(options);
  }


})(jQuery);

/*
  Formalize - version 1.2

  Note: This file depends on the jQuery library.
*/

// Module pattern:
// http://yuiblog.com/blog/2007/06/12/module-pattern
var FORMALIZE = (function($, window, document, undefined) {
  // Internet Explorer detection.
  function IE(version) {
    var b = document.createElement('b');
    b.innerHTML = '<!--[if IE ' + version + ']><br><![endif]-->';
    return !!b.getElementsByTagName('br').length;
  }

  // Private constants.
  var PLACEHOLDER_SUPPORTED = 'placeholder' in document.createElement('input');
  var AUTOFOCUS_SUPPORTED = 'autofocus' in document.createElement('input');
  var IE6 = IE(6);
  var IE7 = IE(7);

  // Expose innards of FORMALIZE.
  return {
    // FORMALIZE.go
    go: function() {
      var i, j = this.init;

      for (i in j) {
        j.hasOwnProperty(i) && j[i]();
      }
    },
    // FORMALIZE.init
    init: {
      // FORMALIZE.init.disable_link_button
      disable_link_button: function() {
        $(document.documentElement).on('click', 'a.button_disabled', function() {
          return false;
        });
      },
      // FORMALIZE.init.full_input_size
      full_input_size: function() {
        if (!IE7 || !$('textarea, input.input_full').length) {
          return;
        }

        // This fixes width: 100% on <textarea> and class="input_full".
        // It ensures that form elements don't go wider than container.
        $('textarea, input.input_full').wrap('<span class="input_full_wrap"></span>');
      },
      // FORMALIZE.init.ie6_skin_inputs
      ie6_skin_inputs: function() {
        // Test for Internet Explorer 6.
        if (!IE6 || !$('input, select, textarea').length) {
          // Exit if the browser is not IE6,
          // or if no form elements exist.
          return;
        }

        // For <input type="submit" />, etc.
        var button_regex = /button|submit|reset/;

        // For <input type="text" />, etc.
        var type_regex = /date|datetime|datetime-local|email|month|number|password|range|search|tel|text|time|url|week/;

        $('input').each(function() {
          var el = $(this);

          // Is it a button?
          if (this.getAttribute('type').match(button_regex)) {
            el.addClass('ie6_button');

            /* Is it disabled? */
            if (this.disabled) {
              el.addClass('ie6_button_disabled');
            }
          }
          // Or is it a textual input?
          else if (this.getAttribute('type').match(type_regex)) {
            el.addClass('ie6_input');

            /* Is it disabled? */
            if (this.disabled) {
              el.addClass('ie6_input_disabled');
            }
          }
        });

        $('textarea, select').each(function() {
          /* Is it disabled? */
          if (this.disabled) {
            $(this).addClass('ie6_input_disabled');
          }
        });
      },
      // FORMALIZE.init.autofocus
      autofocus: function() {
        if (AUTOFOCUS_SUPPORTED || !$(':input[autofocus]').length) {
          return;
        }

        var el = $('[autofocus]')[0];

        if (!el.disabled) {
          el.focus();
        }
      },
      // FORMALIZE.init.placeholder
      placeholder: function() {
        if (PLACEHOLDER_SUPPORTED || !$(':input[placeholder]').length) {
          // Exit if placeholder is supported natively,
          // or if page does not have any placeholder.
          return;
        }

        FORMALIZE.misc.add_placeholder();

        $(':input[placeholder]').each(function() {
          // Placeholder obscured in older browsers,
          // so there's no point adding to password.
          if (this.type === 'password') {
            return;
          }

          var el = $(this);
          var text = el.attr('placeholder');

          el.focus(function() {
            if (el.val() === text) {
              el.val('').removeClass('placeholder_text');
            }
          }).blur(function() {
            FORMALIZE.misc.add_placeholder();
          });

          // Prevent <form> from accidentally
          // submitting the placeholder text.
          el.closest('form').submit(function() {
            if (el.val() === text) {
              el.val('').removeClass('placeholder_text');
            }
          }).on('reset', function() {
            setTimeout(FORMALIZE.misc.add_placeholder, 50);
          });
        });
      }
    },
    // FORMALIZE.misc
    misc: {
      // FORMALIZE.misc.add_placeholder
      add_placeholder: function() {
        if (PLACEHOLDER_SUPPORTED || !$(':input[placeholder]').length) {
          // Exit if placeholder is supported natively,
          // or if page does not have any placeholder.
          return;
        }

        $(':input[placeholder]').each(function() {
          // Placeholder obscured in older browsers,
          // so there's no point adding to password.
          if (this.type === 'password') {
            return;
          }

          var el = $(this);
          var text = el.attr('placeholder');

          if (!el.val() || el.val() === text) {
            el.val(text).addClass('placeholder_text');
          }
        });
      }
    }
  };
// Alias jQuery, window, document.
})(jQuery, this, this.document);

// Automatically calls all functions in FORMALIZE.init
jQuery(document).ready(function() {
  FORMALIZE.go();
});