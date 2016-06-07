<?php
/**
 * @file
 * Custom menu theme implementation to display a block.
 */
?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> group-navigation"<?php print $attributes; ?>>

  <span class="label">GROUP</span>
  <span class="label">DRAFT</span>

  <button type="button" class="navbar-toggle collapsed header-actions--navigation" data-toggle="collapse" data-target="#c4m-og-menu">
    <span class="sr-only">Toggle navigation</span>
    <span class="icon-bar"></span>
    <span class="icon-bar"></span>
    <span class="icon-bar"></span>
  </button>

  <nav role="navigation" class="collapse navbar-collapse" id="c4m-og-menu">
        <?php print $content ?>
  </nav>
</div>
