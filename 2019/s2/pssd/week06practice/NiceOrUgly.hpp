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
        int marks = 0;
        int vowelMarks = 0;
        int consonantMarks = 0;
        int allMarks = 0;
        bool maybeVowel = false;
        bool maybeConsonant = false;

        for (int i = 0; i < s.length(); i++)
        {
            if(checkVowel(s[i]))
            {
                vowel++;
                if(consonant > 0)
                {
                    consonant = 0;
                    consonantAvaliable = false;
                    consonantMarks = 0;
                    marks = 0;
                }
            } else if (checkConsonent(s[i]))
            {
                consonant++;
                if(vowel > 0)
                {
                    vowel = 0;
                    vowelAvaliable = false;
                    vowelMarks = 0;
                    marks = 0;
                }
            } else if (s[i] == '?')
            {
                marks++;
                vowelMarks++;
                consonantMarks++;
                vowelAvaliable = true;
                consonantAvaliable = true;
            }

            //cout << s[i] << " V: " << vowel << " C: " << consonant << " ?V " << vowelMarks << " ?C " << consonantMarks << endl;

            if(vowel >= 3)
            {
                defVowel = true;
                //cout << "FOUND VOWEL" << endl;
            }
            if(consonant >= 5)
            {
                defConsonant = true;
                //cout << "FOUND CONSONANT" << endl;
            }
            if(consonant + consonantMarks >= 5 && consonantAvaliable == true)
            {
                maybeConsonant = true;
                //cout << "MAYBE CONSONANT" << endl;
            }
            if(vowel + consonantMarks >= 3 && vowelAvaliable == true)
            {
                maybeVowel = true;
                //cout << "MAYBE VOWEL" << endl;
            }
            if(marks >= 3 && allMarks == 0)
            {
                allMarks = 1;
                //cout << "ALL ???" << endl;
            }
            if(marks >= 5 && allMarks < 2)
            {
                allMarks = 2;
                //cout << "ALL ?????" << endl;
            }
        }

        if(allMarks > 0 || maybeVowel == true || maybeConsonant == true)
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
