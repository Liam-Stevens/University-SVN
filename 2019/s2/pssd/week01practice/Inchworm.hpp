using namespace std;

class Inchworm
{
  public:
  int lunchtime(int branch, int rest, int leaf)
  {
  	//Set Initial Parameters
  	int eaten = 1;
  	bool done = false;
  	int leafPos = leaf;
  	int wormPos = 0;

  	//Simulate worm
  	while (done == false)
  	{
  		//Update worm position
  		wormPos = wormPos + rest;
  		//Test for next leaf
  		if (wormPos > leafPos)
  		{
  			while(leafPos < wormPos)
  			{
  				leafPos = leafPos + leaf;
  			}
  		}

  		//Test for end of branch
  		if (wormPos > branch)
  		{
  			done = true;
  			break;
  		}
  		else
  		{
  			//Test if leaf can be eaten
  			if (wormPos == leafPos)
  			{
  				eaten++;
  				leafPos = leafPos + leaf;
  			} 
  		}
  	}

    return eaten;
  }
};