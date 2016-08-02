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
    jQuery('#c4m-stop-video').show();
    // Adding the 'video-is-on' fix the height of the header content to prevent
    // overlap between elements on the small screens (see _header.scss).
    jQuery('#header-content-wrapper .header-content').addClass('video-is-on');
    player.playVideo();
  });

  jQuery('#c4m-stop-video').on('click', function (e) {
    jQuery('#c4m-intro-video').hide();
    jQuery('#c4m-stop-video').hide();
    jQuery('#header-content-wrapper .header-content').removeClass('video-is-on');
    player.stopVideo();
  });
}
