<?php
/**
 * @file
 * Bootstrap 8-4 template for Display Suite.
 */
?>

<<?php print $layout_wrapper;
print $layout_attributes; ?> class="<?php print $classes; ?>">
<?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
<?php endif; ?>

<div class="content clearfix">

  <div class="clearfix">
        <div class="event-date">
          <?php print $left; ?>
        </div>
        <div class="event-title">
          <?php print $right; ?>
        </div>
  </div>

  <div class="event-groups">
    <?php print $footer; ?>
  </div>

</div>

</<?php print $layout_wrapper ?>>

<!-- Needed to activate display suite support on forms -->
<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
