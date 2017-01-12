<?php

/**
 * @file
 * Overwrite default header tpl to include the windows UTF-8 BOM.
 */

// Print out header row, if option was selected.
if ($options['header']) {
  // Begin file with UTF-8 BOM.
  print "\xEF\xBB\xBF";
  // Now continue to output header as normal.
  print implode($separator, $header) . "\r\n";
}