#!/bin/bash

#filter inputs by type of input
#first check if caps first or last
if [ "$1" = "-u" ];
then
	caps=true;
	docheck2=true;
elif [ "$4" = "-u" ];
then
	caps=true;
	docheck1=true;
else
	#check if letters and then blocked by caps
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
	#check for single number input
	if [ $# -eq 2 ]
	then
		docheck3=true;
	elif [ $# -lt 2 ]
	then
		failed=true;
	else
		#check for invalid caps
		if [ "$2" = "-u" ]
		then
			failed=true;
		else
			filter1=$2;
			filter2=$3;
			#check for outside range
			if [ "$filter1" -gt 26 -a "$filter2" -gt 26 ]
			then
				failed=true;
			elif [ "$filter1" -lt 1 -a "$filter2" -lt 1 ]
			then
				failed=true;
			fi
			#check for reverse and single out of range
			if [ "$filter1" -gt 26 -a "$filter2" -lt 27 ]
			then
				let filter1=26;
			elif [ "$filter1" -gt 1 -a "$filter2" -lt 0 ]
			then
				let filter2=1;
			fi
			#check for single out of range
			if [ "$filter1" -lt 1 ]
			then
				let in1=0;
				let in2=$filter2-1;
			elif [ "$filter2" -gt 26 ]
			then
				let in1=$filter1-1;
				let in2=25;
			else
				let in1=$filter1-1;
				let in2=$filter2-1;
			fi
			#check if numbers are reverse order
			if [ "$filter1" -gt "$filter2" ]
			then
				backwards=true;
			fi
		fi
	fi
fi

#Checks validity of ending parameter inputs
if [ "$docheck2" = true ];
then
	#check for single number input with caps
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
		filter1=$3;
		filter2=$4;
		#check for outside range
		if [ "$filter1" -gt 26 -a "$filter2" -gt 26 ]
		then
			failed=true;
		elif [ "$filter1" -lt 1 -a "$filter2" -lt 1 ]
		then
			failed=true;
		fi
		#check for reverse and single out of range
		if [ "$filter1" -gt 26 -a "$filter2" -lt 27 ]
		then
			let filter1=26;
		elif [ "$filter1" -gt 1 -a "$filter2" -lt 0 ]
		then
			let filter2=1;
		fi
		#check for single out of range
		if [ "$filter1" -lt 1 ];
		then
			let in1=0;
			let in2=$filter2-1;
		elif [ "$filter2" -gt 26 ];
		then
			let in1=$filter1-1;
			let in2=25;
		else
			let in1=$filter1-1;
			let in2=$filter2-1;
		fi
		#check if numbers are reverse order
		if [ "$filter1" -gt "$filter2" ];
		then
			backwards=true;
		fi
	fi
fi

#Checks validity of 1 digits inputs
if [ "$docheck3" = true ];
then
	#check for invalid input
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

#Moves inputs if backwards
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
		#Makes the list for upper case letters
		out1=${uppercase[$in1]};
		out2=${uppercase[$in2]};
		#First output
		for (( i=$in1+1; i<$in2+1; i++ ))
		do
			out1="${out1}${uppercase[$i]}";
		done
		#Second output
		for (( i=$in2-1; i>$in1-1; i-- ))
		do
			out2="${out2}${uppercase[$i]}";
		done
	else
		#Makes the list for lower case letters
		out1=${lowercase[$in1]};
		out2=${lowercase[$in2]};
		#First output
		for (( i=$in1+1; i<$in2+1; i++ ))
		do
			out1="${out1}${lowercase[$i]}";
		done
		#Second output
		for (( i=$in2-1; i>$in1-1; i-- ))
		do
			out2="${out2}${lowercase[$i]}";
		done
	fi

	#output result
	echo "tr" "'[$out1]'" "'[$out2]'";
fi
exit