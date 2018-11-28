#! /bin/sh
mkdir backup
mysqldump -u root --password=Remidolov12345@ test > "backup/`date`my.mysql"
cp /var/www/html/ind.html "./backup/`date`ind.html"
