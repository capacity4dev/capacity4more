var player;
function onYouTubePlayerAPIReady() {
  // create the global player from the specific iframe (#video)
  player = new YT.Player('c4mVideo', {
    videoId: '<?php print $video_id ?>'
  });

  jQuery('#c4mVideoModal').click(function() {
    player.pauseVideo();
  });
}
