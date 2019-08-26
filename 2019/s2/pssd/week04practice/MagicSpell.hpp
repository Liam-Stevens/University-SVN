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
        int elements = 0;

        for(int i = 0; i < spell.length(); i++)
        {
            if(spell[i] == 'A' || spell[i] == 'Z')
            {
                elements++;
            }
        }

        vector<int> firstHalf;
        vector<int> secondHalf;

        //Records locations of A and Z
        for(int i = 0; i < spell.length(); i++)
        {
            if(spell[i] == 'A' || spell[i] == 'Z')
            {
                firstHalf.push_back(i);
            }
            if(firstHalf.size() == elements/2)
            {
                break;
            }
        }
        for(int i = spell.length()-1; i >= 0; i--)
        {
            if(spell[i] == 'A' || spell[i] == 'Z')
            {
                secondHalf.push_back(i);
            }
            if(secondHalf.size() == elements/2)
            {
                break;
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
