<?php

/**
 * @file
 * getlocations_leaflet.markerinfo.inc
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Provides Leaflet Maps integration for Getlocations.
 *
 *
 */
function _getlocations_leaflet_get_icondata() {

  $inis = array();
  $data = array();

  $markerdirs = module_invoke_all('getlocations_markerdir');
  if (count($markerdirs) < 1) {
    return FALSE;
  }

  foreach ($markerdirs AS $markerdir) {
    $inifiles = file_scan_directory($markerdir, '/.*\.ini$/');
    foreach ($inifiles as $file) {
      $path = drupal_substr($file->uri, 0, -drupal_strlen($file->filename));
      if (!isset($inis[$path])) {
        $inis[$path] = array();
      }
      $inis[$path][] = parse_ini_file($file->uri, TRUE);

    }
    unset($inifiles);
  }
  if (count($inis) < 1) {
    return FALSE;
  }

  foreach ($inis as $path => $path_inis) {
    foreach ($path_inis AS $v) {
      foreach ($v AS $key => $values) {
        if ($key == 'defaults') {
          $defaults = $values;
        }
        else {
          $data[$key]['iconUrl'] = base_path() . $path . $values['sequence'];
          $data[$key]['name'] = $values['name'];
          // size
          $size = getimagesize($path . $values['sequence']);
          $data[$key]['iconSize'] = array('x' => $size[0], 'y' => $size[1]);
          // iconAnchor
          if (isset($values['imagepoint2X'])) {
            $data[$key]['iconAnchor'] = array('x' => $values['imagepoint2X'], 'y' => $values['imagepoint2Y']);
          }
          elseif (isset($defaults['imagepoint1X'])) {
            $data[$key]['iconAnchor'] = array('x' => $defaults['imagepoint2X'], 'y' => $defaults['imagepoint2Y']);
          }
          // popupAnchor
          if (isset($values['imagepoint2X'])) {
            $data[$key]['popupAnchor'] = array('x' => $values['imagepoint1X'], 'y' => -$values['imagepoint2Y']);
          }
          elseif (isset($defaults['imagepoint1X'])) {
            $data[$key]['popupAnchor'] = array('x' => $defaults['imagepoint1X'], 'y' => -$defaults['imagepoint2Y']);
          }
          // shadow
          $data[$key]['shadowUrl'] = '';
          if (isset($values['shadow'])) {
            $data[$key]['shadowUrl'] = base_path() . $path . $values['shadow'];
            $size = getimagesize($path . $values['shadow']);
            $data[$key]['shadowSize'] =  array('x' => $size[0], 'y' => $size[1]);
          }
          elseif (isset($defaults['shadow'])) {
            $data[$key]['shadowUrl'] = base_path() . $path . $defaults['shadow'];
            $size = getimagesize($path . $defaults['shadow']);
            $data[$key]['shadowSize'] =  array('x' => $size[0], 'y' => $size[1]);
          }
          // shadowAnchor
          if (isset($values['shadowpoint2X'])) {
            $data[$key]['shadowAnchor'] = array('x' => $values['shadowpoint2X'], 'y' => $values['shadowpoint2Y']);
          }
          elseif (isset($defaults['shadowpoint2X'])) {
            $data[$key]['shadowAnchor'] = array('x' => $defaults['shadowpoint2X'], 'y' => $defaults['shadowpoint2Y']);
          }
        }
      }
    }
  }

  return $data;

}
