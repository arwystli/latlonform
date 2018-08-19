<?php
/**
 * @file page_ll.inc
 * @author Bob Hutchinson hutch@arwystli.net
 * @copyright GNU GPL
 *
 * An example structure in PHP, handle ll outputs
 */

if (
     $vars['returns'][$vars['page']]['lat1']
  && $vars['returns'][$vars['page']]['lon1']
  && $vars['returns'][$vars['page']]['lat2']
  && $vars['returns'][$vars['page']]['lon2']
  ) {
  print "<p>" . "Point one: " . $vars['returns'][$vars['page']]['lat1'] . "," . $vars['returns'][$vars['page']]['lon1'] . "<br />";
  print "Point two: " . $vars['returns'][$vars['page']]['lat2'] . "," . $vars['returns'][$vars['page']]['lon2'] . "<br />";
  print "Distance: " . $vars['returns'][$vars['page']]['dist'] . " " . latlonform_get_unit_names($vars['returns'][$vars['page']]['unit']);
  print "</p>";
}
print '<h4 class="pageheading">' . $vars['pageheadings'][$vars['page']] . ":</h4>";
include(BASE_PATH . '/incs/form_' . $vars['page'] . '.inc');
