#include "page.h"

using namespace std;

Page::Page()
{

}

//Getters
string Page::getName()
{
    return name;
}

//Setters
void Page::setName(string newName)
{
    name = newName;
}
