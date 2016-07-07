<?php

/**
 * @file
 * Custom group header.
 */
?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> group-header"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
    <?php print $content; ?>
    <button type="button" class="collapsed header-actions--navigation" data-toggle="collapse" data-target="#c4m-og-menu">
      <span class="sr-only">Toggle navigation</span>
      <span class="icon-bar"></span>
      <span class="icon-bar"></span>
      <span class="icon-bar"></span>
    </button>
  </div>
</div>
