var player;
function onYouTubePlayerAPIReady() {
  // create the global player from the specific iframe (#video)
  player = new YT.Player('c4mVideo', {
    videoId: Drupal.settings.youtubeVideoId
  });

  jQuery('#c4mVideoModal').click(function() {
    player.pauseVideo();
  });
}
