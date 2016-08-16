<?php

/**
 * @file
 * Template to render the CTA block for a visitor.
 */
?>
<div class="<?php print $classes; ?>">
  <a class="btn text-small" href="<?php print $url; ?>">
    <i class="fa <?php print $button_icon; ?>"></i>
    <?php print $button_label; ?>
  </a>
</div>
