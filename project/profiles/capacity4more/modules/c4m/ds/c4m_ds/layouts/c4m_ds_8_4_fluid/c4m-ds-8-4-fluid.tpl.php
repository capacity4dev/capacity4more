<?php
/**
 * @file
 * Bootstrap 8-4 template for Display Suite.
 */
?>

<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes; ?>">
<?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
<?php endif; ?>

<div class="content clearfix">
<?php if (!empty($header)): ?>
    <<?php print $header_wrapper; ?> class="group-header col-sm-12 <?php print $header_classes; ?>">
      <?php print $header; ?>
    </<?php print $header_wrapper; ?>>
<?php endif; ?>

  <<?php print $left_wrapper; ?> class="group-left col-sm-8 <?php print $left_classes; ?>">

    <div class="trigger js-navigationButton" data-effect="animation--slideOn">
      <span class="trigger-text">Trigger off-canvas right</span>
    </div>

    <?php print $left; ?>
  </<?php print $left_wrapper; ?>>
  <<?php print $right_wrapper; ?> class="group-right col-sm-4 <?php print $right_classes; ?> offCanvasNavigation--right">
    <?php print $right; ?>
  </<?php print $right_wrapper; ?>>
</div>

</<?php print $layout_wrapper ?>>


<!-- Needed to activate display suite support on forms -->
<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
