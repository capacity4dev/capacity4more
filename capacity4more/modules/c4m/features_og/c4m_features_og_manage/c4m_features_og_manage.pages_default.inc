<?php
/**
 * @file
 * c4m_features_og_manage.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function c4m_features_og_manage_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'group_management';
  $page->task = 'page';
  $page->admin_title = 'Group Management';
  $page->admin_description = '';
  $page->path = 'manage';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_group_management_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'group_management';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => ' OG current group',
        'keyword' => 'og_context',
        'name' => 'og_context',
        'og_context_group_types' => array(
          'group' => 'group',
          'project' => 'project',
        ),
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'User',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        1 => array(
          'name' => 'og_context',
          'settings' => array(
            'og_context_access_groups' => array(
              'group' => 'group',
              'project' => 'project',
            ),
          ),
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'c4m_og_perm',
          'settings' => array(
            'perm' => 'administer group',
          ),
          'context' => array(
            0 => 'logged-in-user',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'homepage';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '64886205-27ad-4340-99e5-94b18d31189e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6a0022f6-90d2-4d90-809b-2b922b35a788';
    $pane->panel = 'left';
    $pane->type = 'group_details';
    $pane->subtype = 'group_details';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6a0022f6-90d2-4d90-809b-2b922b35a788';
    $display->content['new-6a0022f6-90d2-4d90-809b-2b922b35a788'] = $pane;
    $display->panels['left'][0] = 'new-6a0022f6-90d2-4d90-809b-2b922b35a788';
    $pane = new stdClass();
    $pane->pid = 'new-23814cdc-61cf-4158-a995-eab1b143fd5c';
    $pane->panel = 'right';
    $pane->type = 'group_status';
    $pane->subtype = 'group_status';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '23814cdc-61cf-4158-a995-eab1b143fd5c';
    $display->content['new-23814cdc-61cf-4158-a995-eab1b143fd5c'] = $pane;
    $display->panels['right'][0] = 'new-23814cdc-61cf-4158-a995-eab1b143fd5c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['group_management'] = $page;

  return $pages;

}
