#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SimpleDuplicateRemover
{
private:
    vector<int> unique;

    vector<int> reverse(vector<int> input)
    {
        vector<int> tmp;
        for (int i = unique.size() - 1; i >= 0; i--)
        {
            tmp.push_back(unique[i]);
        }
        return tmp;
    }

    bool checkExistance(int number)
    {
        for (int i = 0; i < unique.size(); i++)
        {
            if (unique[i] == number)
            {
                return true;
            }
        }
        return false;
    }

public:
    vector<int> process(vector<int> sequence)
    {
        unique.clear();

        for (int i = sequence.size() - 1; i >= 0; i--)
        {
            if (checkExistance(sequence[i]) == false)
            {
                unique.push_back(sequence[i]);
            }
        }

        unique = reverse(unique);

        return unique;
    }
};
