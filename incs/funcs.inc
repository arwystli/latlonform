<?php
/**
 * @file funcs.inc
 * @author Bob Hutchinson hutch@arwystli.net
 * @copyright GNU GPL
 *
 * An example structure in PHP, functions
 */

/**
 * @function latlonform_get_defaults
 * Provides some default settings
 * @return array
 *
 */
function latlonform_get_defaults() {
  $defaults = array(
    'headertitle' => 'Latitude and Longitude',
    'pagetitle'   => 'Latitude and Longitude',
    'strapline'   => 'Collecting latitude and longitude',
    'dev'         => FALSE,
    'pagesreg'    => array(
      'll' => 'Latitude and Longitude',
    ),
    'pageheadings' => array(
      'll' => 'Collect Latitude and Longitude',
    ),
    'page' => 'll',
    'lang' => 'en',
    'lat'  => 0,
    'lon'  => 0,
  );
  return $defaults;
}

/**
 * @function latlonform_validate_page
 * @param string
 * Checks that the current page exists in pagesreg
 * @return bool
 *
 */
function latlonform_validate_page($p) {
  $def = latlonform_get_defaults();
  if (array_key_exists($p, $def['pagesreg'])) {
    return TRUE;
  }
  return FALSE;
}

/**
 * @function latlonform_get_path
 * Collects the virtual path
 * @return string
 *
 */
function latlonform_get_path() {

  $uri = '';
  if ( isset($_SERVER['REQUEST_URI']) && ! empty($_SERVER['REQUEST_URI'])) {
    $uri = $_SERVER['REQUEST_URI'];
    if ( ! empty(SUB_URL)) {
      $uri = preg_replace("~^" . SUB_URL . '/' . "~", '', $uri);
    }
  }
  return $uri;

}

/**
 * Normalizes a latitude to the [-90,90] range. Latitudes above 90 or
 * below -90 are capped, not wrapped.
 * @param {Number} lat The latitude to normalize, in degrees.
 * @type Number
 * @return Returns the latitude, fit within the [-90,90] range.
 */
function latlonform_normalizelat($lat) {
  return max(-90, min(90, $lat));
}

/**
 * Normalizes a longitude to the [-180,180] range. Longitudes above 180
 * or below -180 are wrapped.
 * @param {Number} lng The longitude to normalize, in degrees.
 * @type Number
 * @return Returns the longitude, fit within the [-180,180] range.
 */
function latlonform_normalizelon($lng) {
  if ($lng % 360 == 180) {
      return 180;
    }
    while ($lng > 180) {
      $lng -= 360;
    }
    while ($lng < -180) {
      $lng += 360;
    }
    return $lng;
}
