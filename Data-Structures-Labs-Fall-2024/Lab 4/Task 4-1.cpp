#include<iostream>
#include<string>
using namespace std;

class IntStack {
private:
    int* StackArray;
    int StackSize;
    int Top;
public:
    IntStack(int);
    ~IntStack();
    bool push(int);
    bool pop(int&);
    bool isFull();
    bool isempty();
    int top();
    void printStack();
};

IntStack::IntStack(int size) {
    StackArray = new int[size];
    StackSize = size;
    Top = -1;
}

IntStack::~IntStack() {
    delete[] StackArray;
}

bool IntStack::push(int val) {
    if (isFull()) {
        cout << "The stack is full." << endl;
        return false;
    }
    Top++;
    StackArray[Top] = val;
    return true;
}

bool IntStack::pop(int& val) {
    if (isempty())
    {
        cout << "The stack is empty.\n";
        return false;
    }
    val = StackArray[Top];
    Top--;
    return true;
}

bool IntStack::isFull() {
    if (Top == StackSize - 1)
        return true;
    else
        return false;
}

bool IntStack::isempty() {
    return (Top == -1);
}

int IntStack::top() {
    if (isempty())
    {
        cout << "The stack is empty.\n";
        return -1;
    }
    return StackArray[Top];
}

void IntStack::printStack() {
    if (isempty()) {
        cout << "The stack is empty." << endl;
    }
    else {
        cout << "Stack elements: ";
        for (int i = 0; i <= Top; i++) {
            cout << StackArray[i] << " ";
        }
        cout << endl;
    }
}

bool isBalanced(string str) {
    IntStack stack(100);
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            stack.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (stack.isempty()) {
                return false;
            }
            int top;
            stack.pop(top);
            if ((str[i] == ')' && top != '(') || (str[i] == '}' && top != '{') || (str[i] == ']' && top != '[')) {
                return false;
            }
        }
    }
    if (stack.isempty()) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    if (isBalanced(str)) {
        cout << "The string is balanced." << endl;
    }
    else {
        cout << "The string is not balanced." << endl;
    }
    return 0;
}