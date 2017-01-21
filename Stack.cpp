#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
	// Create a stack of size 10
	Stack<int> S(10);

	// Push elements into the stack
	S.push(11);
	S.push(22);
	S.push(33);
	S.push(44);
	S.push(55);

	// Pop the top element
	cout << "Element popped = " << S.pop() << endl;

	// Print the element on top of the stack
	cout << "Top of the stack = " << S.top() << endl;
	return 0;
}