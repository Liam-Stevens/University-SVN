#include <iostream>
#include <string>
using namespace std;

class MagicSpell
{
public:
    string fixTheSpell(string spell)
    {
        int elements = spell.length();

        for(int i = 0; i < elements/2; i++)
        {
            if(spell[i] == 'A' && spell[elements-1-i] == 'Z')
            {
                spell[i] = 'Z';
                spell[elements-1-i] = 'A';
            } else if(spell[i] == 'Z' && spell[elements-1-i] == 'A')
            {
                spell[i] = 'A';
                spell[elements-1-i] = 'Z';
            }
        }

        return spell;
    }
};
