#include<iostream>
#include<string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class CharStack {
private:
    Node* Top;
public:
    CharStack();
    ~CharStack();
    bool push(char);
    bool pop(char&);
    bool isempty();
    char top();
    void printStack();
};

CharStack::CharStack() {
    Top = nullptr;
}

CharStack::~CharStack() {
    while (Top != nullptr) {
        Node* temp = Top;
        Top = Top->next;
        delete temp;
    }
}

bool CharStack::push(char val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = Top;
    Top = newNode;
    return true;
}

bool CharStack::pop(char& val) {
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

bool CharStack::isempty() {
    return (Top == nullptr);
}

char CharStack::top() {
    if (isempty()) {
        throw std::runtime_error("Stack is empty");
    }
    return Top->data;
}

void CharStack::printStack() {
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

bool isPalindrome(string str) {
    CharStack stack;
    for (int i = 0; i < str.length(); i++) {
        if (isalnum(str[i])) {
            stack.push(tolower(str[i]));
        }
    }
    for (int i = 0; i < str.length(); i++) {
        if (isalnum(str[i])) {
            char top;
            stack.pop(top);
            if (top != tolower(str[i])) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    if (isPalindrome(str)) {
        cout << "The string is a palindrome." << endl;
    }
    else {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
}