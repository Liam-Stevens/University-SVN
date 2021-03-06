#include "Individual.h"
#include "Mutator.h"
#include "BitFlip.h"
#include "Rearrange.h"
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

//Executes mutation and returns the offspring
Individual execute(Individual* indPtr, Mutator* mPtr, int k)
{
    int tempLength = indPtr->getLength();
    Individual temp(tempLength);
    temp = mPtr->mutate(*indPtr, k);
    return temp;
}


int main()
{
    //Takes inputs
    string line;
	string input[4];
	int inc = 0;
	do {
		cin >> line;
		input[inc] = line;
		inc++;
	}
	while(inc < 4);

    //Declaring variables
    string binarystr1 = input[0];
    string binarystr2 = input[2];
    int k1;
    int k2;
    //Converts string to integers
    k1 = atoi (input[1].c_str());
    k2 = atoi (input[3].c_str());

    //Declares objects
    Individual indiv1(binarystr1);
    Individual indiv2(binarystr2);
    BitFlip flipper;
    Rearrange rearranger;

    //Makes the offspring
    indiv1 = execute(&indiv1,&flipper,k1);
    indiv2 = execute(&indiv2,&rearranger,k2);

    //Output
    cout << indiv1.getString() << " " << indiv2.getString() << " " << indiv2.getMaxOnes() << endl;

}
