<?php

/**
 * @file
 * Override default bootstrap 2 col panel to print empty regions.
 */
?>

<div class="<?php print $classes ?>" <?php print (empty($css_id)) ? "id=\"$css_id\"" : ''; ?>>
  <div class="row">
    <?php print $content['top']; ?>
  </div>
  <div class="row">
    <?php if ($content['left']): ?>
      <?php print $content['left']; ?>
    <?php else: ?>
      <div class="group-left col-sm-8"></div>
    <?php endif; ?>

    <?php if ($content['right']): ?>
      <?php print $content['right']; ?>
    <?php else: ?>
      <div class="group-right col-sm-4"></div>
    <?php endif; ?>
  </div>
  <div class="row">
    <?php print $content['bottom']; ?>
  </div>
</div>
