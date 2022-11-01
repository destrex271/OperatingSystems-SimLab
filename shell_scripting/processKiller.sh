#!/bin/sh

cnt = ps aux | grep $1 | wc
echo $cnt
# if [ $count == 0 ]
# then
# 	echo "Process not found\nGet your head straight you idiot" && exit
# fi

# echo "$0, is the Script that is gonna destroy Process $1"
#
sudo kill -9 $1
