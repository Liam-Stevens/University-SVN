#!/bin/bash

inc=1
while [ $inc -lt 11 ]
do
	rm cptestout.txt
	touch cptestout.txt
	rm cptest.txt
	./create_large.sh $inc > cptest.txt
	echo ""
	echo "Test: #""$inc"
	time (./a.out cptest.txt cptestout.txt)
	let inc=$inc+1
done


