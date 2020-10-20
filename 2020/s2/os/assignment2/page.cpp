#include "page.h"
#include <iostream>
#include <string>

using namespace std;

Page::Page(string newName)
{
    name = newName;    
    refSize = 0;
}

Page::Page(string newName, int newRefSize)
{
    name = newName;
    refSize = newRefSize;
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
    return stoi(history, 0, 2);
}

int Page::getLastAccess()
{
    return lastAccess;
}

int Page::getReference()
{
    return reference;
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
    if ((signed)history.size() > refSize)
    {
        history.pop_back();
    }
}

void Page::setLastAccess(int newLastAccess)
{
    lastAccess = newLastAccess;
}

void Page::setReference(int newReference)
{
    reference = newReference;
}