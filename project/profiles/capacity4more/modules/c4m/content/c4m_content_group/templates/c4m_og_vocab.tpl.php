<?php

/**
 * @file
 * Template for the Vocabulary topics.
 */
?>
<div class="">
  <p class="taxonomy-title"><?php print $tree['root'] ?></p>

  <?php foreach ($tree['children'] as $child): ?>
    <div class="taxonomy-item">
      <i class="fa fa-caret-right" aria-hidden="true"></i>
      <?php print $child; ?>
    </div>
  <?php endforeach; ?>
</div>
