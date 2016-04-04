<?php
/**
 * @file
 * c4m_features_homepage.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function c4m_features_homepage_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'c4m_homepage';
  $page->task = 'page';
  $page->admin_title = 'Homepage';
  $page->admin_description = 'Front page.';
  $page->path = 'node';
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
  $handler->name = 'page_c4m_homepage_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'c4m_homepage';
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
        'column_size' => '8',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'right' => array(
        'column_type' => 'col-sm',
        'column_size' => '4',
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
    $pane->pid = 'new-b86b7195-f263-4bc6-92ee-3e729efe4f9c';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'og_dashboard';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '1',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'og_dashboard_promoted_block',
      'context' => array(
        0 => '',
        1 => '',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b86b7195-f263-4bc6-92ee-3e729efe4f9c';
    $display->content['new-b86b7195-f263-4bc6-92ee-3e729efe4f9c'] = $pane;
    $display->panels['left'][0] = 'new-b86b7195-f263-4bc6-92ee-3e729efe4f9c';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '21c7eb12-4e76-40b8-9db8-0d52ad35523a';
    $display->content['new-21c7eb12-4e76-40b8-9db8-0d52ad35523a'] = $pane;
    $display->panels['left'][1] = 'new-21c7eb12-4e76-40b8-9db8-0d52ad35523a';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'aa710d01-6670-426e-a3fb-dbaa5cc81d65';
    $display->content['new-aa710d01-6670-426e-a3fb-dbaa5cc81d65'] = $pane;
    $display->panels['left'][2] = 'new-aa710d01-6670-426e-a3fb-dbaa5cc81d65';
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
  $handler->name = 'page_c4m_homepage_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'c4m_homepage';
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
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '06511f40-31c3-41f4-be43-f277e145bfb3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e15ee274-a647-4920-85c1-4bb1286686f2';
    $pane->panel = 'bottom';
    $pane->type = 'featured_block';
    $pane->subtype = 'featured_block';
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
    $pane->uuid = 'e15ee274-a647-4920-85c1-4bb1286686f2';
    $display->content['new-e15ee274-a647-4920-85c1-4bb1286686f2'] = $pane;
    $display->panels['bottom'][0] = 'new-e15ee274-a647-4920-85c1-4bb1286686f2';
    $pane = new stdClass();
    $pane->pid = 'new-0611c655-1657-489e-a844-c6648460af7c';
    $pane->panel = 'bottom';
    $pane->type = 'block';
    $pane->subtype = 'c4m_content-global_statistics_summary';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'row',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0611c655-1657-489e-a844-c6648460af7c';
    $display->content['new-0611c655-1657-489e-a844-c6648460af7c'] = $pane;
    $display->panels['bottom'][1] = 'new-0611c655-1657-489e-a844-c6648460af7c';
    $pane = new stdClass();
    $pane->pid = 'new-b3476758-2767-4be2-b3ad-84697ac801c3';
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
    $pane->uuid = 'b3476758-2767-4be2-b3ad-84697ac801c3';
    $display->content['new-b3476758-2767-4be2-b3ad-84697ac801c3'] = $pane;
    $display->panels['left'][0] = 'new-b3476758-2767-4be2-b3ad-84697ac801c3';
    $pane = new stdClass();
    $pane->pid = 'new-5abcf7ba-8a73-4ba1-8599-8e144b4326b1';
    $pane->panel = 'right';
    $pane->type = 'upcoming_events';
    $pane->subtype = 'upcoming_events';
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
    $pane->uuid = '5abcf7ba-8a73-4ba1-8599-8e144b4326b1';
    $display->content['new-5abcf7ba-8a73-4ba1-8599-8e144b4326b1'] = $pane;
    $display->panels['right'][0] = 'new-5abcf7ba-8a73-4ba1-8599-8e144b4326b1';
    $pane = new stdClass();
    $pane->pid = 'new-afc6317f-416b-4682-b8f9-cf0330924740';
    $pane->panel = 'top';
    $pane->type = 'voices_views_carousel';
    $pane->subtype = 'voices_views_carousel';
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
    $pane->uuid = 'afc6317f-416b-4682-b8f9-cf0330924740';
    $display->content['new-afc6317f-416b-4682-b8f9-cf0330924740'] = $pane;
    $display->panels['top'][0] = 'new-afc6317f-416b-4682-b8f9-cf0330924740';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_c4m_homepage_panel_context_4';
  $handler->task = 'page';
  $handler->subtask = 'c4m_homepage';
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
  $display->uuid = '1fe2c852-912c-466f-afc5-6a2ff8f583fc';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c7360f32-08d0-4955-b8e6-7f36e3fe1406';
    $pane->panel = 'bottom';
    $pane->type = 'featured_block';
    $pane->subtype = 'featured_block';
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
    $pane->uuid = 'c7360f32-08d0-4955-b8e6-7f36e3fe1406';
    $display->content['new-c7360f32-08d0-4955-b8e6-7f36e3fe1406'] = $pane;
    $display->panels['bottom'][0] = 'new-c7360f32-08d0-4955-b8e6-7f36e3fe1406';
    $pane = new stdClass();
    $pane->pid = 'new-d0f1ed5f-aa2b-448a-bf2d-8192ea102c9f';
    $pane->panel = 'bottom';
    $pane->type = 'block';
    $pane->subtype = 'c4m_content-global_statistics_summary';
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
    $pane->uuid = 'd0f1ed5f-aa2b-448a-bf2d-8192ea102c9f';
    $display->content['new-d0f1ed5f-aa2b-448a-bf2d-8192ea102c9f'] = $pane;
    $display->panels['bottom'][1] = 'new-d0f1ed5f-aa2b-448a-bf2d-8192ea102c9f';
    $pane = new stdClass();
    $pane->pid = 'new-53b1536c-6f9b-49a7-ad44-245d4e106f4f';
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
    $pane->uuid = '53b1536c-6f9b-49a7-ad44-245d4e106f4f';
    $display->content['new-53b1536c-6f9b-49a7-ad44-245d4e106f4f'] = $pane;
    $display->panels['left'][0] = 'new-53b1536c-6f9b-49a7-ad44-245d4e106f4f';
    $pane = new stdClass();
    $pane->pid = 'new-6291300a-bfa2-4b41-b466-2acf76adce64';
    $pane->panel = 'right';
    $pane->type = 'video_embed';
    $pane->subtype = 'video_embed';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'You\'re not yet a member of any group.',
      'description' => 'Learn how to learn and share knowledge by joining a group',
      'video' => 'http://youtu.be/ISNcUnbQkVQ',
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
    $pane->uuid = '6291300a-bfa2-4b41-b466-2acf76adce64';
    $display->content['new-6291300a-bfa2-4b41-b466-2acf76adce64'] = $pane;
    $display->panels['right'][0] = 'new-6291300a-bfa2-4b41-b466-2acf76adce64';
    $pane = new stdClass();
    $pane->pid = 'new-3e93b788-7d5d-472b-93b7-c120c0b9f8a8';
    $pane->panel = 'right';
    $pane->type = 'my_groups';
    $pane->subtype = 'my_groups';
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
    $pane->uuid = '3e93b788-7d5d-472b-93b7-c120c0b9f8a8';
    $display->content['new-3e93b788-7d5d-472b-93b7-c120c0b9f8a8'] = $pane;
    $display->panels['right'][1] = 'new-3e93b788-7d5d-472b-93b7-c120c0b9f8a8';
    $pane = new stdClass();
    $pane->pid = 'new-5be4e32c-b632-48f9-81af-3ecb57a2eaf7';
    $pane->panel = 'right';
    $pane->type = 'c4m_suggested_groups';
    $pane->subtype = 'c4m_suggested_groups';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '5be4e32c-b632-48f9-81af-3ecb57a2eaf7';
    $display->content['new-5be4e32c-b632-48f9-81af-3ecb57a2eaf7'] = $pane;
    $display->panels['right'][2] = 'new-5be4e32c-b632-48f9-81af-3ecb57a2eaf7';
    $pane = new stdClass();
    $pane->pid = 'new-c4bc1d1e-44b3-4475-a4ff-8d0061d9ff5c';
    $pane->panel = 'right';
    $pane->type = 'upcoming_events';
    $pane->subtype = 'upcoming_events';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'c4bc1d1e-44b3-4475-a4ff-8d0061d9ff5c';
    $display->content['new-c4bc1d1e-44b3-4475-a4ff-8d0061d9ff5c'] = $pane;
    $display->panels['right'][3] = 'new-c4bc1d1e-44b3-4475-a4ff-8d0061d9ff5c';
    $pane = new stdClass();
    $pane->pid = 'new-225dc4fb-702b-464d-94a7-55028265236b';
    $pane->panel = 'top';
    $pane->type = 'voices_views_carousel';
    $pane->subtype = 'voices_views_carousel';
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
    $pane->uuid = '225dc4fb-702b-464d-94a7-55028265236b';
    $display->content['new-225dc4fb-702b-464d-94a7-55028265236b'] = $pane;
    $display->panels['top'][0] = 'new-225dc4fb-702b-464d-94a7-55028265236b';
    $pane = new stdClass();
    $pane->pid = 'new-18f0d3ad-6fc1-4943-b068-84ff2812ccbb';
    $pane->panel = 'top';
    $pane->type = 'filter';
    $pane->subtype = 'filter';
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
    $pane->uuid = '18f0d3ad-6fc1-4943-b068-84ff2812ccbb';
    $display->content['new-18f0d3ad-6fc1-4943-b068-84ff2812ccbb'] = $pane;
    $display->panels['top'][1] = 'new-18f0d3ad-6fc1-4943-b068-84ff2812ccbb';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_c4m_homepage_http_response';
  $handler->task = 'page';
  $handler->subtask = 'c4m_homepage';
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
  $pages['c4m_homepage'] = $page;

  return $pages;

}
