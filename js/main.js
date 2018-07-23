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
  $("input#lat").latlonField(options);
  $("input#lon").latlonField(options);

})(jQuery);
