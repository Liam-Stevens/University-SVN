#ifndef PAGE_H
#define PAGE_H

#include <string>

class Page
{
private:
    std::string name;


public:
	//Constructor
    Page();

    //Getters
    std::string getName();

    //Setters
    void setName(std::string);

};

#endif
