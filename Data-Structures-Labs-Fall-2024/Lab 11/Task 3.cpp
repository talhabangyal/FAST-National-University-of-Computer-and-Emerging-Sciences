//#include <iostream>
//#include <string>
//using namespace std;
//
//struct Node {
//    string username;
//    int timestamp;
//    Node* left;
//    Node* right;
//    int height;
//
//    Node(string user, int time) : username(user), timestamp(time), left(nullptr), right(nullptr), height(1) {}
//};
//
//int max(int a, int b) {
//    if (a > b) {
//        return a;
//    }
//    else {
//        return b;
//    }
//}
//
//int height(Node* node) {
//    if (node == nullptr) {
//        return 0;
//    }
//    return node->height;
//}
//
//int balanceFactor(Node* node) {
//    if (node == nullptr) {
//        return 0;
//    }
//    return height(node->left) - height(node->right);
//}
//
//void updateHeight(Node* node) {
//    if (node)
//        node->height = 1 + max(height(node->left), height(node->right));
//}
//
//Node* rightRotate(Node* y) {
//    Node* x = y->left;
//    Node* temp = x->right;
//    x->right = y;
//    y->left = temp;
//    updateHeight(y);
//    updateHeight(x);
//    return x;
//}
//
//Node* leftRotate(Node* x) {
//    Node* y = x->right;
//    Node* temp = y->left;
//    y->left = x;
//    x->right = temp;
//    updateHeight(x);
//    updateHeight(y);
//    return y;
//}
//
//Node* insertOrUpdate(Node* node, string username, int timestamp) {
//    if (!node)
//        return new Node(username, timestamp);
//
//    if (username < node->username)
//        node->left = insertOrUpdate(node->left, username, timestamp);
//    else if (username > node->username)
//        node->right = insertOrUpdate(node->right, username, timestamp);
//    else {
//        node->timestamp = timestamp;
//        return node;
//    }
//
//    updateHeight(node);
//    int balance = balanceFactor(node);
//
//    if (balance > 1 && username < node->left->username)
//        return rightRotate(node);
//
//    if (balance < -1 && username > node->right->username)
//        return leftRotate(node);
//
//    if (balance > 1 && username > node->left->username) {
//        node->left = leftRotate(node->left);
//        return rightRotate(node);
//    }
//
//    if (balance < -1 && username < node->right->username) {
//        node->right = rightRotate(node->right);
//        return leftRotate(node);
//    }
//
//    return node;
//}
//
//void rangeQuery(Node* node, int startTime, int endTime) {
//    if (!node) return;
//
//    if (node->timestamp >= startTime)
//        rangeQuery(node->left, startTime, endTime);
//
//    if (node->timestamp >= startTime && node->timestamp <= endTime)
//        cout << node->username << " ";
//
//    if (node->timestamp <= endTime)
//        rangeQuery(node->right, startTime, endTime);
//}
//
//void printInOrder(Node* node) {
//    if (!node) return;
//    printInOrder(node->left);
//    cout << node->username << " (" << node->timestamp << ") ";
//    printInOrder(node->right);
//}
//
//void displayMenu() {
//    cout << "--- Instagram login count menu ---" << endl;
//    cout << "1. Insert/Update User" << endl;
//    cout << "2. Query Users by Time Range" << endl;
//    cout << "3. Display All Users" << endl;
//    cout << "0. Exit" << endl;
//}
//
//int main() {
//    Node* root = nullptr;
//    int choice, timestamp, startTime, endTime;
//    string username;
//
//    while (true) {
//        displayMenu();
//        cout << "Choose an option (0-3): ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            cout << "Enter username: ";
//            cin >> username;
//            cout << "Enter timestamp: ";
//            cin >> timestamp;
//            root = insertOrUpdate(root, username, timestamp);
//            break;
//
//        case 2:
//            cout << "Enter start time: ";
//            cin >> startTime;
//            cout << "Enter end time: ";
//            cin >> endTime;
//            cout << "Users who logged in between " << startTime << " and " << endTime << ":\n";
//            rangeQuery(root, startTime, endTime);
//            cout << endl;
//            break;
//
//        case 3:
//            cout << "All users (in-order): ";
//            printInOrder(root);
//            cout << endl;
//            break;
//
//        case 0:
//            cout << "Exiting..." << endl;
//            return 0;
//
//        default:
//            cout << "Invalid option. Please try again." << endl;
//        }
//    }
//
//    system("pause");
//    return 0;
//}