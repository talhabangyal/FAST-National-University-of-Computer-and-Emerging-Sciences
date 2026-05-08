#include<iostream>
using namespace std;
class node {
public:
	int data; node* next;
};

class Stack {
	node* top;
public:
	Stack();
	~Stack();
	void Push(int newelement);
	bool Pop(int&);
	bool IsEmpty();
	void makeNull();
};

Stack::Stack() {
	top = NULL;
}

bool Stack::IsEmpty() {
	return (top == NULL);
}

void Stack::Push(int newelement) {
	node* newptr = new node;
	newptr->data = newelement;
	newptr->next = top;
	top = newptr;
}

bool Stack::Pop(int& returnvalue) {
	if (IsEmpty()){
		cout << "underflow error";
		return false;
	}
	node* tempptr = top;
	returnvalue = top->data;
	top = top->next;
	delete tempptr;
	return true;
}

void Stack::makeNull() {
	int x;
	while (Pop(x));
}

Stack::~Stack() {
	makeNull();
}

int main() {

}