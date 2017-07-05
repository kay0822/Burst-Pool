COMPONENTS+=www/libmicrohttpd databases/mysql-connector-c++

DIRS=home/burstpool/bin home/burstpool/static
BINARIES+=home/burstpool/bin/* /usr/sbin/daemon /bin/sh /usr/local/bin/socat /usr/local/bin/gdb78*
LD_LIBRARY_PATH=build/output:build/build/lib:/usr/local/lib/gcc49
CHROOT_FILES=etc/master.passwd etc/pwd.db etc/spwd.db  home/burstpool/config.js home/burstpool/backtrace.gdb

JAIL=burstpool
# can't use JAIL_INTERFACE because it will destroy the IPv4 address :(
# JAIL_INTERFACE=em0
JAIL_IP_INET4=192.168.0.20
JAIL_IP_INET6=
JAIL_WITH_DEVFS=yes
JAIL_WITH_SYSLOG=yes

# gdb wrapper version
#JAIL_EXEC_START="cd /home/burstpool; /usr/sbin/daemon -r bin/blockchain_monitor 1>>monitor.log 2>&1","cd /home/burstpool; /usr/sbin/daemon -r bin/blockchain_refresh 1>>refresh.log 2>&1","cd /home/burstpool; /usr/sbin/daemon -r bin/block_forger 1>>forge.log 2>&1","cd /home/burstpool; /usr/sbin/daemon -r bin/miner_rewarder 1>>reward.log 2>&1","cd /home/burstpool; /usr/sbin/daemon -r bin/reward_confirmer 1>>confirm.log 2>&1","cd /home/burstpool; /usr/sbin/daemon -r bin/account_updater 1>>updater.log 2>&1","cd /home/burstpool; /usr/sbin/daemon -r /usr/local/bin/gdb782 --command=backtrace.gdb --args bin/server 1>>gdb.log 2>&1","cd /home/burstpool; /usr/sbin/daemon -f -r /usr/local/bin/socat TCP4-LISTEN:80,reuseaddr,fork,backlog=200 TCP4:192.198.95.54:8124"


JAIL_EXEC_START="cd /home/burstpool; /usr/sbin/daemon -r bin/blockchain_monitor 1>>monitor.log 2>&1","cd /home/burstpool; /usr/sbin/daemon -r bin/blockchain_refresh 1>>refresh.log 2>&1","cd /home/burstpool; /usr/sbin/daemon -r bin/block_forger 1>>forge.log 2>&1","cd /home/burstpool; /usr/sbin/daemon -r bin/miner_rewarder 1>>reward.log 2>&1","cd /home/burstpool; /usr/sbin/daemon -r bin/reward_confirmer 1>>confirm.log 2>&1","cd /home/burstpool; /usr/sbin/daemon -r bin/account_updater 1>>updater.log 2>&1","cd /home/burstpool; /usr/sbin/daemon -r -f bin/server","cd /home/burstpool; /usr/sbin/daemon -f -r /usr/local/bin/socat TCP4-LISTEN:80,reuseaddr,fork,backlog=200 TCP4:192.168.0.20:8124","cd /home/burstpool; /usr/sbin/daemon -r bin/bonus_payer 1>>bonus.log 2>&1"

BACKUP_DIRS=${BASE}/home/burstpool/server.log


PRE_INSTALL=svn-burstpool
POST_INSTALL=svn-shmtech static-content server-log

PRE_SAFE=pre-safe
POST_SAFE=post-safe

MYSQL_DATABASE=burstpool
MYSQL_USER=pool
MYSQL_PASSWORD=pool
.include "../../Mk/mysql.mk"

snapshot:
	@echo '--> Taking snapshot <--'
	@snaptime=`date '+%Y%m%d-%H:%M'`; \
		serverpid=`ps -Jburstpool | fgrep server | fgrep -v daemon | fgrep -v gdb | cut -d' ' -f1`; \
		echo Core dump...; \
		gcore -s -c server-$$snaptime.core $$serverpid; \
		echo Burstpool jail process list...; \
		ps -Jburstpool -vww > ps-$$snaptime.txt; \
		echo mySQL connection/process list...; \
		echo 'show full processlist;show engine innodb status;' | mysql --socket ${BASE}/tmp/mysql.sock --user=root --password='_j&7Qb1G'  > mysql-$$snaptime.txt; \
		echo server log for current session...; \
		first_log_ln=`fgrep -n START server.log | tail -1 | cut -d: -f1`; \
		sed -n "$${first_log_ln},\$$p" server.log > server-$$snaptime.log; \
		echo Network status...; \
		netstat -Lan > netstat-$$snaptime.txt; \
		echo Tracing server process until restart...; \
		ktrace -i -d -f ktrace-$$snaptime.out -p $$serverpid; \
		echo '--> RESTARTING POOL <--'; \
		make restart

ps:
	ps -gxvwwJburstpool| fgrep -v socat

config:
	@echo '--> Quick config update and restart <--'
	@chflags noschg ${BASE}/home/burstpool/config.js
	@cp home/burstpool/config.js ${BASE}/home/burstpool/config.js
	@chflags schg ${BASE}/home/burstpool/config.js
	@make restart

update-static:
	@echo '--> Updating static content <--'
	(cd build/static; svn up)
	rsync --recursive --delete --links build/static ${BASE}/home/burstpool/

svn-burstpool:
	@echo '--> Building Burst pool content <--'
	@mkdir -p build
	@${SVN_CO_OR_UP} svn+ssh://dom@svn.shmtech.biz/home/subversion/burst build/
	@${SVN_CO_OR_UP} svn+ssh://shmtech@svn.shmtech.biz/home/subversion/superhypermegatech/build build/build
	(cd build/build; gmake)
	(cd build; gmake)
	@mkdir -p home/burstpool/bin
	@find build/output/* -prune -type f \! -name 'lib*' -exec cp {} home/burstpool/bin/ \;

static-content:
	@echo '--> Copying static content into jail <--'
	rsync --recursive --delete --links build/static ${BASE}/home/burstpool/

server-log:
	@touch ${BASE}/home/burstpool/server.log

svn-shmtech:
	@echo '--> Copying SHMTech content <--'
	@${SVN_CO_OR_UP} svn+ssh://shmtech@svn.shmtech.biz/home/subversion/superhypermegatech/public_html/js ${BASE}/home/shmtech/public_html/js

pre-safe:
	@chmod go+x ${BASE} ${BASE}/etc ${BASE}/home

post-safe:
	@chflags -R noschg ${BASE}/home/burstpool/*.* ${BASE}/root
	@chflags noschg ${BASE}/home/burstpool

.include "../../Mk/debug.mk"

.include "../../Mk/servers.mk"
