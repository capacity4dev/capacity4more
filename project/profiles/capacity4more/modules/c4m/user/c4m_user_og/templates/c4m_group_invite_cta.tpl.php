<?php

/**
 * @file
 * Template to render a link in the CTA block.
 */
?>
<div class="c4m-group-invite-cta">
  <a class="btn" href="<?php print $url; ?>">
    <i class="fa <?php print $button_icon; ?>"></i>
    <?php print $button_label; ?>
  </a>
</div>
