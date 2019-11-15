# Create docker images ("env" contains dependencies and "run" contains source code)
docker build -t minimal_nodejs_and_mongodb_env -f ./Env_Dockerfile .
docker build --no-cache -t minimal_nodejs_and_mongodb_run -f ./Run_Dockerfile .

# Start the container, redirect virtual 8081 port on 8081 port
docker create -p 8081:8081  --tty --interactive --name="minimal_nodejs_and_mongodb_container" minimal_nodejs_and_mongodb_run

# Start the container
docker start minimal_nodejs_and_mongodb_container

# Run MongoDB
docker exec -d minimal_nodejs_and_mongodb_container mongod --dbpath="/opt/www/mongodb"
docker exec -it minimal_nodejs_and_mongodb_container mongoimport --db test_database --file /opt/www/articles.json
# Debug mongo : docker exec -it minimal_nodejs_and_mongodb_container mongo

# Run NodeJS
docker exec minimal_nodejs_and_mongodb_container node index.js
