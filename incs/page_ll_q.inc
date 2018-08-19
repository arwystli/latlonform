<?php
/**
 * @file page_ll_q.inc
 * @author Bob Hutchinson hutch@arwystli.net
 * @copyright GNU GPL
 *
 * An example structure in PHP, handle ic inputs
 */

// do some validation
if (
     (isset($form_state['values']['lat']) && $form_state['values']['lat'] <> 0 )
  && (isset($form_state['values']['lon']) && $form_state['values']['lon'] <> 0 )
  ) {
  $vars['returns'][$vars['page']]['lat'] = latlonform_normalizelat($form_state['values']['lat']);
  $vars['returns'][$vars['page']]['lon'] = latlonform_normalizelon($form_state['values']['lon']);

}
