<script type="text/javascript">
//<![CDATA[
    $(document).ready(function() {
        $("#delAuth").click(function(){
            confirm_deletion();
            return false;
        });

        $("#z3950submit").click(function(){
            [% IF ( authid ) %]
                if (confirm(_("Please note that this Z39.50 search could replace the current record."))){
                    window.open("/cgi-bin/koha/cataloguing/z3950_auth_search.pl?authid=[% authid %]","z3950search",'width=740,height=450,location=yes,toolbar=no,scrollbars=yes,resize=yes');
                }
            [% ELSE %]
                window.open("/cgi-bin/koha/cataloguing/z3950_auth_search.pl","z3950search",'width=740,height=450,location=yes,toolbar=no,scrollbars=yes,resize=yes');
            [% END %]
            return false;
        });

    });

//]]>
</script>

[% IF ( authid || CAN_user_editauthorities) %]

<div id="toolbar" class="btn-toolbar">

[% IF ( authid ) %]
    [% IF ( CAN_user_editauthorities ) %]
        <div class="btn-group"><a class="btn btn-small" id="editAuth" href="authorities.pl?authid=[% authid %]"><i class="fa fa-pencil"></i> Edit</a></div>
        <div class="btn-group"><a class="btn btn-small" id="dupAuth" href="authorities.pl?authid=[% authid %]&amp;op=duplicate"><i class="fa fa-copy"></i> Duplicate</a></div>
        [% UNLESS ( count ) %]
            <div class="btn-group"><a href="#" class="btn btn-small" id="delAuth"><i class="fa fa-remove"></i> Delete</a></div>
        [% END %]
    [% END %]

    <div class="btn-group">
        <a class="btn btn-small dropdown-toggle" data-toggle="dropdown" href="#"><i class="fa fa-download"></i> Save
        <span class="caret"></span>
        </a>
        <ul class="dropdown-menu">
            <li><a href="/cgi-bin/koha/authorities/export.pl?format=mads&amp;op=export&amp;authid=[% authid %]">MADS (XML)</a></li>
            <li><a href="/cgi-bin/koha/authorities/export.pl?format=marcxml&amp;op=export&amp;authid=[% authid %]">MARCXML</a></li>
            <li><a href="/cgi-bin/koha/authorities/export.pl?format=marc8&amp;op=export&amp;authid=[% authid %]">MARC (non-Unicode/MARC-8)</a></li>
            <li><a href="/cgi-bin/koha/authorities/export.pl?format=utf8&amp;op=export&amp;authid=[% authid %]">MARC (Unicode/UTF-8)</a></li>
        </ul>
    </div>
[% END %]

[% IF ( CAN_user_editauthorities ) %]
    <div class="btn-group">
        <a class="btn btn-small dropdown-toggle" data-toggle="dropdown" href="#"><i class="fa fa-plus"></i> New authority
        <span class="caret"></span>
        </a>
        <ul class="dropdown-menu">
            [% FOREACH authtypesloo IN authtypesloop %]
            <li><a href="/cgi-bin/koha/authorities/authorities.pl?authtypecode=[% authtypesloo.value %]">[% authtypesloo.authtypetext %]</a></li>
            [% END %]
        </ul>
    </div>
    <div class="btn-group">
        <a class="btn btn-small" id="z3950submit" href="#"><i class="fa fa-search"></i> New from Z39.50</a>
    </div>
[% END %]
</div>

[% END %]
