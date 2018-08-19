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
