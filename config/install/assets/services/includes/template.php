<?php

/**
 * @file
 * Code to support loading templates.
 */

/**
 * Load template and fill with data.
 *
 * @param string $template
 *   The template file to load relative to the templates directory.
 * @param array $data
 *   The data to use in the template.
 *
 * @return string
 *   The filled in template.
 *
 * @throws Exception
 *   If the template file does not exists.
 */
function services_template_render($template, array $data = array()) {
  $template_file = SERVICES_PATH_TEMPLATES . '/' . trim($template, '/');

  // Check if template exists.
  if (!file_exists($template_file)) {
    throw new Exception(
      sprintf('ERROR : Template file "%s" does not exists.', $template)
    );
  }

  ob_start();
  include $template_file;
  $content = ob_get_contents();
  ob_end_clean();

  return $content;
}
