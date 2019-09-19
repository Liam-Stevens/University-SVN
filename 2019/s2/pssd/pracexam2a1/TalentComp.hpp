#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TalentComp
{
public:
    int round2(vector<int> talent, vector<int> skill)
    {      
        vector<int> sum (talent.size(),0);

        for (int i = 0; i < talent.size(); i++)
        {
            sum[i] = talent[i] + skill[i];
        }

        vector<int> max (3,0);

        for (int i = 0; i < talent.size(); i++)
        {
            if (max[0] < talent[i])
            {
                max[0] = talent[i];
            }
            if (max[1] < sum[i])
            {
                max[1] = sum[i];
            }
            if (max[2] < skill[i])
            {
                max[2] = skill[i];
            }
        }

        int num = 0;
        for (int i = 0; i < talent.size(); i++)
        {
            //cout << "Max0: " << max[0] << " Talent: " << talent[i] << " | " << "Max1: " << max[1] << " Sum: " << sum[i] << " | " << "Max2: " << max[2] << " Skill: " << skill[i] << endl;
            if (talent[i] == max[0] || sum[i] == max[1] || skill[i] == max[2])
            {
                //cout << "FOUND ^" << endl;
                num++;
            }
        }

        return num;
    }
};
