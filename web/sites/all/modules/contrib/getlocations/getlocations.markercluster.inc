<?php

/**
 * @file
 * getlocations.markercluster.inc
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * markerclusterer support
 */

/**
 * To override these copy this file to getlocations.markercluster_override.inc
 * and make your changes there.
 *
 */

function getlocations_get_markerclusterer_styles() {

  $getlocations_defaults = getlocations_defaults();
  if (! empty($getlocations_defaults['markerclusterer_imgpath'])) {
    $jspath = $getlocations_defaults['markerclusterer_imgpath'];
  }
  else {
    $jspath = base_path() . GETLOCATIONS_PATH . '/js/images';
  }

  $markerclusterer_styles = array(
    array(
      (object) array(
        'url' => $jspath . '/people35.png',
        'height' => 35,
        'width' => 35,
        'anchor' => array(16, 0),
        'textColor' => '#ff00ff',
        'textSize' => 10
      ),
      (object) array(
        'url' => $jspath . '/people45.png',
        'height' => 45,
        'width' => 45,
        'anchor' => array(24, 0),
        'textColor' => '#ff0000',
        'textSize' => 11
      ),
      (object) array(
        'url' => $jspath . '/people55.png',
        'height' => 55,
        'width' => 55,
        'anchor' => array(32, 0),
        'textColor' => '#ffffff',
        'textSize' => 12
      )
    ),
    array(
      (object) array(
        'url' => $jspath . '/conv30.png',
        'height' => 27,
        'width' => 30,
        'anchor' => array(3, 0),
        'textColor' => '#ff00ff',
        'textSize' => 10
      ),
      (object) array(
        'url' => $jspath . '/conv40.png',
        'height' => 36,
        'width' => 40,
        'anchor' => array(6, 0),
        'textColor' => '#ff0000',
        'textSize' => 11
      ),
      (object) array(
        'url' => $jspath . '/conv50.png',
        'height' => 45,
        'width' => 50,
        'anchor' => array(8, 0),
        'textColor' => '#ffffff',
        'textSize' => 12
      )
    ),
    array(
      (object) array(
        'url' => $jspath . '/heart30.png',
        'height' => 26,
        'width' => 30,
        'anchor' => array(4, 0),
        'textColor' => '#ff00ff',
        'textSize' => 10
      ),
      (object) array(
        'url' => $jspath . '/heart40.png',
        'height' => 35,
        'width' => 40,
        'anchor' => array(8, 0),
        'textColor' => '#ff0000',
        'textSize' => 11
      ),
      (object) array(
        'url' => $jspath . '/heart50.png',
        'height' => 44,
        'width' => 50,
        'anchor' => array(12, 0),
        'textColor' => '#ffffff',
        'textSize' => 12
      )
    )
  );
  return $markerclusterer_styles;
}

function getlocations_element_markerclusterer_style($default) {

  $element = array(
    '#type' => 'select',
    '#title' => t('Marker Clusterer style'),
    '#default_value' => $default,
    '#options' => array(
      '-1' => t('Default'),
      '0' => t('People'),
      '1' => t('Conversation'),
      '2' => t('Heart')
    ),
  );
  return $element;
}

function getlocations_element_markerclusterer_zoom($default) {

  $element = array(
    '#type' => 'select',
    '#title' => t('Marker Clusterer zoom'),
    '#default_value' => $default,
    '#options' => array(
      '-1' => t('Default'),
      '7' => '7',
      '8' => '8',
      '9' => '9',
      '10' => '10',
      '11' => '11',
      '12' => '12',
      '13' => '13',
      '14' => '14',
    ),
  );
  return $element;
}

function getlocations_element_markerclusterer_size($default) {

  $element = array(
    '#type' => 'select',
    '#title' => t('Marker Clusterer size'),
    '#default_value' => $default,
    '#options' => array(
      '-1' => t('Default'),
      '40' => '40',
      '50' => '50',
      '70' => '70',
      '80' => '80',
    ),
  );
  return $element;
}

function getlocations_element_markerclusterer_minsize($default) {

  $element = array(
    '#type' => 'select',
    '#title' => t('Marker Clusterer Minimum markers'),
    '#default_value' => $default,
    '#options' => array(
      '-1' => t('Default'),
      '3' => '3',
      '4' => '4',
      '5' => '5',
      '6' => '6',
      '7' => '7',
      '8' => '8',
      '9' => '9',
      '10' => '10',
      '12' => '12',
      '15' => '15',
      '20' => '20',
    ),
  );
  return $element;
}
