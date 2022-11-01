#!/bin/sh
# Created for Demo by Vinay Arora

N=10
i=0
j=0

while [ $i -le `expr $N - 1` ]
do
    j=0

    while [ $j -le `expr $N - 1` ]
    do
        if [ `expr $N - 1` -ge `expr $i + $j` ]
        then
          # Print the pattern
          echo -n "#"
        else
          # Print the spaces required
          echo -n " "
        fi
        j=`expr $j + 1`
    done
    # For next line
    echo

    i=`expr $i + 1`
done