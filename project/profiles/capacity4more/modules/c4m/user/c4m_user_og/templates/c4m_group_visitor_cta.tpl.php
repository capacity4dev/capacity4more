<?php

/**
 * @file
 * Template to render the CTA block for a visitor.
 */
?>
  <a class="btn btn-primary text-small" href="<?php print $url; ?>">
    <i class="fa <?php print $button_icon; ?>"></i>
    <?php print $button_label; ?>
  </a>
<?php if ($login_url): ?>
  <div class="c4m-visitor-login-link"><?php print $login_url; ?></div>
<?php endif; ?>
