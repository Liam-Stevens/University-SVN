using namespace std;

class Inchworm
{
  public:
  int lunchtime(int branch, int rest, int leaf)
  {
    int ans = (branch/rest)/leaf;
    return ans;
  }
};