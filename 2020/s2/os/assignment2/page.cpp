#include "page.h"
#include <iostream>

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

bool Page::getFirstHistory()
{
    if ((signed)history.size() > 0)
    {
        return history[0];
    }
    cout << "NO HISTORY" << endl;
    return false;
}

int Page::getHistoryAsDecimal()
{
    //TODO: implement this
    return -1;
}

int Page::getLastAccess()
{
    return lastAccess;
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

void Page::setHistory(bool newHistory)
{
    history.insert(history.begin(), newHistory);
    if ((signed)history.size() > 8)
    {
        history.pop_back();
    }
}

void Page::setLastAccess(int newLastAccess)
{
    lastAccess = newLastAccess;
}