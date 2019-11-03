# Create docker images ("env" contains dependencies and "run" contains source code)
docker build -t minimal_nodejs_env -f ./Env_Dockerfile .
docker build --no-cache -t minimal_nodejs_run -f ./Run_Dockerfile .

# Start the container, redirect virtual 8081 port on 8081 port
docker run -p 8081:8081 --name minimal_nodejs_container -d minimal_nodejs_run node index.js

