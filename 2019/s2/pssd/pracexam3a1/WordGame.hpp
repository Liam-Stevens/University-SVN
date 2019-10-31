#include <iostream>
#include <string>
#include <vector>
using namespace std;

class WordGame
{
private:
    vector<char> replaceable;
    vector<char> testString;
    vector<int> score;

    bool checkLetter(vector<char> checker, char inVector)
    {
        for (int i = 0; i < checker.size(); i++)
        {
            if (checker[i] == inVector)
            {
                return true;
            }
        }
        return false;
    }

    void buildVector(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (!checkLetter(replaceable,s[i]))
            {
                replaceable.push_back(s[i]);
            }
            
        }
        
    }

    string replaceLetter(string input, char from, char to)
    {
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == from)
            {
                input[i] = to;
            }
        }
        return input;
    }

    void addScore(char input)
    {

        for (int i = 0; i < testString.size(); i++)
        {
            if (testString[i] == input)
            {
                score[i]++;
                return;
            }
        }
        return;
    }

    int calculateScore()
    {
        int new_score = 0;
        for (int i = 0; i < score.size(); i++)
        {
            new_score += score[i]*score[i];
        }
        return new_score;
    }

    int evaluateScore(string input)
    {
        testString.clear();
        score.clear();

        for (int i = 0; i < input.size(); i++)
        {
            if(!checkLetter(testString,input[i]))
            {
                testString.push_back(input[i]);
                score.push_back(1);
            }
            else
            {
                addScore(input[i]);
            }
        }

        return calculateScore();
    }


public:
    int bestScore(string s)
    {
        int max = evaluateScore(s);
        replaceable.clear();
        buildVector(s);

        for (int i = 0; i < replaceable.size(); i++)
        {
            for (int j = 0; j < 26; j++)
            {
                string tmp = replaceLetter(s, replaceable[i], (char)(65+j));
                int tmpScore = evaluateScore(tmp);
                if (tmpScore > max)
                {
                    max = tmpScore;
                }
            }
        }

        return max;
    }
};
