
/**
 * @file
 * getlocations_views.js
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript functions for getlocations module in views using custom-content in infobubble/infowindow
 * jquery stuff
*/
(function ($) {

  Drupal.behaviors.getlocations_views = {
    attach: function() {

      if($('#edit-style-options-markeraction').val() == 1 || $('#edit-style-options-markeraction').val() == 2) {
        $('#wrap-custom-content-enable').show();

          if($('#edit-style-options-custom-content-enable').attr('checked')) {
            $('#wrap-custom-content-source').show();
          }
          else {
            $('#wrap-custom-content-source').hide();
          }
      }
      else {
        $('#wrap-custom-content-enable').hide();
        $('#wrap-custom-content-source').hide();
      }

      $("#edit-style-options-markeraction").change(function() {
        if($(this).val() == 1 || $(this).val() == 2) {
          $('#wrap-custom-content-enable').show();

          if($('#edit-style-options-custom-content-enable').attr('checked')) {
            $('#wrap-custom-content-source').show();
          }
          else {
            $('#wrap-custom-content-source').hide();
          }
        }
        else {
          $('#wrap-custom-content-enable').hide();
          $('#wrap-custom-content-source').hide();
        }
      });

      $("#edit-style-options-custom-content-enable").change(function() {
        if($('#edit-style-options-markeraction').val() == 1 || $('#edit-style-options-markeraction').val() == 2) {
            if($(this).attr('checked')) {
              $('#wrap-custom-content-source').show();
            }
            else {
              $('#wrap-custom-content-source').hide();
            }
        }
      });

      if ($("#edit-style-options-trafficinfo").is('input')) {
        if ($("#edit-style-options-trafficinfo").attr('checked')) {
          $("#wrap-getlocations-trafficinfo").show();
        }
        else {
          $("#wrap-getlocations-trafficinfo").hide();
        }
        $("#edit-style-options-trafficinfo").change(function() {
          if ($(this).attr('checked')) {
            $("#wrap-getlocations-trafficinfo").show();
          }
          else {
            $("#wrap-getlocations-trafficinfo").hide();
          }
        });
      }

      if ($("#edit-style-options-bicycleinfo").is('input')) {
        if ($("#edit-style-options-bicycleinfo").attr('checked')) {
          $("#wrap-getlocations-bicycleinfo").show();
        }
        else {
          $("#wrap-getlocations-bicycleinfo").hide();
        }
        $("#edit-style-options-bicycleinfo").change(function() {
          if ($(this).attr('checked')) {
            $("#wrap-getlocations-bicycleinfo").show();
          }
          else {
            $("#wrap-getlocations-bicycleinfo").hide();
          }
        });
      }

      if ($("#edit-style-options-transitinfo").is('input')) {
        if ($("#edit-style-options-transitinfo").attr('checked')) {
          $("#wrap-getlocations-transitinfo").show();
        }
        else {
          $("#wrap-getlocations-transitinfo").hide();
        }
        $("#edit-style-options-transitinfo").change(function() {
          if ($(this).attr('checked')) {
            $("#wrap-getlocations-transitinfo").show();
          }
          else {
            $("#wrap-getlocations-transitinfo").hide();
          }
        });
      }

      if ($("#edit-style-options-panoramio-show").is('input')) {
        if ($("#edit-style-options-panoramio-show").attr('checked')) {
          $("#wrap-getlocations-panoramio").show();
        }
        else {
          $("#wrap-getlocations-panoramio").hide();
        }
        $("#edit-style-options-panoramio-show").change(function() {
          if ($(this).attr('checked')) {
            $("#wrap-getlocations-panoramio").show();
          }
          else {
            $("#wrap-getlocations-panoramio").hide();
          }
        });
      }

      if ($("#edit-style-options-weather-show").is('input')) {
        if ($("#edit-style-options-weather-show").attr('checked')) {
          $("#wrap-getlocations-weather").show();
        }
        else {
          $("#wrap-getlocations-weather").hide();
        }
        $("#edit-style-options-weather-show").change(function() {
          if ($(this).attr('checked')) {
            $("#wrap-getlocations-weather").show();
          }
          else {
            $("#wrap-getlocations-weather").hide();
          }
        });

        if ($("#edit-style-options-weather-cloud").attr('checked')) {
          $("#wrap-getlocations-weather-cloud").show();
        }
        else {
          $("#wrap-getlocations-weather-cloud").hide();
        }
        $("#edit-style-options-weather-cloud").change(function() {
          if ($(this).attr('checked')) {
            $("#wrap-getlocations-weather-cloud").show();
          }
          else {
            $("#wrap-getlocations-weather-cloud").hide();
          }
        });
      }

      if ($("#edit-style-options-polygons-enable").attr('checked')) {
        $("#wrap-getlocations-polygons").show();
      }
      else {
        $("#wrap-getlocations-polygons").hide();
      }
      $("#edit-style-options-polygons-enable").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-polygons").show();
        }
        else {
          $("#wrap-getlocations-polygons").hide();
        }
      });

      if ($("#edit-style-options-rectangles-enable").attr('checked')) {
        $("#wrap-getlocations-rectangles").show();
      }
      else {
        $("#wrap-getlocations-rectangles").hide();
      }
      $("#edit-style-options-rectangles-enable").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-rectangles").show();
        }
        else {
          $("#wrap-getlocations-rectangles").hide();
        }
      });

      if ($("#edit-style-options-circles-enable").attr('checked')) {
        $("#wrap-getlocations-circles").show();
      }
      else {
        $("#wrap-getlocations-circles").hide();
      }
      $("#edit-style-options-circles-enable").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-circles").show();
        }
        else {
          $("#wrap-getlocations-circles").hide();
        }
      });

      if ($("#edit-style-options-polylines-enable").attr('checked')) {
        $("#wrap-getlocations-polylines").show();
      }
      else {
        $("#wrap-getlocations-polylines").hide();
      }
      $("#edit-style-options-polylines-enable").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-polylines").show();
        }
        else {
          $("#wrap-getlocations-polylines").hide();
        }
      });

      // search_places
      if ($("#edit-style-options-search-places").attr('checked')) {
        $("#wrap-getlocations-search-places").show();
      }
      else {
        $("#wrap-getlocations-search-places").hide();
      }
      $("#edit-style-options-search-places").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-search-places").show();
        }
        else {
          $("#wrap-getlocations-search-places").hide();
        }
      });

      // categories
      if ($("#edit-style-options-category-method").val() > 0) {
        $("#wrap-category1").show();
        if ($("#edit-style-options-category-method").val() == 2) {
          $("#wrap-category2").show();
        }
        else {
          $("#wrap-category2").hide();
        }
      }
      else {
        $("#wrap-category1").hide();
      }
      $("#edit-style-options-category-method").change(function() {
        if ($("#edit-style-options-category-method").val() > 0) {
          $("#wrap-category1").show();
          if ($("#edit-style-options-category-method").val() == 2) {
            $("#wrap-category2").show();
          }
          else {
            $("#wrap-category2").hide();
          }
        }
        else {
          $("#wrap-category1").hide();
        }
      });

      // geojson
      if ($("#edit-style-options-geojson-enable").attr('checked')) {
        $("#wrap-getlocations-geojson-enable").show();
      }
      else {
        $("#wrap-getlocations-geojson-enable").hide();
      }
      $("#edit-style-options-geojson-enable").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-geojson-enable").show();
        }
        else {
          $("#wrap-getlocations-geojson-enable").hide();
        }
      });

      // markermangers
      if ( $("#edit-style-options-usemarkermanager").is('input')) {
        if ($("#edit-style-options-usemarkermanager").attr('checked')) {
          $("#wrap-usemarkermanager").show();
        }
        else {
          $("#wrap-usemarkermanager").hide();
        }
        $("#edit-style-options-usemarkermanager").change(function() {
          if ($(this).attr('checked')) {
            $("#wrap-usemarkermanager").show();
          }
          else {
            $("#wrap-usemarkermanager").hide();
          }
        });
      }

      if ( $("#edit-style-options-useclustermanager").is('input')) {
        if ($("#edit-style-options-useclustermanager").attr('checked')) {
          $("#wrap-useclustermanager").show();
        }
        else {
          $("#wrap-useclustermanager").hide();
        }
        $("#edit-style-options-useclustermanager").change(function() {
          if ($(this).attr('checked')) {
            $("#wrap-useclustermanager").show();
          }
          else {
            $("#wrap-useclustermanager").hide();
          }
        });
      }

      if ($("#edit-style-options-controltype").is('select')) {
        if ($("#edit-style-options-controltype").val() == 'none') {
          $("#wrap-getlocations-zoomcontrol").hide();
        }
        else {
          $("#wrap-getlocations-zoomcontrol").show();
        }
        $("#edit-style-options-controltype").change(function() {
          if ($(this).val() == 'none') {
            $("#wrap-getlocations-zoomcontrol").hide();
          }
          else {
            $("#wrap-getlocations-zoomcontrol").show();
          }
        });
      }

      if ($("#edit-style-options-pancontrol").is('input')) {
        if ($("#edit-style-options-pancontrol").attr('checked')) {
          $("#wrap-getlocations-pancontrol").show();
        }
        else {
          $("#wrap-getlocations-pancontrol").hide();
        }
        $("#edit-style-options-pancontrol").change(function() {
          if ($(this).attr('checked')) {
            $("#wrap-getlocations-pancontrol").show();
          }
          else {
            $("#wrap-getlocations-pancontrol").hide();
          }
        });
      }

      if ($("#edit-style-options-mtc").is('select')) {
        if ($("#edit-style-options-mtc").val() == 'none') {
          $("#wrap-getlocations-mapcontrol").hide();
        }
        else {
          $("#wrap-getlocations-mapcontrol").show();
        }
        $("#edit-style-options-mtc").change(function() {
          if ($(this).val() == 'none') {
            $("#wrap-getlocations-mapcontrol").hide();
          }
          else {
            $("#wrap-getlocations-mapcontrol").show();
          }
        });
      }

      if ($("#edit-style-options-scale").is('input')) {
        if ($("#edit-style-options-scale").attr('checked')) {
          $("#wrap-getlocations-scale").show();
        }
        else {
          $("#wrap-getlocations-scale").hide();
        }
        $("#edit-style-options-scale").change(function() {
          if ($(this).attr('checked')) {
            $("#wrap-getlocations-scale").show();
          }
          else {
            $("#wrap-getlocations-scale").hide();
          }
        });
      }

      if ($("#edit-style-options-overview").is('input')) {
        if ($("#edit-style-options-overview").attr('checked')) {
          $("#wrap-getlocations-overview").show();
        }
        else {
          $("#wrap-getlocations-overview").hide();
        }
        $("#edit-style-options-overview").change(function() {
          if ($(this).attr('checked')) {
            $("#wrap-getlocations-overview").show();
          }
          else {
            $("#wrap-getlocations-overview").hide();
          }
        });
      }

      if ($("#edit-style-options-sv-show").is('input')) {
        if ($("#edit-style-options-sv-show").attr('checked')) {
          $("#wrap-getlocations-sv-show").show();
        }
        else {
          $("#wrap-getlocations-sv-show").hide();
        }
        $("#edit-style-options-sv-show").change(function() {
          if ($(this).attr('checked')) {
            $("#wrap-getlocations-sv-show").show();
          }
          else {
            $("#wrap-getlocations-sv-show").hide();
          }
        });
      }

      if ($("#edit-style-options-fullscreen").is('input')) {
        if ($("#edit-style-options-fullscreen").attr('checked')) {
          $("#wrap-getlocations-fs-show").show();
        }
        else {
          $("#wrap-getlocations-fs-show").hide();
        }
        $("#edit-style-options-fullscreen").change(function() {
          if ($(this).attr('checked')) {
            $("#wrap-getlocations-fs-show").show();
          }
          else {
            $("#wrap-getlocations-fs-show").hide();
          }
        });
      }

      if ($("#edit-style-options-highlight-enable").is('input')) {
        if ($("#edit-style-options-highlight-enable").attr('checked')) {
          $("#wrap-getlocations-highlight").show();
        }
        else {
          $("#wrap-getlocations-highlight").hide();
        }
        $("#edit-style-options-highlight-enable").change(function() {
          if ($(this).attr('checked')) {
            $("#wrap-getlocations-highlight").show();
          }
          else {
            $("#wrap-getlocations-highlight").hide();
          }
        });
      }

      // search marker
      if ($("#edit-style-options-views-search-marker-enable").is('input')) {
        if ($("#edit-style-options-views-search-marker-enable").attr('checked')) {
          $("#wrap-getlocations-views-search-marker").show();
        }
        else {
          $("#wrap-getlocations-views-search-marker").hide();
        }
        $("#edit-style-options-views-search-marker-enable").change(function() {
          if ($(this).attr('checked')) {
            $("#wrap-getlocations-views-search-marker").show();
          }
          else {
            $("#wrap-getlocations-views-search-marker").hide();
          }
        });
      }

      // search area shape
      if ($("#edit-style-options-views-search-radshape-enable").is('input')) {
        if ($("#edit-style-options-views-search-radshape-enable").attr('checked')) {
          $("#wrap-getlocations-views-search-radshape").show();
        }
        else {
          $("#wrap-getlocations-views-search-radshape").hide();
        }
        $("#edit-style-options-views-search-radshape-enable").change(function() {
          if ($(this).attr('checked')) {
            $("#wrap-getlocations-views-search-radshape").show();
          }
          else {
            $("#wrap-getlocations-views-search-radshape").hide();
          }
        });
      }

    }
  };

}(jQuery));
