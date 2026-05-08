#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class IntStack {
private:
    Node* Top;
public:
    IntStack();
    ~IntStack();
    bool push(int);
    bool pop(int&);
    bool isempty();
    int top();
    void printStack();
};

IntStack::IntStack() {
    Top = nullptr;
}

IntStack::~IntStack() {
    while (Top != nullptr) {
        Node* temp = Top;
        Top = Top->next;
        delete temp;
    }
}

bool IntStack::push(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = Top;
    Top = newNode;
    return true;
}

bool IntStack::pop(int& val) {
    if (isempty()) {
        cout << "The stack is empty.\n";
        return false;
    }
    val = Top->data;
    Node* temp = Top;
    Top = Top->next;
    delete temp;
    return true;
}

bool IntStack::isempty() {
    return (Top == nullptr);
}

int IntStack::top() {
    if (isempty()) {
        throw std::runtime_error("Stack is empty");
    }
    return Top->data;
}

void IntStack::printStack() {
    if (isempty()) {
        cout << "The stack is empty." << endl;
    }
    else {
        cout << "Stack elements: ";
        Node* temp = Top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    int val, choice;
    IntStack stack;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Push an element onto the stack" << endl;
        cout << "2. Pop an element from the stack" << endl;
        cout << "3. Check if the stack is empty" << endl;
        cout << "4. Check if the stack is full" << endl;
        cout << "5. Get the top element of the stack" << endl;
        cout << "6. Print the stack" << endl;
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
            cout << "The stack is not full." << endl;
            break;
        }
        case 5: {
            try {
                val = stack.top();
                cout << "Top element: " << val << endl;
            }
            catch (const std::exception& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 6: {
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