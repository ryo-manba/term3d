#!/bin/bash
CYAN="\033[36m"
RESET="\033[0m"


find ./models/invalid_files/* | sort > tempfile
echo "---INVALID FILE TEST---"
while read line
do
    echo -en $CYAN"[CASE] "
    filename=(${line//\// })
    echo ${filename[3]}
    echo -en $RESET
    ./term3d $line
done < tempfile
rm tempfile
