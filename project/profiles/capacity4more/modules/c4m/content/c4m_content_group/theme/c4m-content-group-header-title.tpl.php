<?php

/**
 * @file
 * Template for presenting additional information fields.
 *
 * Type, Status and Access at content group header title.
 */
?>

<?php if($title): ?>
  <h1>
    <?php print $title; ?>
  </h1>
<?php endif; ?>

<?php if ($group_type): ?>
  <span class="top-buffer indication label label-default">
    <?php print $group_type; ?>
  </span>
<?php endif; ?>

<?php if ($group_access): ?>
  <i class="top-buffer group-icon group-<?php print $group_access; ?> node-icon as-group-<?php print $group_access; ?>"></i>
  <span class="top-buffer indication label label-access <?php print $group_access; ?>">
    <?php print $group_access; ?>
  </span>
<?php endif; ?>

<?php if ($group_status): ?>
  <span class="top-buffer indication label label-default">
    <?php print $group_status; ?>
  </span>
<?php endif; ?>
