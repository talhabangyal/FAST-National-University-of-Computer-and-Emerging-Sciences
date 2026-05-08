#include<iostream>
#include<string>
using namespace std;

struct node {
    char data;
    node* next;
};

class Stack {
    node* top;
public:
    Stack() { top = NULL; }
    ~Stack() { makeNull(); }
    void Push(char newelement);
    bool Pop(char&);
    bool IsEmpty();
    void makeNull();
    char Top();
};

void Stack::Push(char newelement) {
    node* newptr = new node;
    newptr->data = newelement;
    newptr->next = top;
    top = newptr;
}

bool Stack::Pop(char& returnvalue) {
    if (IsEmpty()) {
        cout << "underflow error";
        return false;
    }
    node* tempptr = top;
    returnvalue = top->data;
    top = top->next;
    delete tempptr;
    return true;
}

bool Stack::IsEmpty() {
    return (top == NULL);
}

void Stack::makeNull() {
    char x;
    while (Pop(x));
}

char Stack::Top() {
    if (IsEmpty()) {
        cout << "Stack is empty";
        return '\0';
    }
    return top->data;
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0;
}

void infixToPostfix(string infix, string& postfix) {
    Stack s;
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == ' ') continue;
        else if (infix[i] == '(') s.Push(infix[i]);
        else if (infix[i] == ')') {
            char c;
            while (!s.IsEmpty() && s.Top() != '(') {
                s.Pop(c);
                postfix += c;
            }
            if (s.IsEmpty() || s.Top() != '(') {
                cout << "Invalid infix expression";
                return;
            }
            s.Pop(c);
        }
        else if (isalpha(infix[i])) postfix += infix[i];
        else {
            while (!s.IsEmpty() && s.Top() != '(' && precedence(s.Top()) >= precedence(infix[i])) {
                char c;
                s.Pop(c);
                postfix += c;
            }
            s.Push(infix[i]);
        }
    }
    while (!s.IsEmpty()) {
        char c;
        s.Pop(c);
        postfix += c;
    }
}

int main() {
    string infix, postfix;
    cout << "Enter infix expression: ";
    getline(cin, infix);
    infixToPostfix(infix, postfix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}