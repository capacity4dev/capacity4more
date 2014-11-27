<?php
/**
 * @file
 * Handler to add links to user selected page displays of current view.
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
   * Retrieve the paths to page displays of this view.
   */
  function allowed_displays() {
    $paths = array();
    foreach($this->view->display as $display) {
      if ('page' == $display->display_plugin &&
        !empty($display->display_title) &&
        !empty($display->display_options['path'])) {
        $paths[$display->display_options['path']] = $display->display_title
          ;
      }
    }
    return $paths;
  }

  function option_definition() {
    $options = parent::option_definition();

    /*foreach($this->allowed_displays() as $path => $title) {
      $suffix = '_' . str_replace('/', '_', $path);
      $options['link_enable' . $suffix] = array(
        'default' => FALSE,
        'bool' => TRUE
      );
      $options['link_text' . $suffix] = array(
        'default' => '',
        'translatable' => TRUE,
      );
      $options['link_class' . $suffix] = array('default' => '');
    }*/

    return $options;
  }

   function options_form(&$form, &$form_state) {
     parent::options_form($form, $form_state);

     // Retrieve the paths to page displays of current View.
     foreach($this->allowed_displays() as $path => $title) {
       $suffix = '_' . str_replace('/', '_', $path);
       $form['page_displays'. $suffix] = array(
         '#type' => 'fieldset',
         '#title' => t('View page with title !title and path !path',
           array('!title' => $title, '!path' => $path)),
         '#collapsible' => TRUE,
         '#collapsed' => FALSE,
       );
       $form['link_enable' . $suffix] = array(
         '#type' => 'checkbox',
         '#title' => t('Add link to page with title !title and path !path',
           array('!title' => $title, '!path' => $path)),
         '#default_value' => isset($this->options['link_enable' . $suffix]) ?
           $this->options['link_enable' . $suffix] : TRUE,
         '#fieldset' => 'page_displays'. $suffix,
       );
       $form['link_text' . $suffix] = array(
         '#type' => 'textfield',
         '#required' => TRUE,
         '#title' => t('Link text'),
         '#description' => t('Set the label for the link.'),
         '#default_value' => $this->options['link_text' . $suffix],
         '#fieldset' => 'page_displays'. $suffix,
       );
       $form['link_class' . $suffix] = array(
         '#type' => 'textfield',
         '#required' => TRUE,
         '#title' => t('Link class'),
         '#description' => t('Optionally set an additional class for the link.'),
         '#default_value' => $this->options['link_class' . $suffix],
         '#fieldset' => 'page_displays'. $suffix,
       );
     }
  }

  /**
   * Find out the information to render.
   */
  function render($empty = FALSE) {
    foreach($this->options as $path => $title) {

    }
    $link_path = filter_xss_admin($this->options['link_path']);
    $link_text = filter_xss_admin($this->options['link_text']);
    $link_class = filter_xss_admin($this->options['link_class']);
    if (!$link_path || !$link_text) {
      return;
    }

    // This handler is not to add custom paths.
    // Check if path is page of current View.
    if (!in_array($link_path, $this->allowed_displays())) {
      return;
    }

    $options = array();
    if (!empty($link_class)) {
      $options = array(
        'attributes' => array(
          'class' => array($link_class),
        )
      );
    }

    return l($link_text, $link_path, $options);
  }
}

