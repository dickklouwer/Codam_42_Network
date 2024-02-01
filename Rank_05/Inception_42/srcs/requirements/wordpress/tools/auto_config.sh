#!/bin/bash

# Check if WordPress is installed by attempting to connect to the database
# and checking if the 'wp_users' table has any entries.

mkdir -p /var/www/
mkdir -p /var/www/wordpress

rm -f /var/www/wordpress/wp-config.php

if [ ! -f /var/www/wordpress/wp-config.php ]; then

	cd /var/www/wordpress

	#Download and configure WP-CLI
	curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

	chmod +x wp-cli.phar

	mv wp-cli.phar /usr/local/bin/wp

	#Dowload WordPress core
	wp core download --allow-root --force

	mv /wp-config.php /var/www/wordpress/wp-config.php


	sed -i -r "s/database/$DATABASE/1" 			wp-config.php
	sed -i -r "s/user/$DATABASE_USER/1" 		wp-config.php
	sed -i -r "s/user_pwd/$DATABASE_PASSWORD/1" wp-config.php

	#Install WordPress with first (admin) user.
	wp core install --allow-root --url=$WP_URL --title="tklouwer.42.fr" --admin_user=$WP_USER1 --admin_password=$WP_PWD1 --admin_email=user1@42.fr
	echo "Created wp-config.php file ..."

	#Create Second User
	wp user create $WP_USER2 user2@42.fr --allow-root --user_pass=$WP_PWD2

	# Ensure correct ownership and permissions
    chown -R www-data:www-data /var/www/wordpress
    find /var/www/wordpress -type d -exec chmod 755 {} \;
    find /var/www/wordpress -type f -exec chmod 644 {} \;

	# Configure to to listen to port '9000' instead of a local socket
	sed -i 's|listen = /run/php/php7.3-fpm.sock|listen = 0.0.0.0:9000|g' /etc/php/7.3/fpm/pool.d/www.conf

fi

echo "WordPress initialized and started..."

/usr/sbin/php-fpm7.3 -F
