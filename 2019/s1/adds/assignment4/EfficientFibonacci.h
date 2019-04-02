#ifndef EFFICIENTFIBONACCI_H
#define EFFICIENTFIBONACCI_H

#include <string>

class EfficientFibonacci
{
private:
	int fibNum;
	bool newCalc;
	int* fibArray;

public:
	EfficientFibonacci();
	
	int calculate(int num);
	void reset();
};

#endif