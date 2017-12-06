#!/bin/bash

#
# @file insertLine.sh
# @brief Show how to insert a line in a file with sed 
# @author Romain TISSIER
# @date 12/2017
#


# Check arguments 
if [ $# -ne 3 ]
then 
	echo "Usage : ${0} <file> <line> <message>"
	exit
fi


# Parse arguments
file=$1
line=$2
msg=$3


# Remove output file if it exists
if [ -f $file ]
then
       echo "Remove original output file"	
       rm -f $file
fi


# Create 
for i in `seq 1 20` 
do 
	echo $i >> $file
done


# Use sed to insert the line
sed -i "${line}i$msg" $file


# Inform user and quit
echo "Line inserted"

