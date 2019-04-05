#!/bin/bash
round=0;
if [ $1 -eq 1 ]
	then
	while [ $round -lt 10000 ]
	do
		echo "test";
		let round=$round+1;
	done
elif [ $1 -eq 2 ]
	then
	while [ $round -lt 100 ]
	do
		echo "test";
		let round=$round+1;
	done
elif [ $1 -eq 3 ]
	then
	while [ $round -lt 1000 ]
	do
		echo "test";
		let round=$round+1;
	done
elif [ $1 -eq 4 ]
	then
	while [ $round -lt 546 ]
	do
		echo "test";
		let round=$round+1;
	done
elif [ $1 -eq 5 ]
	then
	while [ $round -lt 1436 ]
	do
		echo "test";
		let round=$round+1;
	done
elif [ $1 -eq 6 ]
	then
	while [ $round -lt 76 ]
	do
		echo "test";
		let round=$round+1;
	done
elif [ $1 -eq 7 ]
	then
	while [ $round -lt 10 ]
	do
		echo "test";
		let round=$round+1;
	done
elif [ $1 -eq 8 ]
	then
	while [ $round -lt 325 ]
	do
		echo "test";
		let round=$round+1;
	done
elif [ $1 -eq 9 ]
	then
	while [ $round -lt 676 ]
	do
		echo "test";
		let round=$round+1;
	done
elif [ $1 -eq 10 ]
	then
	while [ $round -lt 1 ]
	do
		echo "test";
		let round=$round+1;
	done
fi



