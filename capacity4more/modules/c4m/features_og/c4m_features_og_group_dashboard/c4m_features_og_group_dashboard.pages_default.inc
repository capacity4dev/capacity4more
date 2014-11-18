<?php
/**
 * @file
 * c4m_features_og_group_dashboard.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function c4m_features_og_group_dashboard_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'c4m_og_group_dashboard';
  $page->task = 'page';
  $page->admin_title = 'Group Dashboard';
  $page->admin_description = 'Front page for "Group" group types.';
  $page->path = 'dashboard';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
    'frontpage' => TRUE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_c4m_og_group_dashboard_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'c4m_og_group_dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Group Dashboard',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'OG current group',
        'keyword' => 'og_context',
        'name' => 'og_context',
        'og_context_group_types' => array(
          'group' => 'group',
        ),
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'og_context',
          'settings' => array(
            'og_context_access_groups' => array(
              'group' => 'group',
              'project' => 0,
            ),
          ),
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'front',
          'settings' => NULL,
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'c01b37e8-aba0-4580-be34-5ed36319233e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-21c7eb12-4e76-40b8-9db8-0d52ad35523a';
    $pane->panel = 'left';
    $pane->type = 'quick_form';
    $pane->subtype = 'quick_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'context_og_context_1',
      'override_title' => 1,
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
    $pane->uuid = '21c7eb12-4e76-40b8-9db8-0d52ad35523a';
    $display->content['new-21c7eb12-4e76-40b8-9db8-0d52ad35523a'] = $pane;
    $display->panels['left'][0] = 'new-21c7eb12-4e76-40b8-9db8-0d52ad35523a';
    $pane = new stdClass();
    $pane->pid = 'new-e98fa97b-402c-4b87-b31f-b20ba158f96a';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'group_activity_stream';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'context' => array(
        0 => '',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e98fa97b-402c-4b87-b31f-b20ba158f96a';
    $display->content['new-e98fa97b-402c-4b87-b31f-b20ba158f96a'] = $pane;
    $display->panels['left'][1] = 'new-e98fa97b-402c-4b87-b31f-b20ba158f96a';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['c4m_og_group_dashboard'] = $page;

  return $pages;

}
