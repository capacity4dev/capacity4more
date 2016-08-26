<?php

/**
 * @file
 * Template for presenting additional information fields.
 *
 * Type, Status and Access at content group header title.
 */
?>

<?php if ($title): ?>
  <h1 class="group-title">
    <?php print $title; ?>
  </h1>
<?php endif; ?>

<div class="group-indications">

  <div class="group-indications--access">
    <?php if ($group_access): ?>
      <i class="top-buffer group-icon group-<?php print $group_access; ?> node-icon as-group-<?php print $group_access; ?>"></i>
      <span class="top-buffer indication label label-access <?php print $group_access; ?> group-access">
    <?php print $group_access; ?>
  </span>
    <?php endif; ?>


    <?php if ($organisations): ?>
      <?php if ($organisation_icons): ?>
        <div class="restricted-organisation-icons">
          <?php foreach ($organisation_icons as $organisation_icon) : ?>
            <span class="restricted-organisation-icon">
            <?php print $organisation_icon; ?>
          </span>
          <?php endforeach; ?>

          <?php if ($organisation_ellipsis): ?>
            <span class="group-organisation--more" data-toggle="collapse" data-target="#group-organisations" >
                <span></span>
                <span></span>
                <span></span>
          </span>
          <?php endif; ?>
        </div>
      <?php endif; ?>

      <div class="restricted-extra-wrapper collapse" id="group-organisations">
      <span class="extra-wrapper-close" data-toggle="collapse" data-target="#group-organisations">
        <span class="extra-wrapper-close-background"></span>
        <span class="extra-wrapper-close-bullet"></span>
        <span class="extra-wrapper-close-bullet"></span>
        <span class="extra-wrapper-close-bullet"></span>
      </span>

        <div class="restricted-organisations">
          <ul>
            <?php foreach ($organisations as $organisation) : ?>
              <li><?php print $organisation; ?></li>
            <?php endforeach; ?>
          </ul>
        </div>
        <div class="restricted-emails">
          <ul>
            <?php foreach ($emails as $email) : ?>
              <li><?php print $email; ?></li>
            <?php endforeach; ?>
          </ul>
        </div>
      </div>
    <?php endif; ?>
  </div>
  <?php
  if ($group_type):
    print render($group_type);
  endif;
  if ($group_status):
    print render($group_status);
  endif;
  ?>
</div>
