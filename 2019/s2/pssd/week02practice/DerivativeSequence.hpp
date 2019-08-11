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

        if(n == 0)
        {
            finalSequence = a;
        } else {
            vector<int> working(elements);
            working = a;
            vector<int> saving(elements);
            for (int i = 0; i < n; i++)
            {
                saving.resize(elements-(i+1));
                //cout << "test " << i << ": " << endl;
                for (int j = 0; j < elements-i-1; j++)
                {
                    saving[j] = working[j+1] - working[j];
                    //cout << saving[j] << " | ";
                }
                //cout << endl;

                working.resize(elements-(i+1));
                working = saving;
            }
            finalSequence = working;
        }

        return finalSequence;
    }
};
