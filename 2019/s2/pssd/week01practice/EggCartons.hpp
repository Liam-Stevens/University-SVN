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
            for (int i = 0; i < n; i++)
            {
                if(eggs % 8 == 0) {
                    min = min + (eggs/8);
                    break;
                } else if(eggs % 6 == 0) {
                    min = min + (eggs/6);
                    break;
                } else {
                    min++;
                    eggs = eggs - 8;
                }

                if(eggs < 6 && eggs != 0) {
                    min = -1;
                    break;
                }
            }
        }


        return min;
    }
};
