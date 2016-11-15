<?php
/**
 * @file
 * c4m_og.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function c4m_og_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:group:add user'
  $permissions['node:group:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:administer group'
  $permissions['node:group:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:administer taxonomy'
  $permissions['node:group:administer taxonomy'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:approve and deny subscription'
  $permissions['node:group:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:c4m_og_content_depromote'
  $permissions['node:group:c4m_og_content_depromote'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:c4m_og_content_promote'
  $permissions['node:group:c4m_og_content_promote'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:c4m_og_content_recommend'
  $permissions['node:group:c4m_og_content_recommend'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:c4m_og_content_unrecommend'
  $permissions['node:group:c4m_og_content_unrecommend'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:create discussion content'
  $permissions['node:group:create discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:create document content'
  $permissions['node:group:create document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:create event content'
  $permissions['node:group:create event content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:create news content'
  $permissions['node:group:create news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:create photo content'
  $permissions['node:group:create photo content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:create photoalbum content'
  $permissions['node:group:create photoalbum content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:create share content'
  $permissions['node:group:create share content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:create wiki_page content'
  $permissions['node:group:create wiki_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:delete any discussion content'
  $permissions['node:group:delete any discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete any document content'
  $permissions['node:group:delete any document content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete any event content'
  $permissions['node:group:delete any event content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete any news content'
  $permissions['node:group:delete any news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete any photo content'
  $permissions['node:group:delete any photo content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete any photoalbum content'
  $permissions['node:group:delete any photoalbum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete any share content'
  $permissions['node:group:delete any share content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete any wiki_page content'
  $permissions['node:group:delete any wiki_page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete own discussion content'
  $permissions['node:group:delete own discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:delete own document content'
  $permissions['node:group:delete own document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:delete own event content'
  $permissions['node:group:delete own event content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:delete own news content'
  $permissions['node:group:delete own news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete own photo content'
  $permissions['node:group:delete own photo content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:delete own photoalbum content'
  $permissions['node:group:delete own photoalbum content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:delete own share content'
  $permissions['node:group:delete own share content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:delete own wiki_page content'
  $permissions['node:group:delete own wiki_page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete terms'
  $permissions['node:group:delete terms'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:edit terms'
  $permissions['node:group:edit terms'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:invite visitors'
  $permissions['node:group:invite visitors'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:manage members'
  $permissions['node:group:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:manage permissions'
  $permissions['node:group:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:manage roles'
  $permissions['node:group:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:manage variables'
  $permissions['node:group:manage variables'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:subscribe'
  $permissions['node:group:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:group:subscribe without approval'
  $permissions['node:group:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:unsubscribe'
  $permissions['node:group:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:update any discussion content'
  $permissions['node:group:update any discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update any document content'
  $permissions['node:group:update any document content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update any event content'
  $permissions['node:group:update any event content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update any news content'
  $permissions['node:group:update any news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update any photo content'
  $permissions['node:group:update any photo content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update any photoalbum content'
  $permissions['node:group:update any photoalbum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update any share content'
  $permissions['node:group:update any share content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update any wiki_page content'
  $permissions['node:group:update any wiki_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:update group'
  $permissions['node:group:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:update own discussion content'
  $permissions['node:group:update own discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:update own document content'
  $permissions['node:group:update own document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:update own event content'
  $permissions['node:group:update own event content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:update own news content'
  $permissions['node:group:update own news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update own photo content'
  $permissions['node:group:update own photo content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:update own photoalbum content'
  $permissions['node:group:update own photoalbum content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:update own share content'
  $permissions['node:group:update own share content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:update own wiki_page content'
  $permissions['node:group:update own wiki_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:view unpublished group content'
  $permissions['node:group:view unpublished group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:project:add user'
  $permissions['node:project:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:administer group'
  $permissions['node:project:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:administer taxonomy'
  $permissions['node:project:administer taxonomy'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:approve and deny subscription'
  $permissions['node:project:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:c4m_og_content_depromote'
  $permissions['node:project:c4m_og_content_depromote'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:c4m_og_content_promote'
  $permissions['node:project:c4m_og_content_promote'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:c4m_og_content_recommend'
  $permissions['node:project:c4m_og_content_recommend'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:c4m_og_content_unrecommend'
  $permissions['node:project:c4m_og_content_unrecommend'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:create discussion content'
  $permissions['node:project:create discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:create document content'
  $permissions['node:project:create document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:create event content'
  $permissions['node:project:create event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:create news content'
  $permissions['node:project:create news content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:create photo content'
  $permissions['node:project:create photo content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:create photoalbum content'
  $permissions['node:project:create photoalbum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:create share content'
  $permissions['node:project:create share content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:project:create wiki_page content'
  $permissions['node:project:create wiki_page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:delete any discussion content'
  $permissions['node:project:delete any discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:delete any document content'
  $permissions['node:project:delete any document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:delete any event content'
  $permissions['node:project:delete any event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:delete any news content'
  $permissions['node:project:delete any news content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:delete any photo content'
  $permissions['node:project:delete any photo content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:delete any photoalbum content'
  $permissions['node:project:delete any photoalbum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:delete any share content'
  $permissions['node:project:delete any share content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:delete any wiki_page content'
  $permissions['node:project:delete any wiki_page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:delete own discussion content'
  $permissions['node:project:delete own discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:delete own document content'
  $permissions['node:project:delete own document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:delete own event content'
  $permissions['node:project:delete own event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:delete own news content'
  $permissions['node:project:delete own news content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:delete own photo content'
  $permissions['node:project:delete own photo content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:delete own photoalbum content'
  $permissions['node:project:delete own photoalbum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:delete own share content'
  $permissions['node:project:delete own share content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:project:delete own wiki_page content'
  $permissions['node:project:delete own wiki_page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:delete terms'
  $permissions['node:project:delete terms'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:edit terms'
  $permissions['node:project:edit terms'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:invite visitors'
  $permissions['node:project:invite visitors'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:manage members'
  $permissions['node:project:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:manage permissions'
  $permissions['node:project:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:manage roles'
  $permissions['node:project:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:manage variables'
  $permissions['node:project:manage variables'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:subscribe'
  $permissions['node:project:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:project:subscribe without approval'
  $permissions['node:project:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:unsubscribe'
  $permissions['node:project:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:project:update any discussion content'
  $permissions['node:project:update any discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:update any document content'
  $permissions['node:project:update any document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:update any event content'
  $permissions['node:project:update any event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:update any news content'
  $permissions['node:project:update any news content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:update any photo content'
  $permissions['node:project:update any photo content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:update any photoalbum content'
  $permissions['node:project:update any photoalbum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:update any share content'
  $permissions['node:project:update any share content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:update any wiki_page content'
  $permissions['node:project:update any wiki_page content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:project:update group'
  $permissions['node:project:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:update own discussion content'
  $permissions['node:project:update own discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:update own document content'
  $permissions['node:project:update own document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:update own event content'
  $permissions['node:project:update own event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:update own news content'
  $permissions['node:project:update own news content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:update own photo content'
  $permissions['node:project:update own photo content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:update own photoalbum content'
  $permissions['node:project:update own photoalbum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:update own share content'
  $permissions['node:project:update own share content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:project:update own wiki_page content'
  $permissions['node:project:update own wiki_page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:view unpublished group content'
  $permissions['node:project:view unpublished group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  return $permissions;
}
