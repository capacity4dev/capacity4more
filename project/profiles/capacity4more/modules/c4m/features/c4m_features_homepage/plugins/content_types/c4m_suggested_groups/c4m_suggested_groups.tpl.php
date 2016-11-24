<?php

/**
 * @file
 * Prints out the list of suggested groups.
 */
?>

<?php
$classes = '';
if ($display_more_button) {
  $classes = ' pane--more';
}
?>

<div class="sidebarblock suggested-groups<?php print $classes; ?>">
  <h2 class="sidebarblock__title closely"><?php print t('Suggested Groups') ?></h2>
  <?php print $groups ?>
  <?php if ($display_more_button): ?>
  <div class="sidebarblock__viewmore">
    <a href="<?php print $link; ?>"><?php print t('See more') ?> <i class="fa fa-chevron-right"></i></a>
  </div>
  <?php endif; ?>
</div>
