#include <string>
#include "cart.h"
#include "meerkat.h"
#include <iostream>

using namespace std;

int cart::count2 = 0;


cart::cart()
{
	id2 = count2;
	count2++;
	seat = 0;
}

bool cart::addMeerkat(meerkat cat)
{
	if (seat == 5)
	{
		cout << "Cart is full" << endl;
		return 0;
	}
	inCart[seat] = cat;
	seat++;
	return 1;
}

void cart::emptyCart()
{

}

void cart::printMeerkats()
{
	for (int i = 0; i < seat; i++)
	{
		cout << inCart[i].getName() << " " << inCart[i].getAge() << endl;
	}
}

cart::~cart()
{
	
}
