<?php

/**
 * @file
 * Prints out the list of featured groups.
 */
?>
<?php if (!empty($groups)): ?>
  <div class="sidebarblock featured-groups">
    <h2 class="sidebarblock__title closely"><?php print t('Featured Groups') ?></h2>
    <?php print $groups ?>
  </div>
<?php endif; ?>
