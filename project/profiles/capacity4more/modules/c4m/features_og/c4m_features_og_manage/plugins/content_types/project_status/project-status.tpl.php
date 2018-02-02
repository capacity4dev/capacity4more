<?php

/**
 * @file
 * Project status template for the group status.
 */
?>

<div class="row project-management-dashboard">
  <div class="col-md-12 project-management-wrapper right">
    <div class="group-membership-wrapper panel-pane">
      <div class="title">
        <h2><?php print $info['project_title']; ?></h2>
      </div>
      <div class="row">
        <div class="col-md-12 text-justify"><?php print $info['manage_members_link'] ?></div>
      </div>
    </div>
      <div class="group-statistics-wrapper panel-pane">
          <div class="title">
              <h2><?php print t('Project statistics') ?></h2>
          </div>
          <div class="row">
              <div class="col-md-12 text-justify"><?php print t('View / Filter / Export'); ?></div>
          </div>
          <div class="row">
              <div class="col-md-12 text-justify"><?php print $info['content_statistics']; ?></div>
          </div>
          <div class="row">
              <div class="col-md-12 text-justify"><?php print $info['member_statistics']; ?></div>
          </div>
      </div>
    <div class="thumbnail-image panel-pane">
      <div class="title">
        <h2><?php print t('Thumbnail image') ?></h2>
      </div>
      <div class="row">
        <div class="col-md-12"><?php print $info['thumbnail_image'] ?></div>
      </div>
    </div>
  </div>
</div>
