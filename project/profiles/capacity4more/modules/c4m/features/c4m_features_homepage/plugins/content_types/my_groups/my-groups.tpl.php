<?php

/**
 * @file
 * Prints out a list of all the groups the user is member of.
 */
?>

<div class="sidebarblock my-groups">
  <h2 class="sidebarblock__title closely"><?php print t('Groups') ?></h2>
  <?php print $groups; ?>
  <div class="sidebarblock__viewmore">
    <a class="see-more-link" href="<?php print $link; ?>"><?php print t('Show more') ?> <i class="fa fa-chevron-right"></i></a>
  </div>
</div>
