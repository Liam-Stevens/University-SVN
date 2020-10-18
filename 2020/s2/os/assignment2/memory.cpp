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

void Memory::incRead()
{
    events++;
    reads++;
}

void Memory::incWrite()
{
    writes++;
}

void Memory::incFaults()
{
    faults++;
}

void Memory::outputStats()
{
    cout << "events in trace: " << events << endl << "total disk reads: " << reads << endl << "total disk writes: " << writes << endl << "page faults: " << faults << endl;
}

void Memory::outputActiveList()
{
    for (int i = 0; i < (signed)active.size(); i++)
    {
        cout << "[" << i << "] " << active[i]->getName() << " | D: ";
        if (active[i]->getDirty())
        {
            cout << 'W';
        }
        else
        {
            cout << 'R';
        }
        cout << endl;
    }
    cout << endl;
}

void Memory::cleanMemory()
{
    for (int i = 0; i < (signed)active.size(); i++)
    {
        if (active[i]->getDirty())
        {
            incWrite();
        }
        delete active[i];
    }
    active.clear();
}

bool Memory::checkMemory(string name)
{
    for (int i = 0; i < (signed)active.size(); i++)
    {
        if (active[i]->getName() == name)
        {
            return true;
        }
    }
    return false;
}

/*
*   Algorithms
*    
*/
void Memory::FIFO(vector<struct pageInfo *> instructions)
{
    for (int i = 0; i < (signed)instructions.size(); i++)
    {
        if (!checkMemory(instructions[i]->name))
        {
            incFaults();
            
            Page *temp;
            temp = new Page(instructions[i]->name);

            incRead();
            if (instructions[i]->action == 'R')
            {
                temp->setDirty(false);
            }
            else if (instructions[i]->action == 'W')
            {
                temp->setDirty(true);
            }
            else
            {
                cout << "Page " << i << " has an illegal action type" << endl;
            }

            if ((signed)active.size() < pageFrames)
            {
                active.push_back(temp);
            }
            else
            {
                Page *removal;
                removal = active[activeHead];
                active[activeHead] = temp;
                if (removal->getDirty() == true)
                {
                    incWrite();
                }
                delete removal;
            }

            activeHead++;
            if (activeHead >= pageFrames)
            {
                activeHead = 0;
            }
            //outputActiveList();
        }
    }
    cleanMemory();
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

Memory::~Memory()
{
    cleanMemory();
}
