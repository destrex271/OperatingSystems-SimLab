#!/bin/sh
# Created for Demo by Vinay Arora

echo "Program: $0
The number of arguments specified is $#
The arguments are $*"
grep "$1" $2
echo "\nJob Over"