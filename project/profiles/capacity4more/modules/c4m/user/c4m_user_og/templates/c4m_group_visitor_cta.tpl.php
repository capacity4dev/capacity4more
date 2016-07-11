<?php

/**
 * @file
 * Template to render the CTA block for a visitor.
 */
?>
<div class="c4m-group-visitor-cta">
  <button class="btn">
    <i class="fa <?php print $button_icon; ?>"></i>
    <?php print $button_label; ?>
  </button>
  Please <?php print $login_url; ?> first if you have a C4D account
</div>
