<?php

/**
 * @file
 * Bootstrap 8-4 template for Display Suite.
 */
?>

<<?php print $layout_wrapper; print $layout_attributes; ?> class="cols-3 <?php print $classes; ?>">
<?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
<?php endif; ?>

<div class="content clearfix">
  <div class="icon-wrapper clearfix">
    <<?php print $left_wrapper; ?> class="icon-col <?php print $left_classes; ?>">
      <?php print $left; ?>
    </<?php print $left_wrapper; ?>>
    <<?php print $middle_wrapper; ?> class="content-middle <?php print $middle_classes; ?>">
      <?php print $middle; ?>
    </<?php print $middle_wrapper; ?>>
    <<?php print $right_wrapper; ?> class="content-right <?php print $right_classes; ?>">
      <?php print $right; ?>
    </<?php print $right_wrapper; ?>>
  </div>
</div>

</<?php print $layout_wrapper ?>>


<!-- Needed to activate display suite support on forms -->
<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
