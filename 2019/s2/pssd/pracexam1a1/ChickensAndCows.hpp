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

        //animals.push_back((head*legs)/animalTest[0]);
        //animals.push_back((head*legs)/animalTest[1]);
        int tester[2] = {0,0};
        tester[1] = legs/2 - head;
        tester[0] = head - tester[1];
/*
        int index = 0;
        int oppo = 1;
        if (animalTest[0] > animalTest[1])
        {
            index = 1;
            oppo = 0;
        }
        int mainLegs = 4;
        int remainLegs = 2;
        if(index == 1)
        {
            mainLegs = 2;
            remainLegs = 4;
        }
        int storage[2] = {0,0};

        storage[oppo] = ((head*animalTest[index])/animalTest[oppo]);
        storage[index] = head - ((heads*animalTest[index])/animalTest[oppo]);

        cout << "Chickens: " << storage[0] << " | Cows: " << storage[1] << endl;
*/
        if((tester[0]*2 + tester[1]*4) == legs)
        {
            animals.push_back(tester[0]);
            animals.push_back(tester[1]);
        }
        
        return animals;
    }
};
