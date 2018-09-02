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
  if ($vars['returns'][$vars['page']]['lat1'] <> 0 && $vars['returns'][$vars['page']]['lon1'] <> 0) {
    print "<p>" . "Point one: " . $vars['returns'][$vars['page']]['lat1'] . "," . $vars['returns'][$vars['page']]['lon1'] . "<br />";
  }
  if ($vars['returns'][$vars['page']]['lat2'] <> 0 && $vars['returns'][$vars['page']]['lon2'] <> 0) {
    print "Point two: " . $vars['returns'][$vars['page']]['lat2'] . "," . $vars['returns'][$vars['page']]['lon2'] . "<br />";
  }
  if ($vars['returns'][$vars['page']]['dist'] > 0) {
    print "Distance: " . $vars['returns'][$vars['page']]['dist'] . " " . latlonform_get_unit_names($vars['returns'][$vars['page']]['unit']) . "<br />";
  }
  if ($vars['returns'][$vars['page']]['circ'] > 0) {
    print "Area circle: " . $vars['returns'][$vars['page']]['circ'] . " " . latlonform_get_unit_names($vars['returns'][$vars['page']]['unit']) . "<br />";
  }
  if ($vars['returns'][$vars['page']]['rect'] > 0) {
    print "Area rectangle: " . $vars['returns'][$vars['page']]['rect'] . " " . latlonform_get_unit_names($vars['returns'][$vars['page']]['unit']) . "<br />";
  }
  print "</p>";
}
global $latlon_debug;
if ($latlon_debug) {
  print "<p>" . "DEBUG: " . $latlon_debug . "</p>";
}

print '<h4 class="pageheading">' . $vars['pageheadings'][$vars['page']] . ":</h4>";
include(BASE_PATH . '/incs/form_' . $vars['page'] . '.inc');
