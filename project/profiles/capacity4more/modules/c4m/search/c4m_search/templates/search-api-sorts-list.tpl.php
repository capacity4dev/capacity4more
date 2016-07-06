<?php

/**
 * @file
 * Template to render a single sort list button.
 */
?>
<div class="btn-group search-api-sort">
  <button type="button" class="dropdown-toggle" data-toggle="dropdown" aria-expanded="false">
    <span class="sort-<?php print implode(' ', $active['#options']['attributes']['class']); ?>"><?php echo t('Sort by: @sort', array('@sort' => $active['#name'])); ?></span>
  </button>
  <?php print $list; ?>
</div>
