#include <iostream>
#include <vector>
using namespace std;

class RugSizes
{
private:
    vector<int> found;
    bool unique(int num)
    {
        if(found.size() == 0) {
            return true;
        } else {
            for(int i = 0; i < found.size(); i++)
            {
                if(found[i] == num)
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    int rugCount(int area)
    {
        int sizes = 0;
        found.clear();

        for (int i = 1; i <= area/2; i++)
        {
            int test = area/i;
            if(i % 2 == 0 && test % 2 == 0)
            {
                if(i == test && test*i == area)
                {
                    sizes++;
                    //cout << i << " | " << test << endl;
                }
            } else {
                if (test*i == area)
                {
                    if(unique(test) == true)
                    {
                        found.push_back(i);
                        sizes++;
                        //cout << i << " | " << test << endl;
                    }
                }
            }
        }

        return sizes;
    }
};
