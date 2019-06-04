#include "Queue.h"

Queue::Queue() {
	start = 0;
	end = 0;
	count = 0;
}

void Queue::add(int val) {
	if(count < 8) {
		content[end] = val;
		count++;
		end = count;
	}
	
}

int Queue::remove() {
	if(count == 0)
	{
		return -1;
	}
	else
	{
		int temp = content[0];
		for (int i = 0; i < count-1; i++)
		{
			content[i] = content[i+1];
		}
		count--;
		end = count;
		return temp;
	}
}
