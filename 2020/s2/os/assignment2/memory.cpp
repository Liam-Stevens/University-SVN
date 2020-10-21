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
    timer = 1;
    events = 0;
    reads = 0;
    writes = 0;
    faults = 0;
    
    for (int i = 0; i < windowSize; i++)
    {
        window.push_back("-1");
    }
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
    
    for (int i = 0; i < (signed)active.size(); i++)
    {
        cout << active[i]->getName();
        if (active[i]->getReference() == 0 || active[i]->getReference() == 1)
        {
            cout << "[" << active[i]->getReference() << "]";
        }
        if (active[i]->getHistory() != "")
        {
            cout << "(" << active[i]->getHistory() << ")";
        }
        cout << " ";
    }
    for (int i = (signed)active.size(); i < pageFrames; i++)
    {
        cout << "-1 ";
    }
    cout << " HEAD: " << activeHead;
    cout << endl;*/
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
        if (active[i]->getHistoryAsDecimal() < min)
        {
            min = active[i]->getHistoryAsDecimal();
            index = i;
        }
    }
    return index;
}

int Memory::historyCheck2()
{
    int min = active[0]->getHistoryAsDecimal();
    int index = 0;
    for (int i = 1; i < (signed)active.size(); i++)
    {
        if (timesInWindow(active[0]->getName()) == min)
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
        active[i]->shiftHistory();
    }
    //cout << endl;
}

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

void Memory::addToWindow(string name)
{
    window.push_back(name);
    window.erase(window.begin());
}

int Memory::timesInWindow(std::string name)
{
    int num = 0;
    for (int i = 0; i < (signed)window.size(); i++)
    {
        if (name == window[i])
        {
            num++;
        }
    }
    return num;
}

int Memory::minWindow()
{
    int min = timesInWindow(active[0]->getName());
    int index = 0;
    for (int i = 1; i < (signed)active.size(); i++)
    {
        if (timesInWindow(active[0]->getName()) == min)
        {
            index = -1;
        }
        else if (timesInWindow(active[0]->getName()) < min)
        {
            min = timesInWindow(active[0]->getName());
            index = i;
        }
    }
    return index;
}

int Memory::minWindow2()
{
    int min = timesInWindow(active[0]->getName());
    int index = 0;
    for (int i = 1; i < (signed)active.size(); i++)
    {
        if (timesInWindow(active[0]->getName()) < min)
        {
            min = timesInWindow(active[0]->getName());
            index = i;
        }
    }
    return index;
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
                secondChance();
                Page *removal;
                int index = historyCheck();
                removal = active[index];
                active.erase(active.begin()+index);
                active.push_back(temp);
                
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
            Page * temp = getMemByName(instructions[i]->name);
            temp->setReference(1);
            if (instructions[i]->action == 'W')
            {
                temp->setDirty(true);
            }
            debug(true, instructions[i]->name, "", false);
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
    //Iterate over instruction list
    for (int i = 0; i < (signed)instructions.size(); i++)
    {
        incEvents();
        
        addToWindow(instructions[i]->name);
        
        //Check if already in memory
        if (!checkMemory(instructions[i]->name))
        {
            incFaults();
            
            Page *temp;
            temp = new Page(instructions[i]->name, referenceBits);
            temp->setReference(1);

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
                int index = minWindow();
                if (index == -1)
                {
                    index = historyCheck();
                }
                removal = active[index];
                active.erase(active.begin()+index);
                active.push_back(temp);
                
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
            Page * temp = getMemByName(instructions[i]->name);
            temp->setReference(1);
            if (instructions[i]->action == 'W')
            {
                temp->setDirty(true);
            }
            debug(true, instructions[i]->name, "", false);
        }
        
        //cout << timer << " | " << regularInterval << " % " << timer % regularInterval << endl;
        if (timer % regularInterval == 0)
        {
            setAllHistory();
        }
        tick();
    }
}

void Memory::WSARB2(vector<struct pageInfo *> instructions)
{
        //Iterate over instruction list
    for (int i = 0; i < (signed)instructions.size(); i++)
    {
        incEvents();
        
        addToWindow(instructions[i]->name);
        
        //Check if already in memory
        if (!checkMemory(instructions[i]->name))
        {
            incFaults();
            
            Page *temp;
            temp = new Page(instructions[i]->name, referenceBits);
            temp->setReference(1);

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
                int index = historyCheck2();
                if (index == -1)
                {
                    index = minWindow2();
                }
                removal = active[index];
                active.erase(active.begin()+index);
                active.push_back(temp);
                
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
            Page * temp = getMemByName(instructions[i]->name);
            temp->setReference(1);
            if (instructions[i]->action == 'W')
            {
                temp->setDirty(true);
            }
            debug(true, instructions[i]->name, "", false);
        }
        
        //cout << timer << " | " << regularInterval << " % " << timer % regularInterval << endl;
        if (timer % regularInterval == 0)
        {
            setAllHistory();
        }
        tick();
    }
}

Memory::~Memory()
{
    cleanMemory();
}
