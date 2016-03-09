<?php
// @codingStandardsIgnoreFile

/**
 * @file
 * Handler to optionally add links to page displays of a view.
 */

/**
 * Views area handler to display a link to a view page.
 *
 * This allows the user to switch the layout in which to consult a view if a
 * view has several pages offering content in a different format.
 * f.i.
 * - Format - Show rendered entity - Settings - View mode - Teaser
 * - Format - Show rendered entity - Settings - View mode - Table teaser
 * - ...
 *
 * @ingroup views_area_handlers
 */
class c4m_views_handler_area_switch_page extends views_handler_area {
  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();

    $options['link_path'] = array(
      'default' => '',
    );
    $options['link_text'] = array(
      'default' => 'Add content',
      'translatable' => TRUE,
    );
    $options['link_class'] = array(
      'default' => '',
    );
    $options['link_icon'] = array(
      'default' => '',
    );

    return $options;
  }

  /**
   * Retrieve the paths to page displays of this view.
   *
   * @return array
   *   The allowed pages.
   */
  public function allowed_pages() {
    $options = array();
    foreach ($this->view->display as $display) {
      if ('page' == $display->display_plugin &&
          !empty($display->display_options['path'])) {
        $options[$display->display_options['path']]['path']
          = $display->display_options['path'];

        if (!empty($display->display_options['pager']['options']['items_per_page'])) {
          $options[$display->display_options['path']]['items_per_page']
            = $display->display_options['pager']['options']['items_per_page'];
        }
      }
    }
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Retrieve the paths to page displays of current View.
    foreach ($this->allowed_pages() as $path => $page) {
      $options[$path] = $path;
    }

    $form['link_path'] = array(
      '#type' => 'select',
      '#required' => TRUE,
      '#title' => t('Link path'),
      '#options' => $options,
      '#description' => t('Set the path for the link.'),
      '#default_value' => $this->options['link_path'],
    );

    $form['link_text'] = array(
      '#type' => 'textfield',
      '#required' => TRUE,
      '#title' => t('Link text'),
      '#description' => t('Set the label for the link.'),
      '#default_value' => $this->options['link_text'],
    );

    $form['link_class'] = array(
      '#type' => 'textfield',
      '#required' => TRUE,
      '#title' => t('Link class'),
      '#description' => t('Optionally set an additional class for the link.'),
      '#default_value' => $this->options['link_class'],
    );

    $form['link_icon'] = array(
      '#type' => 'textfield',
      '#required' => FALSE,
      '#title' => t('Link icon'),
      '#description' => t('Optionally icon to use for this link (fontawesome).'),
      '#default_value' => $this->options['link_icon'],
    );
  }

  /**
   * Find out the information to render.
   *
   * Make sure that the get parameters of an active filter are included
   * in the view switch:
   * Include:
   * - Search filters (facets)
   * - Search terms
   * - The pager parameter ONLY when the current page view and the page
   * view you are switching to have the same amount of items per page
   * (pager settings).
   *
   * @param bool $empty
   *   Is the field empty.
   *
   * @return string
   *   The rendered output.
   */
  public function render($empty = FALSE) {
    $link_path = filter_xss_admin($this->options['link_path']);
    $link_text = filter_xss_admin($this->options['link_text']);
    $link_class = filter_xss_admin($this->options['link_class']);
    $link_icon = filter_xss_admin($this->options['link_icon']);
    if (!$link_path || !$link_text) {
      return NULL;
    }

    // This handler is not to add custom paths.
    // Check if path is page of current View.
    if (!array_key_exists($link_path, $this->allowed_pages())) {
      return;
    }

    $options = array(
      'html' => TRUE,
      'attributes' => array(
        'class' => array('custom-link'),
      ),
    );

    // Get query parameters.
    $query = drupal_get_query_parameters();

    // Remove pager if the number of items per page of the page it links to
    // is not equal to the number of items of the current page.
    // Initialize the numbers per item as they may be missing.
    $number_of_items_per_page_on_current_page = NULL;
    $number_of_items_per_page_on_linked_page = NULL;

    foreach ($this->allowed_pages() as $path => $page) {
      if (empty($page['items_per_page'])) {
        continue;
      }
      if ($link_path == $path) {
        $number_of_items_per_page_on_linked_page = $page['items_per_page'];
      }
      if ($path == current_path()) {
        $number_of_items_per_page_on_current_page = $page['items_per_page'];
      }
    }

    if ($number_of_items_per_page_on_current_page !=
        $number_of_items_per_page_on_linked_page) {
      unset($query['page']);
    }
    $options['query'] = $query;
    if (!empty($link_class)) {
      $options['attributes']['class'][] = $link_class;
    }

    // Add the icon (if any).
    $icon = NULL;
    if ($link_icon) {
      $icon = '<i class="fa ' . $link_icon . '"></i>';
      $options['attributes']['class'][] = 'has-icon';
      $options['attributes']['title'] = $link_text;
    }

    return l(
      $icon . '<span class="icon-label">' . $link_text . '</span>',
      $link_path,
      $options
    );
  }

}
