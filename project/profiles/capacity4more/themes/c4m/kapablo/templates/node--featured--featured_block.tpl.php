<?php
/**
 * @file
 * Display a node featured in "Featured block" view mode.
 *
 * @see node.tpl.php
 */
?>

<div class="col-sm-4">
  <a href="<?php print $link; ?>">
    <?php print render($content['c4m_media']); ?>
    <div class="caption">
      <span><?php print $title; ?></span>
      <div class="description"><?php print render($content['c4m_body']); ?></div>
    </div>
  </a>
</div>
