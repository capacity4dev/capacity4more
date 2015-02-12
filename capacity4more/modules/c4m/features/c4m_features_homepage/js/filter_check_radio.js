(function ($) {

  $(document).ready(function() {
    var filter = window.location.search.replace('?filter=', '');
    $("input[value='" + filter + "']").attr("checked", "checked");
  });

})(jQuery);


