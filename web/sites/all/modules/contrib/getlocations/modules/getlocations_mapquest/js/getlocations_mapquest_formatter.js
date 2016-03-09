
/**
 * @file
 * getlocations_mapquest_formatter.js
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript functions for getlocations_mapquest module admin
 * jquery gee whizzery
*/
(function ($) {
  Drupal.behaviors.getlocations_mapquest_formatter = {
    attach: function(context, settings) {

      if ( $("select[id$=zoomcontrol]").val() == 'none') {
        $("#wrap-getlocations-zoomcontrol").hide();
      }
      else {
        $("#wrap-getlocations-zoomcontrol").show();
      }

      $("select[id$=zoomcontrol]").change(function() {
        if ($(this).val() == 'none') {
          $("#wrap-getlocations-zoomcontrol").hide();
        }
        else {
          $("#wrap-getlocations-zoomcontrol").show();
        }
      });

      if ($("input[id$=layercontrol]").attr('checked')) {
        $("#wrap-getlocations-layercontrol").show();
      }
      else {
        $("#wrap-getlocations-layercontrol").hide();
      }
      $("input[id$=layercontrol]").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-layercontrol").show();
        }
        else {
          $("#wrap-getlocations-layercontrol").hide();
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

      if ($("input[id$=trafficcontrol]").attr('checked')) {
        $("#wrap-getlocations-trafficcontrol").show();
      }
      else {
        $("#wrap-getlocations-trafficcontrol").hide();
      }
      $("input[id$=trafficcontrol]").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-trafficcontrol").show();
        }
        else {
          $("#wrap-getlocations-trafficcontrol").hide();
        }
      });

      if ($("input[id$=drawingcontrol]").attr('checked')) {
        $("#wrap-getlocations-drawingcontrol").show();
      }
      else {
        $("#wrap-getlocations-drawingcontrol").hide();
      }
      $("input[id$=drawingcontrol]").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-drawingcontrol").show();
        }
        else {
          $("#wrap-getlocations-drawingcontrol").hide();
        }
      });

      if ($("input[id$=geolocationcontrol]").attr('checked')) {
        $("#wrap-getlocations-geolocationcontrol").show();
      }
      else {
        $("#wrap-getlocations-geolocationcontrol").hide();
      }
      $("input[id$=geolocationcontrol]").change(function() {
        if ($(this).attr('checked')) {
          $("#wrap-getlocations-geolocationcontrol").show();
        }
        else {
          $("#wrap-getlocations-geolocationcontrol").hide();
        }
      });

      // search marker
      if ($("#edit-getlocations-mapquest-defaults-views-search-marker-enable").is('input')) {
        if ($("#edit-getlocations-mapquest-defaults-views-search-marker-enable").attr('checked')) {
          $("#wrap-getlocations-views-search-marker").show();
        }
        else {
          $("#wrap-getlocations-views-search-marker").hide();
        }
        $("#edit-getlocations-mapquest-defaults-views-search-marker-enable").change(function() {
          if ($(this).attr('checked')) {
            $("#wrap-getlocations-views-search-marker").show();
          }
          else {
            $("#wrap-getlocations-views-search-marker").hide();
          }
        });
      }

      // search area shape
      if ($("#edit-getlocations-mapquest-defaults-views-search-radshape-enable").is('input')) {
        if ($("#edit-getlocations-mapquest-defaults-views-search-radshape-enable").attr('checked')) {
          $("#wrap-getlocations-views-search-radshape").show();
        }
        else {
          $("#wrap-getlocations-views-search-radshape").hide();
        }
        $("#edit-getlocations-mapquest-defaults-views-search-radshape-enable").change(function() {
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
