# Here we can export some file before stoping the container
docker cp minimal_nodejs_container:/opt/www/index.js toto.txt

# Stop and remove the container
docker stop minimal_nodejs_container
docker rm minimal_nodejs_container
