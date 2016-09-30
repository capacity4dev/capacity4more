<?php

/**
 * @file
 * Prints out the list of featured groups.
 */
?>
<?php if (!empty($groups)): ?>
  <div class="sidebarblock featured-groups">
    <h2 class="sidebarblock__title"><?php print t('Featured Groups') ?></h2>
    <div class="sidebarblock__content">
      <?php print $groups ?>
    </div>
  </div>
<?php endif; ?>
