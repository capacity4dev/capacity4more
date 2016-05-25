/**
 * @file
 * Pause overlay video on click.
 */

// Create the global player from the specific iframe (#video).
var player;

function onYouTubeIframeAPIReady() {
  var video_id = jQuery('#c4m-intro-video').data('youtube-video-id');

  player = new YT.Player('c4m-intro-video', {
    height: '298',
    width: '100%',
    videoId: video_id,
    playerVars: {
      autoplay: 0,
      enablejsapi: 1,
      rel: 0,
      showinfo: 0
    },
    events: {
      'onReady': onPlayerReady
    }
  });
}

function onPlayerReady() {
  jQuery('#c4m-play-video').on('click', function (e) {
    jQuery('#c4m-intro-video').show();
    player.playVideo();
  });
}
