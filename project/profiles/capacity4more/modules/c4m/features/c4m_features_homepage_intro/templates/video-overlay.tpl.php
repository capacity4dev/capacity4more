<?php

/**
 * @file
 * Prints out the video overlay.
 */
?>
<?php if ($video_id): ?>
  <div class="button-wrapper">
    <?php print render($image); ?>
    <div class="justifier">
      <button type="button" class="btn btn-primary btn-lg" id="c4m-play-video">
        <span class="i-play"></span>
        <span class="button-text"><?php print $video_title ?></span>
      </button>
    </div>
    <div id="c4m-intro-video" data-youtube-video-id="<?php print $video_id; ?>"></div>
  </div>
<?php endif; ?>
