# MedWord

## build base image
docker build -t medword_base:latest -f dockerlibrary/base_Dockerfile .

## deploy
### 1. deploy servers without images:
docker-compose up -d --build

### 2. deploy servers with existed images:
docker-compose up -d 

### 3. start nginx
sudo nginx -c $absolute_path_to_nginx_conf/nginx.conf
