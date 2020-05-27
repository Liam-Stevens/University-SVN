#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "helpers.h"
#include "data.h"

using namespace std;

/*-----------------------------------------
| Verifies the input arguments
------------------------------------------*/
bool verifyArgs(int argNum, string configLocation, string changedConfigLocation)
{
	//Check minleaf validity
	if (argNum != 3)
	{
		return 1;
	}

    //TODO: Check location validity (Unsure if needed)

	return 0;
}

/*-----------------------------------------
| Read the file to a vector
------------------------------------------*/
bool readData(string dataLocation, struct data * myData, bool changed)
{
    string line;
	ifstream dataFile (dataLocation.c_str());

	//Open the file
  	if (dataFile.is_open())
  	{
        stringstream lineStream;

        //Read in node names
        if ( !changed && getline (dataFile,line) )
        {
            int numOfNodes;
            lineStream.str(line);
            lineStream >> numOfNodes;

        	for (int i = 0; i < numOfNodes; i++)
        	{
                getline (dataFile,line);

                myData->keys.push_back(line);
        	}
        }

        //Read in node connections
        if ( getline (dataFile,line) )
        {
            int numOfConnections;
            lineStream.str(line);
            lineStream >> numOfConnections;

            for (int i = 0; i < numOfConnections; i++)
        	{
                getline (dataFile,line);

                myData->weights.push_back(line);
        	}
        }

    	dataFile.close();
  	}
	//Unable to open the file
  	else {
		return 1;
	}

	return 0;
}
