#!/bin/bash

for (( i=1; i<27; i++))
do
	for (( j=i; j<27; j++ ))
	do
		let different=0;
		$(./create_pattern.sh -u -s $i $j) < $1 > test.txt;
		cmp -s test.txt $2 || let different=1;
		rm test.txt;
		if [ $different -eq 0 ]
		then
			echo $i $j "-u";
		fi
	done
done

for (( i=1; i<27; i++))
do
	for (( j=i; j<27; j++ ))
	do
		let different=0;
		$(./create_pattern.sh -s $i $j) < $1 > test.txt;
		cmp -s test.txt $2 || let different=1;
		rm test.txt;
		if [ $different -eq 0 ]
		then
			echo $i $j;
		fi
	done
done


