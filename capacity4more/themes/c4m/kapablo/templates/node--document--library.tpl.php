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
    <div class="col-sm-3">
      <!--Document preview-->
      <?php print $preview; ?>
    </div>
    <div class="col-sm-9">
      <div class="row">
        <h2> <img src="missing_icon.png"/> <a href="javascript://"> <?php print $node->title; ?> </a></h2>
      </div>
      <div class="row">
        <span> <?php print $document_data; ?> </span>
      </div>
      <div class="row">
        <?php print $file_info; ?>
      </div>
    </div>
  </div>


</div>
