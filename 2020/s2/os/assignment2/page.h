#ifndef PAGE_H
#define PAGE_H

#include <string>
#include <vector>

class Page
{
private:
    std::string name;
    bool dirty;
    int reference;
    int refSize;
    std::string history;
    int lastAccess;


public:
	//Constructor
    Page(std::string);
    Page(std::string, int);

    //Getters
    std::string getName();
    bool getDirty();
    int getHistoryAsDecimal();
    int getLastAccess();
    int getReference();
    std::string getHistory();

    //Setters
    void setName(std::string);
    void setDirty(bool);
    void setHistory(bool);
    void setLastAccess(int);
    void setReference(int);

};

#endif
