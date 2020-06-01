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
|
| Expected Input: The number of arguments
| Expected Output: Bool for success or failure (1 failure, 0 success)
|
| Check if there are 3 args (path to 2 files)
------------------------------------------*/
bool verifyArgs(int argNum)
{
	//Check correct number of arguments
	if (argNum != 3)
	{
		return 1;
	}

	return 0;
}

/*-----------------------------------------
| Read the file to a vector
|
| Expected Input: String for path to file, pointer to data structure and boolean for type of file
| Expected Output: Bool for success or failure (1 failure, 0 success)
|
| Opens file for reading and pushes each line to a data struct
| where keys contains the labels for each edge and
| weights is stream streamed each line to contain numbers representing the IDs
| of each edge followed by the weight
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

		//Sort the keys for correct format
		sortKeys(myData);

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
|
| Expected Input: name of the edge and the data struct containing the keys
| Expected Output: the ID of the edge with that name
|
| Searches the vector for the matching string and returns the index
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
|
| Expected Input: First data struct to copy from and a pointer to a data struct to copy to
| Expected Output: Copy of keys in second data struct
|
| Creates a vector in the new data struct to create a copy of the keys from the first data struct
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
|
| Expected Input: string containing two edge names and their weight, and a pointer to the data structure to modify
| Expected Output: Returns bool for success and failure, modifies data struct by expanding weights vector
|
| String streams the string to integers and changes the names of edges to their IDs
| Then stores this in a vector and pushes it to the data struct
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
| Sort Keys using Bubble Sort
|
| Expected Input: Pointer to data struct to modify
| Expected Output: Sorted key vector
|
| Bubble sorts the key vector from lowest to highest
------------------------------------------*/
void sortKeys(struct data * myData)
{
	if ((signed)myData->keys.size() > 1)
    {
        bool sorted;
        //Runs until vector is sorted
        do
        {
            sorted = true;
            //Iterates over connection vector
            for(int i = 0; i < (signed)(myData->keys.size() - 1); i++)
            {
                if (myData->keys[i][0] > myData->keys[i+1][0])
                {
                    //Swap elements
                    string tmp = myData->keys[i];
                    myData->keys[i] = myData->keys[i+1];
                    myData->keys[i+1] = tmp;
                    sorted = false;
                }
            }

        }
        while(sorted != true);
    }
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
