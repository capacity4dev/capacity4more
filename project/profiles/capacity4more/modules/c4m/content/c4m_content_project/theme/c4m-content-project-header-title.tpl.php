<?php

/**
 * @file
 * Template for presenting additional information fields.
 *
 * Type, Status and Stage at content project header title.
 */
?>

<?php if ($title): ?>
  <h1 class="project-title">
    <?php print $title; ?>
  </h1>
<?php endif; ?>

<div class="project-indications">

  <div class="project-indications--stage">
    <?php if ($project_stage): ?>
      <i class="fa <?php print $flag_icon; ?> top-buffer project-icon project-<?php print $project_stage; ?> node-icon as-project-<?php print $project_stage; ?>"></i>
      <span class="top-buffer indication label label-stage <?php print $project_stage; ?> project-stage">
        <?php print $stage_label; ?>
      </span>
    <?php endif; ?>
  </div>

  <?php if ($type): ?>
    <span class="top-buffer indication label label-default project-type"><?php print $type; ?></span>
  <?php endif; ?>
  
  <?php if ($status): ?>
    <span class="top-buffer indication label label-default project-status"><?php print $status; ?></span>
  <?php endif; ?>
</div>
