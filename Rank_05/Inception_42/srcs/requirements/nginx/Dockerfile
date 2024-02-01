FROM debian:buster

# Update packages and install necessary dependencies
RUN apt-get update -y
    
RUN apt install nginx -y 

RUN apt-get install -y openssl curl && \ 
    apt-get install -y libfcgi0ldbl

RUN mkdir -p /etc/nginx/ssl

# Copy Nginx config file and script
COPY conf/nginx.conf /etc/nginx/sites-available/default.conf
COPY start_nginx.sh .

# Make nginx executable, Create nginx config symlink and get self-signed certificate
RUN chmod +x start_nginx.sh

RUN rm -f /etc/nginx/sites-enabled/default && \
    ln -s /etc/nginx/sites-available/default.conf /etc/nginx/sites-enabled/default

RUN openssl req -x509 -nodes -newkey rsa:2048 -out /etc/nginx/ssl/tklouwer.crt -keyout /etc/nginx/ssl/tklouwer.key -subj "/CN=tklouwer.42.fr" 

# Expose port 443 for HTTPS acces
EXPOSE 443

# Set entrypoint to start script.
ENTRYPOINT [ "/start_nginx.sh" ]
