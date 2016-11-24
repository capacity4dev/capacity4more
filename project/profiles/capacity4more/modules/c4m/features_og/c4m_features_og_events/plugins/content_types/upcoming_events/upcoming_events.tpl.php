<?php

/**
 * @file
 * Upcoming events panel template.
 */
?>

<?php
$classes = '';
if ($display_see_more) {
  $classes = ' pane--more';
}
?>

<div class="sidebarblock upcoming-events<?php print $classes; ?>">
  <h2 class="sidebarblock__title closely"><?php print t('Upcoming events') ?></h2>
  <?php print $events; ?>

  <?php if ($display_see_more): ?>
  <div class="sidebarblock__viewmore">
    <a class="see-more-link" href="<?php print url('events/upcoming', array('absolute' => TRUE, 'query' => drupal_get_query_parameters())); ?>"><?php print t('See more') ?> <i class="fa fa-chevron-right"></i></a>
  </div>
  <?php endif; ?>

</div>
