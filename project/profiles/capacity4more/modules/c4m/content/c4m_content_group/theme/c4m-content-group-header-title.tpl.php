<?php

/**
 * @file
 * Template for presenting additional information fields (type, status and
 * access) at content group header title.
 */
?>
<div class="row" id="content-group-header-title">
  <div class="col-sm-12 col-md-8">
    <h1><?php print $title;?></h1>
  </div>
  <div class="col-sm-12 col-md-4" id="content-group-header-title-right-div">
    <div class="row">
      <div class="col-xs-offset-7 col-xs-5">
        <div class="top-buffer indication indication-type">
          group
        </div>
      </div>
    </div>
    <div class="row">
      <div class="col-xs-2">
        <span class="top-buffer group-icon group-<?php print $group_access; ?> node-icon as-group-<?php print $group_access; ?>"></span>
      </div>
      <div class="col-xs-5">
        <div class="top-buffer indication indication-access <?php print $group_access; ?>">
          <?php print $group_access; ?>
        </div>
      </div>
      <div class="col-xs-5">
        <div class="top-buffer indication indication-status">
          <?php print $group_status; ?>
        </div>
      </div>
    </div>
  </div>
</div>
