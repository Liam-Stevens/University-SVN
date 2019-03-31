#!/bin/bash



#Read input file from stdin
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

echo $(find ./ -name "create_pattern.sh")

#Encoding
local=$(find ./ -name "create_pattern.sh")
fileOutput=$(echo $fileInput | $($local $1 $2 $3 $4))
echo $fileOutput > "${5:-/dev/stdout}";

if [ "$inputs" = "0" ]
then
	echo $fileOutput > "${2:-/dev/stdout}";
elif [ "$inputs" = "1" ]
then
	echo $fileOutput > "${3:-/dev/stdout}";
elif [ "$inputs" = "2" ]
then
	echo $fileOutput > "${4:-/dev/stdout}";
elif [ "$inputs" = "3" ]
then
	echo $fileOutput > "${5:-/dev/stdout}";
elif [ "$inputs" = "4" ]
then
	echo $fileOutput > "${6:-/dev/stdout}";
fi

exit








