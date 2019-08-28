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

        for (int i = 1; i <= area/2+1; i++)
        {
            int test = area/i;
            if(i % 2 == 0 && test % 2 == 0 && i > 1)
            {
                if(i == test && test*i == area)
                {
                    sizes++;
                }
            } else {
                if (test*i == area)
                {
                    if(unique(test) == true)
                    {
                        found.push_back(i);
                        sizes++;
                    }
                }
            }
        }

        return sizes;
    }
};
