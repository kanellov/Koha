[% USE Branches %]
<div id="header" class="navbar navbar-static-top">
    <div class="navbar-inner">
        <ul id="toplevelmenu" class="nav">
            [% IF ( CAN_user_circulate ) %]<li><a href="/cgi-bin/koha/circ/circulation-home.pl">Circulation</a></li>[% END %]
            [% IF ( CAN_user_borrowers ) %]<li><a href="/cgi-bin/koha/members/members-home.pl">Patrons</a></li>[% END %]
            [% IF ( CAN_user_catalogue ) %]<li><a href="/cgi-bin/koha/catalogue/search.pl">Search</a></li>[% END %]
            [% IF ( intranetbookbag ) %]
            <li><a href="#" id="cartmenulink">Cart<span id="basketcount"></span></a></li>
            [% END %]
            [% IntranetNav %]
            <li class="dropdown">
                <a href="#" class="dropdown-toggle" data-toggle="dropdown">More <b class="caret"></b></a>
                <ul class="dropdown-menu">
                    <li><a href="/cgi-bin/koha/virtualshelves/shelves.pl">Lists</a></li>
                    [% IF ( CAN_user_editcatalogue_edit_catalogue || CAN_user_editcatalogue_edit_items ) %]
                    <li><a href="/cgi-bin/koha/cataloguing/addbooks.pl">Cataloging</a></li>
                    [% END %]
                    [% IF ( CAN_user_acquisition ) %]
                    <li><a href="/cgi-bin/koha/acqui/acqui-home.pl">Acquisitions</a></li>
                    [% END %]
                    <li><a href="/cgi-bin/koha/authorities/authorities-home.pl">Authorities</a></li>
                    [% IF ( CAN_user_serials ) %]
                    <li><a href="/cgi-bin/koha/serials/serials-home.pl">Serials</a></li>
                    [% END %]
                    [% IF ( UseCourseReserves ) %]
                    <li><a href="/cgi-bin/koha/course_reserves/course-reserves.pl">Course reserves</a></li>
                    [% END %]
                    [% IF ( CAN_user_reports ) %]
                    <li><a href="/cgi-bin/koha/reports/reports-home.pl">Reports</a></li>
                    [% END %]
                    [% IF ( CAN_user_tools ) %]
                    <li><a href="/cgi-bin/koha/tools/tools-home.pl">Tools</a></li>
                    [% END %]
                    [% IF ( CAN_user_parameters ) %]
                    <li><a href="/cgi-bin/koha/admin/admin-home.pl">Administration</a></li>
                    [% END %]
                    <li><a href="/cgi-bin/koha/about.pl">About Koha</a></li>
                </ul>
            </li>
        </ul>
        <ul class="nav pull-right">
            [% IF ( loggedinusername ) %]
            <li class="dropdown">
                <a href="#" id="drop3" role="button" class="dropdown-toggle" data-toggle="dropdown">
                    <span class="loggedinusername">[% loggedinusername %]</span>
                    <span class="separator">|</span>
                    [% IF ( AutoLocation ) %]
                    <brand>
                        [% LoginBranchname %]
                    </brand>
                    [% ELSE %]
                    <strong>
                    [% IF ( LoginBranchname == 'NO_LIBRARY_SET' ) %]
                        NO LIBRARY SET
                    [% ELSE %]
                        <span id="logged-in-branch-name">[% LoginBranchname %]</span>
                        <span id="logged-in-branch-code" class="content_hidden">[% Branches.GetLoggedInBranchcode %]</span>
                    [% END %]
                    </strong>
                    [% END %]
                    <b class="caret"></b>
                </a>
                <ul class="dropdown-menu" role="menu" aria-labelledby="drop3">
                    [% IF ( IndependentBranches ) %]
                        [% IF ( CAN_user_management || CAN_user_editcatalogue_edit_catalogue ) %]
                    <li>
                        <a class="toplinks" href="/cgi-bin/koha/circ/selectbranchprinter.pl">Set library</a>
                    </li>
                        [% END %]
                    [% ELSE %]
                    <li>
                        <a class="toplinks" href="/cgi-bin/koha/circ/selectbranchprinter.pl">Set library</a>
                    </li>
                    [% END %]
                    [% IF EnableSearchHistory %]
                    <li>
                        <a class="toplinks" href="/cgi-bin/koha/catalogue/search-history.pl">Search history</a>
                    </li>
                    [% END %]
                    [% IF loggedinusernumber %]
                        <li class ="toplinks-myaccount">
                            <a class="toplinks" href="/cgi-bin/koha/members/moremember.pl?borrowernumber=[% loggedinusernumber %]">My account</a>
                        </li>
                        <li class="toplinks-mycheckouts">
                            <a class="toplinks" href="/cgi-bin/koha/circ/circulation.pl?borrowernumber=[% loggedinusernumber %]">My checkouts</a>
                        </li>
                    [% END %]
                    <li>
                        <a id="logout" class="toplinks" href="/cgi-bin/koha/mainpage.pl?logout.x=1">Log out</a>
                    </li>
                </ul>
            </li>
            <li>
                <a class="toplinks" href="/cgi-bin/koha/help.pl" id="helper">Help</a>
            </li>
            [% ELSE %]
            <li class="loggedout">
                <span>
                    <a href="/cgi-bin/koha/mainpage.pl" id="login">Log in</a>
                    <span class="separator">|</span>
                    <a class="toplinks" href="/cgi-bin/koha/help.pl" id="helper">Help</a>
                </span>
            </li>
            [% END %]
        </ul>
    </div>
    [% IF ( intranetbookbag ) %]<div id="cartDetails">Your cart is empty.</div>[% END %]
</div>
