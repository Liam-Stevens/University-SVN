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

            min = min + 3*(eggs/24);
            eggs = eggs % 24;

            for (int i = 0; i < n; i++)
            {
                if(eggs % 8 == 0) {
                    min = min + (eggs/8);
                    eggs = eggs % 8;
                    break;
                }
                if(eggs % 6 == 0) {
                    min = min + (eggs/6);
                    eggs = eggs % 6;
                    break;
                }

                eggs = eggs - 8;
                min++;

                if(eggs < 6 && eggs != 0) {
                    min = -1;
                    break;
                }
            }

        }


        return min;
    }
};
