. /mod/etc/conf/mod.cfg

sec_level=1
[ -r /tmp/flash/security ] && mv /tmp/flash/security /tmp/flash/mod/security
[ -r /tmp/flash/mod/security ] && let sec_level="$(cat /tmp/flash/mod/security)"

# HTML-escape pieces of texts, large ones in a streaming manner
# (large_text | html; html "$small_value")
html() {
	if [ $# -eq 0 ]; then
		sed -e '
		    s/&/\&amp;/g
		    s/</\&lt;/g
		    s/>/\&gt;/g
		    s/'\''/\&#39;/g
		    s/"/\&quot;/g
		'
	else
		case $* in
			*[\&\<\>\'\"]*) httpd -e "$*" ;; #'
			*) echo "$*" ;;
		esac
	fi
}

_cgi_id() {
	case $1 in
		*[/]*) echo "$1" | sed "s#/#__#g" ;;
		*) echo "$1" ;;
	esac
}

_cgi_menu() {
local sub=$1
cat << EOF
<div class="menu">
<div id="status"><a href="/freetz/status">Status</a></div>
EOF

if [ "$sub" = "status" -a -r /mod/etc/reg/status.reg ]; then
    	local pkg title cgi
	while IFS='|' read -r pkg title cgi; do
		echo "<div id='$(_cgi_id "status_$cgi")' class='su'><a href='/freetz/status/$cgi'>$(html "$title")</a></div>"
	done < /mod/etc/reg/status.reg 
fi

cat << EOF
<div id="daemons"><a href="/freetz/status/daemons">$(lang de:"Dienste" en:"Services")</a></div>
<div id="settings"><a href="/freetz/conf">$(lang de:"Einstellungen" en:"Settings")</a></div>
EOF

if [ "$sub" = "settings" -a -r /mod/etc/reg/file.reg ]; then
    	local id title sec def
	while IFS='|' read -r id title sec def; do
		echo "<div id='$(_cgi_id "file_$id")' class='su'><a href='/freetz/conf/$id'>$(html "$title")</a></div>"
	done < /mod/etc/reg/file.reg 
fi

cat << EOF
<div id="packages"><a href="/freetz/packages">$(lang de:"Pakete" en:"Packages")</a></div>
EOF

if [ "$sub" = "packages" -a -r /mod/etc/reg/cgi.reg ]; then
    	local pkg title
	while IFS='|' read -r pkg title; do
		echo "<div id='$(_cgi_id "pkg_$pkg")' class='su'><a href='/freetz/packages/$pkg'>$(html "$title")</a></div>"
	done < /mod/etc/reg/cgi.reg 
fi

cat << EOF
<div id="extras"><a href="/cgi-bin/extras.cgi">Extras</a></div>
<div id="backup_restore"><a href="/freetz/backup">$(lang de:"Sichern/Wiederherstellen" en:"Backup/restore")</a></div>
<div id="rudi_shell"><a href="/freetz/shell" target="_blank">$(lang de:"Rudi-Shell" en:"Rudi shell")</a></div>
</div>
EOF
}

cgi_begin() {
local title=$(html "$1") id=${2:+$(_cgi_id "$2")}
cat << EOF
Content-type: text/html; charset=iso-8859-1

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<meta http-equiv="Content-Language" content="$(lang de:"de" en:"en")">
<meta http-equiv="Expires" content="0">
<meta http-equiv="Pragma" content="no-cache">
<title>Freetz&nbsp;&ndash; $title</title>
<link rel="stylesheet" type="text/css" href="/style/base.css">
<link rel="stylesheet" type="text/css" href="/style/colorscheme.css">
EOF

# custom style for fieldset and div.body
if [ ! "$_cgi_width" ]; then
	let _cgi_width=$MOD_CGI_WIDTH
fi
export _cgi_width
let _cgi_total_width="$_cgi_width+40"
let _usr_style="$_cgi_width-230"
echo '<style type="text/css">'
echo "fieldset { margin: 0px; margin-top: 10px; margin-bottom: 10px; padding: 10px; width: "$_usr_style"px;}"
echo "div.body { width: "$_usr_style"px; }"
echo "</style>"

if [ -n "$id" ]; then
cat << EOF
<style type="text/css">
<!--
#$id $(cat /usr/share/style.sel)
-->
</style>
EOF
fi

cat << EOF
</head>
<body>
<table border="0" cellspacing="0" cellpadding="0" align="center" width="$_cgi_total_width">
<tr>
<td width="20"><img src="/images/edge_lt.png" width="20" height="40" border="0" alt=""></td>
<td width="$_cgi_width" id="edgetop"><div class="version">$(html < /etc/.freetz-version)</div><div class="title"><a href="/freetz">Freetz</a>&nbsp;<a href="/freetz/about" target="_blank">&ndash;</a> <span style="font-style: italic;">$title</span></div></td>
<td width="20"><img src="/images/edge_rt.png" width="20" height="40" border="0" alt=""></td>
</tr>
<tr>
<td width="20" id="edgeleft"></td>
<td width="$_cgi_width" id="content">
EOF

local sub
if [ -n "$id" ]; then
	case $id in
		settings|file_*) sub='settings' ;;
		status*) sub='status' ;;
		*) sub='packages' ;;
	esac

	[ -e "/mod/var/cache/menu_$sub" ] || _cgi_menu "$sub" > "/mod/var/cache/menu_$sub"
	cat "/mod/var/cache/menu_$sub"
fi
}

cgi_end() {
cat << EOF
</td>
<td width="20" id="edgeright"></td>
</tr>
<tr>
<td width="20"><img src="/images/edge_lb.png" width="20" height="20" border="0" alt=""></td>
<td width="$_cgi_width" id="edgebottom"></td>
<td width="20"><img src="/images/edge_rb.png" width="20" height="20" border="0" alt=""></td>
</tr>
</table>
<div id="footer">
<span class="datetime" title="$(lang de:"System-Zeit des Routers" en:"Router's system time")">$(date +'$(lang de:"%d.%m.%Y" en:"%m/%d/%Y") %H:%M')</span>&nbsp;&ndash;
<span class="uptime" title="Uptime">$(uptime | sed -r 's/.*(up.*), load.*/\1/')</span>&nbsp;&ndash;
<span class="opt">$(lang de:"optimiert f&uuml;r" en:"optimised for") Mozilla Firefox</span>
</div>
</body>
</html>
EOF
}

sec_begin() {
cat << EOF
<div class="body">
<fieldset>
<legend>$1</legend>
EOF
}

sec_end() {
cat << EOF
</fieldset>
</div>
EOF
}

show_perc() {
	if [ $# -ge 1 -a "$1" -gt 3 ]; then
		echo "$1%"
	fi
}

stat_bar() {
    	local barstyle="br"
	if [ $# -gt 1 ]; then
		barstyle=$1; shift
	fi

	outhtml="<table class='bar $barstyle'><tr>"

	local i=1
	local sum=0
	for percent; do
	    	stat_bar_add_part $i $percent
		let i++
	done
	if let "sum < 100"; then
	    	stat_bar_add_part 0 $((100 - sum))
	fi
	if let "sum > 100"; then
		echo 'ERROR stat_bar: SUM > 100%'
	else
		echo "$outhtml</tr></table>"
	fi
}
stat_bar_add_part() {
    	local n=$1 percent=$2
	if let "percent > 0"; then
	    outhtml="$outhtml<td class='part$n' style='width: ${percent}%;'>$(show_perc $percent)</td>"
	fi
	let sum+=percent
}

# get a single query parameter (unescaped)
cgi_param() {
	local key=$1
	case "&$QUERY_STRING" in
		*"&$key="*)
			local value=${QUERY_STRING##*$key=}
			value=${value%%&*}
			httpd -d "$value"
			;;
	esac

}

back_button() {
    	local where=$1 title=${2:-$(lang de:"Zur&uuml;ck" en:"Back")}
	echo "<form action='$where'><input type='submit' value='$title'></form>"
}
