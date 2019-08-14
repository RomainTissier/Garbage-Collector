# Create docker images ("env" contains dependencies and "run" contains source code) 
docker build -t boost_custom_env -f ./Env_Dockerfile .
docker build -t boost_custom_run -f ./Run_Dockerfile .

# Create container from docker image
docker create --tty --interactive --name="boost_custom_container" boost_custom_run

# Start the container 
docker start boost_custom_container

# Compile and execute boost tests
docker exec boost_custom_container make
docker exec boost_custom_container sh -c "./tests"

# Stop and remove the container
docker stop boost_custom_container
docker rm boost_custom_container

