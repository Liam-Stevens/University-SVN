/*
Created By: Liam Stevens
ID: a1742143
Time:05.09.2020
Contact Email: a1742143@student.adelaide.edu.au
*/

#include <vector>
#include <string>
#include <iostream>

#include "pageInfo.h"
#include "page.h"
#include "page.cpp"
#include "memory.h"
#include "memory.cpp"
#include "helpers.cpp"

using namespace std;

int main(int argc, char **argv)
{
    string fileLocation = argv[1];
    int frameSize = stoi(argv[2]);
    int pageFrames = stoi(argv[3]);
    string algorithm = argv[4];
    int referenceBits = -1;
    int regularInterval = -1;
    int windowSize = -1;
    
    if ( validateAlg(algorithm) )
    {
        cout << "ILLEGAL ARGUMENTS" << endl;
    }
    
    if (algorithm == "ARB" || algorithm == "WSARB-1" || algorithm == "WSARB-2")
    {
        referenceBits = stoi(argv[5]);
        regularInterval = stoi(argv[6]);
    }

    if (algorithm == "WSARB-1" || algorithm == "WSARB-2")
    {
        windowSize = stoi(argv[7]);
    }

    vector<string> fileLines;

    if ( readFile(fileLocation, &fileLines) )
    {
        cout << "FAILED AT READ" << endl;
        return 1;
    }

    fileLines = filterComments(fileLines);
    vector<struct pageInfo *> myPages;
    
    convertToPages(fileLines, &myPages);
    //exportPages(myPages);
    
    /*
    cout << "location: " << fileLocation << " | frameSize: " << frameSize << " | pageFrames: " << pageFrames << " | algorithm: " << algorithm 
    << " | referenceBits: " << referenceBits << " | regularInterval: " << regularInterval << " | windowSize: " << windowSize << endl;
    */
    
    Memory myMemory(frameSize, pageFrames, referenceBits, regularInterval, windowSize);
    if (algorithm == "FIFO")
    {
        myMemory.FIFO(myPages);
    }
    else if(algorithm == "LRU")
    {
        myMemory.LRU(myPages);
    }
    else if (algorithm == "ARB")
    {
        myMemory.ARB(myPages);
    }
    else if (algorithm == "WSARB-1")
    {
        myMemory.WSARB1(myPages);
    }
    else if (algorithm == "WSARB-2")
    {
        myMemory.WSARB2(myPages);
    }
    myMemory.outputStats();

    return 0;
}
