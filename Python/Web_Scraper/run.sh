# Create docker images ("env" contains dependencies and "run" contains source code)
docker build -t python3_web_scraping_env -f ./Env_Dockerfile .
docker build --no-cache -t python3_web_scraping_run -f ./Run_Dockerfile .

# Create container from docker image
#    -> Use --shm-size=2g to run "selenium" properly
docker create --tty --interactive --name="python3_web_scraping_container" --shm-size=2g python3_web_scraping_run

# Start the container
docker start python3_web_scraping_container

# Create and copy a file out of the container
#     -> Use python3 -u to have unbuffered output
docker exec python3_web_scraping_container python3 -u script.py
docker cp python3_web_scraping_container:/output.html output.html

# Stop and remove the container
docker stop python3_web_scraping_container
docker rm python3_web_scraping_container
