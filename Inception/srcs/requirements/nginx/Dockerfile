FROM debian:buster

RUN apt-get update && apt-get -y upgrade \
    && apt-get install -y nginx openssl vim

RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj \
    "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt

RUN mv localhost.dev.crt etc/ssl/certs/ && mv localhost.dev.key etc/ssl/private/
RUN chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

COPY ./conf/default.conf ./
RUN cat default.conf > /etc/nginx/sites-available/default

EXPOSE 443
# EXPOSE 80 443

CMD ["nginx", "-g", "daemon off;"]
