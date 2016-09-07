<?php

/**
 * @file
 * Prints out a list of all the groups the user is member of.
 */
?>

<div class="row">
  <div class="col-md-12 right">
    <div class="my-groups panel-pane">
      <h2 class="pane-title"><?php print t('My Groups') ?></h2>
      <?php print $groups; ?>
      <a class="see-more-link" href="<?php print $link; ?>">
        <?php print t('Show more') ?>
        <i class="fa fa-chevron-right"></i>
      </a>
    </div>
  </div>
</div>
