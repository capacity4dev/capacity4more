<?php

/**
 * @file
 * Template for presenting additional information fields.
 *
 * Type, Status and Access at content group header title.
 */
?>

<?php if ($title): ?>
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

  <?php if ($organisations): ?>
    <?php if ($organisation_icons): ?>
      <div class="restricted-organisation-icons">
        <?php foreach ($organisation_icons as $organisation_icon) : ?>
          <span class="restricted-organisation-icon">
            <?php print $organisation_icon; ?>
          </span>
        <?php endforeach; ?>

        <?php if ($organisation_ellipsis): ?>
          <span class="restricted-organisation-icon ellipsis">
            ...
          </span>
        <?php endif; ?>
      </div>
    <?php endif; ?>

    <div class="restricted-extra-wrapper">
      <div class="restricted-organisations">
        <?php foreach ($organisations as $organisation) : ?>
          <?php print $organisation; ?>
        <?php endforeach; ?>
      </div>
      <div class="restricted-emails">
        <?php foreach ($emails as $email) : ?>
          <?php print $email; ?>
        <?php endforeach; ?>
      </div>
    </div>

  <?php endif; ?>
<?php endif; ?>

<?php if ($group_status): ?>
  <span class="top-buffer indication label label-default">
    <?php print $group_status; ?>
  </span>
<?php endif; ?>
