
/**
 * @file
 * getlocations_search_places.js
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript functions for getlocations search_places support
 * jquery stuff
*/
(function ($) {

  var getlocations_sp_markers = [];
  var getlocations_places_service;

  Drupal.getlocations_search_places = function(key) {
    getlocations_places_service = new google.maps.places.PlacesService(Drupal.getlocations_map[key]);
    var sp_switch = Drupal.settings.getlocations[key].search_places_dd;
    if (sp_switch) {
      // dropdown
      $("#search_places_go_btn_" + key).click( function() {
        var t = $("#search_places_select_" + key).val();
        var b = Drupal.getlocations_map[key].getBounds();
        var s = {bounds:b, types:[t]};
        // clear out existing markers
        Drupal.getlocations_search_places_clearmarkers(key, false);
        getlocations_places_service.search(s, function(places, status) {
          if (status == google.maps.places.PlacesServiceStatus.OK) {
            getlocations_sp_do_places(places, key);
          }
        });
        return false;
      });
    }
    else {
      // textbox
      var getlocations_search_places_Box = new google.maps.places.SearchBox(document.getElementById('search_places_input_' + key));
      getlocations_search_places_Box.bindTo('bounds', Drupal.getlocations_map[key]);
      google.maps.event.addListener(getlocations_search_places_Box, 'places_changed', function() {
        // clear out existing markers
        Drupal.getlocations_search_places_clearmarkers(key, false);
        var places = getlocations_search_places_Box.getPlaces();
        getlocations_sp_do_places(places, key);
      });
    }
  };

  function getlocations_do_sp_bubble(marker, p, key) {
    var ver = Drupal.getlocations.msiedetect();
    var pushit = false;
    if ( (ver == '') || (ver && ver > 8)) {
      pushit = true;
    }
    var main = '<p>';
    if (p.formatted_address !== undefined) {
      main += '<span class="sp_address">' + p.formatted_address + '</span><br />';
    }
    if (p.formatted_phone_number !== undefined) {
      main += '<span class="sp_phone">' + Drupal.t('Phone') + ': '  + p.formatted_phone_number + '</span><br />';
    }
    else if (p.international_phone_number !== undefined) {
      main += '<span class="sp_phone">' + Drupal.t('Int. Phone') + ': ' + p.international_phone_number + '</span><br />';
    }
    if (p.website !== undefined) {
      main += '<span class="sp_web">' + Drupal.t('Web') + ': ' + '<a href="' + p.website + '" target="_blank" >' + p.name + '</a></span><br />';
    }
    if (p.url !== undefined) {
      main += '<span class="sp_web">' + Drupal.t('Google') + ': ' + '<a href="' + p.url + '" target="_blank" >' + p.name + '</a></span><br />';
    }
    // link to Getdirections or google
    if (p.geometry !== undefined) {
      var scheme = 'http';
      if (Drupal.settings.getlocations[key].is_https) {
        scheme = 'https';
      }
      if (Drupal.settings.getlocations[key].getdirections_enabled) {
        main += '<span class="sp_web"><a href="' + Drupal.settings.basePath + 'getdirections/latlon/to/' + p.geometry.location.lat() + ',' + p.geometry.location.lng() + '/' + p.name + '" target="_blank">' + Drupal.t('Directions') + '</a></span><br />';
      }
      else {
        main += '<span class="sp_web"><a href="' + scheme + '://maps.google.com/maps?f=d&ie=UTF8&daddr=' + p.name + '@' + p.geometry.location.lat() + ',' + p.geometry.location.lng() + '"  target="_blank">' + Drupal.t('Google Getdirections')  + '</a></span><br />';
      }
    }
    main += '</p>';

    var photo = '';
    if (p.photos !== undefined && p.photos.length > 0 ) {
      if (p.photos.length > 1)   {
        // pick one at random
        var rn = Math.floor((Math.random() * p.photos.length )+1);
      }
      else {
        var rn = p.photos.length;
      }
      var ph = p.photos[rn - 1].getUrl({'maxWidth': 75});
      photo += '<img class="sp_picture" src="' + ph + '" alt="' + p.name + '" title="' + p.name + '" />';
    }
    var sp_content = "";
    sp_content += '<div class="location vcard">';
    sp_content += '<div class="container-inline">';

    sp_content += '<div class="sp_left1">';
    sp_content += '<img class="placeIcon" src="' + p.icon + '"/>';
    sp_content += '</div>';
    sp_content += '<div class="sp_left2">';
    sp_content += '<h4>' + p.name + '</h4>';
    sp_content += '</div>';
    sp_content += '</div>';
    sp_content += '<div class="sp_main">';

    if (photo) {
    sp_content += '<div class="container-inline">';
      sp_content += '<div class="sp_left3">';
      sp_content += photo;
      sp_content += '</div>';
      sp_content += '<div class="sp_left4">';
      sp_content += main;
      sp_content += '</div>';
      sp_content += '</div>';
    }
    else {
      sp_content += main;
    }
    sp_content += '</div>';
    sp_content += '</div>';
    google.maps.event.addListener(marker, 'click', function() {
      // close any previous instances
      if (pushit) {
        for (var i in Drupal.getlocations_settings[key].infoBubbles) {
          Drupal.getlocations_settings[key].infoBubbles[i].close();
        }
      }
      if (Drupal.getlocations_settings[key].markeraction == 2) {
        if (typeof(infoBubbleOptions) == 'object') {
          var infoBubbleOpts = infoBubbleOptions;
        }
        else {
          var infoBubbleOpts = {};
        }
        infoBubbleOpts.content = sp_content;
        var sp_iw = new InfoBubble(infoBubbleOpts);
      }
      else {
        if (typeof(infoWindowOptions) == 'object') {
          var infoWindowOpts = infoWindowOptions;
        }
        else {
          var infoWindowOpts = {};
        }
        infoWindowOpts.content = sp_content;
        var sp_iw = new google.maps.InfoWindow(infoWindowOpts);
      }
      sp_iw.open(Drupal.getlocations_map[key], marker);
      if (pushit) {
        Drupal.getlocations_settings[key].infoBubbles.push(sp_iw);
      }
    });
  }

  function getlocations_sp_getdetails(m, p, k, i) {
    getlocations_places_service.getDetails({reference: p.reference}, function(result, status) {
      if (status == google.maps.places.PlacesServiceStatus.OK) {
        getlocations_do_sp_bubble(m, result, k);
        getlocations_sp_do_result(result, k, i);
      }
      else {
        getlocations_do_sp_bubble(m, p, k);
        getlocations_sp_do_result(p, k, i);
      }
    });
  }

  function getlocations_sp_do_places(places, key) {
    for (var ip = 0; ip < places.length; ip++) {
      var place = places[ip];
      var image = {
        url: place.icon,
        size: new google.maps.Size(71, 71),
        origin: new google.maps.Point(0, 0),
        anchor: new google.maps.Point(17, 34),
        scaledSize: new google.maps.Size(25, 25)
      };
      var sp_marker = new google.maps.Marker({
        map: Drupal.getlocations_map[key],
        icon: image,
        title: place.name,
        position: place.geometry.location
      });
      getlocations_sp_markers[ip] = sp_marker;
      getlocations_sp_getdetails(sp_marker, place, key, ip);
    }
  }

  function getlocations_sp_do_result(p, k, i) {
    if ($("#search_places_results_" + k).is('ul')) {
      var out = '<li class="sp_link" id="sp_link_' + i + '"><img class="placeIcon" src="' + p.icon + '">&nbsp;&nbsp;' + p.name + '</li>';
      $("#search_places_results_" + k).append(out);

      $("#sp_link_" + i).click( function() {
        google.maps.event.trigger(getlocations_sp_markers[i], 'click');
      });
    }
  }

  Drupal.getlocations_search_places_clearmarkers = function(key, state) {
    // clear out existing markers
    for (var i = 0; i < getlocations_sp_markers.length; i++) {
      sp_marker = getlocations_sp_markers[i];
      sp_marker.setMap(null);
    }
    getlocations_sp_markers = [];

    var ver = Drupal.getlocations.msiedetect();
    if ( (ver == '') || (ver && ver > 8)) {
      for (var i in Drupal.getlocations_settings[key].infoBubbles) {
        Drupal.getlocations_settings[key].infoBubbles[i].close();
      }
    }

    if (state) {
      $("#search_places_input_" + key).val('');
    }
    $("#search_places_results_" + key).html('');
  };

}(jQuery));
