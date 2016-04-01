/**
 * @file
 * Pause overlay video on click.
 */

var player;
function onYouTubePlayerAPIReady() {
  // Create the global player from the specific iframe (#video).
  player = new YT.Player('c4m-intro-video');

  jQuery('#c4m-play-video').click(function() {
    player.playVideo();
    jQuery('#c4m-intro-video').show();
  });
}
