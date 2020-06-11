#include <iostream>
#include <string>
#include <vector>
#include "helpers.h"
#include "data.h"
#include "Graph.h"
#include "Node.h"

using namespace std;

int main(int argc, char **argv)
{
	//the only difference in the two main files is this boolean
	bool poisoned = false;

	string configLocation = argv[1], changedConfigLocation = argv[2];

	//Check argument validity
	if ( verifyArgs(argc) )
	{
		cout << "Bad or missing arguments" << endl;
		return 1;
	}

	struct data configData;
	struct data changedConfigData;

	//Read in Config Data
	if ( readData(configLocation, &configData, false) )
	{
		cout << "Cannot Read Config Data" << endl;
		return 1;
	}

	//Read in Changed Config Data
	copyKeys(configData, &changedConfigData);
	if ( readData(changedConfigLocation, &changedConfigData, true) )
	{
		cout << "Cannot Read Changed Config Data" << endl;
		return 1;
	}

	//Create graph of nodes
	Graph myGraph(configData, changedConfigData);
	//Run Distance Vector Algorithm
	myGraph.runDistanceVector(poisoned);

	return 0;
}
