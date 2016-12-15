<?php
// @codingStandardsIgnoreFile

/**
 * @file
 * Definition of c4m_views_handler_area_result.
 */

/**
 * Views area handler to display some configurable result summary.
 *
 * @ingroup views_area_handlers
 */
class c4m_views_handler_area_result extends views_handler_area_result {
  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();

    $options['classes'] = array(
      'default' => '',
    );

    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function options_form(array &$form, array &$form_state) {
    parent::options_form($form, $form_state);

    $form['classes'] = array(
      '#type' => 'textfield',
      '#title' => t('Optional classes'),
      '#description' => t('Optionally set additional classes on the result,
        separated by comma.'),
      '#default_value' => $this->options['classes'],
    );
  }

  /**
   * {@inheritdoc}
   */
  public function render($empty = FALSE) {
    // Copy from parent::render(). Just use c4m_content_ec_number_format().
    // Must have options and does not work on summaries.
    if (!isset($this->options['content']) || $this->view->plugin_name == 'default_summary') {
      return;
    }
    $output = '';
    $format = $this->options['content'];
    // Calculate the page totals.
    $current_page = (int) $this->view->get_current_page() + 1;
    $per_page = (int) $this->view->get_items_per_page();
    $count = count($this->view->result);
    // @TODO: Maybe use a possible is views empty functionality.
    // Not every view has total_rows set, use view->result instead.
    $total = isset($this->view->total_rows) ? $this->view->total_rows : count($this->view->result);
    $name = check_plain($this->view->human_name);
    if ($per_page === 0) {
      $page_count = 1;
      $start = 1;
      $end = $total;
    }
    else {
      $page_count = (int) ceil($total / $per_page);
      $total_count = $current_page * $per_page;
      if ($total_count > $total) {
        $total_count = $total;
      }
      $start = ($current_page - 1) * $per_page + 1;
      $end = $total_count;
    }
    $current_record_count = ($end - $start) + 1;
    // Get the search information.
    $items = array('start', 'end', 'total', 'name', 'per_page', 'current_page', 'current_record_count', 'page_count');
    $replacements = array();
    foreach ($items as $item) {
      $replacements["@$item"] = c4m_content_ec_number_format((int)${$item});
    }
    // Send the output.
    if (!empty($total)) {
      $output .= filter_xss_admin(str_replace(array_keys($replacements), array_values($replacements), $format));
    }
    // End of parent::render().

    if (!empty($output)) {
      $classes = filter_xss_admin($this->options['classes']);
      if (!empty($classes)) {
        $tag['element'] = array(
          '#tag'       => 'span',
          '#value'     => $output,
        );
        $tag['element']['#attributes']['class'] = explode(', ', $classes);
        return theme_html_tag($tag);
      }
    }
    return $output;
  }

}
