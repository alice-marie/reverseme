# MAKE DOCKER WORK
docker build --platform linux/amd64 -t level2-container .

docker run --rm -it level2-container
