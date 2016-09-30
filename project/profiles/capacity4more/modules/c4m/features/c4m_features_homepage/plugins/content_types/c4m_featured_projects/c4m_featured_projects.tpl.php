<?php

/**
 * @file
 * Prints out the list of featured projects.
 */
?>
<?php if (!empty($projects)): ?>
  <div class="sidebarblock featured-projects">
    <h2 class="sidebarblock__title"><?php print t('Featured Projects') ?></h2>
    <div class="sidebarblock__content">
      <?php print $projects ?>
    </div>
  </div>
<?php endif; ?>
