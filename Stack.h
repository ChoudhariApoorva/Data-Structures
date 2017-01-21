#include <iostream>
#include <vector>
using namespace std;

class StackOverflowException : public exception
{
	public:
		const char* what() { return "Stack is full"; }
};

class StackEmptyException : public exception
{
	public:
		const char* what() { return "Stack is empty"; }
};

template <typename T>
class Stack
{
	private:
		vector<T> v;
		int size;
		bool isEmpty();

	public:
		Stack(int);
		void push(T);
		T pop();
		T top();
};

template <typename T>
Stack<T>::Stack(int size)
{
	this->size = size;
}

template <typename T>
void Stack<T>::push(T key)
{
	try
	{
		if(v.size() >= size)
			throw StackOverflowException();
		else
			v.push_back(key);
	}
	catch(StackOverflowException& e)
	{
		cout << "Exception : " << e.what() << endl;
	}
}

template <typename T>
bool Stack<T>::isEmpty()
{
	return (v.size() <= 0) ? true : false;
}

template <typename T>
T Stack<T>::pop()
{
	T elem;
	try
	{
		if(!isEmpty())
		{
			elem = v.back();
			v.pop_back();
		}
		else
		{
			throw StackEmptyException();	
		}
	}
	catch(StackEmptyException& e)
	{
		cout << "Exception : " << e.what() << endl;
	}

	return elem;
}

template <typename T>
T Stack<T>::top()
{
	T elem;
	try
	{
		if(!isEmpty())
		{
			elem = v.back();
		}
		else
		{
			throw StackEmptyException();	
		}
	}
	catch(StackEmptyException& e)
	{
		cout << "Exception : " << e.what() << endl;
	}

	return elem;	
}