/**
 * @file
 * Support to move a block table.
 */

(function ($) {

  /**
   * Move a block in the blocks table from one region to another via select list.
   *
   * This behavior is dependent on the tableDrag behavior, since it uses the
   * objects initialized in that behavior to update the row.
   */
  Drupal.behaviors.termDrag = {
    attach: function (context, settings) {
      for (id in settings.tableDrag) {
        // Remove term-weight, term-parent, term-depth object element in order
        // not to get relationship error.
        delete settings.tableDrag[id]['term-weight'];
        delete settings.tableDrag[id]['term-parent'];
        delete settings.tableDrag[id]['term-depth'];
        var table = $('#' + id, context);

        // Get the blocks tableDrag object.
        var tableDrag = Drupal.tableDrag[id];
        var rows = $('tr', table).length;

        // Disable indent option for drag'n'drop objects.
        tableDrag.indentEnabled = false;
        tableDrag.hideColumns();
        tableDrag.row.prototype.onSwap = function (swappedRow) {
          // When a row is swapped, keep previous and next page classes set.
          $('tr.taxonomy-term-preview', table).removeClass('taxonomy-term-preview');
          $('tr.taxonomy-term-divider-top', table).removeClass('taxonomy-term-divider-top');
          $('tr.taxonomy-term-divider-bottom', table).removeClass('taxonomy-term-divider-bottom');
          if (settings[id].backStep) {
            for (var n = 0; n < settings[id].backStep; n++) {
              $(table[0].tBodies[0].rows[n]).addClass('taxonomy-term-preview');
            }
            $(table[0].tBodies[0].rows[settings[id].backStep - 1]).addClass('taxonomy-term-divider-top');
            $(table[0].tBodies[0].rows[settings[id].backStep]).addClass('taxonomy-term-divider-bottom');
          }

          if (settings[id].forwardStep) {
            for (var n = rows - settings[id].forwardStep - 1; n < rows - 1; n++) {
              $(table[0].tBodies[0].rows[n]).addClass('taxonomy-term-preview');
            }
            $(table[0].tBodies[0].rows[rows - settings[id].forwardStep - 2]).addClass('taxonomy-term-divider-top');
            $(table[0].tBodies[0].rows[rows - settings[id].forwardStep - 1]).addClass('taxonomy-term-divider-bottom');
          }
        };
      }
    }
  };

})(jQuery);
