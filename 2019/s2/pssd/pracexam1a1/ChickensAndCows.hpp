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

        int tester[2] = {0,0};
        tester[1] = legs/2 - head;
        tester[0] = head - tester[1];

        if(tester[0] > 0 && tester[1] > 0) {
            if((tester[0]*2 + tester[1]*4) == legs)
            {
                animals.push_back(tester[0]);
                animals.push_back(tester[1]);
            }
        }
        

        
        return animals;
    }
};
