#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

class DerivativeSequence
{
    public:
    vector<int> derSeq(vector<int> a, int n)
    {
        int elements = a.size();
        vector<int> finalSequence(elements-n);

        //Don't need to move anything if n=0
        if(n == 0)
        {
            finalSequence = a;
        } else {
            //Create vectors of changing size
            vector<int> working(elements);
            working = a;
            vector<int> saving(elements);

            //Repeat the formula n times
            for (int i = 0; i < n; i++)
            {
                //Change save vector to be 1 element smaller
                saving.resize(elements-(i+1));
                for (int j = 0; j < elements-i-1; j++)
                {
                    //Apply formula for each element
                    saving[j] = working[j+1] - working[j];
                }

                working.resize(elements-(i+1));
                working = saving;
            }
            finalSequence = working;
        }

        return finalSequence;
    }
};
