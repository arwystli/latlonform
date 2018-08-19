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
    'headertitle' => 'Latitudes and Longitudes',
    'pagetitle'   => 'Latitudes and Longitudes',
    'strapline'   => 'Collecting latitude and longitude information',
    'lang'        => 'en',          // default language
    'dev'         => FALSE,         // set to true for development mode
    'page'        => 'll',          // default page
    'ui'          => 'ui-lightness',  // default jquery-ui themes
    'pagesreg'    => array(
      'll' => 'Latitude and Longitude',
      'ld' => 'Calculate distance',
    ),
    'pageheadings' => array(
      'll' => 'Collect Latitude and Longitude',
      'ld' => 'Calculate distance between two points',
    ),
    'returns' => array(
      'll' => array(
        'lat'  => 0,
        'lon'  => 0,
      ),
      'ld' => array(
        'lat1' => 0,
        'lon1' => 0,
        'lat2' => 0,
        'lon2' => 0,
        'unit' => 'km',
        'dist' => '',
      ),
    ),
    'settings' => array(
      'll' => array(),
      'ld' => array(
        'dpt'  => 2           // decimal points to display in distance
      ),
    ),
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

/**
 * License clarification:
 *
 * On Feb 13, 2005, in message <Pine.LNX.4.58.0502131827510.5072@server1.LFW.org>,
 * the creator of these routines, Ka-Ping Yee, authorized these routines to be
 * distributed under the GPL.
 */

/**
 * @file
 * Trigonometry for calculating geographical distances.
 * All function arguments and return values measure distances in metres
 * and angles in degrees.  The ellipsoid model is from the WGS-84 datum.
 * Ka-Ping Yee, 2003-08-11
 */

// This library is an original implementation of UCB CS graduate student, Ka-Ping Yee (http://www.zesty.ca).

define('LATLONFORM_EARTH_RADIUS_SEMIMAJOR', 6378137.0);
define('LATLONFORM_EARTH_RADIUS_SEMIMINOR', (6378137.0*(1-(1/298.257223563))));

// Default latitude halfway between north pole and equator
function latlonform_earth_radius($latitude=45) {
  // Estimate the Earth's radius at a given latitude.
  $lat = deg2rad($latitude);
  $x = (cos($lat) / LATLONFORM_EARTH_RADIUS_SEMIMAJOR);
  $y = (sin($lat) / LATLONFORM_EARTH_RADIUS_SEMIMINOR);
  $return = (1 / (sqrt($x * $x + $y * $y)));
  return $return;
}

/**
 * @param float $latitude1
 * @param float $longitude1
 * @param float $latitude2
 * @param float $longitude2
 *
 * @return string
 *   Returns distance in meters
 *
 */
function latlonform_earth_distance($latitude1, $longitude1, $latitude2, $longitude2) {
  $latitude1  = floatval($latitude1);
  $longitude1 = floatval($longitude1);
  $latitude2  = floatval($latitude2);
  $longitude2 = floatval($longitude2);

  // Estimate the earth-surface distance between two locations.
  $lat1 = deg2rad($latitude1);
  $lon1 = deg2rad($longitude1);
  $lat2 = deg2rad($latitude2);
  $lon2 = deg2rad($longitude2);
  $radius = latlonform_earth_radius(($latitude1 + $latitude2) / 2);
  $cosangle = cos($lat1) * cos($lat2) * (cos($lon1) * cos($lon2) + sin($lon1) * sin($lon2)) + sin($lat1) * sin($lat2);
  return acos($cosangle) * $radius;
}

/**
 * @param $distance
 *   A number in either kilometers, meters, miles, yards or nautical miles.
 *
 * @param $distance_unit
 *   String (optional). in either kilometers (km), meters (m), miles (mi), yards (yd) or nautical miles (nmi).
 *
 * @return
 *   A floating point number where the number in meters after the initially passed scalar has been round()'d
 */
function latlonform_convert_distance_to_meters($distance, $distance_unit = 'km') {
  if (!is_numeric($distance) || ! $distance > 0) {
    return NULL;
  }
  $units = array(
    'km'  => 1000.0,
    'm'   => 1.0,
    'mi'  => 1609.344,
    'yd'  => 0.9144,
    'nmi' => 1852.0
  );
  if (! in_array($distance_unit, array_keys($units))) {
    $distance_unit = 'km';
  }
  $conv = $units[$distance_unit];
  // Convert distance to meters
  $retval = round(floatval($distance) * $conv, 2);
  return $retval;
}

/**
 * @param $meters
 *   The distance in meters.
 *
 * @param $distance_unit
 *   String (optional). in either kilometers (km), meters (m), miles (mi), yards (yd) or nautical miles (nmi).
 *
 * @return
 *   A floating point number where the converted number has been round()'d
 */
function latlonform_convert_meters_to_distance($meters, $distance_unit = 'km') {
  if (!is_numeric($meters) || ! $meters > 0) {
    return NULL;
  }
  $units = array(
    'km'  => 0.001,
    'm'   => 1.0,
    'mi'  => 0.000621371,
    'yd'  => 1.093613298,
    'nmi' => 0.000539957
  );
  if (! in_array($distance_unit, array_keys($units))) {
    $distance_unit = 'km';
  }
  $conv = $units[$distance_unit];
  // Convert meters to display units. formatting in theme_getlocations_fields_distance();
  $retval = ($meters * $conv);
  return $retval;
}

/**
 * Function
 *
 * @param
 *
 * @return
 *   Returns
 *
 */
function latlonform_get_unit_names($unit = '', $type = 'plural') {
  $units_plural = array(
    'km'  => 'Kilometers',
    'm'   => 'Meters',
    'mi'  => 'Miles',
    'yd'  => 'Yards',
    'nmi' => 'Nautical miles',
  );
  $units_plurals = array(
    'km'  => 'Kilometer(s)',
    'm'   => 'Meter(s)',
    'mi'  => 'Mile(s)',
    'yd'  => 'Yard(s)',
    'nmi' => 'Nautical mile(s)',
  );
  $units = array(
    'km'  => 'Kilometer',
    'm'   => 'Meter',
    'mi'  => 'Mile',
    'yd'  => 'Yard',
    'nmi' => 'Nautical mile',
  );
  // for dropdown
  $return = FALSE;
  if (empty($unit)) {
    if ($type == 'plural') {
      $return = $units_plural;
    }
    elseif ($type == 'plurals') {
      $return = $units_plurals;
    }
    else {
      $return = $units;
    }
  }
  else {
    // if $unit is supplied, return display name
    if (! in_array($unit, array_keys($units))) {
      $unit = 'km';
    }
    if ($type == 'plural') {
      $return = $units_plural[$unit];
    }
    elseif ($type == 'plurals') {
      $return = $units_plurals[$unit];
    }
    else {
      $return = $units[$unit];
    }
  }
  return $return;
}
