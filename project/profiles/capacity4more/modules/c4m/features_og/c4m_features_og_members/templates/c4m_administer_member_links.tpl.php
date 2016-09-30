<?php

/**
 * @file
 * Template to print the membership administration links.
 */
?>

<div class="dropdown">
  <span class="label label-primary dropdown-toggle"
          id="adminster-user-<?php print $user_id; ?>" data-toggle="dropdown"
          aria-expanded="true">
    <?php
    if (!empty($membership_level)):
      print $membership_level;
    endif;
    ?>
    <i class="fa fa-cog"></i>
  </span>
  <ul class="dropdown-menu" role="menu"
      aria-labelledby="adminster-user-<?php print $user_id; ?>">
    <?php print implode('', $links); ?>
  </ul>
</div>
