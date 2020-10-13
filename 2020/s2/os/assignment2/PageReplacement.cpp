/*
Created By: Liam Stevens
ID: a1742143
Time:05.09.2020
Contact Email: a1742143@student.adelaide.edu.au
*/

#include <vector>
#include <string>
#include <iostream>

#include "page.h"
#include "page.cpp"
#include "memory.h"
#include "memory.cpp"
#include "helpers.cpp"

using namespace std;

int main(int argc, char **argv)
{
    string fileLocation = argv[1];
    vector<string> fileLines;

    if ( readFile(fileLocation, &fileLines) )
    {
        cout << "FAILED AT READ" << endl;
        return 1;
    }

    fileLines = filterComments(fileLines);

    printStrings(fileLines);

    return 0;
}
