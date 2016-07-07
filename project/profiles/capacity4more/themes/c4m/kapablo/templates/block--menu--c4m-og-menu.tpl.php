<?php

/**
 * @file
 * Custom menu theme implementation to display a block.
 */
?>
<div id="<?php print $block_html_id; ?>"
     class="<?php print $classes; ?> group-navigation"<?php print $attributes; ?>>
  <nav role="navigation" class="collapse navbar-collapse" id="c4m-og-menu">
    <?php if (isset($search_form)): ?>
      <!-- SEARCH-->
      <?php print render($search_form); ?>
    <?php endif; ?>

    <?php print $content; ?>
  </nav>
</div>
<hr class="groupNavigation-divider"/>
