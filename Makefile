.ONESHELL:

docker_build:
	docker build -t tasker-linux-ci .

docker_login: 
	docker tag tasker-linux-ci:latest thebigg1/tasker-linux-ci

docker_push:
	docker push thebigg1/tasker-linux-ci