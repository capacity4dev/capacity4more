jQuery( document ).ready(function() {
  // Listen to watch video button click.
  jQuery( "#watch-video-link" ).click(function() {
    jQuery( "#homepage-banner").hide('fast');
    jQuery( "#watch-video-link").hide('fast');
    jQuery( "#homepage-video").show('fast');
  });
});
