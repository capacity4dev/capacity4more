<?php

/**
 * @file
 * Template to render the CTA block for a visitor.
 */
?>
<div class="<?php print $wrapper_class; ?>">
  <?php if (isset($text_class)) { ?>
  <span class="<?php print $text_class; ?>">
  <?php
  }
  else {
  ?>
  <span>
  <?php } ?>
      <i class="fa <?php print $icon; ?>"></i>
    <?php print $text; ?>
  </span>
</div>
