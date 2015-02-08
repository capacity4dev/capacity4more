<?php
/**
 * @file
 * c4m_features_overview_homepage.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function c4m_features_overview_homepage_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'c4m_homepage';
  $page->task = 'page';
  $page->admin_title = 'Homepage';
  $page->admin_description = 'The homepage of the site.';
  $page->path = 'home';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_c4m_homepage_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'c4m_homepage';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Homepage Authenticated',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 2,
              1 => 3,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'bootstrap_twocol_stacked';
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
  $display->uuid = '2dd546f8-fc69-46b1-b6bd-71d0393ccb0e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3a528cea-86ad-4e87-b7e3-da5c2bf9ff1e';
    $pane->panel = 'left';
    $pane->type = 'activity_stream';
    $pane->subtype = 'activity_stream';
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
    $pane->uuid = '3a528cea-86ad-4e87-b7e3-da5c2bf9ff1e';
    $display->content['new-3a528cea-86ad-4e87-b7e3-da5c2bf9ff1e'] = $pane;
    $display->panels['left'][0] = 'new-3a528cea-86ad-4e87-b7e3-da5c2bf9ff1e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_c4m_homepage_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'c4m_homepage';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Homepage Anonymous',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
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
      'page_top' => NULL,
      'sidebar_first' => NULL,
      'sidebar_second' => NULL,
      'page_bottom' => NULL,
      'content_top' => NULL,
      'content_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '20b56f90-2d32-4320-94fc-cddaba435150';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2f9244f8-7ed7-49fd-b5e6-f92025e7c761';
    $pane->panel = 'content_top';
    $pane->type = 'views_panes';
    $pane->subtype = 'intro_block-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2f9244f8-7ed7-49fd-b5e6-f92025e7c761';
    $display->content['new-2f9244f8-7ed7-49fd-b5e6-f92025e7c761'] = $pane;
    $display->panels['content_top'][0] = 'new-2f9244f8-7ed7-49fd-b5e6-f92025e7c761';
    $pane = new stdClass();
    $pane->pid = 'new-e09a244d-e246-4f5e-9095-9225c6fb7943';
    $pane->panel = 'sidebar_second';
    $pane->type = 'activity_stream';
    $pane->subtype = 'activity_stream';
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
    $pane->uuid = 'e09a244d-e246-4f5e-9095-9225c6fb7943';
    $display->content['new-e09a244d-e246-4f5e-9095-9225c6fb7943'] = $pane;
    $display->panels['sidebar_second'][0] = 'new-e09a244d-e246-4f5e-9095-9225c6fb7943';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['c4m_homepage'] = $page;

  return $pages;

}
