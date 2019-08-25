#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

//Large if else statement to find unique space a digit inside a number during multiplication
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

//Large if else statement to find a unique space in a single number during multiplication
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
	//Finds where leading zeroes are
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

	//Removes leading zeroes
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
		//Seperates the left (high) side of the number
		vector<int> separator(location + num.size()%2,0);
		for (int i = 0; i < location + num.size()%2; i++) {
			separator[i] = num[i];
		}
		return separator;
	} else {
		//Seperates the right (low) side of the number
		vector<int> separator(location,0);
		for (int i = location + num.size()%2; i < num.size(); i++) {
			separator[i - (location + num.size()%2)] = num[i];
		}
		return separator;
	}
}

vector<int> schoolAddition(vector<int> first, vector<int> second, int base)
{
	//Makes an appropriate space to perform addition and ensures both vectors are the same size
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
		//Addition method
		sum[i] = workingFirstNumber[i] + workingSecondNumber[i] + carry;
		carry = 0;

		//Makes the carry for the next number in addition
		while (sum[i] >= base)
		{
			carry = sum[i] / base;
			sum[i] = sum[i] % base;
		}
		//Carry for subtraction
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

	//Makes sure both vectors are the same size
	while (first.size() < 3) {
		first.insert(first.begin(),0);
	}
	while (second.size() < 3) {
		second.insert(second.begin(),0);
	}

	//Schools method multiplication
	for (int i = 2; i >= 0; i--)
	{
		for (int j = 2; j >= 0; j--)
		{
			//Indexers make sure the storage location is unique to each multiplication
			int index = indexer(i,j);
			int mainIndex = uniqueIndexer(i,j);
			subSum[mainIndex][index] = first[j]*second[i];
		}
	}

	//Sum all multiplications together
	vector<int> sum (5,0);
	for (int i = 0; i < 9; i++)
	{
		sum = schoolAddition(sum,subSum[i],base);
	}

	return sum;
}

//Makes all elements negative
vector<int> negative (vector<int> num)
{
	vector<int> negative = num;
	for (int i = 0; i < negative.size(); i++)
	{
		//Multiply all elements by -1
		negative[i] = negative[i]*-1;
	}
	return negative;
}

//The recursive function of karatsuba multiplication
vector<int> recursiveKaratsuba (vector<int> first, vector<int> second, int base)
{
	//Base Case
	if (first.size() <= 3 && second.size() <= 3)
	{
		return schoolMultiplication(first,second,base);
	}

	int halfer = first.size()/2; //k
	vector<int> lowFirst = separate(first,halfer,true); //a0
	vector<int> highFirst = separate(first,halfer,false); //a1
	vector<int> lowSecond = separate(second,halfer,true); //b0
	vector<int> highSecond = separate(second,halfer,false); //b1

	vector<int> section1 = recursiveKaratsuba(highFirst,highSecond,base); //p2
	vector<int> section3 = recursiveKaratsuba(lowFirst,lowSecond,base); //p0
	vector<int> section2Part1 = schoolAddition(highFirst,lowFirst,base);
	vector<int> section2Part2 = schoolAddition(lowSecond,highSecond,base);
	vector<int> section2 = recursiveKaratsuba(section2Part1,section2Part2,base); //p1

	vector<int> intermediate = schoolAddition(section1,section3,base); //p2+p0

	intermediate = negative(intermediate); //-(p2+p0)
	intermediate = schoolAddition(intermediate,section2,base); //p1-(p2+p0)


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

	//Remove all leading zeroes
	section1 = removeLeading(section1);
	section3 = removeLeading(section3);
	intermediate = removeLeading(intermediate);

	//Adds all the sections together
	vector<int> finale (1,0);
	finale = schoolAddition(finale,section1,base);
	finale = schoolAddition(finale,intermediate,base);
	finale = schoolAddition(finale,section3,base);

	return finale;
}


vector<int> karatsubaMultiplication (vector<int> first, vector<int> second, int base)
{
	if (first.size() <= 3 && second.size() <= 3)
	{
		//School method
		return schoolMultiplication(first,second,base);
	} else {
		//Make the vector size equal by padding 0
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
				//Push to firstNum
				firstNum.push_back(line[i]-48);
			} else if (index == 1)
			{
				//Push to secondNum
				secondNum.push_back(line[i]-48);
			} else if(index == 2)
			{
				//Find the base
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
	//Print the results of addition
	for (int i = 0; i < sum.size(); i++)
	{
		cout << sum[i];
	}
	cout << " ";

	//Karatsuba Multiplication
	vector<int> karatsubaResult = removeLeading( karatsubaMultiplication(firstNum,secondNum,baseNumber) );

	//Division for postgraduates only (NOT REQUIRED)
	int divisionResult = 0;

	//Outputs the results of karatsuba
	for (int j = 0; j < karatsubaResult.size(); j++)
	{
		cout << karatsubaResult[j];
	}
	cout << " " << divisionResult << endl;

	return 0;
}
