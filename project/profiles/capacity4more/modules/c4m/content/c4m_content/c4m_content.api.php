<?php

/**
 * @file
 * Hooks provided by the capacity4more Content module.
 */

/**
 * Define the available content statistics.
 *
 * You need to implement the hook_c4m_content_statistics_info() hook to define
 * what statistics should be made available.
 *
 * @return array
 *   An array of statistic lists and their settings. Grouped by the scope where
 *   the statistics can be collected.
 *
 *   The supported scopes are:
 *   - global : Overall statistics.
 *   - group : Statistics for a specific group.
 *   - topic : Statistics for a specific topic.
 *
 *   Each list has the following data:
 *   - type:
 *       The identifier of the statistics list.
 *   - callback:
 *       The callback to retrieve the statistics.
 *   - weight:
 *       The weight used to sort the lists.
 *   - singular:
 *       The singular name of the statistic type.
 *   - plural:
 *       The plural name of the statistic type.
 *   - attributes:
 *       Standard attributes array to use in theme function (class, id, ...).
 *   - link:
 *       Should the item be showed as a link? This array contains the parameters
 *       needed for the l() function. The plural parameters will be used as the
 *       link label.
 *       - path : path to use in the link.
 *       - options : array of supported link options. See l().
 *   - og_id:
 *       The Organic Group ID of the statistics.
 *   - topic:
 *       The topic of the statistics.
 *   - entity_type:
 *       The entity type of the statistics.
 *       Required if no callback is defined.
 *   - bundles:
 *       The bundles to use in the statistics when it's a node as entity type.
 *       Required if no callback is defined.
 *   - state:
 *       The status of the entity as integer (published, unpublished).
 *       Required if no callback is defined.
 *   - c4m_status:
 *       The C4M status of the entity (published, requested, ...).
 *       Required if no callback is defined.
 *   - aggregate:
 *       Array containing type.
 *       Required if no callback is defined.
 *   - aggregate type:
 *       The identifier to group lists, belonging to this type, together.
 *       Required if no callback is defined.
 *   - feature_name:
 *       The name of the group feature.
 *       Required if no callback is defined.
 */
function hook_c4m_content_statistics_info() {
  return array(
    'global' => array(
      'c4m_discussions' => array(
        'type'        => 'discussion',
        'entity_type' => 'node',
        'bundles'     => array('discussion'),
        'singular'    => 'Post',
        'plural'      => 'Posts',
        'state'       => NULL,
        'c4m_status'  => NULL,
        'aggregate'   => array(
          'type' => 'posts',
        ),
        'weight'      => 1,
        'attributes'  => array(
          'class' => array('posts'),
        ),
      ),
    ),
    'group' => array(
      'c4m_og_discussions' => array(
        'type'          => 'discussion',
        'entity_type'   => 'node',
        'bundles'       => array('discussion'),
        'singular'      => 'Discussion',
        'plural'        => 'Discussions',
        'state'         => NULL,
        'c4m_status'    => array('published', 'archived'),
        'aggregate'     => array(),
        'weight'        => 1,
        'feature_name'  => 'c4m_features_og_discussions',
        'attributes'    => array(
          'class' => array('og-discussions'),
        ),
        'link'          => array(
          'path' => 'discussions',
        ),
      ),
    ),
    'topic' => array(
      'c4m_topic_discussions' => array(
        'type'          => 'discussion',
        'entity_type'   => 'node',
        'bundles'       => array('discussion'),
        'singular'      => 'Discussion',
        'plural'        => 'Discussions',
        'state'         => NULL,
        'c4m_status'    => array('published', 'archived'),
        'aggregate'     => array(),
        'weight'        => 1,
        'attributes'    => array(
          'class' => array('topic-discussions'),
        ),
        'link'          => array(
          'path' => 'search',
          'options' => array(
            'query' => array(
              'f' => array(
                'c4m_vocab_topic:@TOPIC_ID',
                'type:discussion',
              ),
            ),
          ),
        ),
      ),
    ),
  );
}
