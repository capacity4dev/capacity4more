<?php

/**
 * @file
 * Template file for c4m_helper_entity_print_action.
 */
?>
<div class="dropdown">
    <a id="printThisPage" data-target="#" href="javascript:window.print()" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false">
        <i class="fa fa-print" aria-hidden="true"></i><span class="action">Print page</span>
    </a>
    <ul class="dropdown-menu" aria-labelledby="dLabel">
        <li><a href="javascript: jQuery('body').removeClass('text-only-print'); window.print();"><i class="fa fa-print" aria-hidden="true"></i><span class="action">Print this page</span></a></li>
        <li><a href="javascript: jQuery('body').addClass('text-only-print'); window.print();"><i class="fa fa-file-text-o" aria-hidden="true"></i><span class="action">Text-only</span></a></li>
    </ul>
</div>
