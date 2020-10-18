#include "memory.h"
#include "page.h"
#include "pageInfo.h"

Memory::Memory(int newFrameSize, int newPageFrames, int newRefernceBits, int newRegularInterval, int newWindowSize)
{
    frameSize = newFrameSize;
    pageFrames = newPageFrames;
    referenceBits = newRefernceBits;
    regularInterval = newRegularInterval;
    windowSize = newWindowSize;
    activeHead = 0;
    timer = 0;
    events = 0;
    reads = 0;
    writes = 0;
    faults = 0;
}

/*
*   Getters
*    
*/
int Memory::getEvents()
{
    return events;
}

int Memory::getReads()
{
    return reads;
}

int Memory::getWrites()
{
    return writes;
}

int Memory::getFaults()
{
    return faults;
}

int Memory::getActiveHead()
{
    return activeHead;
}

int Memory::getTimer()
{
    return timer;
}

/*
*   Setters
*    
*/
void Memory::setEvents(int newEvents)
{
    events = newEvents;
}

void Memory::setReads(int newReads)
{
    reads = newReads;
}

void Memory::setWrites(int newWrites)
{
    writes = newWrites;
}

void Memory::setFaults(int newFaults)
{
    faults = newFaults;
}

void Memory::setActiveHead(int newActiveHead)
{
    activeHead = newActiveHead;
}

void Memory::setTimer(int newTimer)
{
    timer = newTimer;
}

/*
*   Helpers
*    
*/
void Memory::tick()
{
    timer++;
}

void Memory::outputStats()
{
    cout << "events in trace: " << events << endl << "total disk reads: " << reads << endl << "total disk writes: " << writes << endl << "page faults: " << faults << endl;
}

void Memory::cleanMemory()
{
    //TODO: implement if needed
}

/*
*   Algorithms
*    
*/
void Memory::FIFO(vector<struct pageInfo *> instructions)
{
    for (int i = 0; i < (signed)instructions.size(); i++)
    {
        
    }
}

void Memory::LRU(vector<struct pageInfo *> instructions)
{
    
}

void Memory::ARB(vector<struct pageInfo *> instructions)
{
    
}

void Memory::WSARB1(vector<struct pageInfo *> instructions)
{
    
}

void Memory::WSARB2(vector<struct pageInfo *> instructions)
{
    
}
