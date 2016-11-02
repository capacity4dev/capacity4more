<?php

/**
 * @file
 * Prints out the list of suggested projects.
 */
?>

<div class="row">
  <div class="col-md-12 right">
    <div class="suggested-projects panel-pane">
      <h2 class="pane-title"><?php print t('Suggested projects') ?></h2>
      <?php print $projects ?>
      <a class="see-more-link" href="<?php print $link; ?>">
        <?php print t('See more') ?>
        <i class="fa fa-chevron-right"></i>
      </a>
    </div>
  </div>
</div>
