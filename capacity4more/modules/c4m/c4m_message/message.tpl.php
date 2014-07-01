<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <span class="profile-pic">
    <?php echo $user_picture; ?>
  </span>

  <h6 class="operation <?php print $activity_class; ?>"><?php print render($content); ?></h6>

  <div class="details"><span class="performer"><?php print $user_name; ?></span>,<span class="date"><?php print $created; ?></span></div>
</div>
