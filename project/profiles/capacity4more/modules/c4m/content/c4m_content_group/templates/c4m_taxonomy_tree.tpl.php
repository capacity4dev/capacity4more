<?php

/**
 * @file
 * Template for the taxonomy tree.
 */
?>
<div class="item">
  <span class="taxonomy-root"><?php print $root ?></span>

  <?php if (!empty($local_tree)): ?>
    <span class="taxonomy-tree">
      <i class="fa fa-caret-right" aria-hidden="true"></i>
      <?php print $local_tree; ?>
    </span>
  <?php endif; ?>
</div>
