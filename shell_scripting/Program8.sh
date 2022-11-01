#!/bin/sh
# Created for Demo by Vinay Arora

echo "MENU DRIVEN\n"

echo "1. Listing the files\n 2. Processes in the system"
read inpValue

case "$inpValue" in

1) ls -l ;;
2) ps
3) ls -l ;;
#*) echo "No such option"

esac