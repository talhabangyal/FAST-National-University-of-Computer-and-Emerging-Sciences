#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    int height;

    Node(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* node) {
    return node ? node->height : 0;
}

int balanceFactor(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

void updateHeight(Node* node) {
    if (node) {
        node->height = 1 + max(height(node->left), height(node->right));
    }
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

Node* insert(Node* node, int value) {
    if (!node) return new Node(value);

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else
        return node;

    updateHeight(node);
    int balance = balanceFactor(node);

    if (balance > 1 && value < node->left->value)
        return rightRotate(node);

    if (balance < -1 && value > node->right->value)
        return leftRotate(node);

    if (balance > 1 && value > node->left->value) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && value < node->right->value) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* findMax(Node* node) {
    while (node->right) {
        node = node->right;
    }
    return node;
}

Node* join(Node* T1, Node* T2) {
    if (!T1) return T2;
    if (!T2) return T1;

    Node* maxNode = findMax(T1);
    maxNode->right = T2;

    updateHeight(maxNode);
    int balance = balanceFactor(T1);

    if (balance > 1 && balanceFactor(T1->left) >= 0) {
        return rightRotate(T1);
    }
    if (balance < -1 && balanceFactor(T1->right) <= 0) {
        return leftRotate(T1);
    }
    if (balance > 1 && balanceFactor(T1->left) < 0) {
        T1->left = leftRotate(T1->left);
        return rightRotate(T1);
    }
    if (balance < -1 && balanceFactor(T1->right) > 0) {
        T1->right = rightRotate(T1->right);
        return leftRotate(T1);
    }

    return T1;
}

void printInOrder(Node* node) {
    if (!node) return;
    printInOrder(node->left);
    cout << node->value << " ";
    printInOrder(node->right);
}

void displayMenu() {
    cout << "--- AVL Tree Operations ---" << endl;
    cout << "1. Insert into T1" << endl;
    cout << "2. Insert into T2" << endl;
    cout << "3. Join T1 and T2" << endl;
    cout << "4. Display joined AVL tree (in-order)" << endl;
    cout << "0. Exit" << endl;
}

int main() {
    Node* T1 = nullptr;
    Node* T2 = nullptr;
    Node* joinedTree = nullptr;

    int choice, value;
    while (true) {
        displayMenu();
        cout << "Choose an option (0-4): ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert into T1: ";
            cin >> value;
            T1 = insert(T1, value);
            cout << "Inserted " << value << " into T1." << endl;
            break;

        case 2:
            cout << "Enter value to insert into T2: ";
            cin >> value;
            T2 = insert(T2, value);
            cout << "Inserted " << value << " into T2." << endl;
            break;

        case 3:
            joinedTree = join(T1, T2);
            cout << "Joined T1 and T2 into a single AVL tree." << endl;
            break;

        case 4:
            if (joinedTree) {
                cout << "In-order traversal of the joined AVL tree: ";
                printInOrder(joinedTree);
                cout << endl;
            }
            else {
                cout << "The AVL tree has not been joined yet." << endl;
            }
            break;

        case 0:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}
