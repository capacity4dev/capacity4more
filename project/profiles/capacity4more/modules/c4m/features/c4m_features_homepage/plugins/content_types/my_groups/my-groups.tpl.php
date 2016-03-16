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
      <?php print $first_groups ?>
      <div class="collapse" id="allGroups">
        <?php print $extra_groups ?>
      </div>
      <?php if ($show_all_link) : ?>
        <a class="see-more-link" id="toggleMyGroups" href="javascript://" data-toggle="collapse" data-target="#allGroups" aria-expanded="false" aria-controls="allGroups">
          <?php print t('Show all') ?>
          <i class="fa fa-chevron-right"></i>
        </a>
      <?php endif; ?>
    </div>
  </div>
</div>
