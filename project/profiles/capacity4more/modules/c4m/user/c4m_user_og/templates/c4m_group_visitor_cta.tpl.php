<?php

/**
 * @file
 * Template to render the CTA block for a visitor.
 */
?>
<div class="c4m-group-visitor-cta">
  <a class="btn" href="<?php print $button_link; ?>">
    <i class="fa <?php print $button_icon; ?>"></i>
    <?php print $button_label; ?>
  </a>
  Please <?php print $login_url; ?> first if you have a C4D account
</div>
