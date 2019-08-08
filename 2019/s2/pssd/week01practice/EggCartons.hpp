#include <iostream>
using namespace std;

class EggCartons
{
    public:
    int minCartons(int n)
    {
        int min = 0;
        int eggs = n;
        //Check for valid eggs
        if(eggs == 0) {
            min = 0;
        } else if(eggs < 6) {
            min = -1;
        } else {

            //Iterate over factors of 8 and 6
            for (int i = 0; i < n; i++)
            {
                //Reduce the scope of the problem without invalidating it
                if(eggs % 24 >= 12 || eggs % 24 == 6 || eggs % 24 == 8 || eggs % 24 == 0) {
                    min = min + 3*(eggs/24);
                    eggs = eggs % 24;
                }
                //Check for best outcome
                if(eggs % 8 == 0) {
                    min = min + (eggs/8);
                    eggs = eggs % 8;
                    break;
                }
                //Check second best outcome
                if(eggs % 6 == 0) {
                    min = min + (eggs/6);
                    eggs = eggs % 6;
                    break;
                }

                //Remove largest carton worth of eggs
                eggs = eggs - 8;
                min++;

                //Check validity
                if(eggs < 6 && eggs != 0) {
                    min = -1;
                    break;
                }
            }

        }

        return min;
    }
};
