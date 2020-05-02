#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Node.h"
#include "Graph.h"
#include "data.h"
#include "helpers.h"

using namespace std;

int main(int argc, char **argv)
{
	string trainLocation = argv[1], testLocation = argv[2];
	int minLeaf = atoi(argv[3]);

	if ( verify(argc, trainLocation, testLocation, minLeaf) )
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

	Graph myGraph(trainingData, minLeaf);

	struct splits mySplit;

	myGraph.chooseSplit(&mySplit, trainingData);

	for (int i = 0; i < (signed)testData.attributes.size(); i++)
	{
		cout << myGraph.predict(testData.attributes[i]) << endl;
	}













/*
	sortAttribute(&trainingData, 0);
	cout << "NO SPLIT" << endl;
	for (int i = 0; i < (signed)trainingData.attributes.size(); i++)
	{
		cout << trainingData.attributes[i][0] << endl;
	}



	struct data leftSplit;
	struct data rightSplit;
	splitData(mySplit.bestAttribute, mySplit.bestSplitValue, trainingData, &leftSplit, &rightSplit);
	cout << "LEFT SPLIT" << endl;
	for (int i = 0; i < (signed)leftSplit.attributes.size(); i++)
	{
		cout << leftSplit.attributes[i][0] << endl;
	}
	cout << "RIGHT SPLIT" << endl;
	for (int i = 0; i < (signed)rightSplit.attributes.size(); i++)
	{
		cout << rightSplit.attributes[i][0] << endl;
	}
*/



	return 0;
}
