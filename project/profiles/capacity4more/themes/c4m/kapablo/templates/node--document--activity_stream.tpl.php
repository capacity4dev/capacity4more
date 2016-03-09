<?php
/**
 * @file
 * Display a node in "Activity stream" view mode.
 *
 * @see node.tpl.php
 */

// We hide the comments and links now so that we can render them later.
hide($content['comments']);
hide($content['links']);
?>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
    <?php print render($content); ?>
  </div>
  <div class="row">
    <?php print $download_link; ?>
    <?php print $file_info; ?>
  </div>
</div>
