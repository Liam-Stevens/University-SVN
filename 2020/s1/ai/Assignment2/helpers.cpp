#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>
#include "helpers.h"
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

/*-----------------------------------------
| Read the file to a vector
------------------------------------------*/
bool readData(string dataLocation, struct data * myData )
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

/*-----------------------------------------
| Bubble sort data for an attribute
------------------------------------------*/
void sortAttribute(struct data * myData, int attri)
{
	bool sorted;

    do
    {
        sorted = true;
        for(int i = 0; i < (signed)(myData->attributes.size() - 1); i++)
        {
            if (myData->attributes[i][attri] > myData->attributes[i+1][attri])
            {
                vector<float> temp = myData->attributes[i];
				myData->attributes[i] = myData->attributes[i+1];
				myData->attributes[i+1] = temp;

				string tempString = myData->ratings[i];
				myData->ratings[i] = myData->ratings[i+1];
				myData->ratings[i+1] = tempString;

                sorted = false;
            }
        }

    }
    while(sorted != true);
}

/*-----------------------------------------
| Calculate the gain at the split
------------------------------------------*/
float calcGain(struct data myData, int attri, float splitValue)
{
	//Gain = Information Content - Remainder
	vector<int> samples(7,0);
	vector<int> leftSamples(7,0);
	vector<int> rightSamples(7,0);
	for (int i = 0; i < (signed)myData.ratings.size(); i++)
	{
		if (myData.ratings[i] == "AAA")
		{
			samples[0]++;
			if (myData.attributes[i][attri] <= splitValue)
			{
				leftSamples[0]++;
			}
			else
			{
				rightSamples[0]++;
			}
		} else if (myData.ratings[i] == "AA")
		{
			samples[1]++;
			if (myData.attributes[i][attri] <= splitValue)
			{
				leftSamples[1]++;
			}
			else
			{
				rightSamples[1]++;
			}
		} else if (myData.ratings[i] == "A")
		{
			samples[2]++;
			if (myData.attributes[i][attri] <= splitValue)
			{
				leftSamples[2]++;
			}
			else
			{
				rightSamples[2]++;
			}
		} else if (myData.ratings[i] == "BBB")
		{
			samples[3]++;
			if (myData.attributes[i][attri] <= splitValue)
			{
				leftSamples[3]++;
			}
			else
			{
				rightSamples[3]++;
			}
		} else if (myData.ratings[i] == "BB")
		{
			samples[4]++;
			if (myData.attributes[i][attri] <= splitValue)
			{
				leftSamples[4]++;
			}
			else
			{
				rightSamples[4]++;
			}
		} else if (myData.ratings[i] == "B")
		{
			samples[5]++;
			if (myData.attributes[i][attri] <= splitValue)
			{
				leftSamples[5]++;
			}
			else
			{
				rightSamples[5]++;
			}
		} else if (myData.ratings[i] == "CCC")
		{
			samples[6]++;
			if (myData.attributes[i][attri] <= splitValue)
			{
				leftSamples[6]++;
			}
			else
			{
				rightSamples[6]++;
			}
		}
	}

	int totalParent = myData.ratings.size();
	int totalLeft = 0;
	int totalRight = 0;
	for (int i = 0; i < 7; i++)
	{
		totalLeft += leftSamples[i];
		totalRight += rightSamples[i];
	}

	float parentInformationContent = 0;
	float leftInformationContent = 0;
	float rightInformationContent = 0;
	for (int i = 0; i < 7; i++)
	{
		float probability = ((float)samples[i]/(float)totalParent);
		if (probability != 0)
		{
			parentInformationContent = parentInformationContent - (probability*log2(probability));
		}

		probability = ((float)leftSamples[i]/(float)totalLeft);
		if (probability != 0)
		{
			leftInformationContent = leftInformationContent - (probability*log2(probability));
		}

		probability = ((float)rightSamples[i]/(float)totalRight);
		if (probability != 0)
		{
			rightInformationContent = rightInformationContent - (probability*log2(probability));
		}
	}

	float gain = parentInformationContent - (leftInformationContent*totalLeft)/totalParent - (rightInformationContent*totalRight)/totalParent;

	return gain;
}

int distinctLabel(struct data myData)
{
	vector<int> distinction(7,0);
	for (int i = 0; i < (signed)myData.ratings.size(); i++)
	{
		if (myData.ratings[i] == "AAA")
		{
			distinction[0]++;
		} else if (myData.ratings[i] == "AA")
		{
			distinction[1]++;
		} else if (myData.ratings[i] == "A")
		{
			distinction[2]++;
		} else if (myData.ratings[i] == "BBB")
		{
			distinction[3]++;
		} else if (myData.ratings[i] == "BB")
		{
			distinction[4]++;
		} else if (myData.ratings[i] == "B")
		{
			distinction[5]++;
		} else if (myData.ratings[i] == "CCC")
		{
			distinction[6]++;
		}
	}


	int max = 0;
	int distinct = -1;
	bool unique = true;
	for (int i = 0; i < (signed)distinction.size(); i++)
	{
		if (distinction[i] > max)
		{
			max = distinction[i];
			distinct = i;
			unique = true;
		}
		else if (distinction[i] == max)
		{
			unique = false;
		}
	}

	if (unique == false)
	{
		distinct = -1;
	}

	return distinct;
}

void splitData(int attribute, float splitValue, struct data myData, struct data * leftDataSplit, struct data * rightDataSplit)
{

	for (int i = 0; i < (signed)myData.attributes.size(); i++)
	{

		if (myData.attributes[i][attribute] <= splitValue)
		{
			leftDataSplit->attributes.push_back(myData.attributes[i]);
			leftDataSplit->ratings.push_back(myData.ratings[i]);
		}
		else
		{
			rightDataSplit->attributes.push_back(myData.attributes[i]);
			rightDataSplit->ratings.push_back(myData.ratings[i]);
		}

	}

}

//TODO: make it check if nums are the same
bool checkSame(struct data myData)
{
	bool sameLabel = true;
	bool sameAttribute = true;
	for (int i = 0; i < (signed)myData.ratings.size(); i++)
	{
		if (myData.ratings[0] != myData.ratings[i])
		{
			sameLabel = false;
		}

		if (myData.attributes[0][0] != myData.attributes[i][0] || myData.attributes[0][1] != myData.attributes[i][1] ||
			myData.attributes[0][2] != myData.attributes[i][2] || myData.attributes[0][3] != myData.attributes[i][3] ||
			myData.attributes[0][4] != myData.attributes[i][4])
		{
			sameAttribute = false;
		}
	}

	return (sameLabel || sameAttribute);
}
