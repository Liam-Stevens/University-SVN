#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LineSpacing
{
private:
    vector<int> placement;
    int num_of_spaces;
    vector<string> secondPassCheck;

    int word_size(vector<string> words)
    {
        int size = 0;

        for (int i = 0; i < words.size(); i++)
        {
            size += words[i].size();
        }

        return size;
    }

    void insert_lower()
    {

        for (int i = 0; i < placement.size(); i++)
        {
            //cout << "sp: " << (int)secondPassCheck[i+1][0] << " " << secondPassCheck[i+1][0] << " | _ " << (int)'_' << " | spaces " << num_of_spaces << endl;
            if((int)secondPassCheck[i+1][0] > (int)'_' && num_of_spaces > 0)
            {
                num_of_spaces--;
                placement[i]++;
            }
        }

        return;
    }

    void insert_upper()
    {

        for (int i = placement.size()-1; i >= 0; i--)
        {
            if((int)secondPassCheck[i+1][0] < (int)'_' && num_of_spaces > 0)
            {
                num_of_spaces--;
                placement[i]++;
            }
        }

        return;
    }

    void second_pass()
    {
        insert_lower();
        insert_upper();

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
        secondPassCheck = words;
        int num_of_characters = word_size(words);
        num_of_spaces = width - num_of_characters;

        first_pass(words.size()-1);

        return buildLine(words);
    }
};
