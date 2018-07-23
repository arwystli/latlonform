<?php
/*
 * @file config.inc
 * @author Bob Hutchinson hutch@arwystli.net
 * @copyright GNU GPL
 *
 * An example structure in PHP, initial config
 */

// if you are running this in a subfolder edit this, no trailing slash
#define('SUB_URL', '');
define('SUB_URL', '/latlonform');

define('PHP_SELF', $_SERVER['PHP_SELF']);
define('BASE_PATH', $_SERVER['DOCUMENT_ROOT'] . SUB_URL);
include(BASE_PATH . '/incs/funcs.inc');
include(BASE_PATH . '/incs/init.inc');
include(BASE_PATH . '/incs/layout.inc');
