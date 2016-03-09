<?php
/**
 * @file
 * getlocations-view-streetview.tpl.php
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Default simple view template to display a list of rows.
 * Derived from views-view-unformatted.tpl.php
 *
 * @ingroup views_templates
 */
?>
<?php if ($mapid): ?>
<!-- getlocations-view-streetview.tpl -->
  <?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
  <?php endif; ?>
  <div class="getlocations_streetview_wrapper">
    <div id="getlocations_streetview_wrapper_<?php print $mapid; ?>" style="width: <?php print $width .';'; ?> height: <?php print $height; ?>">
      <div class="getlocations_streetview_canvas" id="getlocations_streetview_canvas_<?php print $mapid; ?>" style="width: 100%; height: 100%"></div>
    </div>
  </div>
<!-- /getlocations-view-streetview.tpl -->
<?php endif; ?>
