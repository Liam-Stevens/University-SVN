#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

void printNumber(vector<int> num)
{
	for (int i = 0; i < num.size(); i++)
	{
		cout << num[i];
	}
}

int indexer (int bottom, int top)
{
	if (bottom == 2 && top == 2)
	{
		return 4;
	} else if ((bottom == 2 && top == 1) || (bottom == 1 && top == 2))
	{
		return 3;
	} else if ((bottom == 0 && top == 2) || (bottom == 2 && top == 0) || (bottom == 1 && top == 1))
	{
		return 2;
	} else if ((bottom == 1 && top == 0) || (bottom == 0 && top == 1))
	{
		return 1;
	} else if (bottom == 0 && top == 0)
	{
		return 0;
	}
}

int uniqueIndexer (int bottom, int top)
{
	if (bottom == 2 && top == 2)
	{
		return 8;
	} else if (bottom == 2 && top == 1)
	{
		return 7;
	} else if (bottom == 2 && top == 0)
	{
		return 6;
	} else if (bottom == 1 && top == 2)
	{
		return 5;
	} else if (bottom == 1 && top == 1)
	{
		return 4;
	} else if (bottom == 1 && top == 0)
	{
		return 3;
	} else if (bottom == 0 && top == 2)
	{
		return 2;
	} else if (bottom == 0 && top == 1)
	{
		return 1;
	} else if (bottom == 0 && top == 0)
	{
		return 0;
	}
}

vector<int> removeLeading(vector<int> num)
{
	//Removes leading zeroes
	int cut = 0;
	for (int i = 0; i < num.size()-1; i++)
	{
		if (num[i] == 0)
		{
			cut++;
		} else {
			break;
		}
	}
	if (cut != 0)
	{
		num.erase(num.begin(),num.begin()+cut);
	}
	return num;
}

vector<int> separate(vector<int> num, int location, bool section)
{
	if (section == false)
	{
		vector<int> separator(location + num.size()%2,0);
		for (int i = 0; i < location + num.size()%2; i++) {
			separator[i] = num[i];
		}
		return separator;
	} else {
		vector<int> separator(location,0);
		for (int i = location + num.size()%2; i < num.size(); i++) {
			separator[i - (location + num.size()%2)] = num[i];
		}
		return separator;
	}
}

vector<int> schoolAddition(vector<int> first, vector<int> second, int base)
{
	//Makes an appropriate space to perform addition
	int maxLength = first.size();
	if (second.size() > maxLength)
	{
		maxLength = second.size();
	}
	//Extra room for the addition
	maxLength++;
	vector<int> workingFirstNumber = first;
	workingFirstNumber.insert(workingFirstNumber.begin(),0);
	vector<int>	workingSecondNumber = second;
	workingSecondNumber.insert(workingSecondNumber.begin(),0);
	//Pads zeroes until both sides are equal
	while(workingFirstNumber.size() < workingSecondNumber.size())
	{
		workingFirstNumber.insert(workingFirstNumber.begin(),0);
	}
	while(workingFirstNumber.size() > workingSecondNumber.size())
	{
		workingSecondNumber.insert(workingSecondNumber.begin(),0);
	}

	//School Method for Addition
	vector<int> sum(maxLength,0);
	int carry = 0;
	for (int i = maxLength - 1; i >= 0; i--)
	{
		sum[i] = workingFirstNumber[i] + workingSecondNumber[i] + carry;
		//cout << "Num" << i << " | " << sum[i] << endl;
		carry = 0;
		//Makes the carry for the next number
		while (sum[i] >= base)
		{
			carry = sum[i] / base;
			sum[i] = sum[i] % base;
		}
		while (sum[i] < 0)
		{
			sum[i] = sum[i] + base;
			carry--;
		}
	}

	return sum;
}


vector<int> schoolMultiplication(vector<int> first, vector<int> second, int base)
{
	vector<int> initialization (5,0);
	vector< vector<int> > subSum (9, initialization);

	while (first.size() < 3) {
		first.insert(first.begin(),0);
	}
	while (second.size() < 3) {
		second.insert(second.begin(),0);
	}

	for (int i = 2; i >= 0; i--)
	{

		for (int j = 2; j >= 0; j--)
		{
			int index = indexer(i,j);
			int mainIndex = uniqueIndexer(i,j);
			subSum[mainIndex][index] = first[j]*second[i];
			//cout << "Index: " << j+i << " | First: " << first[j] << " | Second: " << second[i] << endl;
		}

	}

	vector<int> sum (5,0);

	for (int i = 0; i < 9; i++)
	{
		sum = schoolAddition(sum,subSum[i],base);
		/*for (int j = 0; j < 5; j++)
		{
			cout << subSum[i][j];
		}
		cout << endl;*/
	}

	return sum;
}

//Makes all elements negative
vector<int> negative (vector<int> num)
{
	vector<int> negative = num;
	for (int i = 0; i < negative.size(); i++)
	{
		negative[i] = negative[i]*-1;
	}
	return negative;
}

//The recursive function of karatsuba multiplication
vector<int> recursiveKaratsuba (vector<int> first, vector<int> second, int base)
{
	/*cout << first.size() << " | " << second.size() << " {} " << endl;
	cout << "Number1: ";
	printNumber(first);
	cout << " Number2: ";
	printNumber(second);
	cout << endl;*/
	//Base Case
	if (first.size() <= 3 && second.size() <= 3)
	{
		/*cout << "Multiplier: ";
		printNumber(schoolMultiplication(first,second,base));
		cout << endl;*/
		return schoolMultiplication(first,second,base);
	}
	//cout << first.size() << " | " << second.size() << endl;

	int halfer = first.size()/2; //k
	vector<int> lowFirst = separate(first,halfer,true); //a0
	vector<int> highFirst = separate(first,halfer,false); //a1
	vector<int> lowSecond = separate(second,halfer,true); //b0
	vector<int> highSecond = separate(second,halfer,false); //b1
/*
	cout << "LowFirst: ";
	printNumber(lowFirst);
	cout << " HighFirst: ";
	printNumber(highFirst);
	cout << " LowSecond: ";
	printNumber(lowSecond);
	cout << " HighSecond: ";
	printNumber(highSecond);
	cout << endl;*/

	vector<int> section1 = recursiveKaratsuba(highFirst,highSecond,base); //p2
	/*cout << "Number1: ";
	printNumber(first);
	cout << " Number2: ";
	printNumber(second);
	cout << " LowFirst: ";
	printNumber(lowFirst);
	cout << " HighFirst: ";
	printNumber(highFirst);
	cout << " LowSecond: ";
	printNumber(lowSecond);
	cout << " HighSecond: ";
	printNumber(highSecond);
	cout << " Section1 ";
	printNumber(section1);
	cout << endl;*/
	vector<int> section3 = recursiveKaratsuba(lowFirst,lowSecond,base); //p0
	/*cout << "Number1: ";
	printNumber(first);
	cout << " Number2: ";
	printNumber(second);
	cout << " LowFirst: ";
	printNumber(lowFirst);
	cout << " HighFirst: ";
	printNumber(highFirst);
	cout << " LowSecond: ";
	printNumber(lowSecond);
	cout << " HighSecond: ";
	printNumber(highSecond);
	cout << " Section3 ";
	printNumber(section3);
	cout << endl;*/
	vector<int> section2Part1 = schoolAddition(highFirst,lowFirst,base);
	/*cout << "Number1: ";
	printNumber(first);
	cout << " Number2: ";
	printNumber(second);
	cout << " LowFirst: ";
	printNumber(lowFirst);
	cout << " HighFirst: ";
	printNumber(highFirst);
	cout << " LowSecond: ";
	printNumber(lowSecond);
	cout << " HighSecond: ";
	printNumber(highSecond);
	cout << " Section2Part1 ";
	printNumber(section2Part1);
	cout << endl;*/
	vector<int> section2Part2 = schoolAddition(lowSecond,highSecond,base);
	/*cout << "Number1: ";
	printNumber(first);
	cout << " Number2: ";
	printNumber(second);
	cout << " LowFirst: ";
	printNumber(lowFirst);
	cout << " HighFirst: ";
	printNumber(highFirst);
	cout << " LowSecond: ";
	printNumber(lowSecond);
	cout << " HighSecond: ";
	printNumber(highSecond);
	cout << " Section2Part2 ";
	printNumber(section2Part2);
	cout << endl;*/
	vector<int> section2 = recursiveKaratsuba(section2Part1,section2Part2,base); //p1
	/*cout << "Number1: ";
	printNumber(first);
	cout << " Number2: ";
	printNumber(second);
	cout << " LowFirst: ";
	printNumber(lowFirst);
	cout << " HighFirst: ";
	printNumber(highFirst);
	cout << " LowSecond: ";
	printNumber(lowSecond);
	cout << " HighSecond: ";
	printNumber(highSecond);
	cout << " Section2 ";
	printNumber(section2);
	cout << endl;*/

	vector<int> intermediate = schoolAddition(section1,section3,base); //p2+p0
	/*cout << "Intermediate ";
	printNumber(intermediate);
	cout << endl;*/
	intermediate = negative(intermediate);
	intermediate = schoolAddition(intermediate,section2,base); //p1-(p2+p0)
	/*cout << "Intermediate2 ";
	printNumber(intermediate);
	cout << endl;*/

	//Pad 2k zeroes to the end of p2
	for (int i = 0; i < 2*halfer; i++)
	{
		section1.push_back(0);
	}
	//Pad k zeroes to the end of p1-(p2+p0)
	for (int i = 0; i < halfer; i++)
	{
		intermediate.push_back(0);
	}

	section1 = removeLeading(section1);
	section3 = removeLeading(section3);
	intermediate = removeLeading(intermediate);

	vector<int> finale (1,0);
	/*cout << "Number1: ";
	printNumber(first);
	cout << " Number2: ";
	printNumber(second);
	cout << " SECTION1 ";
	printNumber(section1);
	cout << " INTERMEDIATE ";
	printNumber(intermediate);
	cout << " SECTION3 ";
	printNumber(section3);*/
	finale = schoolAddition(finale,section1,base);
	/*cout << " Finale1 ";
	printNumber(finale);*/
	finale = schoolAddition(finale,intermediate,base);
	/*cout << " Finale2 ";
	printNumber(finale);*/
	finale = schoolAddition(finale,section3,base);
	/*cout << " Finale3 ";
	printNumber(finale);
	cout << endl;*/

	return finale;

}


vector<int> karatsubaMultiplication (vector<int> first, vector<int> second, int base)
{
	if (first.size() <= 3 && second.size() <= 3)
	{
		return schoolMultiplication(first,second,base);
	} else {
		//Make their size equal
		while (first.size() < second.size()) {
			first.insert(first.begin(),0);
		}
		while (second.size() < first.size()) {
			second.insert(second.begin(),0);
		}
		return recursiveKaratsuba(first,second,base);
	}
}


int main()
{
	//Take the input
	string line;
	getline(cin,line);
	int elements = line.length();

	//Filter string to integer
	vector<int> firstNum;
	vector<int> secondNum;
	int baseNumber = 0;
	int index = 0;
	for (int i = 0; i < elements; i++)
	{
		//Test for integer inside string
		if (isdigit (line[i]))
		{
			if(index == 0)
			{
				firstNum.push_back(line[i]-48);
			} else if (index == 1)
			{
				secondNum.push_back(line[i]-48);
			} else if(index == 2)
			{
				baseNumber = baseNumber * 10;
				baseNumber = baseNumber + line[i] - 48;
			} else {
				break;
			}
		} else {
			//Next number if space detected
			index++;
		}
	}

	//School Addition
	vector<int> sum = removeLeading( schoolAddition(firstNum,secondNum,baseNumber) );
	for (int i = 0; i < sum.size(); i++)
	{
		cout << sum[i];
	}
	cout << " ";
	sum.clear();


	//Karatsuba Multiplication
	vector<int> karatsubaResult = removeLeading( karatsubaMultiplication(firstNum,secondNum,baseNumber) );


	//Division for postgraduates only (NOT REQUIRED)
	int divisionResult = 0;


	//Outputs the results
	//Output Addition
	for (int j = 0; j < karatsubaResult.size(); j++)
	{
		cout << karatsubaResult[j];
	}
	cout << " " << divisionResult << endl;

	return 0;
}
