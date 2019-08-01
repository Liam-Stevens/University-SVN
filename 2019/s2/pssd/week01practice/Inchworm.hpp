using namespace std;

class Inchworm
{
  public:
  int lunchtime(int branch, int rest, int leaf)
  {
  	int eaten = 1;
  	bool done = false;
  	int leafPos = leaf;
  	int wormPos = 0;
  	while (done == false)
  	{
  		wormPos = wormPos + rest;
  		if (wormPos > branch)
  		{
  			done = true;
  			break;
  		}
  		else
  		{
  			if (wormPos == leafPos)
  			{
  				eaten++;
  				leafPos = leafPos + leaf;
  			} else if (wormPos > leafPos)
  			{
  				while(leafPos < wormPos)
  				{
  					leafPos = leafPos + leaf;
  				}
  			}
  			else
  			{

  			}
  		}
  	}

    return eaten;
  }
};