# Create docker images ("env" contains dependencies and "run" contains source code) 
docker build -t csharp_custom_env -f ./Env_Dockerfile .
docker build -t csharp_custom_run -f ./Run_Dockerfile .

# Create container from docker image
docker create --tty --interactive --name="csharp_custom_container" csharp_custom_run

# Start the container 
docker start csharp_custom_container

# Compile C# file
docker exec csharp_custom_container mcs ./hello.cs

# Run C# program
docker exec csharp_custom_container mono hello.exe

# Stop and remove the container
docker stop csharp_custom_container
docker rm csharp_custom_container

