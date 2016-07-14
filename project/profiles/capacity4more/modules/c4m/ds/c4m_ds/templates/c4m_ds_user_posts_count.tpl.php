<?php

/**
 * @file
 * Template to output the posts count in the user stats.
 *
 * Uses the same icon for posts as in theme_c4m_website_statistics_summary().
 *
 * Available variables:
 *   - $count: the views count.
 */
?>

<span class="row-entity-count count-posts">
  <i class="fa fa-comments-o"></i>
  <?php print $count; ?>
</span>
