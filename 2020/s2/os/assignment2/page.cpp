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
    history = "0";
    for (int i = 0; i < refSize - 1; i++)
    {
        history = history + "0";
    }
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
    int temp = 0;
    if (history.length() > 0)
    {
        temp = stoi(history, 0, 2);
    }
    return temp;
}

int Page::getLastAccess()
{
    return lastAccess;
}

int Page::getReference()
{
    return history[0];
}

string Page::getHistory()
{
    return history;
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

void Page::setLastAccess(int newLastAccess)
{
    lastAccess = newLastAccess;
}

void Page::setReference(int newReference)
{
    if (newReference == 0)
    {
        history[0] = '0';
    }
    else
    {
        history[0] = '1';
    }
    
}

void Page::shiftHistory()
{
    history =  "0" + history;
    if ((signed)history.size() > refSize)
    {
        history.pop_back();
    }
}