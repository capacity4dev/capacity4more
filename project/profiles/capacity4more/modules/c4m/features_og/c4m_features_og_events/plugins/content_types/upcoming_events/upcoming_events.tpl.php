<?php
/**
 * @file
 * Upcoming events panel template.
 */
?>

<div class="row">
  <div class="col-md-12 right">
    <div class="upcoming-events panel-pane">
      <h2 class="pane-title"><?php print t('Upcoming events') ?></h2>
      <?php print $events; ?>
      <a class="see-more-link" href="<?php print url('events/upcoming', array('absolute' => TRUE)); ?>">
          <?php print t('See more') ?>
          <i class="fa fa-chevron-right"></i>
        </a>
    </div>
  </div>
</div>
