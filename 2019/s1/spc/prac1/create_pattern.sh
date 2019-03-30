#!/bin/bash

#filter inputs
if [ "$1" = "-u" ];
then
	caps="true";
	let in1=$3-1;
	let in2=$4-1;
else
	if [ "$1" = "-s" ];
	then
		let in1=$2-1;
		let in2=$3-1;
	else
		kill;
	fi
fi

#inputs to letters array
uppercase=(A B C D E F G H I J K L M N O P Q R S T U V W X Y Z);
lowercase=(a b c d e f g h i j k l m n o p q r s t u v w x y z);

#change inputs to outputs

if [ "$caps" = "true" ];
then
	out1=${uppercase[$in1]};
	out2=${uppercase[$in2]};
	for (( i=$in1+1; i<$in2+1; i++ ))
	do
		out1="${out1}${uppercase[$i]}";
	done
	for (( i=$in2-1; i>$in1-1; i-- ))
	do
		out2="${out2}${uppercase[$i]}";
	done
else
	out1=${lowercase[$in1]};
	out2=${lowercase[$in2]};
	for (( i=$in1+1; i<$in2+1; i++ ))
	do
		out1="${out1}${lowercase[$i]}";
	done
	for (( i=$in2-1; i>$in1-1; i-- ))
	do
		out2="${out2}${lowercase[$i]}";
	done
fi


echo "tr" "'[$out1]'" "'[$out2]'";



