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
  <ul class="dropdown-menu" aria-labelledby="dLabel">
    <li><a href="javascript: w=window.open('/book/<?php print $nid; ?>/print?no_children=true');">Print page</a></li>
    <li><a href="javascript: w=window.open('/book/<?php print $nid; ?>/print');">Print page & sub-pages</a></li>
    <li><a href="javascript: w=window.open('/book/<?php print $bid; ?>/print');">Print all pages & sub-pages</a></li>
  </ul>
</div>
