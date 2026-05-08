//#include <iostream>
//using namespace std;
//
//struct Node {
//	int value;
//	Node* left;
//	Node* right;
//	int height;
//
//	Node(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
//};
//
//int max(int a, int b) {
//	if (a > b) {
//		return a;
//	}
//	else {
//		return b;
//	}
//}
//int height(Node* node) {
//	if (node == nullptr) {
//		return 0;
//	}
//	return node->height;
//}
//
//int balanceFactor(Node* node) {
//	if (node == nullptr) {
//		return 0;
//	}
//	return height(node->left) - height(node->right);
//}
//
//void updateHeight(Node* node) {
//	if (node) {
//		node->height = 1 + max(height(node->left), height(node->right));
//	}
//}
//
//Node* rightRotate(Node* y) {
//	Node* x = y->left;
//	Node* temp = x->right;
//	x->right = y;
//	y->left = temp;
//	updateHeight(y);
//	updateHeight(x);
//	return x;
//}
//
//Node* leftRotate(Node* x) {
//	Node* y = x->right;
//	Node* temp = y->left;
//	y->left = x;
//	x->right = temp;
//	updateHeight(x);
//	updateHeight(y);
//	return y;
//}
//
//Node* insert(Node* node, int value) {
//	if (!node) return new Node(value);
//	if (value < node->value) {
//		node->left = insert(node->left, value);
//	}
//	else if (value > node->value) {
//		node->right = insert(node->right, value);
//	}
//	else {
//		return node;
//	}
//	updateHeight(node);
//	int balance = balanceFactor(node);
//	if (balance > 1 && value < node->left->value) {
//		return rightRotate(node);
//	}
//	if (balance < -1 && value > node->right->value) {
//		return leftRotate(node);
//	}
//	if (balance > 1 && value > node->left->value) {
//		node->left = leftRotate(node->left);
//		return rightRotate(node);
//	}
//	if (balance < -1 && value < node->right->value) {
//		node->right = rightRotate(node->right);
//		return leftRotate(node);
//	}
//
//	return node;
//}
//
//Node* BSTtoAVL(Node* bstRoot) {
//	if (!bstRoot) return nullptr;
//	Node* avlRoot = new Node(bstRoot->value);
//	avlRoot->left = BSTtoAVL(bstRoot->left);
//	avlRoot->right = BSTtoAVL(bstRoot->right);
//	updateHeight(avlRoot);
//	int balance = balanceFactor(avlRoot);
//	if (balance > 1 && balanceFactor(avlRoot->left) >= 0) {
//		return rightRotate(avlRoot);
//	}
//	if (balance < -1 && balanceFactor(avlRoot->right) <= 0) {
//		return leftRotate(avlRoot);
//	}
//	if (balance > 1 && balanceFactor(avlRoot->left) < 0) {
//		avlRoot->left = leftRotate(avlRoot->left);
//		return rightRotate(avlRoot);
//	}
//	if (balance < -1 && balanceFactor(avlRoot->right) > 0) {
//		avlRoot->right = rightRotate(avlRoot->right);
//		return leftRotate(avlRoot);
//	}
//	return avlRoot;
//}
//
//bool hasPathSum(Node* root, int sum, int X) {
//	if (!root) 
//		return false;
//	sum += root->value;
//	if (!root->left && !root->right) {
//		return sum > X;
//	}
//	return hasPathSum(root->left, sum, X) || hasPathSum(root->right, sum, X);
//}
//
//Node* swapSubtrees(Node* root) {
//	if (!root) return nullptr;
//	swap(root->left, root->right);
//	updateHeight(root);
//	int balance = balanceFactor(root);
//	if (balance > 1 && balanceFactor(root->left) >= 0) {
//		return rightRotate(root);
//	}
//	if (balance < -1 && balanceFactor(root->right) <= 0) {
//		return leftRotate(root);
//	}
//	if (balance > 1 && balanceFactor(root->left) < 0) {
//		root->left = leftRotate(root->left);
//		return rightRotate(root);
//	}
//	if (balance < -1 && balanceFactor(root->right) > 0) {
//		root->right = rightRotate(root->right);
//		return leftRotate(root);
//	}
//	return root;
//}
//
//void printInOrder(Node* node) {
//	if (!node) return;
//	printInOrder(node->left);
//	cout << node->value << " ";
//	printInOrder(node->right);
//}
//
//void displayMenu() {
//	cout << "--- BST-AVL Tree ---" << endl;
//	cout << "1. Insert " << endl;
//	cout << "2. Convert BST-AVL" << endl;
//	cout << "3. Display the BST-AVL" << endl;
//	cout << "4. Sum Target" << endl;
//	cout << "5. Swap sub Tree" << endl;
//	cout << "0. Exit" << endl;
//}
//
//int main() {
//	Node* bstRoot = nullptr;
//	Node* avlRoot = nullptr;
//	int choice, value;
//
//	while (true) {
//		displayMenu();
//		cout << "Choose an option (0-5): ";
//		cin >> choice;
//
//		switch (choice) {
//		case 1:
//			cout << "Enter value to insert: ";
//			cin >> value;
//			bstRoot = insert(bstRoot, value);
//			break;
//
//		case 2:
//			avlRoot = BSTtoAVL(bstRoot);
//			cout << "Converted BST to AVL." << endl;
//			break;
//
//		case 3:
//			cout << "AVL tree in-order: ";
//			printInOrder(avlRoot);
//			cout << endl;
//			break;
//
//		case 4:
//			int X;
//			cout << "Enter target sum: ";
//			cin >> X;
//			if (hasPathSum(avlRoot, 0, X))
//				cout << "Yes" << endl;
//			else
//				cout << "No" << endl;
//			break;
//
//		case 5:
//			avlRoot = swapSubtrees(avlRoot);
//			cout << "Swapped subtrees." << endl;
//			break;
//
//		case 0:
//			cout << "Exiting..." << endl;
//			return 0;
//
//		default:
//			cout << "Invalid option. Please try again." << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}
