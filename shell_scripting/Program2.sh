#!/bin/sh
# Created for Demo by Vinay Arora

echo "Enter the pattern to be searched: \c"
read pname

echo "Enter the file to be used: \c"
read fname

echo "Searching for $pname from file $fname"

grep "$pname" $fname

echo "Selected records shown above"