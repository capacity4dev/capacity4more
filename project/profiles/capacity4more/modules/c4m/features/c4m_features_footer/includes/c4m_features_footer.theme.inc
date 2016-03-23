<?php
/**
 * @file
 * Theme functions for the c4m_features_footer module.
 */

/**
 * Theme function for c4m footer block.
 *
 * @param array $variables
 *   Template variables.
 *
 * @return mixed
 *   Rendered output.
 */
function theme_c4m_footer_bar(array $variables) {
  $output = '<div class="c4m-footer-bar">';

  // Get c4m footer navigation links.
  $footer_navigation = variable_get('c4m_footer_navigation_links');
  $navigation_html = '<div class="c4m-footer-navigation">';
  foreach ($footer_navigation as $link) {
    $navigation_html .= '<div class="c4m-footer-nav-link">';
    $navigation_html .= l(t('@title', array('@title' => $link['title'])),
                          $link['url'],
                          array('attributes' => $link['attributes'])
                        );
    $navigation_html .= '</div>';
  }
  $navigation_html .= '</div>';
  $output .= $navigation_html;

  // Get c4m social media.
  $social_media = variable_get('c4m_social_media');
  $social_media_html = theme_c4m_social_media($social_media);
  $output .= $social_media_html;

  $output .= '</div>';

  return $output;
}

/**
 * Theme function for c4m footer block.
 *
 * @param array $variables
 *   Template variables.
 *
 * @return mixed
 *   Rendered output.
 */
function theme_c4m_footer_menu(array $variables) {
  $output = '<div class="c4m-footer-menu">';

  // Get c4m footer menu.
  $c4m_footer_menu = menu_tree('c4m-footer');
  $output .= render($c4m_footer_menu);

  $output .= '</div>';
  return $output;
}

/**
 * Function to theme the social media links.
 *
 * @param array $social_media
 *    Array with the social media info.
 *
 * @return string
 *    Rendered html of social media.
 */
function theme_c4m_social_media(array $social_media) {
  $output = '<div class="c4m-social-media">';
  foreach ($social_media as $key => $link) {
    $output .= '<div class="c4m-social-media-item c4m-social-media-' . $key . '">';
    $output .= l(t('@title', array('@title' => $link['title'])), $link['url'],
                array('attributes' => array('target' => '_blank')));
    $output .= '</div>';
  }
  $output .= '</div>';

  return $output;
}
