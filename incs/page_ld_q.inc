<?php
/**
 * @file page_ld_q.inc
 * @author Bob Hutchinson hutch@arwystli.net
 * @copyright GNU GPL
 *
 * An example structure in PHP, handle ld inputs
 */

// do some validation and calculation
if (
     (isset($form_state['values']['lat1']) && $form_state['values']['lat1'] <> 0 )
  && (isset($form_state['values']['lon1']) && $form_state['values']['lon1'] <> 0 )
  && (isset($form_state['values']['lat2']) && $form_state['values']['lat2'] <> 0 )
  && (isset($form_state['values']['lon2']) && $form_state['values']['lon2'] <> 0 )
  ) {
  $vars['returns'][$vars['page']]['lat1'] = latlonform_normalizelat($form_state['values']['lat1']);
  $vars['returns'][$vars['page']]['lon1'] = latlonform_normalizelon($form_state['values']['lon1']);
  $vars['returns'][$vars['page']]['lat2'] = latlonform_normalizelat($form_state['values']['lat2']);
  $vars['returns'][$vars['page']]['lon2'] = latlonform_normalizelon($form_state['values']['lon2']);
  $vars['returns'][$vars['page']]['unit'] = $form_state['values']['unit'];
  $vars['returns'][$vars['page']]['dist'] = number_format(latlonform_convert_meters_to_distance(latlonform_earth_distance($vars['returns'][$vars['page']]['lat1'], $vars['returns'][$vars['page']]['lon1'], $vars['returns'][$vars['page']]['lat2'], $vars['returns'][$vars['page']]['lon2']), $form_state['values']['unit']), $vars['settings'][$vars['page']]['dpt']);
}
