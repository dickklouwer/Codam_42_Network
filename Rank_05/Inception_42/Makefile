NAME = inception

all:
	@mkdir -p /home/tklouwer/data/mariadb
	@mkdir -p /home/tklouwer/data/wordpress
	@docker-compose -f srcs/docker-compose.yml up --build -d
	@echo "Everything up and running ..."

down:
	@docker-compose -f srcs/docker-compose.yml down

re:
	@docker-compose -f srcs/docker-compose.yml up --build -d

clean:
	@docker stop $$(docker ps -qa); \
	docker rm $$(docker ps -qa); \
	docker rmi -f $$(docker images -q); \
	docker volume rm $$(docker volume ls -q); \