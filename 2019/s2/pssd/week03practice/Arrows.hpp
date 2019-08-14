#include <iostream>
#include <string>
using namespace std;

class Arrows
{
private:
    int max;
    int consecArrowNum;
    bool left;
    bool doubleArrow;

    void reset()
    {
        consecArrowNum = 0;
        left = false;
        doubleArrow = false;
    }

    void update()
    {
        //cout << "PRE Max: " << max << " ArrowNum: " << consecArrowNum << endl;
        if (max < consecArrowNum)
        {
            max = consecArrowNum;
        }
        //cout << "Max: " << max << " ArrowNum: " << consecArrowNum << endl;
    }

public:
    int longestArrow(string s)
    {
        max = 0;
        reset();

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '>')
            {
                if (left != true)
                {
                    consecArrowNum++;
                }
                //cout << "Pass: " << i << " RIGHT" << endl;
                update();
                reset();
            } else if(s[i] == '-' && doubleArrow == false)
            {
                consecArrowNum++;
                //cout << "Pass: " << i << " B" << " Arrow Num: " << consecArrowNum << endl;
            } else if (s[i] == '=' && doubleArrow == false)
            {
                if (left == true)
                {
                    update();
                    //cout << "Pass: " << i << " C" << endl;
                }
                reset();
                consecArrowNum++;
                doubleArrow = true;
                //cout << "Pass: " << i << " D" << endl;
            } else if (s[i] == '-' && doubleArrow == true)
            {
                if (left == true)
                {
                    update();
                    //cout << "Pass: " << i << " E" << endl;
                }
                reset();
                consecArrowNum++;
                //cout << "Pass: " << i << " F" << endl;
            } else if (s[i] == '=' && doubleArrow == true)
            {
                consecArrowNum++;
                //cout << "Pass: " << i << " G" << endl;
            } else if (s[i] != '-' && doubleArrow == false && consecArrowNum < 0)
            {
                update();
                reset();
                //cout << "Pass: " << i << " H" << endl;
            } else if(s[i] == '<')
            {
                if (left == true) {
                    update();
                }
                reset();
                left = true;
                consecArrowNum++;
                //cout << "Pass: " << i << " LEFT" << endl;
            } else if (i == s.length()-1 && left == true)
            {
                update();
            }



        }

        if(max == 0)
        {
            max = -1;
        }


        return max;
    }
};
