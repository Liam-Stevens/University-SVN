#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class TomekPhone
{
private:

    int sum(vector<int> input)
    {
        int sum = 0;
        for (int i = 0; i < input.size(); i++)
        {
            sum = sum + input[i];
        }
        return sum;
    }

public:
    int minKeystrokes(vector<int> frequencies, vector<int> keySizes)
    {
        if (sum(keySizes) < frequencies.size())
        {
            return -1;
        }

        int strokes = 0;
        int depth = 1;
        int head = 0;

        sort(frequencies.begin(),frequencies.end(), greater<int>());

        for (int i = 0; i < frequencies.size(); i++)
        {
            while (keySizes[head] < depth)
            {
                head++;
                if (head+1 > keySizes.size())
                {
                    depth++;
                    head = 0;
                }
            }
            strokes = strokes + frequencies[i]*depth;
            head++;
            if (head+1 > keySizes.size())
            {
                depth++;
                head = 0;
            }
        }

        return strokes;
    }
};
