#!/bin/bash



#Read input file
inputs=$#;
if [ "$inputs" = "0" ]
then
	while read line
	do
	  fileInput="${fileInput}${line}";
	done < "${1:-/dev/stdin}"
elif [ "$inputs" = "1" ]
then
	while read line
	do
	  fileInput="${fileInput}${line}";
	done < "${2:-/dev/stdin}"
elif [ "$inputs" = "2" ]
then
	while read line
	do
	  fileInput="${fileInput}${line}";
	done < "${3:-/dev/stdin}"
elif [ "$inputs" = "3" ]
then
	while read line
	do
	  fileInput="${fileInput}${line}";
	done < "${4:-/dev/stdin}"
elif [ "$inputs" = "4" ]
then
	while read line
	do
	  fileInput="${fileInput}${line}";
	done < "${5:-/dev/stdin}"
fi

#Encoding
fileOutput=$(echo $fileInput | $(./create_pattern.sh $1 $2 $3 $4))
echo $fileOutput;

exit








