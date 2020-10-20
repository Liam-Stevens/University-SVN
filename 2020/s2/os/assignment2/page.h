#ifndef PAGE_H
#define PAGE_H

#include <string>
#include <vector>

class Page
{
private:
    std::string name;
    bool dirty;
    std::vector<bool> history;
    int lastAccess;


public:
	//Constructor
    Page(std::string);

    //Getters
    std::string getName();
    bool getDirty();
    bool getFirstHistory();
    int getHistoryAsDecimal();
    int getLastAccess();

    //Setters
    void setName(std::string);
    void setDirty(bool);
    void setHistory(bool);
    void setLastAccess(int);

};

#endif
