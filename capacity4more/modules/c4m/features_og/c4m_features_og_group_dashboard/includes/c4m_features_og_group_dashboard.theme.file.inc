<?php

/**
 * Theme function for flagged content block
 * @param $variables
 */
function theme_c4m_flagged_content_block($variables) {
  $output = '';
  $display_mode         = $variables['display_mode'];
  $header               = $variables['header'];
  $flag                 = $variables['flag'];
  $flagged_content      = $variables['flagged_content'];
  $full_flagged_content = entity_load($flag->entity_type, array_keys($flagged_content));

  if (empty($flagged_content)) {
    return $output;
  }

  $output = '<div class="flagged-content-block">';

  foreach ($flagged_content as $nid => $flag_content) {
    if (isset($flag_content->uid)) {
      $user = user_load($flag_content->uid);
      $output .= '<div class="fcb_header">' . t($header, array('%username' => $user->name)) . '</div>';
      if (isset($full_flagged_content[$nid])) {
        $node = node_view($full_flagged_content[$nid], $display_mode);
        $output .= render($node);
      }
    }
  }

  $output .= '</div>';
  return $output;
}