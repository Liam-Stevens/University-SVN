#include <iostream>
#include <string>
#include <vector>
using namespace std;

class GoodHours
{
private:
    bool finder(vector<int> first, vector<int> second)
    {
        int num1 = 1;
        int num2 = 1;

        for(int i = 0; i < first.size(); i++)
        {
            num1 = num1*first[i];
        }
        for(int i = 0; i < second.size(); i++)
        {
            num2 = num2*second[i];
        }

        if (num1 == num2)
        {
            return true;
        } else {
            return false;
        }

    }

    bool findGood(vector<int> time1)
    {
        vector<int> test11;
        test11.push_back(time1[0]);
        vector<int> test12;
        test12.push_back(time1[1]);
        test12.push_back(time1[2]);
        test12.push_back(time1[3]);

        vector<int> test21;
        test21.push_back(time1[0]);
        test21.push_back(time1[1]);
        vector<int> test22;
        test22.push_back(time1[2]);
        test22.push_back(time1[3]);

        vector<int> test31;
        test31.push_back(time1[0]);
        test31.push_back(time1[1]);
        test31.push_back(time1[2]);
        vector<int> test32;
        test32.push_back(time1[3]);

        if(finder(test11,test12))
        {
            return true;
        } else if (finder(test21,test22))
        {
            return true;
        } else if (finder(test31,test32))
        {
            return true;
        }

        return false;
    }

    vector<int> incrementTime(vector<int> increment)
    {
        increment[3]++;
        if (increment[3] >= 10)
        {
            increment[3] = increment[3] - 10;
            increment[2]++;
        }
        if (increment[2] >= 6)
        {
            increment[2] = increment[2] - 6;
            increment[1]++;
        }
        if (increment[1] >= 10)
        {
            increment[1] = increment[1] - 10;
            increment[0]++;
        }
        if (increment[0] >= 2 && increment[1] >= 4)
        {
            increment[0] = 0;
            increment[1] = 0;
        }

        return increment;
    }

public:
    int howMany(string beforeTime, string afterTime)
    {
        int num = 0;
        //String to array
        vector<int> firstTime;
        firstTime.push_back(beforeTime[0]-48);
        firstTime.push_back(beforeTime[1]-48);
        firstTime.push_back(beforeTime[3]-48);
        firstTime.push_back(beforeTime[4]-48);
        vector<int> secondTime;
        secondTime.push_back(afterTime[0]-48);
        secondTime.push_back(afterTime[1]-48);
        secondTime.push_back(afterTime[3]-48);
        secondTime.push_back(afterTime[4]-48);

        //Loop before -> afterTime
        secondTime = incrementTime(secondTime);
        do {
            //cout << firstTime[0] << firstTime[1] << ":" << firstTime[2] << firstTime[3] << endl;

            //Good Finder
            if(findGood(firstTime))
            {
                num++;
            }

            firstTime = incrementTime(firstTime);
        } while(firstTime != secondTime);



        return num;
    }
};
