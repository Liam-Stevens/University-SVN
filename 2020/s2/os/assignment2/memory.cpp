#include "memory.h"

Memory::Memory()
{

}

//Getters
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

//Setters
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
