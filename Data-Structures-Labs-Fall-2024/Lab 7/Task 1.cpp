//#include <iostream>
//using namespace std;
//
//class Queue {
//private:
//    struct node {
//        int value;
//        node* next;
//    };
//    node* front;
//    node* rear;
//    int numItems;
//
//public:
//    Queue();
//    ~Queue();
//    bool isEmpty();
//    void makeNull();
//    void push(int);
//    bool pop(int&);
//    void top();
//    void display();
//};
//
//Queue::Queue() {
//    front = NULL;
//    rear = NULL;
//    numItems = 0;
//}
//
//Queue::~Queue() {
//    makeNull();
//}
//
//bool Queue::isEmpty() {
//    return front == NULL;
//}
//
//void Queue::push(int num) {
//    node* newNode = new node;
//    newNode->value = num;
//    newNode->next = NULL;
//
//    if (isEmpty()) {
//        front = rear = newNode;
//    }
//    else if (num >= front->value) {
//        newNode->next = front;
//        front = newNode;
//    }
//    else {
//        node* temp = front;
//        while (temp->next != NULL && temp->next->value > num) {
//            temp = temp->next;
//        }
//        newNode->next = temp->next;
//        temp->next = newNode;
//        if (newNode->next == NULL) {
//            rear = newNode;
//        }
//    }
//    numItems++;
//}
//
//bool Queue::pop(int& num) {
//    if (isEmpty()) {
//        cout << "The queue is empty." << endl;
//        return false;
//    }
//
//    num = front->value;
//    node* temp = front;
//    front = front->next;
//    delete temp;
//
//    if (front == NULL) {
//        rear = NULL;
//    }
//
//    numItems--;
//    return true;
//}
//
//void Queue::top() {
//    if (!isEmpty()) {
//        cout << "Max priority element is: " << front->value << endl;
//    }
//    else {
//        cout << "The queue is empty." << endl;
//    }
//}
//
//void Queue::display() {
//    if (isEmpty()) {
//        cout << "The queue is empty." << endl;
//        return;
//    }
//
//    node* temp = front;
//    cout << "Queue elements: ";
//    while (temp != NULL) {
//        cout << temp->value << "->";
//        temp = temp->next;
//    }
//    cout << endl;
//}
//
//void Queue::makeNull() {
//    int x;
//    while (!isEmpty()) {
//        pop(x);
//    }
//}
//
//int main() {
//    Queue pq;
//    int choice, value;
//
//    while (true) {
//        cout << "------------Menu------------" << endl;
//        cout << "1. Push (Insert value)" << endl;
//        cout << "2. Pop (Remove Max priority value)" << endl;
//        cout << "3. Top (Display Max priority value)" << endl;
//        cout << "4. Display all elements in the queue" << endl;
//        cout << "0. Exit the program" << endl;
//        cout << "Enter a value to select an option: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            cout << "Enter a value to insert: ";
//            cin >> value;
//            pq.push(value);
//            break;
//        case 2:
//            if (pq.pop(value)) {
//                cout << "Removed Max priority value: " << value << endl;
//            }
//            break;
//        case 3:
//            pq.top();
//            break;
//        case 4:
//            pq.display();
//            break;
//        case 0:
//            cout << "Exiting program..." << endl;
//            return 0;
//        default:
//            cout << "Invalid choice! Please try again." << endl;
//            break;
//        }
//    }
//
//    return 0;
//}