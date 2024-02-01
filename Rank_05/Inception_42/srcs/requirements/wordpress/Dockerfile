# Dockerfile to set up a WordPress environment with PHP-FPM and MariaDB Client.

#Base Image.
FROM debian:buster

RUN apt-get update -y

#Install all requiered packages.
RUN apt-get -y install wget

RUN apt-get install -y net-tools \
     php7.3 \
     php-mysql \
     php-fpm \
     mariadb-client

RUN apt install curl -y

# Create the directory for the PHP-FPM socket
RUN mkdir -p /run/php

# Copy WordPress script to the container.
COPY ./tools/auto_config.sh .
COPY ./conf/wp-config.php .

# Making the WordPress script runnable.
RUN chmod +x auto_config.sh

# Specifies the script that's run everytime the container starts.
CMD ["./auto_config.sh"]
