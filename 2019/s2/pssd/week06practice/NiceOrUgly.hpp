#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NiceOrUgly
{
private:
    bool checkVowel(char letter)
    {
        if (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U')
        {
            return true;
        } else {
            return false;
        }
    }

    bool checkConsonent(char letter)
    {
        if (letter != 'A' && letter != 'E' && letter != 'I' && letter != 'O' && letter != 'U' && letter != '?')
        {
            return true;
        } else {
            return false;
        }
    }

public:
    string describe(string s)
    {
        int vowel = 0;
        int consonant = 0;
        bool ugly = false;
        bool both = false;
        int vowelMarks = 0;
        int consonantMarks = 0;
        int rowMarks = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if(checkVowel(s[i]))
            {
                vowel++;
                if(consonant > 0)
                {
                    consonant = 0;
                    consonantMarks = 0;
                    rowMarks = 0;
                }
            } else if (checkConsonent(s[i]))
            {
                consonant++;
                if(vowel > 0)
                {
                    vowel = 0;
                    vowelMarks = 0;
                    rowMarks = 0;
                }
            } else if (s[i] == '?')
            {
                vowelMarks++;
                consonantMarks++;
                rowMarks++;
            }

            //cout << s[i] << " V: " << vowel << " C: " << consonant << " ?V " << vowelMarks << " ?C " << consonantMarks << " ?T " << rowMarks << endl;

            if (vowel >= 3)
            {
                ugly = true;
                //cout << "FOUND VOWEL" << endl;
                break;
            } else if (consonant >= 5)
            {
                ugly = true;
                //cout << "FOUND CONSONANT" << endl;
                break;
            } else if (rowMarks >= 3)
            {
                both = true;
            } else if (vowel + vowelMarks >= 3)
            {
                both = true;
            } else if (consonant + consonantMarks >= 5)
            {
                both = true;
            }
        }

        if (ugly == true)
        {
            return "UGLY";
        } else if (both == true) {
            return "42";
        } else
        {
            return "NICE";
        }

        return "ERROR";
    }
};
