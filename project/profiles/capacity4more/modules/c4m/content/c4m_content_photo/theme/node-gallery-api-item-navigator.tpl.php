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
  <div class="col-xs-4 text-right">
    <?php print isset($prev_link) ? l(
      '<i class="fa fa-arrow-circle-o-left"></i> ' . t('Previous'),
      $prev_link,
      array('html' => TRUE)
    ) : ''; ?>
  </div>
  <div class="col-xs-4 text-center">
    <?php if ($gallery_link): ?>
      <?php print l(t("Back to gallery"), $gallery_link) ?>
    <?php endif; ?>
    <?php if ($navigator['total'] > 0): ?>
      <br/>
      <?php print t(
        "Photo %current of %total",
        array(
          '%current' => $navigator['current'],
          '%total' => $navigator['total'],
        )
      );
      ?>
    <?php endif; ?>
  </div>
  <div class="col-xs-4 text-left">
    <?php print isset($next_link) ? l(
      t('Next') . ' <i class="fa fa-arrow-circle-o-right"></i>',
      $next_link,
      array('html' => TRUE)
    ) : ''; ?>
  </div>
</nav>
