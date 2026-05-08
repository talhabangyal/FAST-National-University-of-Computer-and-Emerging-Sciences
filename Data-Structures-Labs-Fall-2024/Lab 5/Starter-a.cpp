#include<iostream>
using namespace std;
class IntStack
{
private:
	int* stackArray;
	int stackSize;
	int top;
public:
	IntStack(int);

	~IntStack();
	bool push(int);
	bool pop(int&);
	bool isFull();
	bool isEmpty();
};

IntStack::IntStack(int size) //constructor
{
	stackArray = new int[size];
	stackSize = size;
	top = -1;
}

IntStack::~IntStack(void) //destructor

{
	delete[] stackArray;

}

bool IntStack::isFull(void)
{
	if (top == stackSize - 1)
		return true;
	else
		return false;
	// return (top == stackSize-1);
}

bool IntStack::isEmpty(void)
{
	return (top == -1);
}

bool IntStack::push(int num)
{
	if (isFull())
	{
		cout << "The stack is full.\n";
		return false;
	}
	top++;
	stackArray[top] = num;
	return true;
}

bool IntStack::pop(int& num)
{
	if (isEmpty())
	{
		cout << "The stack is empty.\n";
		return false;
	}
	num = stackArray[top];
	top--;
	return true;
}

int main() {

}