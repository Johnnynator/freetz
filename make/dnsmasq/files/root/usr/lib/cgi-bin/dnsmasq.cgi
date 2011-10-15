#!/bin/sh


. /usr/lib/libmodcgi.sh

check "$DNSMASQ_ENABLED" yes:auto "*":man
check "$DNSMASQ_DHCP" yes:dhcp_yes "*":dhcp_no
check "$DNSMASQ_BOGUSPRIV" yes:boguspriv
check "$DNSMASQ_ETHERS" yes:ethers
check "$DNSMASQ_DHCP_BOOT" yes:dhcp_boot_yes "*":dhcp_boot_no
check "$DNSMASQ_STOP_DNS_REBIND" yes:stop_dns_rebind
check "$DNSMASQ_TFTP" yes:tftp_yes "*":tftp_no
check "$DNSMASQ_AVM_DNS" yes:avm_dns
check "$DNSMASQ_WRAPPER" yes:wrapper
check "$DNSMASQ_LOG_QUERIES" yes:log_queries

sec_begin '$(lang de:"Starttyp" en:"Start type")'
cat << EOF
<p>
<input id="e1" type="radio" name="enabled" value="yes"$auto_chk><label for="e1"> $(lang de:"Automatisch" en:"Automatic")</label>
<input id="e2" type="radio" name="enabled" value="no"$man_chk><label for="e2"> $(lang de:"Manuell" en:"Manual")</label>
</p>
<p>
<input type="hidden" name="wrapper" value="no">
<input id="e1" type="checkbox" name="wrapper" value="yes"$wrapper_chk><label for="w1"> $(lang de:"vor multid starten" en:"start before multid")</label><br>
</p>
EOF
sec_end

sec_begin '$(lang de:"DNS Server" en:"DNS server")'
cat << EOF
<h2>$(lang de:"Der DNS Server ist gebunden an" en:"The DNS server is listening on"):</h2>
<p>Port: <input type="text" name="dns_port" size="5" maxlength="5" value="$(html "$DNSMASQ_DNS_PORT")"></p>
<p>$(lang de:"Domain" en:"Domain"): <input type="text" name="domain" size="20" maxlength="255" value="$(html "$DNSMASQ_DOMAIN")"></p>
<p>
<input type="hidden" name="boguspriv" value="no">
<input id="b1" type="checkbox" name="boguspriv" value="yes"$boguspriv_chk><label for="b1"> $(lang de:"Reverse DNS-Anfragen f&uuml;r private IP-Adressen (RFC1918) nicht an andere DNS-Server (z.B. im VPN) weiterleiten." en:"Do not forward reverse DNS lookups for private IP address ranges (RFC1918).")</label><br>
<input type="hidden" name="stop_dns_rebind" value="no">
<input id="c1" type="checkbox" name="stop_dns_rebind" value="yes"$stop_dns_rebind_chk><label for="c1"> $(lang de:"Adressen von Upstream Nameservern ablehnen, wenn sie in privaten IP-Bereichen sind." en:"Reject addresses from upstream nameservers which are in private IP ranges.")</label><br>
<input type="hidden" name="log_queries" value="no">
<input id="f1" type="checkbox" name="log_queries" value="yes"$log_queries_chk><label for="f1"> $(lang de:"Namensaufl&ouml;sung loggen." en:"Log name resolution.")</label><br>
</p>
<p>
<input type="hidden" name="avm_dns" value="no">
<input id="d1" type="checkbox" name="avm_dns" value="yes"$avm_dns_chk><label for="d1"> $(lang de:"Durch AVM/Provider zugewiesene Upstream Nameserver nutzen." en:"Use the upstream nameservers of your provider/AVM.")</label>
<br>$(lang de:"momentan: " en:"at the moment: ")
EOF
echo 'servercfg.dns1' | ar7cfgctl -s
cat << EOF
$(lang de:" und " en:" and ")
EOF
echo 'servercfg.dns2' | ar7cfgctl -s
cat << EOF
</p>
<p>$(lang de:"zus&auml;tzlich diese Upstream Nameserver nutzen (durch Leerzeichen getrennt)" en:"Use these upstream nameservers additionally (seperated by space)"): <input type="text" name="upstream" size="55" maxlength="255" value="$(html "$DNSMASQ_UPSTREAM")"></p>
<h2>$(lang de:"Zus&auml;tzliche Kommandozeilen-Optionen (f&uuml;r Experten)" en:"Additional command-line options (for experts)"):</h2>
<p>$(lang de:"Optionen" en:"Options"): <input type="text" name="options" size="55" maxlength="255" value="$(html "$DNSMASQ_OPTIONS")"></p>
EOF
sec_end

sec_begin '$(lang de:"DHCP Server" en:"DHCP server")'
cat << EOF
<p>
<input id="d1" type="radio" name="dhcp" value="yes"$dhcp_yes_chk><label for="d1"> $(lang de:"Aktiviert" en:"Enabled")</label>
<input id="d2" type="radio" name="dhcp" value="no"$dhcp_no_chk><label for="d2"> $(lang de:"Deaktiviert" en:"Disabled")</label>
</p>
<h2>$(lang de:"DHCP Range (eine pro Zeile)" en:"DHCP range (one per line)")</h2>
<p><textarea name="dhcp_range" rows="3" cols="50" maxlength="255">$(html "$DNSMASQ_DHCP_RANGE")</textarea></p>
<p>
<input type="hidden" name="ethers" value="no">
<input id="s1" type="checkbox" name="ethers" value="yes"$ethers_chk><label for="s1"> $(lang de:"Statische DHCP Leases aus" en:"Static DHCP leases from") <a href="$(href file mod hosts)">hosts</a> (MAC &lt;-&gt; IP)</label><br>
<span style="font-size:10px;">($(lang de:"nur Eintr&auml;ge, die eine g&uuml;ltige IP und MAC aufweisen" en:"items with valid IP and MAC addresses only"))</span>
</p>
EOF
sec_end

sec_begin '$(lang de:"DHCP Boot" en:"DHCP Boot")'
cat <<EOF
<p>
<input id="p1" type="radio" name="dhcp_boot" value="yes"$dhcp_boot_yes_chk><label for="p1"> $(lang de:"Aktiviert" en:"Enabled")</label>
<input id="p2" type="radio" name="dhcp_boot" value="no"$dhcp_boot_no_chk><label for="p2"> $(lang de:"Deaktiviert" en:"Disabled")</label>
</p>
<p>$(lang de:"boot file" en:"boot file"): <input type="text" name="dhcp_bootfile" size="20" maxlength="255" value="$(html "$DNSMASQ_DHCP_BOOTFILE")"></p>
EOF
sec_end

sec_begin '$(lang de:"TFTP Server" en:"TFTP server")'
cat <<EOF
<p>
<input id="p1" type="radio" name="tftp" value="yes"$tftp_yes_chk><label for="p1"> $(lang de:"Aktiviert" en:"Enabled")</label>
<input id="p2" type="radio" name="tftp" value="no"$tftp_no_chk><label for="p2"> $(lang de:"Deaktiviert" en:"Disabled")</label>
</p>
<p>$(lang de:"tftp root" en:"tftp root"): <input type="text" name="tftp_tftproot" size="40" maxlength="255" value="$(html "$DNSMASQ_TFTP_TFTPROOT")"></p>
EOF
sec_end
