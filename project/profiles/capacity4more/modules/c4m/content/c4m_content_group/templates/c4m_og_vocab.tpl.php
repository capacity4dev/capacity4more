<?php

/**
 * @file
 * Template for the Vocabulary topics.
 */
?>
<div>
  <p class="taxonomy-title"><?php print $root ?></p>

  <?php if ($tree): ?>
    <div class="taxonomy-item">
      <i class="fa fa-caret-right" aria-hidden="true"></i>
      <?php print $tree; ?>
    </div>
  <?php endif; ?>
</div>
