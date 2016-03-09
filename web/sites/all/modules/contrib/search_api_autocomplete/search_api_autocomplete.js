(function ($) {

// Auto-submit main search input after autocomplete
if (typeof Drupal.jsAC != 'undefined') {

  /**
   * Handler for the "keyup" event.
   *
   * Extend from Drupal's autocomplete.js to automatically submit the form
   * when Enter is hit.
   */
  var default_onkeyup = Drupal.jsAC.prototype.onkeyup;
  Drupal.jsAC.prototype.onkeyup = function (input, e) {
    if (!e) {
      e = window.event;
    }
    // Fire standard function.
    $.proxy(default_onkeyup, this)(input, e);

    if (13 == e.keyCode && $(input).hasClass('auto_submit')) {
      var selector;
      if (typeof Drupal.settings.search_api_autocomplete != 'undefined'
          && typeof Drupal.settings.search_api_autocomplete.selector != 'undefined') {
        selector = Drupal.settings.search_api_autocomplete.selector;
      }
      else {
        selector = ':submit';
      }
      $(selector, input.form).trigger('click');
    }
  };

  /**
   * Handler for the "keydown" event.
   *
   * Extend from Drupal's autocomplete.js to avoid ajax interfering with the
   * autocomplete.
   */
  var default_onkeydown = Drupal.jsAC.prototype.onkeydown;
  Drupal.jsAC.prototype.onkeydown = function (input, e) {
    if (!e) {
      e = window.event;
    }
    // Fire standard function.
    $.proxy(default_onkeydown, this)(input, e);

    // Prevent that the ajax handling of views fires to early and thus
    // misses the form update.
    if (13 == e.keyCode && $(input).hasClass('auto_submit')) {
      e.preventDefault();
      return false;
    }
  };


  Drupal.jsAC.prototype.select = function(node) {
    this.input.value = $(node).data('autocompleteValue');
    $(this.input).trigger('autocompleteSelect', [node]);
    if ($(this.input).hasClass('auto_submit')) {
      if (typeof Drupal.search_api_ajax != 'undefined') {
        // Use Search API Ajax to submit
        Drupal.search_api_ajax.navigateQuery($(this.input).val());
      }
      else {
        var selector;
        if (typeof Drupal.settings.search_api_autocomplete != 'undefined'
            && typeof Drupal.settings.search_api_autocomplete.selector != 'undefined') {
          selector = Drupal.settings.search_api_autocomplete.selector;
        }
        else {
          selector = ':submit';
        }

        $(selector, this.input.form).trigger('click');
      }
      return true;
    }
  };

  /**
   * Overwrite default behaviour.
   *
   * Just always return true to make it possible to submit even when there was
   * an autocomplete suggestion list open.
   */
  Drupal.autocompleteSubmit = function () {
    $('#autocomplete').each(function () {
      this.owner.hidePopup();
    });
    return true;
  };
}

/**
* Performs a cached and delayed search.
*/
Drupal.ACDB.prototype.search = function (searchString) {
  this.searchString = searchString;

  // Check allowed length of string for autocomplete.
  var data = $(this.owner.input).first().data('min-autocomplete-length');
  if (data && searchString.length < data) {
    return;
  }

  // See if this string needs to be searched for anyway.
  if (searchString.match(/^\s*$/)) {
    return;
  }

  // Prepare search string.
  searchString = searchString.replace(/^\s+/, '');
  searchString = searchString.replace(/\s+/g, ' ');

  // See if this key has been searched for before.
  if (this.cache[searchString]) {
    return this.owner.found(this.cache[searchString]);
  }

  var db = this;
  this.searchString = searchString;

  // Initiate delayed search.
  if (this.timer) {
    clearTimeout(this.timer);
  }
  this.timer = setTimeout(function () {
    db.owner.setStatus('begin');

    // Ajax GET request for autocompletion. We use Drupal.encodePath instead of
    // encodeURIComponent to allow autocomplete search terms to contain slashes.
    $.ajax({
      type: 'GET',
      url: db.uri + '/' + Drupal.encodePath(searchString),
      dataType: 'json',
      success: function (matches) {
        if (typeof matches.status == 'undefined' || matches.status != 0) {
          db.cache[searchString] = matches;
          // Verify if these are still the matches the user wants to see.
          if (db.searchString == searchString) {
            db.owner.found(matches);
          }
          db.owner.setStatus('found');
        }
      },
      error: function (xmlhttp) {
        if (xmlhttp.status) {
          alert(Drupal.ajaxError(xmlhttp, db.uri));
        }
      }
    });
  }, this.delay);
};

})(jQuery);
