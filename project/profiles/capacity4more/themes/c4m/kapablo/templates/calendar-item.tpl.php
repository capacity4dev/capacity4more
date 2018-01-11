<?php

/**
 * @file
 * Copy of calendar-item.tpl.php.
 */
?>
<div class="<?php print !empty($item->class) ? $item->class : 'item'; ?> c4m-event">
  <div class="view-item view-item-<?php print $view->name ?>">
    <?php
      $element_style = '';
      if (!empty($item->stripe[0])) {
        $element_style = 'style="background-color:' . $item->stripe[0] . '"';
      }
    ?>
    <div class="calendar <?php print $item->granularity; ?>view" <?php print $element_style; ?>>
      <div class="<?php print $item->date_id ?> contents">
        <?php foreach ($rendered_fields as $field): ?>
          <?php print $field; ?>
        <?php endforeach; ?>
      </div>
    </div>
  </div>
</div>
