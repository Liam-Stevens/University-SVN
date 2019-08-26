#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MagicSpell
{
private:
    string swap(string swapper, int element1, int element2)
    {
        char tmp = swapper[element1];
        swapper[element1] = swapper[element2];
        swapper[element2] = tmp;
        return swapper;
    }

public:
    string fixTheSpell(string spell)
    {
        int elements = spell.length();
        vector<int> firstHalf;
        vector<int> secondHalf;

        //Records locations of A and Z
        for(int i = 0; i < elements/2; i++)
        {
            if(spell[i] == 'A' || spell[i] == 'Z')
            {
                firstHalf.push_back(i);
            }
        }
        for(int i = elements-1; i >= elements/2; i--)
        {
            if(spell[i] == 'A' || spell[i] == 'Z')
            {
                secondHalf.push_back(i);
            }
        }

        //Ensures that both halfs are the same size
        while(firstHalf.size() != secondHalf.size())
        {
            if(firstHalf.size() > secondHalf.size())
            {
                firstHalf.erase(firstHalf.begin()+firstHalf.size());
            }
            if(firstHalf.size() < secondHalf.size())
            {
                secondHalf.erase(secondHalf.begin()+secondHalf.size());
            }
        }

        //Swaps all elements
        for(int i = 0; i < firstHalf.size(); i++)
        {
            spell = swap(spell,firstHalf[i],secondHalf[i]);
        }

        return spell;
    }
};
