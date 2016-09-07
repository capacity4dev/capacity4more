<?php

/**
 * @file
 * Template file for "c4m_features_social_actions_share".
 *
 * Available variables:
 *  - $json_data: JSON data
 *
 * @ingroup themeable
 */

?>
<div class="social-actions-share">
  <h3><?php print t('Share this page'); ?></h3>
  <script type="application/json"><?php print $json_data; ?></script>
  <div id="c4m-print">
    <div class="share_list share_style_link share_style_icon_24">
      <a href="#" title="Print" onclick="window.print();return false;"></a>
    </div>
  </div>
</div>
