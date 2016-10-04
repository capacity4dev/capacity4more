<?php

/**
 * @file
 * Prints out the list of featured projects.
 */
?>
<?php if (!empty($projects)): ?>
  <div class="sidebarblock featured-projects">
    <h2 class="sidebarblock__title closely"><?php print t('Featured Projects') ?></h2>
    <?php print $projects ?>
  </div>
<?php endif; ?>
