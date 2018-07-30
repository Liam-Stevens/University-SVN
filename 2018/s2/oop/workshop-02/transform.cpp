#include <iostream>
#include <cmath>

void main() {
	int value = 158;
	int binary[] = {0,0,0,0,0,0,0,0};

	for(int i=0; i < 8; i++){
		binary[i] = value / pow(2,(7-i));
		if(binary[i] == 1) {
			value = value - pow(2,(7-i));
		}
	}
	std::cout <<
}