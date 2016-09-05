<?php

/**
 * @file
 * Template for the taxonomy tree.
 */
?>
<div class="item <?php print $class ?>">
  <div class="taxonomy-root"><?php print $root ?></div>

  <?php if (!empty($local_tree)): ?>
    <div class="taxonomy-tree">
      <i class="fa fa-caret-right" aria-hidden="true"></i>
      <?php print $local_tree; ?>
    </div>
  <?php endif; ?>
</div>
