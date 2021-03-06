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
        vector<int> stalemates;

        if (elements == 0)
        {
            return 0;
        }

        for(int i = 0; i < elements; i++)
        {
            votes[voter[i]]++;
            exile[excluded[i]]++;
        }

        /*for (int i = 0; i < votes.size(); i++)
        {
            cout << votes[i] << " | ";
        }
        cout << endl;
        for (int i = 0; i < exile.size(); i++)
        {
            cout << exile[i] << " | ";
        }
        cout << endl;*/

        bool stalemate = false;
        int max = 0;
        int winner = 0;
        for (int i = 0; i < exile.size(); i++)
        {
            if(max < exile[i])
            {
                stalemate = false;
                max = exile[i];
                winner = i;
                stalemates.clear();
                stalemates.push_back(i);
            } else if (max == exile[i])
            {
                stalemate = true;
                stalemates.push_back(i);
            }
        }

        if(stalemate == true)
        {
            stalemate = false;
            int maxVotes = -1;
            int maxVoter = -1;
            vector<int> stalemates2;

            /*for (int i = 0; i < stalemates.size(); i++)
            {
                cout << stalemates[i] << " {} ";
            }
            cout << endl;*/

            for (int i = 0; i < stalemates.size(); i++)
            {
                if (votes[stalemates[i]] > maxVotes)
                {
                    maxVoter = stalemates[i];
                    maxVotes = votes[stalemates[i]];
                    stalemates2.clear();
                    stalemates2.push_back(stalemates[i]);
                }
            }
            for (int i = 0; i < stalemates.size(); i++)
            {
                if (votes[stalemates[i]] == maxVotes && i != maxVoter)
                {
                    stalemate = true;
                    stalemates2.push_back(stalemates[i]);
                }
            }

            if(stalemate == true)
            {
                /*for (int i = 0; i < stalemates.size(); i++)
                {
                    cout << stalemates2[i] << " {} ";
                }
                cout << endl;*/

                //cout << "exit1" << endl;
                return stalemates2[0];
            } else {
                //cout << "exit2" << endl;
                return maxVoter;
            }


        } else {
            //cout << "exit3" << endl;
            return winner;
        }

        return -1;
    }
};
