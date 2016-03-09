<?php

/**
 * @file
 * getlocations.drush.inc
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * drush integration for getlocations.
 * 'drush getlocations-markers' will install the basic getlocations marker set
 * 'drush getlocations-geojson' will install the GeoJSON javascript library
 * 'drush getlocations-leaflet' will install the Leafletjs javascript library
 */

define('GETLOCATIONS_MARKERS_DOWNLOAD_URI', 'http://dl.dropboxusercontent.com/u/41489105/Drupal/getlocations/getlocations-markers.zip');
define('GETLOCATIONS_GEOJSON_DOWNLOAD_URI', 'https://github.com/JasonSanford/GeoJSON-to-Google-Maps/archive/master.zip');
define('GETLOCATIONS_LEAFLET_DOWNLOAD_URI', 'http://leaflet-cdn.s3.amazonaws.com/build/leaflet-0.7.3.zip');
define('GETLOCATIONS_GEOCODER_DOWNLOAD_URI', 'https://github.com/geocoder-php/geocoder-js/archive/master.zip');
define('GETLOCATIONS_LEAFLET_HASH_DOWNLOAD_URI', 'https://github.com/mlevans/leaflet-hash/archive/master.zip');

/**
 * Implements hook_drush_command().
 *
 * In this hook, you specify which commands your
 * drush module makes available, what it does and
 * description.
 *
 * Notice how this structure closely resembles how
 * you define menu hooks.
 *
 * See `drush topic docs-commands` for a list of recognized keys.
 *
 * @return
 *   An associative array describing your command(s).
 */
function getlocations_drush_command() {
  $items = array();

  // the key in the $items array is the name of the command.
  $items['getlocations-markers'] = array(
    'callback' => 'drush_getlocations_markers',
    'description' => dt('Download and install the basic set of getlocations markers.'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap.
    'arguments' => array(
      'path' => dt('Optional. A path where to install the Getlocations markers. If omitted Drush will use the default location.'),
    ),
    'aliases' => array('getlocationsmarkers'),
  );
  $items['getlocations-geojson'] = array(
    'callback' => 'drush_getlocations_geojson',
    'description' => dt('Download and install the GeoJSON javascript library.'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap.
    'arguments' => array(
      'path' => dt('Optional. A path where to install the GeoJSON javascript library. If omitted Drush will use the default location.'),
    ),
    'aliases' => array('getlocationsgeojson'),
  );
  $items['getlocations-geocoder'] = array(
    'callback' => 'drush_getlocations_geocoder',
    'description' => dt('Download and install the geocoder-js javascript library.'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap.
    'arguments' => array(
      'path' => dt('Optional. A path where to install the geocoder-js javascript library. If omitted Drush will use the default location.'),
    ),
    'aliases' => array('getlocationsgeocoder'),
  );
  $items['getlocations-leaflet'] = array(
    'callback' => 'drush_getlocations_leaflet',
    'description' => dt('Download and install the Leafletjs library.'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap.
    'arguments' => array(
      'path' => dt('Optional. A path where to install the Leafletjs library. If omitted Drush will use the default location.'),
    ),
    'aliases' => array('getlocationsleaflet'),
  );
  $items['getlocations-leaflet-hash'] = array(
    'callback' => 'drush_getlocations_leaflet_hash',
    'description' => dt('Download and install the Leaflet-hash library.'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap.
    'arguments' => array(
      'path' => dt('Optional. A path where to install the Leaflet-hash library. If omitted Drush will use the default location.'),
    ),
    'aliases' => array('getlocationsleaflethash'),
  );

  return $items;
}

/**
 * Implements hook_drush_help().
 *
 * This function is called whenever a drush user calls
 * 'drush help <name-of-your-command>'
 *
 * @param
 *   A string with the help section (prepend with 'drush:')
 *
 * @return
 *   A string with the help text for your command.
 */
function getlocations_drush_help($section) {
  switch ($section) {
    case 'drush:getlocations-markers':
      return dt('Download and install the basic set of getlocations markers from Dropbox, default location is sites/all/libraries.');
    case 'drush:getlocations-geojson':
      return dt('Download and install the GeoJSON javascript library from Github, default location is sites/all/libraries.');
    case 'drush:getlocations-geocoder':
      return dt('Download and install the geocoder-js javascript library from Github, default location is sites/all/libraries.');
    case 'drush:getlocations-leaflet':
      return dt('Download and install the Leafletjs library from http://leafletjs.com, default location is sites/all/libraries.');
    case 'drush:getlocations-leaflet-hash':
      return dt('Download and install the Leaflet-hash library from Github, default location is sites/all/libraries.');
  }
}

/**
 * Command to download the basic Getlocations markers.
 */
function drush_getlocations_markers() {
  $args = func_get_args();
  if (!empty($args[0])) {
    $path = $args[0];
  }
  else {
    $path = 'sites/all/libraries';
  }

  // Create the path if it does not exist.
  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
  }

  // Set the directory to the download location.
  $olddir = getcwd();
  chdir($path);

  $zip = GETLOCATIONS_MARKERS_DOWNLOAD_URI;
  $dirname = 'getlocations';

  // Getlocations markers directory exists, bailing out
  if (is_dir($dirname)) {
    drush_log(dt('An existing Getlocations markerset was found in @path, not continuing.', array('@path' => $path)), 'notice');
    return;
  }

  // Download the zip archive
  if ($filepath = drush_download_file($zip)) {
    $filename = basename($filepath);

    // Decompress the zip archive
    drush_tarball_extract($filename);
  }

  if (is_dir($dirname)) {
    drush_log(dt('Getlocations markers have been installed in @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to install the Getlocations markers to @path', array('@path' => $path)), 'error');
  }

  // Set working directory back to the previous working directory.
  chdir($olddir);
}


/**
 * Command to download the GeoJSON javascript library.
 */
function drush_getlocations_geojson() {
  $args = func_get_args();
  if (!empty($args[0])) {
    $path = $args[0];
  }
  else {
    $path = 'sites/all/libraries';
  }

  // Create the path if it does not exist.
  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
  }

  // Set the directory to the download location.
  $olddir = getcwd();
  chdir($path);

  $zip = GETLOCATIONS_GEOJSON_DOWNLOAD_URI;
  $dirname = 'GeoJSON';
  // Download the zip archive
  if ($filepath = drush_download_file($zip)) {
    $filename = basename($filepath);

     // Remove any existing directory
    if (is_dir($dirname)) {
      drush_delete_dir($dirname, TRUE);
      drush_log(dt('An existing GeoJSON library was deleted from @path', array('@path' => $path)), 'notice');
    }

    // Decompress the zip archive
    drush_tarball_extract($filename);

    // Change the directory name to "GeoJSON" if needed.
    if (is_dir('geojson-google-maps-master')) {
      drush_move_dir('geojson-google-maps-master', $dirname, TRUE);
    }
  }

  if ($filepath && is_dir($dirname)) {
    drush_log(dt('GeoJSON javascript library has been installed in @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to install the GeoJSON javascript library to @path', array('@path' => $path)), 'error');
  }

  // Set working directory back to the previous working directory.
  chdir($olddir);
}

/**
 * Command to download the Geocoder-js javascript library.
 */
function drush_getlocations_geocoder() {
  $args = func_get_args();
  if (!empty($args[0])) {
    $path = $args[0];
  }
  else {
    $path = 'sites/all/libraries';
  }

  // Create the path if it does not exist.
  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
  }

  // Set the directory to the download location.
  $olddir = getcwd();
  chdir($path);

  $zip = GETLOCATIONS_GEOCODER_DOWNLOAD_URI;
  $dirname = 'geocoder-js';
  // Download the zip archive
  if ($filepath = drush_download_file($zip)) {
    $filename = basename($filepath);

     // Remove any existing directory
    if (is_dir($dirname)) {
      drush_delete_dir($dirname, TRUE);
      drush_log(dt('An existing Geocoder-js library was deleted from @path', array('@path' => $path)), 'notice');
    }

    // Decompress the zip archive
    drush_tarball_extract($filename);

    // Copy the file into place.
    $src = 'geocoder-js-master';
    if (is_dir($src)) {
      if (drush_mkdir($dirname)) {
        drush_copy_dir($src . '/dist/geocoder.min.js', $dirname . '/geocoder.min.js');
        drush_delete_dir($src);
      }
    }
  }

  if ($filepath && is_dir($dirname)) {
    drush_log(dt('Geocoder-js javascript library has been installed in @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to install the Geocoder-js javascript library to @path', array('@path' => $path)), 'error');
  }

  // Set working directory back to the previous working directory.
  chdir($olddir);
}

/**
 * Command to download the Leafletjs library.
 */
function drush_getlocations_leaflet() {
  $args = func_get_args();
  if (!empty($args[0])) {
    $path = $args[0];
  }
  else {
    $path = 'sites/all/libraries';
  }

  // Create the path if it does not exist.
  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
  }

  // Set the directory to the download location.
  $olddir = getcwd();
  chdir($path);

  $zip = GETLOCATIONS_LEAFLET_DOWNLOAD_URI;
  // Download the archive
  if ($filepath = drush_download_file($zip)) {
    $filename = basename($filepath);
    $dirname = 'leaflet';

    // Remove any existing directory
    if (is_dir($dirname)) {
      drush_delete_dir($dirname, TRUE);
      drush_log(dt('An existing Leafletjs library was deleted from @path', array('@path' => $path)), 'notice');
    }

    // Decompress the zip archive
    drush_tarball_extract($filename, $dirname);

  }

  if (is_dir($dirname)) {
    drush_log(dt('Leafletjs library has been installed in @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to install the Leafletjs library to @path', array('@path' => $path)), 'error');
  }

  // Set working directory back to the previous working directory.
  chdir($olddir);

}

/**
 * Command to download the Leaflet-hash javascript library.
 */
function drush_getlocations_leaflet_hash() {
  $args = func_get_args();
  if (!empty($args[0])) {
    $path = $args[0];
  }
  else {
    $path = 'sites/all/libraries';
  }

  // Create the path if it does not exist.
  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
  }

  // Set the directory to the download location.
  $olddir = getcwd();
  chdir($path);

  $zip = GETLOCATIONS_LEAFLET_HASH_DOWNLOAD_URI;
  $dirname = 'leaflet-hash';
  // Download the zip archive
  if ($filepath = drush_download_file($zip)) {
    $filename = basename($filepath);

     // Remove any existing directory
    if (is_dir($dirname)) {
      drush_delete_dir($dirname, TRUE);
      drush_log(dt('An existing Leaflet-hash library was deleted from @path', array('@path' => $path)), 'notice');
    }

    // Decompress the zip archive
    drush_tarball_extract($filename);

    // Copy the file into place.
    $src = 'leaflet-hash-master';
    if (is_dir($src)) {
      if (drush_mkdir($dirname)) {
        drush_copy_dir($src . '/leaflet-hash.js', $dirname . '/leaflet-hash.js');
        drush_delete_dir($src);
      }
    }
  }

  if ($filepath && is_dir($dirname)) {
    drush_log(dt('Leaflet-hash javascript library has been installed in @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to install the Leaflet-hash javascript library to @path', array('@path' => $path)), 'error');
  }

  // Set working directory back to the previous working directory.
  chdir($olddir);
}
