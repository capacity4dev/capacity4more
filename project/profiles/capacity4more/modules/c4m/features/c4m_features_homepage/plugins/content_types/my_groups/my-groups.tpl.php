<?php

/**
 * @file
 * Prints out a list of all the groups the user is member of.
 */
?>

<div class="sidebarblock my-groups">
  <h2 class="sidebarblock__title closely"><?php print t('My Groups') ?></h2>
  <?php print $groups; ?>
  <div class="sidebarblock__viewmore">
    <?php if ($display_see_more): ?>
    <a class="see-more-link" href="<?php print $link; ?>"><?php print t('Show more') ?> <i class="fa fa-chevron-right"></i></a>
    <?php endif; ?>
  </div>
</div>
