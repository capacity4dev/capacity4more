<?php
/**
 * @file
 * c4m_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function c4m_pages_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Group',
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
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'group' => 'group',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'group';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'activity_stream' => NULL,
      'middle' => NULL,
      'title' => NULL,
      'image' => NULL,
      'description' => NULL,
      'created' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'c073f956-0586-4ec8-a543-76d635069dda';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a1ff2efb-5cd3-4c4e-98f2-b122899847ad';
    $pane->panel = 'activity_stream';
    $pane->type = 'views_panes';
    $pane->subtype = 'activity_stream-panel_pane_activity_stream';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a1ff2efb-5cd3-4c4e-98f2-b122899847ad';
    $display->content['new-a1ff2efb-5cd3-4c4e-98f2-b122899847ad'] = $pane;
    $display->panels['activity_stream'][0] = 'new-a1ff2efb-5cd3-4c4e-98f2-b122899847ad';
    $pane = new stdClass();
    $pane->pid = 'new-eb7243c7-8e06-4a31-ac6a-e06d96fc4d69';
    $pane->panel = 'created';
    $pane->type = 'node_created';
    $pane->subtype = 'node_created';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'short',
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = 'eb7243c7-8e06-4a31-ac6a-e06d96fc4d69';
    $display->content['new-eb7243c7-8e06-4a31-ac6a-e06d96fc4d69'] = $pane;
    $display->panels['created'][0] = 'new-eb7243c7-8e06-4a31-ac6a-e06d96fc4d69';
    $pane = new stdClass();
    $pane->pid = 'new-806aa31a-4b49-49aa-9c34-8fd8e749e356';
    $pane->panel = 'description';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:c4m_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_trimmed',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'trim_length' => '600',
      ),
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '806aa31a-4b49-49aa-9c34-8fd8e749e356';
    $display->content['new-806aa31a-4b49-49aa-9c34-8fd8e749e356'] = $pane;
    $display->panels['description'][0] = 'new-806aa31a-4b49-49aa-9c34-8fd8e749e356';
    $pane = new stdClass();
    $pane->pid = 'new-9e16ad76-df80-4666-8152-dc727cbff52a';
    $pane->panel = 'image';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:c4m_media';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'group_banner',
        'image_link' => '',
      ),
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '9e16ad76-df80-4666-8152-dc727cbff52a';
    $display->content['new-9e16ad76-df80-4666-8152-dc727cbff52a'] = $pane;
    $display->panels['image'][0] = 'new-9e16ad76-df80-4666-8152-dc727cbff52a';
    $pane = new stdClass();
    $pane->pid = 'new-41f8671b-3c56-4883-ad05-1ad566211ebb';
    $pane->panel = 'title';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'none',
      'id' => '',
      'class' => '',
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '41f8671b-3c56-4883-ad05-1ad566211ebb';
    $display->content['new-41f8671b-3c56-4883-ad05-1ad566211ebb'] = $pane;
    $display->panels['title'][0] = 'new-41f8671b-3c56-4883-ad05-1ad566211ebb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  return $export;
}
