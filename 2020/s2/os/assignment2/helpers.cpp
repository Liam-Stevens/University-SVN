#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "pageInfo.h"

using namespace std;

//Validates that the algorithm exists
bool validateAlg(string algorithm)
{
    if (algorithm == "FIFO" || algorithm == "LRU" || algorithm == "ARB" || algorithm == "WSARB-1" || algorithm == "WSARB-2")
    {
        return 0;
    }
    return 1;
}

//Read a text file into a vector
bool readFile(string fileLocation, vector<string> * fileLines)
{
    string line;
  	ifstream inputFile (fileLocation.c_str());

	//Open the file
  	if (inputFile.is_open())
  	{
    	while ( getline (inputFile,line) )
    	{
      		fileLines->push_back(line);
    	}
    	inputFile.close();
  	}
	//Unable to open the file
  	else {
		return 1;
	}
    return 0;
}

//Removes lines containing a '#' at the start of it
vector<string> filterComments(vector<string> fileLines)
{
    vector<string> newLines;
    for (int i = 0; i < (signed)fileLines.size(); i++)
    {
        if (fileLines[i][0] != '#')
        {
            newLines.push_back(fileLines[i]);
        }
    }
    return newLines;
}

//Converts lines of input to a page vector
void convertToPages(vector<string> lines, vector<struct pageInfo *> * myPages)
{
    for (int i = 0; i < (signed)lines.size(); i++)
    {
        struct pageInfo * temp;
        temp = new pageInfo;
        stringstream ss(lines[i]);
        ss >> temp->action;
        ss >> temp->name;
        myPages->push_back(temp);
    }
}

void convertPageHex(vector<struct pageInfo *> myPages, int frameSize)
{
    for (int i = 0; i < (signed)myPages.size(); i++)
    {
        int x;
        stringstream ss;
        ss << hex << myPages[i]->name;
        ss >> x;
        x = x / frameSize;
        myPages[i]->name = to_string(x);
    }
}

//Prints all pages
void exportPages(vector<struct pageInfo *> myPages)
{
    for (int i = 0; i < (signed)myPages.size(); i++)
    {
        cout << myPages[i]->action << " | " << myPages[i]->name << endl;
    }
}

//Prints all strings in a vector to the terminal
void printStrings(vector<string> lines)
{
    cout << "Printed Lines: " << endl;
    for (int i = 0; i < (signed)lines.size(); i++)
    {
        cout << i << ": " << lines[i] << endl;
    }
}
