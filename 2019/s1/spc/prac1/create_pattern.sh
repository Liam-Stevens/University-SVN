#!/bin/bash

#filter inputs
if [ "$1" = "-u" ];
then
	caps=true;
	docheck2=true;
elif [ "$4" = "-u" ];
then
	caps=true;
	docheck1=true;
else
	if [ "$1" = "-s" ];
	then
		if [ "$3" = "-u" ];
		then
			caps=true;
			docheck3=true;
		else
			docheck1=true;
		fi
	else
		failed=true;
	fi
fi

#Checks middle parameter inputs
if [ "$docheck1" = true ];
then
	if [ $# -eq 2 ]
	then
		docheck3=true;
	elif [ $# -lt 2 ]
	then
		failed=true;
	else
		if [ "$2" = "-u" ]
		then
			failed=true;
		else
			if [ "$2" -gt 26 ]
			then
				failed=true;
			elif [ "$3" -lt 1 ]
			then
				failed=true;
			elif [ "$2" -lt 1 ]
			then
				let in1=0;
				let in2=$3-1;
			elif [ "$3" -gt 26 ]
			then
				let in1=$2-1;
				let in2=25;
			else
				let in1=$2-1;
				let in2=$3-1;
			fi
			if [ "$2" -gt "$3" ]
			then
				backwards=true;
			fi
		fi
	fi
fi

#Checks validity of ending parameter inputs
if [ "$docheck2" = true ];
then
	if [ $# -lt 3 ];
		then
		failed=true;
	elif [ $# -eq 3 ];
	then
		if [ "$3" -gt 26 ];
		then	
			let in1=25;
			let in2=25;
		elif [ "$3" -lt 1 ];
		then
			let in1=0;
			let in2=0;
		else
			let in1=$3-1;
			let in2=$3-1;
		fi
	else
		if [ "$3" -gt 26 ];
		then
			failed=true;
		elif [ "$4" -lt 1 ];
		then
			failed=true;
		elif [ "$3" -lt 1 ];
		then
			let in1=0;
			let in2=$4-1;
		elif [ "$4" -gt 26 ];
		then
			let in1=$3-1;
			let in2=25;
		else
			let in1=$3-1;
			let in2=$4-1;
		fi
		if [ "$3" -gt "$4" ];
		then
			backwards=true;
		fi
	fi
fi

#Checks validity of 1 digits inputs
if [ "$docheck3" = true ];
then
	if [ "$2" = "-u" ];
	then
		failed=true;
	elif [ "$2" -gt 26 ];
	then	
		let in1=25;
		let in2=25;
	elif [ "$2" -lt 1 ];
	then
		let in1=0;
		let in2=0;
	else
		let in1=$2-1;
		let in2=$2-1;
	fi
fi

#Moves inputs is backwards
if [ "$backwards" = true ] && [ "$failed" != true ];
then
	let temp=$in1;
	let in1=$in2;
	let in2=$temp;
fi

#Exits the program
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



