#!/bin/bash

#Checks for an upper case encoding
for (( i=1; i<27; i++))
do
	for (( j=i; j<27; j++ ))
	do
		#Makes a file with an encoding
		let different=0;
		$(./create_pattern.sh -u -s $i $j) < $1 > test.txt;
		#Checks if the encoding is the same as the result
		cmp -s test.txt $2 || let different=1;
		rm test.txt;
		#Outputs the encoding type if they are the same
		if [ $different -eq 0 ]
		then
			echo $i $j "-u";
		fi
	done
done

#Checks for lower case encoding
for (( i=1; i<27; i++))
do
	for (( j=i; j<27; j++ ))
	do
		#Makes a file with an encoding
		let different=0;
		$(./create_pattern.sh -s $i $j) < $1 > test.txt;
		#Checks if the encoding is the same as the result
		cmp -s test.txt $2 || let different=1;
		rm test.txt;
		#Outputs the encoding type if they are the same
		if [ $different -eq 0 ]
		then
			echo $i $j;
		fi
	done
done


