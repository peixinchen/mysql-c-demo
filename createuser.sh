#! /bin/sh

USERNAME="peixinchen"
PASSWORD="pxc_DB"

mysql -uroot -e "CREATE USER ${USERNAME}@localhost IDENTIFIED BY '${PASSWORD}'"
mysql -uroot -e "GRANT ALL ON testdb.* TO ${USERNAME}@localhost"
