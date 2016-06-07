<?php
/**
 * @file
 * Custom menu theme implementation to display a block.
 */
?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> row"<?php print $attributes; ?>>
  <nav class="navbar col-sm-12" role="navigation">
      <!-- Brand and toggle get grouped for better mobile display -->
      <div class="navbar-header">
        <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#c4m-og-menu">
          <span class="sr-only">Toggle navigation</span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
        </button>
      </div>

      <!-- Collect the nav links, forms, and other content for toggling -->
      <div class="collapse navbar-collapse" id="c4m-og-menu">
        <?php print $content ?>
      </div>
  </nav>
</div>
<!-- TODO: remove include of this PHP file? -->
