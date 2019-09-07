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
        bool defVowel = false;
        bool defConsonant = false;
        bool vowelAvaliable = false;
        bool consonantAvaliable = false;
        bool marked = false;

        for (int i = 0; i < s.length(); i++)
        {
            if(checkVowel(s[i]))
            {
                vowel++;
                if(consonant > 0)
                {
                    consonant = 0;
                    consonantAvaliable = false;
                }
            } else if (checkConsonent(s[i]))
            {
                consonant++;
                if(vowel > 0)
                {
                    vowel = 0;
                    vowelAvaliable = false;
                }
            } else if (s[i] == '?')
            {
                vowel++;
                consonant++;
                vowelAvaliable = true;
                consonantAvaliable = true;
            }

            //cout << s[i] << " V: " << vowel << " C: " << consonant << " ?1 " << vowelAvaliable << " ?2 " << consonantAvaliable << endl;

            if(vowel >= 3)
            {
                defVowel = true;
                if(vowelAvaliable == true)
                {
                    marked = true;
                }
                //cout << "FOUND VOWEL" << endl;
            }
            if(consonant >= 5)
            {
                defConsonant = true;
                if(consonantAvaliable == true)
                {
                    marked = true;
                }
                //cout << "FOUND CONSONANT" << endl;
            }
        }

        if(marked == true && (defVowel != true || defConsonant != true))
        {
            return "42";
        } else if (defVowel == true || defConsonant == true)
        {
            return "UGLY";
        } else
        {
            return "NICE";
        }

        return "ERROR";
    }
};
