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

void infixToPrefix(string infix, string& prefix) {
    Stack s;
    string temp = infix;
    reverse(temp.begin(), temp.end());
    for (int i = 0; i < temp.length(); i++) {
        if (temp[i] == ' ') continue;
        else if (temp[i] == '(') {
            char c;
            while (!s.IsEmpty() && s.Top() != ')') {
                s.Pop(c);
                prefix += c;
            }
            if (s.IsEmpty() || s.Top() != ')') {
                cout << "Invalid infix expression";
                return;
            }
            s.Pop(c);
        }
        else if (temp[i] == ')') s.Push(temp[i]);
        else if (isalpha(temp[i])) prefix += temp[i];
        else {
            while (!s.IsEmpty() && s.Top() != ')' && precedence(s.Top()) >= precedence(temp[i])) {
                char c;
                s.Pop(c);
                prefix += c;
            }
            s.Push(temp[i]);
        }
    }
    while (!s.IsEmpty()) {
        char c;
        s.Pop(c);
        prefix += c;
    }
    reverse(prefix.begin(), prefix.end());
}

int main() {
    string infix, prefix;
    cout << "Enter infix expression: ";
    getline(cin, infix);
    infixToPrefix(infix, prefix);
    cout << "Prefix expression: " << prefix << endl;
    return 0;
}