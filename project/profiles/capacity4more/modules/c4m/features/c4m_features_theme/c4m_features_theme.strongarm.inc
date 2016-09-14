<?php
/**
 * @file
 * c4m_features_theme.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4m_features_theme_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_kapablo_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 1,
    'toggle_slogan' => 1,
    'toggle_node_user_picture' => 1,
    'toggle_comment_user_picture' => 1,
    'toggle_comment_user_verification' => 1,
    'toggle_favicon' => 1,
    'toggle_main_menu' => 1,
    'toggle_secondary_menu' => 1,
    'default_logo' => 1,
    'logo_path' => '',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
    'bootstrap__active_tab' => 'edit-general',
    'bootstrap_fluid_container' => 0,
    'bootstrap_button_size' => '',
    'bootstrap_button_colorize' => 1,
    'bootstrap_button_iconize' => 1,
    'bootstrap_forms_required_has_error' => 0,
    'bootstrap_forms_smart_descriptions' => 0,
    'bootstrap_forms_smart_descriptions_limit' => '250',
    'bootstrap_forms_smart_descriptions_allowed_tags' => 'b, code, em, i, kbd, span, strong',
    'bootstrap_image_shape' => '',
    'bootstrap_image_responsive' => 1,
    'bootstrap_table_bordered' => 0,
    'bootstrap_table_condensed' => 0,
    'bootstrap_table_hover' => 1,
    'bootstrap_table_striped' => 1,
    'bootstrap_table_responsive' => 1,
    'bootstrap_navbar_position' => '',
    'bootstrap_navbar_inverse' => 0,
    'bootstrap_pager_first_and_last' => 1,
    'bootstrap_region_well-navigation' => '',
    'bootstrap_region_well-user_bar' => '',
    'bootstrap_region_well-top_menu' => '',
    'bootstrap_region_well-header' => '',
    'bootstrap_region_well-content_top' => '',
    'bootstrap_region_well-content_above' => '',
    'bootstrap_region_well-highlighted' => '',
    'bootstrap_region_well-help' => '',
    'bootstrap_region_well-content' => '',
    'bootstrap_region_well-sidebar_first_top' => 'well',
    'bootstrap_region_well-sidebar_first' => 'well',
    'bootstrap_region_well-sidebar_second' => '',
    'bootstrap_region_well-content_bottom' => '',
    'bootstrap_region_well-footer_top' => '',
    'bootstrap_region_well-footer_bottom' => '',
    'bootstrap_region_well-off_canvas' => '',
    'bootstrap_anchors_fix' => '0',
    'bootstrap_anchors_smooth_scrolling' => '0',
    'bootstrap_forms_has_error_value_toggle' => 1,
    'bootstrap_popover_enabled' => 1,
    'bootstrap_popover_animation' => 1,
    'bootstrap_popover_html' => 0,
    'bootstrap_popover_placement' => 'right',
    'bootstrap_popover_selector' => '',
    'bootstrap_popover_trigger' => array(
      'click' => 'click',
      'hover' => 0,
      'focus' => 0,
      'manual' => 0,
    ),
    'bootstrap_popover_trigger_autoclose' => 1,
    'bootstrap_popover_title' => '',
    'bootstrap_popover_content' => '',
    'bootstrap_popover_delay' => '0',
    'bootstrap_popover_container' => 'body',
    'bootstrap_tooltip_enabled' => 1,
    'bootstrap_tooltip_animation' => 1,
    'bootstrap_tooltip_html' => 0,
    'bootstrap_tooltip_placement' => 'auto left',
    'bootstrap_tooltip_selector' => '',
    'bootstrap_tooltip_trigger' => array(
      'hover' => 'hover',
      'focus' => 'focus',
      'click' => 0,
      'manual' => 0,
    ),
    'bootstrap_tooltip_delay' => '0',
    'bootstrap_tooltip_container' => 'body',
    'bootstrap_toggle_jquery_error' => 0,
    'bootstrap_cdn_provider' => '',
    'bootstrap_cdn_custom_css' => 'https://cdn.jsdelivr.net/bootstrap/3.3.5/css/bootstrap.css',
    'bootstrap_cdn_custom_css_min' => 'https://cdn.jsdelivr.net/bootstrap/3.3.5/css/bootstrap.min.css',
    'bootstrap_cdn_custom_js' => 'https://cdn.jsdelivr.net/bootstrap/3.3.5/js/bootstrap.js',
    'bootstrap_cdn_custom_js_min' => 'https://cdn.jsdelivr.net/bootstrap/3.3.5/js/bootstrap.min.js',
    'bootstrap_cdn_jsdelivr_version' => '3.3.5',
    'bootstrap_cdn_jsdelivr_theme' => 'bootstrap',
    'jquery_update_jquery_version' => '1.8',
  );
  $export['theme_kapablo_settings'] = $strongarm;

  return $export;
}
