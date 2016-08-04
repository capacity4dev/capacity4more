<?php

/**
 * @file
 * Prints out the list of suggested groups.
 */
?>

<div class="row">
  <div class="col-md-12 right">
    <div class="suggested-groups panel-pane">
      <h2 class="pane-title"><?php print t('Suggested Groups') ?></h2>
      <?php print $groups ?>
      <a class="see-more-link" href="<?php print $link; ?>">
        <?php print t('See more') ?>
        <i class="fa fa-chevron-right"></i>
      </a>
    </div>
  </div>
</div>
