<?php
/**
 * @file
 * Hooks provided by the capacity4more Content module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Define the available content statistics.
 *
 * You need to implement the hook_c4m_content_statistics() hook to define
 * what search pages should be made available.
 *
 * @return array
 *   An array of statistic lists and their settings.
 *   Each list has the following data:
 *   - type : The identifier of the statistics list.
 *   - entity_type : The entity type of the statistics.
 *   - bundles : The bundles to use in the statistics when it's a node as entity type.
 *   - singular : The singular name of the statistic type.
 *   - plural : The plural name of the statistic type.
 *   - state : The status of the entity as integer (published, unpublished, ...).
 *   - c4m_status : The C4M status of the entity (published, requested, draft, ...).
 *   - scope : Sets the list as global/group statistics info.
 *   - og_id : The group id.
 *   - aggregate : Array containing type.
 *   - aggregate type : The identifier to group lists, belonging to this type, together.
 *   - weight : The weight used to sort the lists.
 *   - feature_name : The name of the group feature.
 *   - attributes : Standard attributes array to use in theme function (class, id, ...).
 */
function hook_c4m_content_statistics() {
  return array(
    'c4m_discussions' => array(
      'type'        => 'discussion',
      'entity_type' => 'node',
      'bundles'     => array('discussion'),
      'singular'    => 'Post',
      'plural'      => 'Posts',
      'state'       => NULL,
      'c4m_status'  => NULL,
      'scope'       => 'global',
      'og_id'       => NULL,
      'aggregate'   => array(
        'type' => 'posts',
      ),
      'weight'      => 1,
      'attributes'  => array(
        'class' => array('posts'),
      ),
    ),
    'c4m_og_discussions' => array(
      'type'          => 'discussion',
      'entity_type'   => 'node',
      'bundles'       => array('discussion'),
      'singular'      => 'Discussion',
      'plural'        => 'Discussions',
      'state'         => NULL,
      'c4m_status'    => array('published', 'archived'),
      'scope'         => 'group',
      'og_id'         => 37,
      'aggregate'     => array(),
      'weight'        => 1,
      'feature_name'  => 'c4m_features_og_discussions',
      'attributes'    => array(
        'class' => array('og-discussions'),
      ),
    ),
  );
}


/**
 * @} End of "addtogroup hooks".
 */
