#include <string>
#include <iostream>
#include "memory.h"
#include "page.h"
#include "pageInfo.h"

using namespace std;

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
void Memory::debug(bool hit, string name, string replace, bool dirty)
{
    /*
    cout << "Time " << timer << " ";
    if (hit)
    {
        cout << "HIT: ";
    } 
    else
    {
        cout << "MISS: ";
    }
    cout << " Page: " << name << " ";
    if (replace != "")
    {
        cout << "REPLACE:  Page: " << replace << " ";
        if(dirty)
        {
           cout << "(DIRTY) ";
        }
    }
    cout << " frames: ";
    for (int i = (signed)active.size(); i < pageFrames; i++)
    {
        cout << "-1 ";
    }
    
    for (int i = (signed)active.size() - 1; i >= 0; i--)
    {
        cout << active[i]->getName();
        if (active[i]->getHistory() != "")
        {
            cout << "(" << active[i]->getHistory() << ")";
        }
        cout << " ";
    }
    cout << endl;
    */
}

void Memory::tick()
{
    timer++;
}

void Memory::incEvents()
{
    events++;
}

void Memory::incRead()
{
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

Page * Memory::getMemByName(string name)
{
    for (int i = 0; i < (signed)active.size(); i++)
    {
        if (active[i]->getName() == name)
        {
            return active[i];
        }
    }
    return nullptr;
}

int Memory::getIndexOfLeastTime()
{
    int min = active[0]->getLastAccess();
    int index = 0;
    for (int i = 0; i < (signed)active.size(); i++)
    {
        if (active[i]->getLastAccess() < min)
        {
            min = active[i]->getLastAccess();
            index = i;
        }
    }
    return index;
}

int Memory::historyCheck()
{
    int min = active[0]->getHistoryAsDecimal();
    int index = 0;
    for (int i = 1; i < (signed)active.size(); i++)
    {
        if (active[i]->getHistoryAsDecimal() == min)
        {
            index = -1;
        }
        else if (active[i]->getHistoryAsDecimal() < min)
        {
            min = active[i]->getHistoryAsDecimal();
            index = i;
        }
    }
    return index;
}

void Memory::setAllHistory()
{
    for (int i = 0; i < (signed)active.size(); i++)
    {
        //cout << "Set page " << active[i]->getName() << " to " << active[i]->getReference();
        active[i]->setHistory(active[i]->getReference());
    }
    //cout << endl;
}

//TODO: activeHead might need to not be touched
int Memory::secondChance()
{
    for (int i = 0; i < 2*(signed)active.size(); i++)
    {
        if (active[activeHead]->getReference() == 1)
        {
            active[activeHead]->setReference(0);
        }
        else
        {
            return activeHead;
        }
        
        activeHead++;
        if (activeHead >= pageFrames)
        {
            activeHead = 0;
        }
    }
    return activeHead;
}

/*
*   Algorithms
*    
*/

//First-in-first-out
void Memory::FIFO(vector<struct pageInfo *> instructions)
{
    //Iterate over instruction list
    for (int i = 0; i < (signed)instructions.size(); i++)
    {
        incEvents();
        //Check if already in memory
        if (!checkMemory(instructions[i]->name))
        {
            incFaults();
            
            Page *temp;
            temp = new Page(instructions[i]->name);

            incRead();
            //Check action
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
            
            //Add directly to memory
            if ((signed)active.size() < pageFrames)
            {
                active.push_back(temp);
                debug(false, temp->getName(),"",false);
            }
            //Replace page in memory
            else
            {
                Page *removal;
                removal = active[activeHead];
                active[activeHead] = temp;
                if (removal->getDirty() == true)
                {
                    incWrite();
                }
                debug(false, temp->getName(), removal->getName(), removal->getDirty());
                delete removal;
            }
            
            //Move headPTR
            activeHead++;
            if (activeHead >= pageFrames)
            {
                activeHead = 0;
            }
        }
        //Change chached page
        else
        {
            debug(true, instructions[i]->name, "", false);
            Page * temp = getMemByName(instructions[i]->name);
            if (instructions[i]->action == 'W')
            {
                temp->setDirty(true);
            }
        }
        tick();
    }
}

void Memory::LRU(vector<struct pageInfo *> instructions)
{
    //Iterate over instruction list
    for (int i = 0; i < (signed)instructions.size(); i++)
    {
        incEvents();
        //Check if already in memory
        if (!checkMemory(instructions[i]->name))
        {
            incFaults();
            
            Page *temp;
            temp = new Page(instructions[i]->name);
            temp->setLastAccess(timer);

            incRead();
            //Check action
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
            
            //Add directly to memory
            if ((signed)active.size() < pageFrames)
            {
                active.push_back(temp);
                debug(false, temp->getName(),"",false);
            }
            //Replace page in memory
            else
            {
                int replace = getIndexOfLeastTime();
                Page *removal;
                removal = active[replace];
                active[replace] = temp;
                if (removal->getDirty() == true)
                {
                    incWrite();
                }
                debug(false, temp->getName(), removal->getName(), removal->getDirty());
                delete removal;
            }
        }
        //Change chached page
        else
        {
            debug(true, instructions[i]->name, "", false);
            Page * temp = getMemByName(instructions[i]->name);
            temp->setLastAccess(timer);
            if (instructions[i]->action == 'W')
            {
                temp->setDirty(true);
            }
        }
        tick();
    }
}

void Memory::ARB(vector<struct pageInfo *> instructions)
{
    //Iterate over instruction list
    for (int i = 0; i < (signed)instructions.size(); i++)
    {
        incEvents();
        //Check if already in memory
        if (!checkMemory(instructions[i]->name))
        {
            incFaults();
            
            Page *temp;
            temp = new Page(instructions[i]->name, referenceBits);
            temp->setReference(1);
            if(timer % regularInterval != 0)
            {
                temp->setHistory(1);
            }

            incRead();
            //Check action
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
            
            //Add directly to memory
            if ((signed)active.size() < pageFrames)
            {
                active.push_back(temp);
                debug(false, temp->getName(),"",false);
            }
            //Replace page in memory
            else
            {
                Page *removal;
                int index = historyCheck();
                if (index == -1)
                {
                    //FIXME: Not sure if this satisfies the FIFO nature (get highest time?)
                    removal = active[activeHead];
                    active[activeHead] = temp;
                }
                else
                {
                    removal = active[index];
                    active[index] = temp;
                }
                
                if (removal->getDirty() == true)
                {
                    incWrite();
                }
                debug(false, temp->getName(), removal->getName(), removal->getDirty());
                delete removal;
            }
            
            //Move headPTR
            activeHead++;
            if (activeHead >= pageFrames)
            {
                activeHead = 0;
            }
        }
        //Change chached page
        else
        {
            debug(true, instructions[i]->name, "", false);
            Page * temp = getMemByName(instructions[i]->name);
            temp->setReference(1);
            if (instructions[i]->action == 'W')
            {
                temp->setDirty(true);
            }
        }
        
        //cout << timer << " | " << regularInterval << " % " << timer % regularInterval << endl;
        if (timer % regularInterval == 0)
        {
            setAllHistory();
        }
        tick();
    }
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
