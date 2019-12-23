#!/bin/bash
if [ $# -ne 1 ]
then 
        echo "Usage : . ./cdwin.sh \"windows path\""
        exit
fi

echo $1
tmp_1=$(echo "$1" | sed "s/^/\/mnt\//")
tmp_2=$(echo "$tmp_1" | sed "s/\:/\//")
tmp_3=$(echo "$tmp_2" | sed "s/\\\/\//g")
echo "cd \"$tmp_3\""
cd "$tmp_3"

