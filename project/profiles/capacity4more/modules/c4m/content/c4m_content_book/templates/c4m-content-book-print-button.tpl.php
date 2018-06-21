<?php

/**
 * @file
 * Template for the book print buttons.
 */
?>

<div class="dropdown">
  <a id="printThisBookPage" data-target="#" href="javascript:window.print()" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false">
    <i class="fa fa-print" aria-hidden="true"></i><span class="action">Print options</span>
    <span class="caret"></span>
  </a>
  <ul class="dropdown-menu book-print-buttons" style="right: 0; left: auto;" aria-labelledby="dLabel">
    <li><?php print $page_url; ?></li>
    <li><?php print $page_subpages_url; ?></li>
    <li><?php print $book_url; ?></li>
  </ul>
</div>
