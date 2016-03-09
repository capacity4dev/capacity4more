<?php

/**
 * @file
 * getlocations_marker_box.tpl.php
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Template file for colorbox implementation
 * @ingroup themeable
 */

?>
<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">
<!-- getlocations_marker_box -->
<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
<style>
/* adjust these to match your colorbox size */
  body {
    width: 460px;
    margin: 0;
  }
  #page {
    width: 100%;
    margin: 0px 0px 0px 0px;
    padding: 0px 0px 0px 0px;
  }
  #content-area {
  }
  table, tbody, tr, td, th {
    border: 0;
  }
  td {
    text-align: center;
  }
</style>
<?php
  $title = t('Getlocations marker');
  if (isset($content['cat'])) {
    if ($content['cat'] == 'n') {
      $title = t('Getlocations Node marker');
    }
    elseif ($content['cat'] == 'u') {
      $title = t('Getlocations User marker');
    }
    elseif ($content['cat'] == 'v') {
      $title = t('Getlocations Vocabulary marker');
    }
    elseif ($content['cat'] == 'c') {
      $title = t('Getlocations Comment marker');
    }
    elseif ($content['cat'] == 'i') {
      $title = t('Getlocations Input marker');
    }
  }
?>
</head>

<body class="<?php print $body_classes; ?>">

  <div id="page"><div id="page-inner">
    <div id="main"><div id="main-inner" class="clear-block">
      <div id="content"><div id="content-inner">
<?php
  if ($title) {
    print '<h2 class="title">' . $title . '</h2>';
    print '<p>' . t('To select an icon click on it and close the box.') . '</p>';
  }
?>
        <div id="content-area">
<?php
  $data = $content['data'];
  $linktype = $content['linktype'];
  $output = '';
  $ct = 0;
  // number of columns
  $numcols = 12;
  $output .= '<table>';
  foreach (array_keys($data) AS $k) {
    if ($ct == 0) {
      $output .= '<tr>';
    }
    $output .= '<td><a href="#" onClick="Drupal.getlocations_marker_box.getlocations_marker_get(\'' . $data[$k]['machine_name'] . '\', \'' . $linktype . '\'); return false;" ><img src="' . base_path() .  $data[$k]['path'] . '" title="' . $data[$k]['display_name'] . '"></a></td>';
    $ct++;
    if ($ct >= $numcols) {
      $output .= '</tr>';
      $ct = 0;
    }
  }
  // fill in empty tds
  if ($ct > 0) {
    for ($ct2 = $ct; $ct2 < $numcols; $ct2++) {
      $output .= '<td>&nbsp;</td>';
    }
    $output .= '</tr>';
  }
  $output .= '</table>';
  print $output;
?>
        </div>
      </div></div>
    </div></div>
  </div></div>
  <?php print $closure; ?>
</body>
</html>
