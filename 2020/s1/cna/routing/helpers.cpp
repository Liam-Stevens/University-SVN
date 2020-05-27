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
        //Read in node names
        if ( !changed && getline (dataFile,line) )
        {
            int numOfNodes;
            stringstream lineStream;
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
            stringstream lineStream;
            lineStream.str(line);
            lineStream >> numOfConnections;

            for (int i = 0; i < numOfConnections; i++)
        	{
                getline (dataFile,line);

                //Fails if file formatted wrong
                if ( translateToWeight(line, myData) )
                {
                    return 1;
                }
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

/*-----------------------------------------
| Get the key value from name
------------------------------------------*/
int getKey(string name, struct data myData)
{
    for (int i = 0; (signed)myData.keys.size(); i++)
    {
        if (name == myData.keys[i])
        {
            return i;
        }
    }
    return -1;
}

/*-----------------------------------------
| Copy Keys from one struct to another
------------------------------------------*/
void copyKeys(struct data copyFromData, struct data * copyToData)
{
    for (int i = 0; i < (signed)copyFromData.keys.size(); i++)
    {
        copyToData->keys.push_back( copyFromData.keys[i] );
    }
}

/*-----------------------------------------
| Translate from string to weight vector
------------------------------------------*/
bool translateToWeight(string link, struct data * myData)
{
    stringstream linkStream;
    string name1, name2;
    int weight;

    linkStream.str(link);
    linkStream >> name1;
    linkStream >> name2;
    linkStream >> weight;

    vector<int> thisLink;

    int key1 = getKey(name1, *myData);
    int key2 = getKey(name2, *myData);
    if (key1 == -1 || key2 == -1 || weight < 0)
    {
        return 1;
    }

    thisLink.push_back(key1);
    thisLink.push_back(key2);
    thisLink.push_back(weight);

    myData->weights.push_back(thisLink);

    return 0;
}


/*-----------------------------------------
| Debug
------------------------------------------*/

//Prints labels
extern void printLabels(struct data myData)
{
    cout << "Read Labels" << endl;
	for (int i = 0; i < (signed)myData.keys.size(); i++)
	{
		cout << myData.keys[i] << endl;
	}
}

//Prints a table of links
extern void printLinks(struct data myData)
{
    cout << "Link Table" << endl;
	for (int i = 0; i < (signed)myData.weights.size(); i++)
	{
		for (int j = 0; j < (signed)myData.weights[0].size(); j++)
		{
			cout << myData.weights[i][j] << " ";
		}
		cout << endl;
	}
}
