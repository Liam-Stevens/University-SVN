#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ImportantTasks
{
private:
    int minimumElement(vector<int> input)
    {
        int min = input[0];
        int element = 0;
        for (int i = 1; i < input.size(); i++)
        {
            if (min > input[i])
            {
                min = input[i];
                element = i;
            }
        }
        return element;
    }

public:
    int maximalCost(vector<int> complexity, vector<int> computers)
    {
        int tasks = 0;

        while(true)
        {
            if (computers.size() < 1 || complexity.size() < 1)
            {
                break;
            }

            int minComplexity = minimumElement(complexity);
            int minComputer = minimumElement(computers);

            if (complexity[minComplexity] <= computers[minComputer])
            {
                tasks++;
                complexity.erase(complexity.begin() + minComplexity);
                computers.erase(computers.begin() + minComputer);
            } else if (complexity[minComplexity] > computers[minComputer])
            {
                computers.erase(computers.begin() + minComputer);
            }

        }


        return tasks;
    }
};
