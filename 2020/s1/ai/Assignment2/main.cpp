#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "data.h"
#include "helpers.h"

using namespace std;

int main(int argc, char **argv)
{
	string trainLocation = argv[1], testLocation = argv[2];
	int minleaf = atoi(argv[3]);

	if ( verify(argc, trainLocation, testLocation, minleaf) )
	{
		cout << "Invalid Arguments" << endl;
		return 1;
	}

	struct data trainingData;
	struct data testData;

	if ( readData(trainLocation, &trainingData) )
	{
		cout << "Cannot Read Training Data" << endl;
		return 1;
	}

	if ( readData(testLocation, &testData) )
	{
		cout << "Cannot Read Test Data" << endl;
		return 1;
	}


	


	return 0;
}
