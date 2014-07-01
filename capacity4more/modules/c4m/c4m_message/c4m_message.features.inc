<?php
/**
 * @file
 * c4m_message.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_message_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function c4m_message_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function c4m_message_image_default_styles() {
  $styles = array();

  // Exported image style: activity_stream_media.
  $styles['activity_stream_media'] = array(
    'name' => 'activity_stream_media',
    'label' => 'Activity stream media',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 259,
          'height' => 288,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: activity_stream_user_picture.
  $styles['activity_stream_user_picture'] = array(
    'name' => 'activity_stream_user_picture',
    'label' => 'Activity stream user picture',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 75,
          'height' => 84,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_default_message_type().
 */
function c4m_message_default_message_type() {
  $items = array();
  $items['comment_added'] = entity_import('message_type', '{
    "name" : "comment_added",
    "description" : "Comment added",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "Commented on a [message:field-comment:node:content-type]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003ECommented on a [message:field-comment:node:content-type]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['node_added'] = entity_import('message_type', '{
    "name" : "node_added",
    "description" : "Node added",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "Added a [message:field-node:content-type:name]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EAdded a [message:field-node:content-type:name]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['node_edited'] = entity_import('message_type', '{
    "name" : "node_edited",
    "description" : "Node edited",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "Edited a [message:field-node:content-type:name]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EEdited a [message:field-node:content-type:name]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['user_added'] = entity_import('message_type', '{
    "name" : "user_added",
    "description" : "User added",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "New member",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003ENew member\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
