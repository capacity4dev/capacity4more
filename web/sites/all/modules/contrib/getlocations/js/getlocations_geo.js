
/**
 * @file
 * getlocations_geo.js
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript geo functions for getlocations module for Drupal 7
 * this is for googlemaps API version 3
 */

(function ($) {

  if ( typeof(Drupal.getlocations) == 'undefined') {
    Drupal.getlocations = {};
  }

  Drupal.getlocations.geo = {};
  Drupal.getlocations.geo.EARTH_RADIUS_SEMIMAJOR = 6378137.0;
  Drupal.getlocations.geo.EARTH_FLATTENING = (1/298.257223563);
  Drupal.getlocations.geo.EARTH_RADIUS_SEMIMINOR = (Drupal.getlocations.geo.EARTH_RADIUS_SEMIMAJOR * (1 - Drupal.getlocations.geo.EARTH_FLATTENING));
  //Drupal.getlocations.geo.EARTH_ECCENTRICITY_SQ = (2*(1/298.257223563)-Math.pow((1/298.257223563), 2));

  /**
   * Normalizes a latitude to the [-90,90] range. Latitudes above 90 or
   * below -90 are capped, not wrapped.
   * @param {Number} lat The latitude to normalize, in degrees.
   * @type Number
   * @return Returns the latitude, fit within the [-90,90] range.
   */
  Drupal.getlocations.geo.normalizeLat = function(lat) {
    return Math.max(-90, Math.min(90, lat));
  };

  /**
   * Normalizes a longitude to the [-180,180] range. Longitudes above 180
   * or below -180 are wrapped.
   * @param {Number} lng The longitude to normalize, in degrees.
   * @type Number
   * @return Returns the longitude, fit within the [-180,180] range.
   */
  Drupal.getlocations.geo.normalizeLng = function(lng) {
    if (lng % 360 == 180) {
      return 180;
    }
    lng = lng % 360;
    return lng < -180 ? lng + 360 : lng > 180 ? lng - 360 : lng;
  };

  /**
   * Decimal Degrees to Radians.
   * @param {Number} Decimal Degrees
   * @returns {Number} Radians
   *
   */
  Drupal.getlocations.geo.toRad = function(deg) {
    return deg * Math.PI / 180;
  };

  /**
   * Radians to Decimal Degrees.
   * @param {Number} Radians
   * @returns {Number} Decimal Degrees
   *
   */
  Drupal.getlocations.geo.toDeg = function(rad) {
    return rad * 180 / Math.PI;
  };

  /**
   * Returns the earth's radius at a given latitude
   * @param {Number} Latitude
   * @returns {Number} radius
   *
   */
  Drupal.getlocations.geo.earth_radius = function(latitude) {
    var lat = Drupal.getlocations.geo.toRad(latitude);
    var x = (Math.cos(lat) / Drupal.getlocations.geo.EARTH_RADIUS_SEMIMAJOR);
    var y = (Math.sin(lat) / Drupal.getlocations.geo.EARTH_RADIUS_SEMIMINOR);
    var r = (1 / (Math.sqrt(x * x + y * y)));
    return r;
  };

  /**
   * Estimate the min and max longitudes within distance of a given location.
   * @param {Number} latitude
   * @param {Number} longitude
   * @param {Number} distance in meters
   * @returns {Array}
   *
   */
  Drupal.getlocations.geo.earth_longitude_range = function(latitude, longitude, distance) {

    if (! distance > 0) {
      distance = 1;
    }
    latitude = parseFloat(latitude);
    longitude = parseFloat(longitude);
    distance = parseInt(distance);
    var lng = Drupal.getlocations.geo.toRad(longitude);
    var lat =  Drupal.getlocations.geo.toRad(latitude);
    var radius = Drupal.getlocations.geo.earth_radius(latitude) * Math.cos(lat);
    var angle = 0;
    if (radius > 0) {
      angle = Math.abs(distance / radius);
      angle = Math.min(angle, Math.PI);
    }
    else {
      angle = Math.PI;
    }
    var minlong = lng - angle;
    var maxlong = lng + angle;
    if (minlong < -Math.PI) {
      minlong = minlong + Math.PI * 2;
    }
    if (maxlong > Math.PI) {
      maxlong = maxlong - Math.PI * 2;
    }
    var minlongDeg = Drupal.getlocations.geo.toDeg(minlong);
    minlongDeg = Drupal.getlocations.geo.normalizeLng(minlongDeg);
    var maxlongDeg = Drupal.getlocations.geo.toDeg(maxlong);
    maxlongDeg = Drupal.getlocations.geo.normalizeLng(maxlongDeg);
    var r = [minlongDeg.toFixed(6), maxlongDeg.toFixed(6)];
    return r;
  };

  /**
   * Estimate the min and max latitudes within distance of a given location.
   * @param {Number} latitude
   * @param {Number} longitude
   * @param {Number} distance in meters
   * @returns {Array}
   *
   */
  Drupal.getlocations.geo.earth_latitude_range = function(latitude, longitude, distance) {

    if (! distance > 0) {
      distance = 1;
    }
    latitude = parseFloat(latitude);
    longitude = parseFloat(longitude);
    distance = parseInt(distance);
    var lng = Drupal.getlocations.geo.toRad(longitude);
    var lat =  Drupal.getlocations.geo.toRad(latitude);
    var radius = Drupal.getlocations.geo.earth_radius(latitude);
    var angle = distance / radius;
    var minlat = lat - angle;
    var maxlat = lat + angle;
    var rightangle = Math.PI / 2;
    var overshoot = 0;
    if (minlat < -rightangle) { // wrapped around the south pole
      overshoot = -minlat - rightangle;
      minlat = -rightangle + overshoot;
      if (minlat > maxlat) {
        maxlat = minlat;
      }
      minlat = -rightangle;
    }
    if (maxlat > rightangle) { // wrapped around the north pole
      overshoot = maxlat - rightangle;
      maxlat = rightangle - overshoot;
      if (maxlat < minlat) {
        minlat = maxlat;
      }
      maxlat = rightangle;
    }
    var minlatDeg = Drupal.getlocations.geo.toDeg(minlat);
    minlatDeg = Drupal.getlocations.geo.normalizeLat(minlatDeg);
    var maxlatDeg = Drupal.getlocations.geo.toDeg(maxlat);
    maxlatDeg = Drupal.getlocations.geo.normalizeLat(maxlatDeg);
    var r = [minlatDeg.toFixed(6), maxlatDeg.toFixed(6)];
    return r;
  };

  /**
   * Estimate the earth-surface distance between two locations.
   *
   * @param {Number} latitude1
   * @param {Number} longitude1
   * @param {Number} latitude2
   * @param {Number} longitude2
   * @returns {Number} distance in meters
   */
  Drupal.getlocations.geo.earth_distance = function(latitude1, longitude1, latitude2, longitude2) {
    var lat1 = Drupal.getlocations.geo.toRad(parseFloat(latitude1));
    var lng1 = Drupal.getlocations.geo.toRad(parseFloat(longitude1));
    var lat2 = Drupal.getlocations.geo.toRad(parseFloat(latitude2));
    var lng2 = Drupal.getlocations.geo.toRad(parseFloat(longitude2));
    var radius = Drupal.getlocations.geo.earth_radius((parseFloat(latitude1) + parseFloat(latitude2)) / 2);
    var cosangle = Math.cos(lat1) * Math.cos(lat2) * (Math.cos(lng1) * Math.cos(lng2) + Math.sin(lng1) * Math.sin(lng2)) + Math.sin(lat1) * Math.sin(lat2);
    return Math.acos(cosangle) * radius;
  };

  /**
   * Estimate the earth-surface distance between two locations, Haversine formula.
   *
   * @param {Number} latitude1
   * @param {Number} longitude1
   * @param {Number} latitude2
   * @param {Number} longitude2
   * @returns {Number} distance in meters
   */
  Drupal.getlocations.geo.earth_distance2 = function(latitude1, longitude1, latitude2, longitude2) {
    var lat1 = Drupal.getlocations.geo.toRad(parseFloat(latitude1));
    var lng1 = Drupal.getlocations.geo.toRad(parseFloat(longitude1));
    var lat2 = Drupal.getlocations.geo.toRad(parseFloat(latitude2));
    var lng2 = Drupal.getlocations.geo.toRad(parseFloat(longitude2));
    var radius = Drupal.getlocations.geo.earth_radius((parseFloat(latitude1) + parseFloat(latitude2)) / 2);
    var latm = lat2 - lat1;
    var lngm = lng2 - lng1;
    var a = Math.sin(latm / 2) * Math.sin(latm / 2) + Math.cos(lat1) * Math.cos(lat2) * Math.sin(lngm / 2) * Math.sin(lngm / 2);
    return radius * 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1-a));
  };

  /**
   * Convert a distance to meters
   * @param {Number} distance
   * @param {String} the distance unit
   * @returns {Number} the distance in meters
   */
  Drupal.getlocations.geo.convert_distance_to_meters = function(distance, distance_unit) {
    if (typeof(distance) !== 'number' || !distance > 0) {
      return null;
    }
    var units = {
      'km': 1000.0,
      'm': 1.0,
      'mi': 1609.344,
      'yd': 0.9144,
      'nmi': 1852.0
    };
    if (units[distance_unit] === undefined) {
      distance_unit = 'km';
    }
    var conv = units[distance_unit];
    var n = parseFloat(distance) * parseFloat(conv);
    var retval = n.toFixed(2);
    return retval;
  };

  /**
   * Convert meters to a distance
   * @param {Number} meters
   * @param {String} the distance unit
   * @returns {Number} the distance in the distance unit
   */
  Drupal.getlocations.geo.convert_meters_to_distance = function(meters, distance_unit) {
    if (typeof(meters) !== 'number' || !meters > 0) {
      return null;
    }
    var units = {
      'km': 0.001,
      'm': 1.0,
      'mi': 0.000621371,
      'yd': 1.093613298,
      'nmi': 0.000539957
    };
    if (units[distance_unit] === undefined) {
      distance_unit = 'km';
    }
    var conv = units[distance_unit];
    var n = parseFloat(meters) * parseFloat(conv);
    var retval = n.toFixed(2);
    return retval;
  };

  /**
   * Convert Decimal Degrees to Degrees, minutes, seconds
   * @param {Number} coordinate in Decimal Degrees
   * @param {String} 'lat' for latitude or anything else for longitude
   * @return {String} Degrees, minutes, seconds formatted for webpage
   */
  Drupal.getlocations.geo.dd_to_dms_do = function(coord, latlon, web) {
    if (typeof web == 'undefined') web = true;
    if (latlon == 'lat') {
      coord = Drupal.getlocations.geo.normalizeLat(coord);
      direction = (coord < 0) ? 'S' : 'N';
    }
    else {
      coord = Drupal.getlocations.geo.normalizeLng(coord);
      direction = (coord < 0) ? 'W' : 'E';
    }
    coord = Math.abs(coord);
    degrees = Math.floor(coord);
    coord = (coord - degrees) * 60;
    minutes = Math.floor(coord);
    coord = (coord - minutes) * 60;
    seconds = Math.round(coord, 6);
    if (web) {
      output = degrees + "&deg;&nbsp;" + minutes + "&#39;&nbsp;" + seconds + "&#34;&nbsp;" + direction;
    }
    else {
      output = degrees + '°' + minutes + '′' + seconds + '″' + direction;
    }

    return output;
  };

  /**
   * Convert Decimal Degrees Latitude to Degrees, minutes, seconds
   * @param {Number} coordinate in Decimal Degrees
   * @return {String} Degrees, minutes, seconds formatted for webpage
   */
  Drupal.getlocations.geo.dd_to_dms_lat = function(coord) {
    return Drupal.getlocations.geo.dd_to_dms_do(coord, 'lat');
  };

  /**
   * Convert Decimal Degrees Longitude to Degrees, minutes, seconds
   * @param {Number} coordinate in Decimal Degrees
   * @return {String} Degrees, minutes, seconds formatted for webpage
   */
  Drupal.getlocations.geo.dd_to_dms_lng = function(coord) {
    return Drupal.getlocations.geo.dd_to_dms_do(coord, 'lng');
  };

  /**
   * Format Decimal Degrees Latitude
   * @param {Number} coordinate in Decimal Degrees
   * @param {Number} number of digits after decimal point
   * @return {Number} formatted to standard length
   *
   */
  Drupal.getlocations.geo.dd_lat = function(coord, len) {
    if (typeof len == 'undefined') len = 6;
    coord = Drupal.getlocations.geo.normalizeLat(coord);
    return coord.toFixed(len);
  };

  /**
  * Format Decimal Degrees Longitude
  * @param {Number} coordinate in Decimal Degrees
  * @param {Number} number of digits after decimal point
  * @return {Number} formatted to standard length
  *
  */
  Drupal.getlocations.geo.dd_lng = function(coord, len) {
    if (typeof len == 'undefined') len = 6;
    coord = Drupal.getlocations.geo.normalizeLng(coord);
    return coord.toFixed(len);
  };

  /**
   * Convert Degrees, minutes, seconds to Decimal Degrees
   * from www.movable-type.co.uk/scripts/latlong.html
   * Sample usage:
   *   var lat = Drupal.getlocations.geo.parseDMS('51° 28′ 40.12″ N');
   *   var lon = Drupal.getlocations.geo.parseDMS('000° 00′ 05.31″ W');
   *
   * @param {String} Degrees, minutes, seconds
   * @return {Number} Decimal Degrees
   */
  Drupal.getlocations.geo.parseDMS = function(dmsStr) {
    // check for signed decimal degrees without NSEW, if so return it directly
    if (typeof dmsStr == 'number' && isFinite(dmsStr)) return Number(dmsStr);

    // strip off any sign or compass dir'n & split out separate d/m/s
    var dms = String(dmsStr).trim().replace(/^-/,'').replace(/[NSEW]$/i,'').split(/[^0-9.,]+/);
    if (dms[dms.length-1]=='') dms.splice(dms.length-1);  // from trailing symbol

    if (dms == '') return NaN;
    // and convert to decimal degrees...
    var deg;
    switch (dms.length) {
      case 3:  // interpret 3-part result as d/m/s
        deg = dms[0]/1 + dms[1]/60 + dms[2]/3600;
        break;
      case 2:  // interpret 2-part result as d/m
        deg = dms[0]/1 + dms[1]/60;
        break;
      case 1:  // just d (possibly decimal) or non-separated dddmmss
        deg = dms[0];
        // check for fixed-width unseparated format eg 0033709W
        //if (/[NS]/i.test(dmsStr)) deg = '0' + deg;  // - normalise N/S to 3-digit degrees
        //if (/[0-9]{7}/.test(deg)) deg = deg.slice(0,3)/1 + deg.slice(3,5)/60 + deg.slice(5)/3600;
        break;
      default:
        return NaN;
    }
    if (/^-|[WS]$/i.test(dmsStr.trim())) deg = -deg; // take '-', west and south as -ve
    return Number(deg);

  };

  /**
   * Converts decimal degrees to deg/min/sec format
   *  - degree, prime, double-prime symbols are added, but sign is discarded, though no compass
   *    direction is added.
   *
   * @private
   * @param   {number} deg - Degrees to be formatted as specified.
   * @param   {string} [format=dms] - Return value as 'd', 'dm', 'dms'.
   * @param   {number} [dp=0|2|4] - Number of decimal places to use – default 0 for dms, 2 for dm, 4 for d.
   * @returns {string} Degrees formatted as deg/min/secs according to specified format.
   */
  Drupal.getlocations.geo.toDMS = function(deg, format, dp) {
    if (isNaN(deg)) return null;  // give up here if we can't make a number from deg

    // default values
    if (typeof format == 'undefined') format = 'dms';
    if (typeof dp == 'undefined') {
      switch (format) {
        case 'd':   dp = 4; break;
        case 'dm':  dp = 2; break;
        case 'dms': dp = 0; break;
        default:    format = 'dms'; dp = 0;  // be forgiving on invalid format
      }
    }

    deg = Math.abs(deg);  // (unsigned result ready for appending compass dir'n)

    var dms, d, m, s;
    switch (format) {
      default: // invalid format spec!
      case 'd':
        d = deg.toFixed(dp);     // round degrees
        if (d<100) d = '0' + d;  // pad with leading zeros
        if (d<10) d = '0' + d;
        dms = d + '°';
        break;
      case 'dm':
        var min = (deg*60).toFixed(dp);  // convert degrees to minutes & round
        d = Math.floor(min / 60);    // get component deg/min
        m = (min % 60).toFixed(dp);  // pad with trailing zeros
        if (d<100) d = '0' + d;          // pad with leading zeros
        if (d<10) d = '0' + d;
        if (m<10) m = '0' + m;
        dms = d + '°' + m + '′';
        break;
      case 'dms':
        var sec = (deg*3600).toFixed(dp);  // convert degrees to seconds & round
        d = Math.floor(sec / 3600);    // get component deg/min/sec
        m = Math.floor(sec/60) % 60;
        s = (sec % 60).toFixed(dp);    // pad with trailing zeros
        if (d<100) d = '0' + d;            // pad with leading zeros
        if (d<10) d = '0' + d;
        if (m<10) m = '0' + m;
        if (s<10) s = '0' + s;
        dms = d + '°' + m + '′' + s + '″';
        break;
    }

    return dms;
  };

  /**
   * Converts numeric degrees to deg/min/sec latitude (2-digit degrees, suffixed with N/S).
   *
   * @param   {number} deg - Degrees to be formatted as specified.
   * @param   {string} [format=dms] - Return value as 'd', 'dm', 'dms'.
   * @param   {number} [dp=0|2|4] - Number of decimal places to use – default 0 for dms, 2 for dm, 4 for d.
   * @returns {string} Degrees formatted as deg/min/secs according to specified format.
   */
  Drupal.getlocations.geo.toLat = function(deg, format, dp) {
    var lat = Drupal.getlocations.geo.toDMS(deg, format, dp);
    return lat===null ? '–' : lat.slice(1) + (deg<0 ? 'S' : 'N');  // knock off initial '0' for lat!
  };

  /**
   * Convert numeric degrees to deg/min/sec longitude (3-digit degrees, suffixed with E/W)
   *
   * @param   {number} deg - Degrees to be formatted as specified.
   * @param   {string} [format=dms] - Return value as 'd', 'dm', 'dms'.
   * @param   {number} [dp=0|2|4] - Number of decimal places to use – default 0 for dms, 2 for dm, 4 for d.
   * @returns {string} Degrees formatted as deg/min/secs according to specified format.
   */
  Drupal.getlocations.geo.toLon = function(deg, format, dp) {
    var lon = Drupal.getlocations.geo.toDMS(deg, format, dp);
    return lon===null ? '–' : lon + (deg<0 ? 'W' : 'E');
  };

  /**
   * Converts numeric degrees to deg/min/sec as a bearing (0°..360°)
   *
   * @param   {number} deg - Degrees to be formatted as specified.
   * @param   {string} [format=dms] - Return value as 'd', 'dm', 'dms'.
   * @param   {number} [dp=0|2|4] - Number of decimal places to use – default 0 for dms, 2 for dm, 4 for d.
   * @returns {string} Degrees formatted as deg/min/secs according to specified format.
   */
  Drupal.getlocations.geo.toBrng = function(deg, format, dp) {
    deg = (Number(deg)+360) % 360;  // normalise -ve values to 180°..360°
    var brng =  Drupal.getlocations.geo.toDMS(deg, format, dp);
    return (brng === null ? '–' : brng.replace('360', '0'));  // just in case rounding took us up to 360°!
  };

}(jQuery));
