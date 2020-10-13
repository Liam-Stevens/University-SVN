#ifndef MEMORY_H
#define MEMORY_H

class Memory
{
private:
    int events;
    int reads;
    int writes;
    int faults;

public:
	//Constructor
    Memory();

    //Getters
    int getEvents();
    int getReads();
    int getWrites();
    int getFaults();

    //Setters
    void setEvents(int);
    void setReads(int);
    void setWrites(int);
    void setFaults(int);

};

#endif
