<?php
/**
 * @file
 * Template for the Vocabulary topics.
 */
?>
<div>
  <p class="taxonomy-title"><?php print l($root->name, "/taxonomy/term/" . $root->tid); ?></p>

  <div class="taxonomy-item">
    <i class="fa fa-caret-right" aria-hidden="true"></i>
    <?php print $tree; ?>
  </div>
</div>
