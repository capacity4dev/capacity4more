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
    <li><a href="/book/<?php print $nid; ?>/print?no_children=true" target="_blank" >Print page</a></li>
    <li><a href="/book/<?php print $nid; ?>/print" target="_blank">Print page & sub-pages</a></li>
    <li><a href="/book/<?php print $bid; ?>/print" target="_blank">Print all pages & sub-pages</a></li>
  </ul>
</div>
