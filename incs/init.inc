<?php
/**
 * @file init.inc
 * @author Bob Hutchinson hutch@arwystli.net
 * @copyright GNU GPL
 *
 * An example structure in PHP, initialise
 */

$vars = latlonform_get_defaults();

// enable for dev mode
$vars['dev'] = TRUE;

$form_state = array();
$form_state['values'] = $_REQUEST;

if (isset($form_state['values']['page']) && $form_state['values']['page'] && in_array($form_state['values']['page'], array_keys($vars['pagesreg']))) {
  $vars['page'] = $form_state['values']['page'];
}

$uri = latlonform_get_path();
if (latlonform_validate_page($uri)) {
  $vars['page'] = $uri;
}

// do stuff
include(BASE_PATH . '/incs/page_' . $vars['page'] . '_q.inc');
