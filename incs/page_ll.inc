<?php
/**
 * @file page_ll.inc
 * @author Bob Hutchinson hutch@arwystli.net
 * @copyright GNU GPL
 *
 * An example structure in PHP, handle ll outputs
 */

if ($vars['lat'] && $vars['lon']) {
  print "<p>" . "Latitude: " . $vars['lat'] . " Longitude: " . $vars['lon'] . "</p>";
}
print '<h4 class="pageheading">' . $vars['pageheadings'][$vars['page']] . ":</h4>";
include(BASE_PATH . '/incs/form.inc');
