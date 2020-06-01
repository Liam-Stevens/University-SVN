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
	string configLocation = argv[1], changedConfigLocation = argv[2];

	//Check argument validity
	if ( verifyArgs(argc, configLocation, changedConfigLocation) )
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

	Graph myGraph(configData, changedConfigData);
	myGraph.runDistanceVector();
	//myGraph.printAllTables();

	return 0;
}
