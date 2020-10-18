#include "page.h"

using namespace std;

Page::Page(string newName)
{
    name = newName;    
}

//Getters
string Page::getName()
{
    return name;
}

bool Page::getDirty()
{
    return dirty;
}

int Page::getHistoryAsDecimal()
{
    //TODO: implement this
    return -1;
}

//Setters
void Page::setName(string newName)
{
    name = newName;
}

void Page::setDirty(bool newDirty)
{
    dirty = newDirty;
}