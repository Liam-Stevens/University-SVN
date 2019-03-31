#!/bin/bash

#filter inputs
if [ "$1" = "-u" ];
then
	caps=true;
	docheck2=true;
else
	if [ "$4" = "-u" ];
	then
		caps=true;
		docheck1=true;
	else
		if [ "$1" = "-s" ];
		then
			docheck1=true;
		else
			failed=true;
		fi
	fi
fi
#make the check then exe inside
if [ "$docheck2" = true ];
then
	if [ $# -lt 4 ]
	then
		failed=true;
	else
		let in1=$3-1;
		let in2=$4-1;
	fi
fi
#make the check then exe inside
if [ "$docheck1" = true ];
then
	if [ $# -lt 3 ]
	then
		failed=true;
	else
		if [ "$2" = "-u" ] || [ "$3" = "-u" ]
		then
			failed=true;
		else
			let in1=$2-1;
			let in2=$3-1;
		fi
	fi
fi

if [ "$failed" = true ];
then
	echo "tr" "'[]'" "'[]'";
else

	#inputs to letters array
	uppercase=(A B C D E F G H I J K L M N O P Q R S T U V W X Y Z);
	lowercase=(a b c d e f g h i j k l m n o p q r s t u v w x y z);

	#change inputs to outputs

	if [ "$caps" = true ];
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
fi



