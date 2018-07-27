 
// function to find two five and nines
#include <iostream>

void twofivenine(int array[], int n)
{
    if(n < 1){
    	std::cout << "2:0;5:0;9:0;" << std::endl;
    } else {
    	int twos = 0;
    	int fives = 0;
    	int nines = 0;
    	for(int i = 0; i < n; i++){
	    	switch(array[i]){
	    		case 2:
	    			twos++;
	    			break;
	    		case 5:
	    			fives++;
	    			break;
	    		case 9:
	    			nines++;
	    			break;
	    	}
	    }
    	std::cout << "2:" << twos << ";5:" << fives << ";9:" << nines << ";" << std::endl;
    }
}
