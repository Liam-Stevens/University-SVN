#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LineSpacing
{
private:
    vector<int> placement;
    int num_of_spaces;
    int maxSpaces;
    int minSpaces;

    int word_size(vector<string> words)
    {
        int size = 0;

        for (int i = 0; i < words.size(); i++)
        {
            size += words[i].size();
        }

        return size;
    }

    void checkMinMax()
    {
        maxSpaces = placement[0];
        minSpaces = placement[0];
        for (int i = 1; i < placement.size(); i++)
        {
            if (placement[i] > maxSpaces)
            {
                maxSpaces = placement[i];
            }
            if (placement[i] < minSpaces)
            {
                minSpaces = placement[i];
            }
        }
        return;
    }

    void second_pass()
    {
        checkMinMax();




        return;
    }

    void first_pass(int slots)
    {
        if (slots == 0)
        {
            return;
        }

        int spaces_per_slot = num_of_spaces/slots;
        
        for (int i = 0; i < slots; i++)
        {
            placement.push_back(spaces_per_slot);
            num_of_spaces -= spaces_per_slot;
        }

        if (num_of_spaces == 0)
        {
            return;
        }
        else
        {
            second_pass();
        }

    }

    string buildLine(vector<string> words)
    {
        string line = words[0];
        for (int i = 0; i < placement.size(); i++)
        {
            string space = "";
            for (int j = 0; j < placement[i]; j++)
            {
                space += '_';
            }

            line += space;
            line += words[i+1];
        }
        return line;
    }

public:
    string adjusted(vector<string> words, int width)
    {
        placement.clear();
        int num_of_characters = word_size(words);
        num_of_spaces = width - num_of_characters;

        first_pass(words.size()-1);

        return buildLine(words);
    }
};
