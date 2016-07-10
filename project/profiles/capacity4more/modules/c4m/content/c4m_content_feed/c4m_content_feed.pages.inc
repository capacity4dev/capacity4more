<?php

/**
 * @file
 * c4m_content_feed.pages.inc
 */

/**
 * Page callback for rss feed.
 */
function c4m_content_feed_rss() {
  global $language;

  // Load feed.
  $feed = _c4m_content_feed_load(arg(0) . '/' . arg(1));
  $feed = entity_metadata_wrapper('node', $feed);

  $channel = array(
    'version'     => '2.0',
    'title'       => $feed->title->value(),
    'link'        => $feed->url->value() . '/rss',
    'description' => trim($feed->c4m_body->value->value()),
    'language'    => substr($language->language, 0, 2),
  );

  $items = c4m_content_feed_topics_format_rss($feed->c4m_related_topic);
  $items .= c4m_content_feed_articles_format_rss($feed->c4m_related_articles);
  $items .= c4m_content_feed_groups_format_rss($feed->c4m_related_group_unlimited);

  $output = "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
  $output .= "<rss version=\"" . $channel["version"] . "\" xml:base=\"" . url('<front>', array('absolute' => TRUE)) . "\">\n";
  $output .= format_rss_channel($channel['title'], $channel['link'], $channel['description'], $items, $channel['language']);
  $output .= "</rss>\n";

  drupal_add_http_header('Content-Type', 'application/rss+xml; charset=utf-8');

  print $output;
}

/**
 * Format RSS for feed Topics.
 */
function c4m_content_feed_topics_format_rss($topics) {
  $items = array();
  foreach ($topics->getIterator() as $item) {
    // Skip unpublished content.
    if ($item->status->value() != NODE_PUBLISHED) {
      continue;
    }

    $item_title = $item->title->value();
    $item_link = $item->url->value();
    $item_body = c4m_content_feed_convert_relative_links($item_link, $item->c4m_body->value->value());
    $item_file = isset($item->c4m_media) ? $item->c4m_media->value() : FALSE;

    $args = array(
      'category'  => t('Topic'),
      'pubDate'   => format_date($item->created->value(), 'custom', 'r'),
    );
    $args[] = c4m_content_feed_format_rss_guid($item);

    if ($item_file) {
      $args[] = c4m_content_feed_format_rss_image($item_file);
    }

    $items[] = format_rss_item($item_title, $item_link, $item_body, $args);
  }
  return implode($items);
}

/**
 * Format RSS for feed Articles.
 */
function c4m_content_feed_articles_format_rss($articles) {
  $items = array();
  foreach ($articles->getIterator() as $item) {
    // Skip unpublished content.
    if ($item->status->value() != NODE_PUBLISHED) {
      continue;
    }

    $item_title = $item->title->value();
    $item_link = $item->url->value();
    $item_body = c4m_content_feed_convert_relative_links($item_link, $item->c4m_body->value->value());
    $item_file = isset($item->c4m_media) ? $item->c4m_media->value() : FALSE;

    $args = array(
      'category'       => t('Voices & views'),
      'pubDate'        => format_date($item->created->value(), 'custom', 'r'),
      'count_views'    => $item->views->value(),
      'comments'       => $item->comment_count->value(),
      'topics'         => c4m_content_feed_format_topics($item->c4m_vocab_topic),
      'geo'            => c4m_content_feed_format_geo($item->c4m_vocab_geo),
    );
    $args[] = c4m_content_feed_format_rss_guid($item);

    if ($item_file) {
      $args[] = c4m_content_feed_format_rss_image($item_file);
    }

    $items[] = format_rss_item($item_title, $item_link, $item_body, $args);
  }
  return implode($items);
}

/**
 * Format RSS for feed Groups.
 */
function c4m_content_feed_groups_format_rss($groups) {
  $items = array();
  foreach ($groups->getIterator() as $item) {
    // Skip unpublished content.
    if ($item->status->value() != NODE_PUBLISHED) {
      continue;
    }

    $item_title = $item->title->value();
    $item_link = $item->url->value();
    $item_body = c4m_content_feed_convert_relative_links($item_link, $item->c4m_body->value->value());
    $item_file = isset($item->c4m_media) ? $item->c4m_media->value() : FALSE;

    $args = array(
      'category' => t('Group'),
      'pubDate'  => format_date($item->created->value(), 'custom', 'r'),
      'topics'   => c4m_content_feed_format_topics($item->c4m_vocab_topic),
      'geo'      => c4m_content_feed_format_geo($item->c4m_vocab_geo),
    );
    $args[] = c4m_content_feed_format_rss_guid($item);

    if ($item_file) {
      $args[] = c4m_content_feed_format_rss_image($item_file);
    }

    $items[] = format_rss_item($item_title, $item_link, $item_body, $args);
  }
  return implode($items);
}

/**
 * Format a list of Topics for an RSS feed.
 */
function c4m_content_feed_format_topics($topics) {
  $items = array();
  foreach ($topics->getIterator() as $item) {
    $items[] = $item->name->value();
  }
  return implode($items, ', ');
}

/**
 * Format a list of Geo regions for an RSS feed.
 */
function c4m_content_feed_format_geo($geo) {
  $items = array();
  foreach ($geo->getIterator() as $item) {
    $items[] = $item->name->value();
  }
  return implode($items, ', ');
}

/**
 * Format a guid for an RSS feed.
 */
function c4m_content_feed_format_rss_guid($item) {
  return array(
    'key' => 'guid',
    'value' => $item->getIdentifier() . '-' . $item->changed->value(),
    'attributes' => array(
      'isPermaLink' => 'false',
    ),
  );
}

/**
 * Format an image for an RSS feed.
 */
function c4m_content_feed_format_rss_image($file) {
  return array(
    'key' => 'enclosure',
    'attributes' => array(
      'url'    => file_create_url($file['uri']),
      'length' => $file['filesize'],
      'type'   => $file['filemime'],
    ),
  );
}

/**
 * Converts relative links in description to absolute links.
 *
 * Convert all relative links contained in the src and href elements within
 * a feed item's description to absolute links.
 *
 * @param string $link
 *   This is the link to the item.
 * @param string $description
 *   The description.
 *
 * @return mixed
 *   The string passed in $description with all relative links changed.
 */
function c4m_content_feed_convert_relative_links($link, $description) {
  // Create parts to use in the replacement patterns.
  $item_url_parts = parse_url($link);
  $item_base_url  = $item_url_parts['scheme'] . '://' . $item_url_parts['host'];

  if (array_key_exists('path', $item_url_parts)) {
    $item_path_parts = pathinfo($item_url_parts['path']);
    $item_dir = $item_base_url . $item_path_parts['dirname'] . '/';
  }
  else {
    $item_dir = $item_base_url . '/';
  }

  // Replace all links starting with '/'.
  $regexp      = "/\b(href|src)(\s*=\s*['\"])([\/][A-Za-z0-9\-\._]+\/?[A-Za-z0-9_\.\-\?\+\/~=&#;,]*)(['\"])/";
  $description = preg_replace($regexp, '$1$2' . $item_base_url . '$3$4', $description);

  // Replace all relative links not starting with '/'. Absolute links are not
  // matched, since ':' is not in the capture pattern.
  $regexp      = "/\b(href|src)(\s*=\s*['\"])([^\/][A-Za-z0-9\-\._]+\/?[A-Za-z0-9_\.\-\?\+\/~=&#;,]*)(['\"])/";
  $description = preg_replace($regexp, '$1$2' . $item_dir . '$3$4', $description);

  return $description;
}
