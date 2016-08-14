<?php

/**
 * @file
 * Template for the taxonomy tree.
 */
?>
<div class="item">
  <p class="taxonomy-title"><?php print $root ?></p>

  <?php if (!empty($local_tree)): ?>
    <p class="taxonomy-item">
      <i class="fa fa-caret-right" aria-hidden="true"></i>
      <?php print $local_tree; ?>
    </p>
  <?php endif; ?>
</div>
