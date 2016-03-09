/**
 * @file
 * Contains DnDUploadAbstract class.
 */

/**
 * DnDUploadAbstract class.
 *
 * Attaches events' callbacks to droppables to make them work properly.
 */
var DnDUploadAbstract = function () {
  throw new Error('It is disallowed to instantiate this class! Extend it at first.');
};

(function ($) {
  DnDUploadAbstract.prototype = {
    dnd: null,
    processed: {},

    /**
     * Attach events to the given droppable areas.
     *
     * @param {jQuery} $droppables
     */
    attachEvents: function ($droppables) {
      var me = this;

      $.each(me.eventsList.dnd, function (name, func) {
        $droppables.bind(name, func.bind(me));
      });
    },

    /**
     * Detach events from the given droppable areas.
     *
     * @param {jQuery|undefined} $droppables
     */
    detachEvents: function ($droppables) {
      var me = this;

      $.each(me.eventsList.dnd, function (name) {
        $droppables.unbind(name);
      });
    },

    /**
     * Add droppable area.
     *
     * @param {string|jQuery} droppable
     */
    addDroppable: function (droppable) {
      var $droppable = $(droppable);
      this.dnd.addDroppable($droppable);

      this.attachEvents($droppable);
    },

    /**
     * Remove droppable area.
     *
     * @param {string|jQuery} droppable
     */
    removeDroppable: function (droppable) {
      var $droppable = $(droppable);
      this.detachEvents($droppable);

      this.dnd.removeDroppable($droppable);

    },

    /**
     * Set the given event callback as processed.
     *
     * @param {String} name
     */
    setProcessed: function (name) {
      this.processed[name] = true;
    },

    /**
     * Check whether the given event callback is already processed.
     *
     * @param {String} name
     */
    isProcessed: function (name) {
      this.processed[name] = true;
    },

    /**
     * Clear the processed event callbacks stack.
     */
    clearProcessed: function () {
      var me = this;
      $.each(me.processed, function (name) {
        me.processed[name] = false;
      });
    },

    /**
     * Get a prototype of this class.
     *
     * This method will be used in child classes to call parent methods.
     */
    parent: function () {
      return DnDUploadAbstract.prototype;
    },

    /**
     * Event callback that will be binded to the droppable areas.
     */
    eventsList: {
      /**
       * Droppable events.
       */
      dnd: {}
    }
  };

})(jQuery);
