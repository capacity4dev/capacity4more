<?php
/**
 * @file
 *
 * Custom Display Suite function fields.
 */

/**
 * DS function field.
 *
 * Render an <em> tag with the content disclaimer.
 *
 * @param $field
 *
 * @return string
 */
function c4m_content_article_disclaimer($field) {
  $disclaimer = variable_get('c4m_ds_content_disclaimer', 'DISCLAIMER: This information is provided in the interests of knowledge sharing and capacity development and should not be interpreted as the official view of the European Commission, or any other organisation.');

  $tag['element'] = array(
    '#tag'   => 'em',
    '#value' => $disclaimer,
  );

  return theme_html_tag($tag);
}
