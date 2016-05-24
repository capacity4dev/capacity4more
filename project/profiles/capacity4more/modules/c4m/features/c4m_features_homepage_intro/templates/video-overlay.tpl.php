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
        <span><?php print $video_title ?></span>
      </button>
    </div>
    <iframe id="c4m-intro-video" allowfullscreen="true" width="100%" height="298" src="https://www.youtube.com/embed/<?php print $video_id; ?>?rel=0&amp;showinfo=0&amp;autoplay=0&amp;enablejsapi=1" frameborder="0"></iframe>
  </div>
<?php endif; ?>
