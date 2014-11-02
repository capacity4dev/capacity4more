(function ($) {
  Drupal.behaviors.c4m_og = {
    setupArray: function (array) {

      // Trim values.
      for (var i=0; i < array.length; ++i) {
        array[i] = array[i].trim();
      }

      // Remove empty.
      for (var i=0; i < array.length; ++i) {
        if (array[i].length == 0) {
          array.splice(i, 1);
        }
      }
      return array;
    },
    cleanArray: function (values, toRemove) {
      values = this.setupArray(values);

      // Remove values.
      for (var i=0; i < toRemove.length; ++i) {
        for (var j=0; j < values.length; ++j) {
          if (values[j] === toRemove[i])
            values.splice(j, 1);
        }
      }

      return values;
    },
    mergeArrays: function (array) {
      var a = this.setupArray(array.concat());

      // Remove duplications.
      for (var i=0; i<a.length; ++i) {
        for (var j=i+1; j < a.length; ++j) {
          if (a[i] === a[j] || a[j].length == 0)
            a.splice(j--, 1);
        }
      }

      return a;
    },
    attach: function (context) {
      var tool = this;
      $('#edit-restricted-organisations-ec').change(function(event) {
        var isChecked = $(event.currentTarget).attr('checked');
        var domains = Drupal.settings.c4m_og.ec_domains;
        var existingDomains = $('#edit-restricted-by-domain').val().split(',');
        var newValue;
        if (isChecked) {
          // Add all needed domains.
          newValue = tool.mergeArrays(existingDomains.concat(domains));
        }
        else {
          // Remove all needed domains.
          newValue = tool.cleanArray(existingDomains, domains);
        }
        $('#edit-restricted-by-domain').val(newValue);
      });
      $('#edit-restricted-organisations-eu').change(function(event) {
        var isChecked = $(event.currentTarget).attr('checked');
        var domains = Drupal.settings.c4m_og.eu_domains;
        var existingDomains = $('#edit-restricted-by-domain').val().split(',');
        var newValue;
        if (isChecked) {
          // Add all needed domains.
          newValue = tool.mergeArrays(existingDomains.concat(domains));
        }
        else {
          // Remove all needed domains.
          newValue = tool.cleanArray(existingDomains, domains);
        }
        $('#edit-restricted-by-domain').val(newValue);
      });
    }
  }
})(jQuery);
