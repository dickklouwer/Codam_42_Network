#!/bin/bash

echo "<html>"
echo "<head><title>Uploaded Images</title></head>"
echo "<body>"
echo "<h1><center>Uploaded Images</h1>"
echo "<center>this functionality only support image extensions."
echo "<hr>"
echo "<div>"

IMAGE_DIR="srv/www/uploads"

for img in $IMAGE_DIR/*; do
    filename=$(basename "$img")
    echo "<div><img src='/uploads/$filename' alt='$filename<' style='max-width: 600px; max-height: 600px;'><p><h1>$filename</h1></p></div>"
done

echo "</div>"
echo "</body>"
echo "</html>"
