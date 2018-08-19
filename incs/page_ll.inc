<?php
/**
 * @file page_ll.inc
 * @author Bob Hutchinson hutch@arwystli.net
 * @copyright GNU GPL
 *
 * An example structure in PHP, handle ll outputs
 */

if ($vars['returns'][$vars['page']]['lat'] && $vars['returns'][$vars['page']]['lon']) {
  print "<p>" . "Latitude: " . $vars['returns'][$vars['page']]['lat'] . " Longitude: " . $vars['returns'][$vars['page']]['lon'] . "</p>";
}
print '<h4 class="pageheading">' . $vars['pageheadings'][$vars['page']] . ":</h4>";
include(BASE_PATH . '/incs/form_' . $vars['page'] . '.inc');
