<?php

/**
 * @file
 * Template to render the CTA block for a visitor.
 */
?>
<div class="<?php print $wrapper_class; ?>">
  <span<?php if (isset($text_class)) print ' class="' . $text_class . '"'; ?>>
      <i class="fa <?php print $icon; ?>"></i>
    <?php print $text; ?>
  </span>
</div>
