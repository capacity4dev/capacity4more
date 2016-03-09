<?php
/**
 * @file
 * Template to render a single sort list button.
 */
?>
<div class="btn-group search-api-sort">
  <button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown" aria-expanded="false">
    <span class="sort-<?php print implode(' ', $active['#options']['attributes']['class']); ?>"><?php print $active['#name']; ?></span>
  </button>
  <?php print $list; ?>
</div>
