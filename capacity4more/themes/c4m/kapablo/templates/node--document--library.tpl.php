<?php

/**
 * @file
 * Display a node in "Activity stream" view mode.
 *
 * @see node.tpl.php
 */
?>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="row">
    <div class="col-sm-1">
      <img src="missing_icon.png"/>
    </div>
    <div class="col-sm-11">
      <h2> <a href="javascript://"> <?php print $node->title; ?> </a></h2>
    </div>
  </div>
  <div class="row">
    <span> <?php print $document_data; ?> </span>
  </div>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>
  <div class="row">
    <?php print $file_info; ?>
  </div>

</div>
