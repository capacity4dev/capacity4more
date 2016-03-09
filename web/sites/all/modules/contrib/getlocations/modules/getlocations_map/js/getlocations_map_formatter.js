
/**
 * @file getlocations_map_formatter.js
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript functions for getlocations_map module admin
 * jquery gee whizzery
*/
(function ($) {
  Drupal.behaviors.getlocations_map_formatter = {
    attach: function() {

      if ($("input[id$=settings-trafficinfo]").attr('checked')) {
        $("#wrap-getlocations-trafficinfo").show();
      }
      else {
        $("#wrap-getlocations-trafficinfo").hide();
      }
      $("input[id$=settings-trafficinfo]").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-trafficinfo").show();
        }
        else {
          $("#wrap-getlocations-trafficinfo").hide();
        }
      });

      if ($("input[id$=settings-bicycleinfo]").attr('checked')) {
        $("#wrap-getlocations-bicycleinfo").show();
      }
      else {
        $("#wrap-getlocations-bicycleinfo").hide();
      }
      $("input[id$=settings-bicycleinfo]").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-bicycleinfo").show();
        }
        else {
          $("#wrap-getlocations-bicycleinfo").hide();
        }
      });

      if ($("input[id$=settings-transitinfo]").attr('checked')) {
        $("#wrap-getlocations-transitinfo").show();
      }
      else {
        $("#wrap-getlocations-transitinfo").hide();
      }
      $("input[id$=settings-transitinfo]").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-transitinfo").show();
        }
        else {
          $("#wrap-getlocations-transitinfo").hide();
        }
      });

      if ($("input[id$=settings-panoramio-show]").attr('checked')) {
        $("#wrap-getlocations-panoramio").show();
      }
      else {
        $("#wrap-getlocations-panoramio").hide();
      }
      $("input[id$=settings-panoramio-show]").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-panoramio").show();
        }
        else {
          $("#wrap-getlocations-panoramio").hide();
        }
      });

      if ($("input[id$=settings-weather-show]").attr('checked')) {
        $("#wrap-getlocations-weather").show();
      }
      else {
        $("#wrap-getlocations-weather").hide();
      }
      $("input[id$=settings-weather-show]").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-weather").show();
        }
        else {
          $("#wrap-getlocations-weather").hide();
        }
      });

      if ($("input[id$=settings-weather-cloud]").attr('checked')) {
        $("#wrap-getlocations-weather-cloud").show();
      }
      else {
        $("#wrap-getlocations-weather-cloud").hide();
      }
      $("input[id$=settings-weather-cloud]").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-weather-cloud").show();
        }
        else {
          $("#wrap-getlocations-weather-cloud").hide();
        }
      });


      if ($("input[id*=polygons-enable]").attr('checked')) {
        $("#wrap-getlocations-polygons").show();
      }
      else {
        $("#wrap-getlocations-polygons").hide();
      }
      $("input[id*=polygons-enable]").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-polygons").show();
        }
        else {
          $("#wrap-getlocations-polygons").hide();
        }
      });

      if ($("input[id*=rectangles-enable]").attr('checked')) {
        $("#wrap-getlocations-rectangles").show();
      }
      else {
        $("#wrap-getlocations-rectangles").hide();
      }
      $("input[id*=rectangles-enable]").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-rectangles").show();
        }
        else {
          $("#wrap-getlocations-rectangles").hide();
        }
      });

      if ($("input[id*=circles-enable]").attr('checked')) {
        $("#wrap-getlocations-circles").show();
      }
      else {
        $("#wrap-getlocations-circles").hide();
      }
      $("input[id*=circles-enable]").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-circles").show();
        }
        else {
          $("#wrap-getlocations-circles").hide();
        }
      });

      if ($("input[id*=polylines-enable]").attr('checked')) {
       $("#wrap-getlocations-polylines").show();
      }
      else {
        $("#wrap-getlocations-polylines").hide();
      }
      $("input[id*=polylines-enable]").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-polylines").show();
        }
        else {
          $("#wrap-getlocations-polylines").hide();
        }
      });
      // search_places
      if ($("input[id$=search-places]").attr('checked')) {
       $("#wrap-getlocations-search-places").show();
      }
      else {
        $("#wrap-getlocations-search-places").hide();
      }
      $("input[id$=search-places]").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-search-places").show();
        }
        else {
          $("#wrap-getlocations-search-places").hide();
        }
      });
      // geojson
      if ($("input[id*=geojson-enable]").attr('checked')) {
       $("#wrap-getlocations-geojson-enable").show();
      }
      else {
        $("#wrap-getlocations-geojson-enable").hide();
      }
      $("input[id*=geojson-enable]").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-geojson-enable").show();
        }
        else {
          $("#wrap-getlocations-geojson-enable").hide();
        }
      });
      if ($("input[id$=pancontrol]").attr('checked')) {
        $("#wrap-getlocations-pancontrol").show();
      }
      else {
        $("#wrap-getlocations-pancontrol").hide();
      }
      $("input[id$=pancontrol]").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-pancontrol").show();
        }
        else {
          $("#wrap-getlocations-pancontrol").hide();
        }
      });

      if ($("select[id$=controltype]").val() == 'none') {
        $("#wrap-getlocations-zoomcontrol").hide();
      }
      else {
        $("#wrap-getlocations-zoomcontrol").show();
      }
      $("select[id$=controltype]").change(function() {
        if ($(this).val() == 'none') {
          $("#wrap-getlocations-zoomcontrol").hide();
        }
        else {
          $("#wrap-getlocations-zoomcontrol").show();
        }
      });

      if ($("select[id$=mtc]").val() == 'none') {
        $("#wrap-getlocations-mapcontrol").hide();
      }
      else {
        $("#wrap-getlocations-mapcontrol").show();
      }
      $("select[id$=mtc]").change(function() {
        if ($(this).val() == 'none') {
          $("#wrap-getlocations-mapcontrol").hide();
        }
        else {
          $("#wrap-getlocations-mapcontrol").show();
        }
      });

      if ($("input[id$=scale]").attr('checked')) {
        $("#wrap-getlocations-scale").show();
      }
      else {
        $("#wrap-getlocations-scale").hide();
      }
      $("input[id$=scale]").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-scale").show();
        }
        else {
          $("#wrap-getlocations-scale").hide();
        }
      });

      if ($("input[id$=overview]").attr('checked')) {
        $("#wrap-getlocations-overview").show();
      }
      else {
        $("#wrap-getlocations-overview").hide();
      }
      $("input[id$=overview]").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-overview").show();
        }
        else {
          $("#wrap-getlocations-overview").hide();
        }
      });

      if ($("input[id$=sv-show]").attr('checked')) {
        $("#wrap-getlocations-sv-show").show();
      }
      else {
        $("#wrap-getlocations-sv-show").hide();
      }
      $("input[id$=sv-show]").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-sv-show").show();
        }
        else {
          $("#wrap-getlocations-sv-show").hide();
        }
      });

      if ($("input[id$=fullscreen]").attr('checked')) {
        $("#wrap-getlocations-fs-show").show();
      }
      else {
        $("#wrap-getlocations-fs-show").hide();
      }
      $("input[id$=fullscreen]").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-fs-show").show();
        }
        else {
          $("#wrap-getlocations-fs-show").hide();
        }
      });

    }
  };
}(jQuery));
