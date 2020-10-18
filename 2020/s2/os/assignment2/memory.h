#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include "page.h"
#include "pageInfo.h"

class Memory
{
private:
    int frameSize;
    int pageFrames;
    
    int referenceBits;
    int regularInterval;
    int windowSize;
    
    int events;
    int reads;
    int writes;
    int faults;
    
    int activeHead;
    int timer;
    std::vector<Page *> active;

public:
	//Constructor
    Memory(int, int, int, int, int);

    //Getters
    int getEvents();
    int getReads();
    int getWrites();
    int getFaults();
    int getActiveHead();
    int getTimer();

    //Setters
    void setEvents(int);
    void setReads(int);
    void setWrites(int);
    void setFaults(int);
    void setActiveHead(int);
    void setTimer(int);
    
    //Helpers
    void tick();
    void incRead();
    void incWrite();
    void incFaults();
    void outputStats();
    void outputActiveList();
    void cleanMemory();
    bool checkMemory(std::string);
    
    //Algorithms
    void FIFO(std::vector<struct pageInfo *>);
    void LRU(std::vector<struct pageInfo *>);
    void ARB(std::vector<struct pageInfo *>);
    void WSARB1(std::vector<struct pageInfo *>);
    void WSARB2(std::vector<struct pageInfo *>);

    ~Memory();
};

#endif
