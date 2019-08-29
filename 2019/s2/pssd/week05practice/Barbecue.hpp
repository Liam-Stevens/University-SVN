#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Barbecue
{
public:
    int eliminate(int n, vector<int> voter, vector<int> excluded)
    {      
        int elements = voter.size();
        vector<int> votes(0,n);
        vector<int> exile(0,n);

        for(int i = 0; i < elements; i++)
        {
            //votes[voter[i]]++;
            //exile[excluded[i]]++;
        }
        cout << "test" << endl;
        bool stalemate = false;
        int max = 0;
        for (int i = 0; i < elements; i++)
        {
            /*if(max < exile[i])
            {
                stalemate = false;
                max = exile[i];
            } else if (max == exile[i])
            {
                stalemate == true;
            }*/
        }

        if(stalemate == true)
        {
            cout << "stalemate" << endl;
        } else {
            return max;
        }

        return 0;
    }
};
