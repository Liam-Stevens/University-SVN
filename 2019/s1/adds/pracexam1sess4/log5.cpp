#include<iostream>
using namespace std;

/*
 Please note, you must use recursion in answering this question.
 */

/*
 Implement the following function based on the given description.
 */
int log5helper(int i, int inc)
{
    if (i/5 == 0)
    {
    	return inc;
    }
    else
    {
    	return log5helper(i/5, inc + 1);
    }
}

int log5(int i)
{
	return log5helper(i, 0);
}

// You are not supposed to change the main function
int main() {
    cout << log5(1)<< endl; //
    cout << log5(5)<< endl; //
    cout << log5(26)<< endl; //
    cout << log5(1026)<< endl; //
}
