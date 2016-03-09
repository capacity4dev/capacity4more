<?php

/**
 * @file
 * getlocations.markerinfo.inc
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Getlocations marker information routines.
 * code derived from gmap_markerinfo.inc
 * converted to google maps version 3
 *
 * This file is pulled in whenever we need to refresh the marker information
 * and marker name caches.
 *
 * hook_getlocations_markerdir() code from jhm http://drupal.org/user/15946
 */

/**
 * Get marker icon data for constructing json object.
 */
function _getlocations_get_icondata() {
  $icons = array();
  $imagetypes = array(
    'shadow',
  );
  $inis = array();

  $markerdirs = module_invoke_all('getlocations_markerdir');
  if (count($markerdirs) < 1) {
    return FALSE;
  }
  foreach ($markerdirs as $i => $markerdir) {
    // The following routines are designed to be easy to comprehend, not fast.
    // This whole process gets cached.

    // Get the ini files.
    $inifiles = file_scan_directory($markerdir, '/.*\.ini$/');
    // Parse the ini files and store by path
    foreach ($inifiles as $file) {
      $path = drupal_substr($file->uri, drupal_strlen($markerdir), -drupal_strlen($file->filename));
      if (!isset($inis[$markerdir . $path])) {
        $inis[$path] = array();
      }
      $inis[$markerdir . $path][] = parse_ini_file($file->uri, TRUE);
    }
    unset($inifiles);
  }
  if (count($inis) < 1) {
    return FALSE;
  }
  // Per directory..
  foreach ($inis as $path => $path_inis) {
    $icons[$path] = array(
      'tempf' => array(),
      'f' => array(),
      'w' => array(),
      'h' => array(),
      'i' => array(), // Sets of sets
    );

    // Part 1: Collect image names
    $filenames = array();
    foreach ($path_inis as $ini) {
      foreach ($ini as $k => $v) {
        // Is this definition for an icon? (anything with a dot is a file)
        if (strpos($k, '.') !== FALSE) {
          // Add the icon name.
          $filenames[$k] = TRUE;
        }
        else {
          // Shadow / alternate search
          foreach ($imagetypes as $check) {
            if (isset($v[$check])) {
              $filenames[$v[$check]] = TRUE;
            }
          }
          // A sequence is a list of image names.
          if (isset($v['sequence'])) {
            foreach (explode(',', $v['sequence']) as $f) {
              $filenames[trim($f)] = TRUE;
            }
          }
        }
      }
    }
    $icons[$path]['tempf'] = $filenames;
  }
  unset($filenames);

  // Part 2: Assign ids, get width and height
  foreach ($icons as $path => $v) {
    $counter = 0;
    foreach ($icons[$path]['tempf'] as $filename => $fv) {
      // Skip empty filenames to avoid warnings.
      if (empty($filename)) {
        continue;
      }
      $size = getimagesize($path . $filename);
      $icons[$path]['f'][$counter] = $filename;
      $icons[$path]['w'][$counter] = $size[0];
      $icons[$path]['h'][$counter] = $size[1];
      // Store an index under tempf for the next part...
      $icons[$path]['tempf'][$filename] = $counter;
      $counter++;
    }
    _getlocations_compress_array($icons[$path]['w']);
    _getlocations_compress_array($icons[$path]['h']);
  }

  // Part 3: Main ini parsing
  // Per directory...
  foreach ($inis as $path => $path_inis) {
    // Per file...
    foreach ($path_inis as $i => $ini) {
      // Compression.
      foreach ($ini as $k => $v) {
        // Compress sequence filenames.
        if (isset($ini[$k]['sequence'])) {
          $temp = array();
          foreach (explode(',', $ini[$k]['sequence']) as $file) {
            $temp[] = $icons[$path]['tempf'][$file];
          }
          $ini[$k]['sequence'] = $temp;
        }
        // Compress other image field filenames.
        foreach ($imagetypes as $t) {
          if (isset($ini[$k][$t])) {
            $ini[$k][$t] = $icons[$path]['tempf'][$ini[$k][$t]];
          }
        }
        // Setup key for compression
        $ini[$k]['key'] = $k;
      }

      $mv = array();
      $iv = array();
      if (isset($ini['defaults'])) {
        $mv[0] = $ini['defaults'];
        unset($ini['defaults']);
      }
      else {
        $mv[0] = array();
      }
      foreach ($ini as $k => $v) {
        if (strpos($k, '.') === FALSE) {
          $mv[] = $ini[$k];
        }
        else {
          $iv[] = $ini[$k];
        }
      }

      $icons[$path]['i'][] = array(
        _getlocations_compress_icon_def($mv),
        _getlocations_compress_icon_def($iv),
      );

    }
  }
  foreach ($icons as $path => $v) {
    unset($icons[$path]['tempf']);
  }
  return $icons;
}

/**
 * Make a compressed definition.
 * A series of arrays with trailing holes allowed.
 * Any missing values at the end of subarrays
 * are equal to the last defined value.
 */
function _getlocations_compress_icon_def($iconset) {

  $order = array(
    'key', 'name', 'sequence',
    'imagepoint1X', 'imagepoint1Y', 'imagepoint2X', 'imagepoint2Y',
    'shadow', 'shadowpoint1X', 'shadowpoint1Y', 'shadowpoint2X', 'shadowpoint2Y',
    'shapecoords', 'shapetype'
  );
  $ints = array(3 => TRUE, 4 => TRUE, 5 => TRUE, 6 => TRUE, 8 => TRUE, 9 => TRUE, 10 => TRUE, 11 => TRUE);
  $nulls = array('', '', array(), 0, 0, 0, 0, '', 0, 0, 0, 0, '', '');

  $a = array();
  for ($c0 = 0; $c0<count($order); $c0++) {
    $a[$c0] = array();
    for ($c1=0; $c1<count($iconset); $c1++) {
      $temp = isset($iconset[$c1][$order[$c0]]) ? $iconset[$c1][$order[$c0]] : $nulls[$c0];
      // Ensure that numeric quantities are encoded as ints, not strings.
      if (isset($ints[$c0])) {
        $temp = (int)$temp;
      }
      $a[$c0][$c1] = $temp;
    }
    _getlocations_compress_array($a[$c0]);
  }
  for ($c0--;$c0>=0;$c0--) {
    if ($a[$c0] === array($nulls[$c0])) {
      unset($a[$c0]);
    }
    else {
      break;
    }
  }
  return $a;
}

/**
 * Remove trailing duplicates from an array.
 */
function _getlocations_compress_array(&$arr) {
  if (empty($arr)) {
    return;
  }
  $c = count($arr) - 1;
  // Walk backwards and unset duplicates...
  for ($cval = $arr[$c]; $c>0; $c--) {
    if ($arr[$c-1]==$cval) {
      unset($arr[$c]);
    }
    else {
      // .. until we hit a different number.
      break;
    }
  }
}

function _getlocations_get_marker_titles() {

  // The following routines are designed to be easy to comprehend, not fast.
  // This whole process gets cached.

  $inis = array();

  $markerdirs = module_invoke_all('getlocations_markerdir');
  foreach ($markerdirs as $markerdir) {
    // Get the ini files.
    $inifiles = file_scan_directory($markerdir, '/.*\.ini$/');
    // Parse the ini files and store by path
    foreach ($inifiles as $file) {
      $data = parse_ini_file($file->uri, TRUE);
      if (isset($data['defaults'])) {
        // Ignore defaults
        unset($data['defaults']);
      }
      foreach ($data as $k => $v) {
        if (strpos($k, '.') !== FALSE) {
          // Ignore files
          unset($data[$k]);
        }
      }
      $inis[] = $data;
    }
    unset($inifiles);
  }

  $titles = array();
  foreach ($inis as $ini => $inidata) {
    foreach ($inidata as $k => $v) {
      $titles[$k] = t($inis[$ini][$k]['name']);
    }
  }
  return $titles;
}
