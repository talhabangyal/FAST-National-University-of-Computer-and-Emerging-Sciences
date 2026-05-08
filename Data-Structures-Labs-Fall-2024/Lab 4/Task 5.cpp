#include<iostream>
#include<string>
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

int evaluatePostfix(string str) {
    IntStack stack;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            continue;
        }
        else if (isdigit(str[i])) {
            int num = 0;
            while (i < str.length() && isdigit(str[i])) {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            i--;
            stack.push(num);
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            int op1, op2;
            stack.pop(op2);
            stack.pop(op1);
            if (str[i] == '+') {
                stack.push(op1 + op2);
            }
            else if (str[i] == '-') {
                stack.push(op1 - op2);
            }
            else if (str[i] == '*') {
                stack.push(op1 * op2);
            }
            else if (str[i] == '/') {
                stack.push(op1 / op2);
            }
        }
    }
    return stack.top();
}

int main() {
    string str;
    cout << "Enter a postfix expression: ";
    getline(cin, str);
    cout << "Result: " << evaluatePostfix(str) << endl;
    return 0;
}