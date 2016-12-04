<?php

/**
 * @file
 * Template to render the CTA block for the management links.
 */
?>
<div class="c4m-group-cta">
  <?php if ($title): ?>
    <h2 class="pane-title"><?php print $title; ?></h2>
  <?php endif; ?>
  <?php foreach ($links as $link): ?>
    <?php print render($link); ?>
  <?php endforeach; ?>
</div>
