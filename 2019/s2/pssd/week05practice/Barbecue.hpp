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
        vector<int> votes(n,0);
        vector<int> exile(n,0);

        for(int i = 0; i < elements; i++)
        {
            votes[voter[i]]++;
            exile[excluded[i]]++;
        }

        bool stalemate = false;
        int max = 0;
        for (int i = 0; i < exile.size(); i++)
        {
            if(max < exile[i])
            {
                stalemate = false;
                max = exile[i];

            } else if (max == exile[i])
            {
                stalemate = true;
            }
        }

        if(stalemate == true)
        {
            stalemate = false;
            int maxVotes = 0;
            int maxVoter = 0;
            vector<int> stalemates;

            for (int i = 0; i < votes.size(); i++)
            {
                if (votes[i] > maxVotes)
                {
                    maxVoter = i;
                    maxVotes = votes[i];
                    stalemates.clear();
                    stalemates.push_back(i);
                }
            }
            for (int i = 0; i < votes.size(); i++)
            {
                if (votes[i] == maxVotes && i != maxVoter)
                {
                    stalemate = true;
                    stalemates.push_back(i);
                }
            }

            if(stalemate == true)
            {
                int minIndex = stalemates[0];
                for (int i = 0; i < stalemates.size(); i++)
                {
                    if (minIndex > stalemates[i])
                    {
                        minIndex = stalemates[i];
                    }
                }
                return minIndex;
            } else {
                return maxVoter;
            }


        } else {
            return max;
        }

        return -1;
    }
};
