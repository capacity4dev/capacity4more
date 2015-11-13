/**
 * @file
 * Pause overlay video on click.
 */

var player;
function onYouTubePlayerAPIReady() {
  // Create the global player from the specific iframe (#video).
  player = new YT.Player('c4mVideo');

  jQuery('#c4mVideoModal').click(function() {
    player.pauseVideo();
  });
}
