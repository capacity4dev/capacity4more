<?php

/**
 * @file
 * Template to render the CTA block for a visitor.
 */
?>
<div class="c4m-wide-gothic-btn">
  <a class="btn text-small" href="<?php print $url; ?>">
    <i class="fa <?php print $button_icon; ?>"></i>
    <?php print $button_label; ?>
  </a>
  <div class="c4m-visitor-login-link"><?php print $login_url; ?></div>
</div>
