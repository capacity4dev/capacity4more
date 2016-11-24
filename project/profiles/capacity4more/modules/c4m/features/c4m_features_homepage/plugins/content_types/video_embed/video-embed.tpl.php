<?php

/**
 * @file
 * Prints out an embedded video block.
 */
?>

<div class="sidebarblock video-embed text-copy--small">
  <div class="sidebarblock__content">
    <div class="video-preview-wrapper">
      <div class="video-preview">
        <div class="video-details">
          <div data-toggle="modal" data-target="#c4mVideoModal">
            <?php print $video_thumbnail; ?>
          </div>
          <span class="video-title">
            <?php print $video_title; ?>
          </span>
          <span class="video-description">
            <?php print $video_description; ?>
          </span>
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
    <div class="video-preview-cta">
      <div class="cta"> <?php print $cta; ?></div>
      <div class="link text-right"> <?php print l(t('More groups') . ' <i class="fa fa-chevron-right"></i>', '/groups', array('html' => TRUE)); ?></div>
    </div>
  </div>
</div>
