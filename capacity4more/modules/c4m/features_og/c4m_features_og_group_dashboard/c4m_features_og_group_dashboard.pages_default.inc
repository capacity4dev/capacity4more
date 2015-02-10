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
  $page->path = 'node';
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
        1 => array(
          'name' => 'front',
          'settings' => NULL,
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'og_context',
          'settings' => array(
            'og_context_access_groups' => array(
              'group' => 0,
              'project' => 0,
            ),
          ),
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
      'left' => array(
        'column_type' => 'col-sm',
        'column_size' => '7',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'right' => array(
        'column_type' => 'col-sm',
        'column_size' => '5',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'top' => NULL,
      'bottom' => NULL,
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
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
    $pane->pid = 'new-aa710d01-6670-426e-a3fb-dbaa5cc81d65';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'aa710d01-6670-426e-a3fb-dbaa5cc81d65';
    $display->content['new-aa710d01-6670-426e-a3fb-dbaa5cc81d65'] = $pane;
    $display->panels['left'][1] = 'new-aa710d01-6670-426e-a3fb-dbaa5cc81d65';
    $pane = new stdClass();
    $pane->pid = 'new-1e41655c-1367-4fe9-ba4f-be3c36b3fc25';
    $pane->panel = 'right';
    $pane->type = 'c4m_content_group';
    $pane->subtype = 'c4m_content_group';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'clearfix',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1e41655c-1367-4fe9-ba4f-be3c36b3fc25';
    $display->content['new-1e41655c-1367-4fe9-ba4f-be3c36b3fc25'] = $pane;
    $display->panels['right'][0] = 'new-1e41655c-1367-4fe9-ba4f-be3c36b3fc25';
    $pane = new stdClass();
    $pane->pid = 'new-61364c4a-b99a-48c5-a681-818853195c85';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'c4m_overview_og_highlights';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '5',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'clearfix',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '61364c4a-b99a-48c5-a681-818853195c85';
    $display->content['new-61364c4a-b99a-48c5-a681-818853195c85'] = $pane;
    $display->panels['right'][1] = 'new-61364c4a-b99a-48c5-a681-818853195c85';
    $pane = new stdClass();
    $pane->pid = 'new-d54f83ca-540d-4bd0-9d56-d99e5afd46d8';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'c4m_overview_og_members';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '10',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'override_title' => 1,
      'override_title_text' => 'Recent Members',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'clearfix',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'd54f83ca-540d-4bd0-9d56-d99e5afd46d8';
    $display->content['new-d54f83ca-540d-4bd0-9d56-d99e5afd46d8'] = $pane;
    $display->panels['right'][2] = 'new-d54f83ca-540d-4bd0-9d56-d99e5afd46d8';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_c4m_og_group_dashboard_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'c4m_og_group_dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = -3;
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
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'og_no_purl',
          'settings' => NULL,
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
      'content_top' => NULL,
      'sidebar_first' => NULL,
      'sidebar_second' => NULL,
      'content_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '06511f40-31c3-41f4-be43-f277e145bfb3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9077df0a-aec8-47e5-a469-8fa9d5a7717a';
    $pane->panel = 'content_top';
    $pane->type = 'views';
    $pane->subtype = 'intro_block';
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
    $pane->uuid = '9077df0a-aec8-47e5-a469-8fa9d5a7717a';
    $display->content['new-9077df0a-aec8-47e5-a469-8fa9d5a7717a'] = $pane;
    $display->panels['content_top'][0] = 'new-9077df0a-aec8-47e5-a469-8fa9d5a7717a';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-9077df0a-aec8-47e5-a469-8fa9d5a7717a';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_c4m_og_group_dashboard_panel_context_4';
  $handler->task = 'page';
  $handler->subtask = 'c4m_og_group_dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = -2;
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
        2 => array(
          'name' => 'og_no_purl',
          'settings' => NULL,
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
  $display->title = 'Homepage';
  $display->uuid = '1fe2c852-912c-466f-afc5-6a2ff8f583fc';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_c4m_og_group_dashboard_http_response';
  $handler->task = 'page';
  $handler->subtask = 'c4m_og_group_dashboard';
  $handler->handler = 'http_response';
  $handler->weight = 4;
  $handler->conf = array(
    'title' => 'access denied',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '403',
    'destination' => '',
  );
  $page->default_handlers[$handler->name] = $handler;
  $pages['c4m_og_group_dashboard'] = $page;

  return $pages;

}
