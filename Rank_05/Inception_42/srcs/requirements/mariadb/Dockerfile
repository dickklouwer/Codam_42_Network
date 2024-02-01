#This Dockerfile creates an image based on Debian Buster, 
# installs MariaDB server and client on it, makes the 
# necessary changes to the MariaDB configuration to allow
# external connections, and finally uses the script to set 
# up the MariaDB server when the container is started.

FROM debian:buster

RUN apt-get update -y

RUN	apt-get install -y mariadb-server

RUN mkdir -p /var/run/mysqld && \
    chown -R mysql:mysql /var/run/mysqld && \
    chown -R mysql:mysql /etc/mysql
    

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./tools/init_mariadb.sh /

RUN chown mysql:mysql /init_mariadb.sh

ENTRYPOINT [ "./init_mariadb.sh" ]
CMD [ "mysqld" ]