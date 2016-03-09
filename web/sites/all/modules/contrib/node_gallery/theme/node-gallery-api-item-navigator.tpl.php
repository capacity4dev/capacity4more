<?php

/**
 * @file
 * Default theme implementation to show a 6 column table containing the image navigator.
 *
 * Available variables:
 * @todo: fill this in
 *
 * @see theme_preprocess_node_gallery_api_item_navigator()
 */
?>
<table id="node-gallery-item-navigator" class="item-navigator">
  <tbody>
    <tr class="odd">
      <td class="item-navigator-position">
        <?php print t("%current of %total", array('%current' => $navigator['current'], '%total' => $navigator['total'])); ?>
      </td>
      <td class="item-navigator-first">
        <?php print isset($first_link) ? '<a href="'. $first_link .'">&lt;&lt; '. t('First') .'</a>' : '&nbsp;'; ?>
      </td>
      <td class="item-navigator-prev">
        <?php print isset($prev_link) ? '<a href="'. $prev_link .'">&lt; '. t('Previous') .'</a>' : '&nbsp;'; ?>
      </td>
      <td class="item-navigator-next">
        <?php print isset($next_link) ? '<a href="'. $next_link .'">'. t('Next') .' &gt;</a>' : '&nbsp;'; ?>
      </td>
      <td class="item-navigator-last">
        <?php print isset($last_link) ? '<a href="'. $last_link .'">'. t('Last') .' &gt;&gt;</a>' : '&nbsp;'; ?>
      </td>
      <td class="item-navigator-gallery-link">
        <?php print '<a href="'. $gallery_link .'">'. t("Back to gallery") .'</a>'; ?>
      </td>
    </tr>
  </tbody>
</table>
