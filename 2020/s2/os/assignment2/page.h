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


public:
	//Constructor
    Page(std::string);

    //Getters
    std::string getName();
    bool getDirty();
    int getHistoryAsDecimal();

    //Setters
    void setName(std::string);
    void setDirty(bool);

};

#endif
