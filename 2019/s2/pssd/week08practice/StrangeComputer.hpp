#include <iostream>
#include <string>
#include <vector>
using namespace std;

class StrangeComputer
{
private:
    string computer;

public:
    int setMemory(string mem)
    {
        int consec = 0;
        int flips = 0;

        for (int i = 0; i < mem.length(); i++)
        {
            if (mem[i] != consec)
            {
                consec = mem[i];
                flips++;
            }
        }


        return flips;
    }
};
