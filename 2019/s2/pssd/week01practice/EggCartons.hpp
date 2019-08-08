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

            //cout << "Initial Eggs: " << eggs << " Cartons: " << min << endl;

            for (int i = 0; i < n; i++)
            {
                //cout <<"Test "<< i << " Eggs: " << eggs << " Cartons: " << min << endl;
                if(eggs % 24 > 6 || eggs % 24 == 0) {
                    min = min + 3*(eggs/24);
                    eggs = eggs % 24;
                }
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
                //cout <<"Test "<< i << " Eggs: " << eggs << " Cartons: " << min << endl;
                if(eggs < 6 && eggs != 0) {
                    min = -1;
                    break;
                }
            }

        }
        //cout <<"Final Eggs: " << eggs << " Cartons: " << min << endl;
        return min;
    }
};
