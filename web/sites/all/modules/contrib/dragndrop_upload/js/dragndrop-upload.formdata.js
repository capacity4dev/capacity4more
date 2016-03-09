/**
 * @file
 * Contains DnDFormData class.
 *
 * This is a wrapper for FormData class designed to allow filtering
 * and removing of appended elements.
 *
 * @param {Object} [data]
 */
function DnDFormData(data) {
  this.data = [];
  this.multiAppend(data);
}

(function ($) {
  DnDFormData.prototype = {

    /**
     * Clear current data object and fill it with new data.
     *
     * @param data
     */
    hydrate: function (data) {
      this.clear();
      this.multiAppend(data);
    },

    /**
     * Append to DnDFormData multiple elements at once.
     *
     * @param data
     */
    multiAppend: function (data) {
      var me = this;
      if (data) {
        $.each(data, function (key, value) {
          me.append(key, value);
        });
      }
    },

    /**
     * Check if there is a key in DnDFormData.
     *
     * @param key
     * @returns {*}
     */
    has: function (key) {
      for (var i in this.data) {
        if (this.data.hasOwnProperty(i)) {
          if (this.data[i].key == key) {
            return i;
          }
        }
      }
      return -1;
    },

    /**
     * Helper function to create data element for DnDFormData.
     *
     * @param key
     * @param value
     * @returns {{key: *, value: *}}
     */
    el: function (key, value) {
      return {
        key: key,
        value: value
      };
    },

    /**
     * Add value to DnDFormData.
     *
     * @param {String} op
     *    'prepend' or 'append' data to the DnDFormData.
     * @param {String} key
     * @param {String|File|Blob} value
     * @param {String} [name]
     *    File or Blob name
     */
    add: function (op, key, value, name) {
      if (name) {
        value = {
          data: value,
          name: name
        };
      }

      var elIndex = this.has(key);
      if (elIndex == -1) {
        if (op == 'prepend') {
          this.data.splice(0, 0, this.el(key, value));
        }
        else {
          if (op == 'append') {
            this.data.push(this.el(key, value));
          }
        }
      }
      else {
        if (!$.isArray(this.data[elIndex].value)) {
          this.data[elIndex].value = [this.data[elIndex].value];
        }

        this.data[elIndex].value.push(value);
      }
    },

    /**
     * Append value to DnDFormData.
     *
     * @param {String} key
     * @param {String|File|Blob} value
     * @param {String} [name]
     *    File or Blob name
     */
    append: function (key, value, name) {
      this.add('append', key, value, name);
    },

    /**
     * Prepend value to DnDFormData.
     *
     * @param {String} key
     * @param {String|File|Blob} value
     * @param {String} [name]
     *    File or Blob name
     */
    prepend: function (key, value, name) {
      this.add('prepend', key, value, name);
    },

    /**
     * Remove element from DnDFormData.
     *
     * @param key
     * @param index
     * @returns {boolean}
     */
    remove: function (key, index) {
      var elIndex = this.data.has(key);
      if (elIndex == -1) {
        return false;
      }
      else {
        if (index) {
          if ($.isArray(this.data[elIndex].value) && this.data[elIndex].value[index]) {
            this.data[elIndex].value.splice(index, 1);
            return true;
          }
          else {
            return false;
          }
        }
        else {
          delete this.data[elIndex];
          return true;
        }
      }
    },

    /**
     * Filter current values of DnDFormData.
     *
     * @param {Function} callback
     *    function (value, key) {
     *      // ...
     *    }
     * @see jQuery.map()
     */
    filter: function (callback) {
      for (var a in this.data) {
        if (this.data.hasOwnProperty(a)) {
          if ($.isArray(this.data[a].value)) {
            for (var b in this.data[a].value) {
              if (this.data[a].value.hasOwnProperty(b)) {
                if ((this.data[a][b] = callback(this.data[a].value[b], this.data[a].key)) === null) {
                  delete this.data[a].value[b];
                }
              }
            }
          }
          else {
            if ((this.data[a].value = callback(this.data[a].value, this.data[a].key)) === null) {
              delete this.data[a];
            }
          }
        }
      }
    },

    /**
     * Get element from DnDFormData.
     *
     * @param {String }key
     * @param {Number} index
     * @returns {*}
     */
    getElement: function (key, index) {
      var needle = undefined;
      $.each(this.data, function (i, el) {
        if (el.key == key) {
          if (index) {
            if ($.isArray(el.value) && el.value[index]) {
              needle = el.value[index];
            }
          }
          else {
            needle = el.value;
          }
          return false;
        }
        return true;
      });

      return needle;
    },

    /**
     * Clear DnDFormData object.
     */
    clear: function () {
      this.data = [];
    },

    /**
     * Render DnDFormData object.
     *
     * @returns {FormData}
     */
    render: function () {
      var formData = new FormData();
      $.each(this.data, function (i, el) {
        if (el != undefined) {
          if ($.isArray(el.value)) {
            $.each(el.value, function (i, v) {
              if ($.isPlainObject(v)) {
                formData.append(el.key, v.data, v.name);
              }
              else {
                formData.append(el.key, v);
              }
            });
          }
          else {
            if ($.isPlainObject(el.value)) {
              formData.append(el.key, el.value.data, el.value.name);
            }
            else {
              formData.append(el.key, el.value);
            }
          }
        }
      });
      return formData;
    }
  };
})(jQuery);
