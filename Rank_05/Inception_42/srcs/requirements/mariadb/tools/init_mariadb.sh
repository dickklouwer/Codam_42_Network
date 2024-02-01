#!/bin/bash

mysqld --skip-grant-tables --skip-networking &

sleep 5

# SQL init commands.
cat << EOF > init.sql
    FLUSH PRIVILEGES;
    CREATE DATABASE IF NOT EXISTS $DATABASE;
    
    FLUSH PRIVILEGES;
    CREATE USER IF NOT EXISTS '$DATABASE_USER'@'%' IDENTIFIED BY '$DATABASE_PASSWORD';
    GRANT ALL ON $DATABASE.* to '$DATABASE_USER'@'%';
    FLUSH PRIVILEGES;

    ALTER USER 'root'@'%' IDENTIFIED BY '$DATABASE_PASSWORD';
    FLUSH PRIVILEGES;

EOF

# Restarting MariaDB with init file
mysqladmin -u root shutdown

echo "Mariadb initialized and started ..."

mysqld --init-file=/init.sql

echo "Error in starting MariaDB ..."
