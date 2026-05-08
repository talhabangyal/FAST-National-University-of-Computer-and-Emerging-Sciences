#include<iostream>
using namespace std;

class IntStack {
private:
    int* StackArray;
    int StackSize;
    int Top;
    int Min;
public:
    IntStack(int);
    ~IntStack();
    bool push(int);
    bool pop(int&);
    bool isFull();
    bool isempty();
    int top();
    int getMin();
    void printStack();
};

IntStack::IntStack(int size) {
    StackArray = new int[size];
    StackSize = size;
    Top = -1;
    Min = INT_MAX;
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
    if (val < Min) {
        Min = val;
    }
    return true;
}

bool IntStack::pop(int& val) {
    if (isempty())
    {
        cout << "The stack is empty.\n";
        return false;
    }
    val = StackArray[Top];
    if (val == Min) {
        Min = INT_MAX;
        for (int i = 0; i <= Top - 1; i++) {
            if (StackArray[i] < Min) {
                Min = StackArray[i];
            }
        }
    }
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

int IntStack::getMin() {
    if (isempty())
    {
        cout << "The stack is empty.\n";
        return -1;
    }
    return Min;
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

int main() {
    int val, choice;
    IntStack stack(5);

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Push an element onto the stack" << endl;
        cout << "2. Pop an element from the stack" << endl;
        cout << "3. Check if the stack is empty" << endl;
        cout << "4. Check if the stack is full" << endl;
        cout << "5. Get the top element of the stack" << endl;
        cout << "6. Get the minimum element of the stack" << endl;
        cout << "7. Print the stack" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter an integer to push onto the stack: ";
            cin >> val;
            if (stack.push(val)) {
                cout << "Element pushed successfully." << endl;
            }
            break;
        }
        case 2: {
            if (stack.pop(val)) {
                cout << "Popped element: " << val << endl;
            }
            break;
        }
        case 3: {
            if (stack.isempty()) {
                cout << "The stack is empty." << endl;
            }
            else {
                cout << "The stack is not empty." << endl;
            }
            break;
        }
        case 4: {
            if (stack.isFull()) {
                cout << "The stack is full." << endl;
            }
            else {
                cout << "The stack is not full." << endl;
            }
            break;
        }
        case 5: {
            val = stack.top();
            if (val != -1) {
                cout << "Top element: " << val << endl;
            }
            break;
        }
        case 6: {
            val = stack.getMin();
            if (val != -1) {
                cout << "Minimum element: " << val << endl;
            }
            break;
        }
        case 7: {
            stack.printStack();
            break;
        }
        case 0: {
            cout << "Exiting..." << endl;
            return 0;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }

    return 0;
}