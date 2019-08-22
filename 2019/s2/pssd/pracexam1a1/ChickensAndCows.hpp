#include <vector>
#include <iostream>
using namespace std;

class ChickensAndCows
{
    public:
    vector<int> howMany(int head, int legs)
    {
    	vector<int> animals;

        int animalTest[2];
        animalTest[0] = head*2;
        animalTest[1] = head*4;

        if(animalTest[0] == legs)
        {
            animals.push_back(head);
            animals.push_back(0);
            return animals;
        } else if(animalTest[1] == legs)
        {
            animals.push_back(0);
            animals.push_back(head);
            return animals;
        } else if(head == 0 && legs == 0)
        {
            animals.push_back(0);
            animals.push_back(0);
            return animals;
        }


        int index = 0;
        int oppo = 1;
        if (animalTest[0] > animalTest[1])
        {
            index = 1;
            oppo = 0;
        }
        int mainLegs = 2;
        int remainLegs = 4;
        if(index == 1)
        {
            mainLegs = 4;
            remainLegs = 2;
        }
        int storage[2] = {0,0};

        storage[index] = ((legs*animalTest[index])/animalTest[oppo])/mainLegs;
        legs = legs - ((legs*animalTest[index])/animalTest[oppo]);
        storage[oppo] = legs/remainLegs;

        if((storage[0]*2 + storage[1]*4) == legs)
        {
            animals.push_back(storage[0]);
            animals.push_back(storage[1]);
        }
        
        return animals;
    }
};
