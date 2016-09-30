<?php

/**
 * @file
 * Prints out the list of suggested groups.
 */
?>

<div class="sidebarblock suggested-groups">
  <h2 class="sidebarblock__title"><?php print t('Suggested Groups') ?></h2>
  <div class="sidebarblock__content">
    <?php print $groups ?>
  </div>
  <div class="sidebarblock__viewmore">
    <a href="<?php print $link; ?>"><?php print t('See more') ?><i class="fa fa-chevron-right"></i></a>
  </div>
</div>
