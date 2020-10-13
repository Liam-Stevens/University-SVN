#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

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

//Prints all strings in a vector to the terminal
void printStrings(vector<string> lines)
{
    cout << "Printed Lines: " << endl;
    for (int i = 0; i < (signed)lines.size(); i++)
    {
        cout << i << ": " << lines[i] << endl;
    }
}
