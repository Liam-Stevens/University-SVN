#include <iostream>
#include <string>
#include <vector>
using namespace std;

class StrangeComputer
{
private:
    int consec;

public:
    int setMemory(string mem)
    {
        consec = 0;
        int flips = 0;

        for (int i = 0; i < mem.length(); i++)
        {
            cout << "Consec: " << consec << " | Mem: " << mem[i] << endl;
            if (mem[i] - 48 != consec)
            {
                cout << "FLIP" << endl;
                consec = mem[i] - 48;
                flips++;
            }
        }


        return flips;
    }
};
