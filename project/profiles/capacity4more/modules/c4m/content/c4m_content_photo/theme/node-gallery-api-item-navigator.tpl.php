<?php

/**
 * @file
 * Default theme implementation to show the image gallery navigator.
 *
 * Available variables:
 *
 * @todo: fill this in
 *
 * @see theme_preprocess_node_gallery_api_item_navigator()
 */
?>

<nav class="photoalbum-navigator row">
  <div class="navigator--left">
    <?php print isset($prev_link) ? l(
      '<i class="fa fa-chevron-left"></i>',
      $prev_link,
      array('html' => TRUE)
    ) : ''; ?>
  </div>
  <div class="navigator--center">
    <?php if ($gallery_link): ?>
      <div class="back-link">
        <?php print l(t("Back to photo album"), $gallery_link) ?>
      </div>
    <?php endif; ?>
    <?php if ($navigator['total'] > 0): ?>
      <div class="indicator label label-primary">
      <?php print t(
        "Photo %current of %total",
        array(
          '%current' => $navigator['current'],
          '%total' => $navigator['total'],
        )
      );
      ?>
      </div>
    <?php endif; ?>
  </div>
  <div class="navigator--right">
    <?php print isset($next_link) ? l(
      '<i class="fa fa-chevron-right"></i>',
      $next_link,
      array('html' => TRUE)
    ) : ''; ?>
  </div>
</nav>
