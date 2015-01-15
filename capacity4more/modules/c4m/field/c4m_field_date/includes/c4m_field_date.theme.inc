<?php
/**
 * Theme function for a custom 'time ago' implementation
 *
 * @param $variables
 * @return string
 */
function theme_c4m_field_date_format_interval($variables) {
  $datetime = $variables['item']['value'];
  return c4m_helper_date_time_ago(strtotime($datetime));
}
