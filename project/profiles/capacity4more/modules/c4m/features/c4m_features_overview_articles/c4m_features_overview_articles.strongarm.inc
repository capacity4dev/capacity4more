<?php

/**
 * @file
 * c4m_features_overview_articles.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4m_features_overview_articles_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_article_pattern';
  $strongarm->value = 'articles/[node:title]';
  $export['pathauto_node_article_pattern'] = $strongarm;

  return $export;
}
