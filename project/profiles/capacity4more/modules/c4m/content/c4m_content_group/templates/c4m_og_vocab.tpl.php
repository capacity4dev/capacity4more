<?php
/**
 * @file
 * Template for the Vocabulary topics and regions.
 */
?>
<div>
  <p class="taxonomy-title"><?php print l($root->name, "/taxonomy/term/" . $root->tid); ?></p>

  <div class="taxonomy-item">
    <i class="fa fa-caret-right" aria-hidden="true"></i>
    <?php foreach ($tree as $item => $data): ?>
      <?php print l($data->name, "/taxonomy/term/" . $data->tid); ?>,
    <?php endforeach; ?>
  </div>
</div>
