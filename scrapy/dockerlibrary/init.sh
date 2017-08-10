#!/bin/bash

sql_command="DELETE FROM mysql.user WHERE user = 'root' AND host = '%';
    CREATE USER 'root'@'%';
	GRANT ALL ON *.* TO 'root'@'%' WITH GRANT OPTION ;
    CREATE DATABASE test;
    FLUSH PRIVILEGES ;"

# execute the command supplied
result=$(mysql -u root -e "$sql_command")
echo "got: $result"
