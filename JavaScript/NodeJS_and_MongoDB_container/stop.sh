
# Export MongoDB database
docker exec -it minimal_nodejs_and_mongodb_container mongoexport --db test_database --collection articles --pretty --out /opt/www/export.json
date=$(date '+%Y%m%d_%H%M%S') # Format YYYYMMDD_hhmmss
docker cp minimal_nodejs_and_mongodb_container:/opt/www/export.json export.json_$date

# Stop and remove the container
docker stop minimal_nodejs_and_mongodb_container
docker rm minimal_nodejs_and_mongodb_container
