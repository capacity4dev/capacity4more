<?php
/**
 * @file
 * Template for presenting additional information fields.
 *
 * Type, Status and Access at content group header title.
 */
?>
<div class="row" id="content-project-header-title">
  <div class="col-sm-12 col-md-8">
    <h1>
      <?php print $title;?>
    </h1>
  </div>
  <div class="col-sm-12 col-md-4" id="content-project-header-title-right-div">
    <div class="row">
      <div class="col-xs-2">
        <span class="fa fa-flag<?php print $flag; ?> indication top-buffer project-icon <?php print $prj_stage?>">
        </span>
      </div>
      <div class="col-xs-5">
        <div class="top-buffer indication label label-stage <?php print $prj_stage?>">
          <?php print $stage; ?>
        </div>
      </div>
      <div class="col-xs-5">
        <div class="top-buffer indication label label-default">
          <?php print $type; ?>
        </div>
      </div>
    </div>
    <div class="row">
      <div class="col-xs-offset-7 col-xs-5">
        <div class="top-buffer indication label label-default">
          <?php print $status; ?>
        </div>
      </div>
    </div>
  </div>
</div>
