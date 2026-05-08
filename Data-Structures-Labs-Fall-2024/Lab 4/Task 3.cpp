#include<iostream>
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
    void displayStack();
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

void IntStack::displayStack() {
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

void reverseStack(IntStack& stack) {
    IntStack tempStack(stack.StackSize);
    while (!stack.isempty()) {
        int val;
        stack.pop(val);
        tempStack.push(val);
    }
    stack = tempStack;
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
        cout << "6. Reverse the stack" << endl;
        cout << "7. Display the stack" << endl;
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
            reverseStack(stack);
            cout << "Stack reversed successfully." << endl;
            break;
        }
        case 7: {
            stack.displayStack();
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