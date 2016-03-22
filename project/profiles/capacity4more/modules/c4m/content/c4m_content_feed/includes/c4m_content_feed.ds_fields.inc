<?php
/**
 * @file
 * Custom Display Suite function fields.
 */

/**
 * Render an link to the RSS feed.
 *
 * @param array $field
 *   The field info.
 *
 * @return string
 *   The rendered field.
 */
function c4m_content_feed_url(array $field) {
  $feed = entity_metadata_wrapper('node', $field['entity']);

  $url = $feed->url->value() . '/rss';
  $options = array(
    'attributes' => array(
      'class' => 'rss-link',
    ),
  );
  $link = l($url, $url, $options);

  $tag['element'] = array(
    '#tag'   => 'em',
    '#value' => $link,
  );

  return theme_html_tag($tag);
}
