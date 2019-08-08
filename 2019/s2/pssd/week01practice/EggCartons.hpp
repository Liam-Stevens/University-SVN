#include <iostream>
using namespace std;

class EggCartons
{
    public:
    int minCartons(int n)
    {
        int min = 0;
        int eggs = n;
        if(eggs == 0) {
            min = 0;
        } else if(eggs < 6) {
            min = -1;
        } else {
            cout << "Eggs: " << eggs << " Min: " << min << endl;
            min = min + 3*(eggs/24);
            eggs = eggs % 24;
            min = min + (eggs/6);
            eggs = eggs % 6;
            cout << "Eggs: " << eggs << " Min: " << min << endl;

            if(eggs < 6 && eggs != 0) {
                min = -1;
            }
        }


        return min;
    }
};
