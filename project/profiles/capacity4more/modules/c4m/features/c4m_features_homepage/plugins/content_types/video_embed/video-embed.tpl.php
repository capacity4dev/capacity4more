<?php
/**
 * @file
 * Prints out an embedded video block.
 */

?>

<div class="video-preview-wrapper">
  <div class="video-preview" data-toggle="modal" data-target="#c4mVideoModal">
    <div class="video-details">
      <span class="video-title">
        <?php print $video_title ?>
      </span>
      <span class="video-description">
        <?php print $video_description ?>
      </span>
    </div>
    <div>
      <?php print $video_thumbnail ?>
    </div>
  </div>
</div>
<div class="modal fade" id="c4mVideoModal" tabindex="-1" role="dialog" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="<?php print t('Close') ?>"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title" id="c4dVideoLabel"><?php print $video_title ?></h4>
      </div>
      <div class="modal-body">
        <?php print $video_embed ?>
      </div>
    </div>
  </div>
</div>
