<?php

/**
 * @file
 * Template for the taxonomy tree.
 */
?>
<div class="">
  <p class="taxonomy-title"><?php print $root ?></p>

  <?php if (!empty($local_tree)): ?>
    <i class="fa fa-caret-right" aria-hidden="true"></i>
    <?php print $local_tree; ?>
  <?php endif; ?>
</div>
