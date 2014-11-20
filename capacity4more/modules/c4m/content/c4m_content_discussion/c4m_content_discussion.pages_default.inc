<?php
/**
 * @file
 * c4m_content_discussion.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function c4m_content_discussion_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'discussion';
  $page->task = 'page';
  $page->admin_title = 'Discussion Edit';
  $page->admin_description = '';
  $page->path = 'node/%node/js-edit';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_discussion_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'discussion';
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
        'identifier' => 'Current OG Group from context',
        'keyword' => 'og_context',
        'name' => 'og_context',
        'og_context_group_types' => array(
          'group' => 'group',
        ),
        'id' => 1,
      ),
    ),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Angular full form to add a discussion';
  $display->uuid = '96dfdad3-0441-4a83-989a-9b01acfca8a9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fd6199fa-e769-48c3-a40c-86a564fd40db';
    $pane->panel = 'middle';
    $pane->type = 'quick_form';
    $pane->subtype = 'quick_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        1 => 'argument_entity_id:node_1',
        2 => 'empty',
        3 => 'empty',
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
    $pane->uuid = 'fd6199fa-e769-48c3-a40c-86a564fd40db';
    $display->content['new-fd6199fa-e769-48c3-a40c-86a564fd40db'] = $pane;
    $display->panels['middle'][0] = 'new-fd6199fa-e769-48c3-a40c-86a564fd40db';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-fd6199fa-e769-48c3-a40c-86a564fd40db';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['discussion'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'discussion_add';
  $page->task = 'page';
  $page->admin_title = 'Discussion Add';
  $page->admin_description = '';
  $page->path = 'node/js-add/%resource/!file';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'resource' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'file' => array(
      'id' => 1,
      'identifier' => 'File: ID',
      'name' => 'entity_id:file',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_discussion_add_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'discussion_add';
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
        'identifier' => 'Current OG Group from context',
        'keyword' => 'og_context',
        'name' => 'og_context',
        'og_context_group_types' => array(
          'group' => 'group',
        ),
        'id' => 1,
      ),
    ),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'fce3467a-c051-4c3c-81c0-36e1a09402a6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f5c34115-5cb4-4354-b76a-2be1d6e29920';
    $pane->panel = 'middle';
    $pane->type = 'quick_form';
    $pane->subtype = 'quick_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        1 => 'empty',
        2 => 'argument_string_1',
        3 => 'argument_entity_id:file_1',
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
    $pane->uuid = 'f5c34115-5cb4-4354-b76a-2be1d6e29920';
    $display->content['new-f5c34115-5cb4-4354-b76a-2be1d6e29920'] = $pane;
    $display->panels['middle'][0] = 'new-f5c34115-5cb4-4354-b76a-2be1d6e29920';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f5c34115-5cb4-4354-b76a-2be1d6e29920';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['discussion_add'] = $page;

  return $pages;

}
