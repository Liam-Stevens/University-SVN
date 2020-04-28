#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "data.h"

using namespace std;

/*-----------------------------------------
| Verifies the input arguments
------------------------------------------*/
bool verify(int argNum, string trainLocation, string testLocation, int minleaf)
{
	//TODO: Check location validity (Unsure if needed)

	//Check minleaf validity
	if (minleaf <= 0)
	{
		return 1;
	}

	return 0;
}

bool readData(string dataLocation, struct data * myData)
{
	string line;
	ifstream dataFile (dataLocation.c_str());

	//Open the file
  	if (dataFile.is_open())
  	{
		getline (dataFile,line);
    	while ( getline (dataFile,line) )
    	{
			stringstream lineStream;
			lineStream.str(line);
      		string ratingLabel;
			float num;
			vector<float> numbers;

			//Create vector of attribute data
			for (int i = 0; i < 5; i++)
			{
				lineStream >> num;
				numbers.push_back(num);
			}

			//Get rating
			lineStream >> ratingLabel;

			//Store data in struct
			myData->attributes.push_back(numbers);
			if (ratingLabel != "")
			{
				myData->ratings.push_back(ratingLabel);
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
