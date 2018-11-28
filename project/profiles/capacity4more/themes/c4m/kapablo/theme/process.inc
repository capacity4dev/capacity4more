<?php

/**
 * @file
 * All process functionality.
 */

/**
 * Overrides template_process_html().
 *
 * Add DG COMM satisfaction survey.
 */
function kapablo_process_html(&$variables) {
  $variables['page_bottom'] .= '<script type="text/javascript" src="https://ec.europa.eu/wel/surveys/wr_survey01/wr_survey.js"></script>';
}
