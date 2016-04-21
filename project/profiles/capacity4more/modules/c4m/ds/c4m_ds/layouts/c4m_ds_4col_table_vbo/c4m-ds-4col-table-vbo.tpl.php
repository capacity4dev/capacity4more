<?php
/**
 * @file
 * Four column layout to use in "table" views with views bulk operations.
 */
?>


<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes; ?>">
<?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
<?php endif; ?>

<div class="content clearfix">
  <<?php print $first_wrapper; ?> class="content-first <?php print $first_classes; ?>">
    <?php print $first; ?>
  </<?php print $first_wrapper; ?>>
  <<?php print $second_wrapper; ?> class="content-second <?php print $second_classes; ?>">
    <?php print $second; ?>
  </<?php print $second_wrapper; ?>>
  <<?php print $third_wrapper; ?> class="content-third <?php print $third_classes; ?>">
    <?php print $third; ?>
  </<?php print $third_wrapper; ?>>
  <<?php print $fourth_wrapper; ?> class="content-fourth <?php print $fourth_classes; ?>">
    <?php print $fourth; ?>
  </<?php print $fourth_wrapper; ?>>
</div>

</<?php print $layout_wrapper ?>>


<!-- Needed to activate display suite support on forms -->
<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
