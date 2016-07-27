<?php

/**
 * @file
 * Group status template for the group status.
 */
?>

<div class="row group-management-dashboard">
  <div class="col-md-12 group-management-wrapper right">
    <div class="group-status panel-pane">
      <div class="title">
        <h2><?php print t('Group status') ?></h2>
      </div>
      <div class="row">
        <div class="col-md-4 group-status-text"><?php print $info['status'] ?></div>
        <div class="col-md-8 archive-group"><?php print $info['archive_link'] ?></div>
      </div>
      <div class="row">
        <div class="col-md-12"><?php print $info['pending_members_link'] ?> <?php print t('are waiting for approval.') ?></div>
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
