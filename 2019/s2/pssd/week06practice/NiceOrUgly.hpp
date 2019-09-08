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

    int checkPattern(string s, int num, bool restart)
    {
        int store = 0;
        if(s.length() >= num + 7)
        {
            if (restart == false)
            {
                if( (checkConsonent(s[num]) && checkConsonent(s[num+1]) && checkConsonent(s[num+2]) && checkConsonent(s[num+3]) && s[num+4] == '?' && checkVowel(s[num+5]) && checkVowel(s[num+6]))
                || (checkVowel(s[num]) && checkVowel(s[num+1]) && s[num+2] == '?' && checkConsonent(s[num+3]) && checkConsonent(s[num+4]) && checkConsonent(s[num+5]) && checkConsonent(s[num+6])) )
                {
                    return -1;
                } else if ( (checkConsonent(s[num]) && checkConsonent(s[num+1]) && checkConsonent(s[num+2]) && checkConsonent(s[num+3]) && s[num+4] == '?' && checkVowel(s[num+5]) && s[num+6] == '?')
                || (checkVowel(s[num]) && checkVowel(s[num+1]) && s[num+2] == '?' && checkConsonent(s[num+3]) && checkConsonent(s[num+4]) && checkConsonent(s[num+5]) && s[num+6] == '?') )
                {
                    store = num+6;
                }

                if (s.length() >= num + 9)
                {
                    if ( checkVowel(s[num]) && checkVowel(s[num+1]) && s[num+2] == '?' && checkConsonent(s[num+3]) && checkConsonent(s[num+4]) && checkConsonent(s[num+5]) && s[num+6] == '?' && checkVowel(s[num+7]) && checkVowel(s[num+8]) )
                    {
                        return -1;
                    }
                }
                if (s.length() >= num + 11)
                {
                    if ( checkConsonent(s[num]) && checkConsonent(s[num+1]) && checkConsonent(s[num+2]) && checkConsonent(s[num+3]) && s[num+4] == '?' && checkVowel(s[num+5]) && s[num+6] == '?' && checkConsonent(s[num+7]) && checkConsonent(s[num+8]) && checkConsonent(s[num+9]) && checkConsonent(s[num+10]) )
                    {
                        return -1;
                    }
                }


            } else {
                //cout << "Checked" << endl;
                if( (s[num] == '?' && checkConsonent(s[num+1]) && checkConsonent(s[num+2]) && checkConsonent(s[num+3]) && s[num+4] == '?' && checkVowel(s[num+5]) && checkVowel(s[num+6]))
                || (s[num] == '?' && checkVowel(s[num+1]) && s[num+2] == '?' && checkConsonent(s[num+3]) && checkConsonent(s[num+4]) && checkConsonent(s[num+5]) && checkConsonent(s[num+6])) )
                {
                    return -1;
                } else if ( (s[num] == '?' && checkConsonent(s[num+1]) && checkConsonent(s[num+2]) && checkConsonent(s[num+3]) && s[num+4] == '?' && checkVowel(s[num+5]) && s[num+6] == '?')
                || (s[num] == '?' && checkVowel(s[num+1]) && s[num+2] == '?' && checkConsonent(s[num+3]) && checkConsonent(s[num+4]) && checkConsonent(s[num+5]) && s[num+6] == '?') )
                {
                    store = num+6;
                }

                if (s.length() >= num + 9)
                {
                    if ( s[num] == '?' && checkVowel(s[num+1]) && s[num+2] == '?' && checkConsonent(s[num+3]) && checkConsonent(s[num+4]) && checkConsonent(s[num+5]) && s[num+6] == '?' && checkVowel(s[num+7]) && checkVowel(s[num+8]) )
                    {
                        return -1;
                    }
                }
                if (s.length() >= num + 11)
                {
                    if ( s[num] == '?' && checkConsonent(s[num+1]) && checkConsonent(s[num+2]) && checkConsonent(s[num+3]) && s[num+4] == '?' && checkVowel(s[num+5]) && s[num+6] == '?' && checkConsonent(s[num+7]) && checkConsonent(s[num+8]) && checkConsonent(s[num+9]) && checkConsonent(s[num+10]) )
                    {
                        return -1;
                    }
                }
            }


        }

        return store;
    }

    bool findPattern(string s)
    {
        if (s.length() >= 7)
        {
            int checker = 0;
            bool recheck = false;
            for (int i = 0; i < s.length() - 6; i++)
            {
                checker = checkPattern(s,i,recheck);
                recheck = false;
                //cout << "Letter: " << s[i] << " i: " << i << " value: " << checker << endl;
                if (checker == -1)
                {
                    return true;
                } else if (checker >= 1)
                {
                    i = checker-1;
                    recheck = true;
                }
            }



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

        if (findPattern(s))
        {
            return "UGLY";
        }

        for (int i = 0; i < s.length(); i++)
        {
            if(checkVowel(s[i]))
            {
                vowel++;
                consonant = 0;
                consonantMarks = 0;
                rowMarks = 0;
            } else if (checkConsonent(s[i]))
            {
                consonant++;
                vowel = 0;
                vowelMarks = 0;
                rowMarks = 0;
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
                break;
            } else if (consonant >= 5)
            {
                ugly = true;
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
