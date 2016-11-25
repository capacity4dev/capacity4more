<?php

/**
 * @file
 * Template to render the CTA block for the management links.
 */
?>
<div class="c4m-group-cta">
  <?php if ($title): ?>
    <h3 class="pane-title"><?php print $title; ?></h3>
  <?php endif; ?>
  <?php foreach ($links as $link): ?>
    <?php print render($link); ?>
  <?php endforeach; ?>
</div>
