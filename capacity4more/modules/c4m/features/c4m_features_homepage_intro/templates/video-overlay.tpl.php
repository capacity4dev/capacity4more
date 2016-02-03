<?php
/**
 * @file
 * Prints out the video overlay.
 */

?>

<div class="button-wrapper">
  <?php print render($image); ?>
  <button type="button" class="btn btn-primary btn-lg" data-toggle="modal" data-target="#c4mVideoModal">
    <span><?php print $video_title ?></span>
  </button>
</div>
<div class="modal fade" id="c4mVideoModal" tabindex="-1" role="dialog" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="<?php print t('Close') ?>"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title" id="c4dVideoLabel"><?php print $video_title ?></h4>
      </div>
      <div class="modal-body">
        <iframe id="c4mVideo" allowfullscreen="true" width="100%" height="477" src="https://www.youtube.com/embed/<?php print $video_id; ?>?rel=0&amp;showinfo=0&amp;autoplay=0&amp;enablejsapi=1" frameborder="0"></iframe>
      </div>
    </div>
  </div>
</div>
