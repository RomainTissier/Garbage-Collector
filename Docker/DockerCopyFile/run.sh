# Create Docker image
docker build -t docker_copy_file_image .

# Create container from docker image
docker create --tty --interactive --name="docker_copy_file_container" docker_copy_file_image

# Start the container 
docker start docker_copy_file_container

# Create and copy a file out of the container
docker exec docker_copy_file_container touch magic.txt
docker exec docker_copy_file_container sh -c "echo MAGIC > magic.txt"
docker cp docker_copy_file_container:/magic.txt magic.txt

# Stop and remove the container
docker stop docker_copy_file_container
docker rm docker_copy_file_container

