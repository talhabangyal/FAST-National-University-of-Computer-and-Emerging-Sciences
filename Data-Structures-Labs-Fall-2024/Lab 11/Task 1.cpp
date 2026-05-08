//#include <iostream>
//#include <string>
//
//using namespace std;
//struct Node {
//	string word;
//	Node* left;
//	Node* right;
//	int height;
//	Node(const string& w) : word(w), left(nullptr), right(nullptr), height(1) {}
//};
//class AVLTree {
//private:
//	Node* root;
//
//	int max(int a, int b) {
//		if (a > b) {
//			return a;
//		}
//		else {
//			return b;
//		}
//	}
//
//	int height(Node* node) {
//		if (node == nullptr) {
//			return 0;
//		}
//		return node->height;
//	}
//
//	int balanceFactor(Node* node) {
//		if (node == nullptr) {
//			return 0;
//		}
//		return height(node->left) - height(node->right);
//	}
//
//	void updateHeight(Node* node) {
//		if (node) {
//			node->height = 1 + max(height(node->left), height(node->right));
//		}
//	}
//
//	Node* rightRotate(Node* y) {
//		Node* x = y->left;
//		Node* temp = x->right;
//		x->right = y;
//		y->left = temp;
//		updateHeight(y);
//		updateHeight(x);
//		return x;
//	}
//	Node* leftRotate(Node* x) {
//		Node* y = x->right;
//		Node* temp = y->left;
//		y->left = x;
//		x->right = temp;
//		updateHeight(x);
//		updateHeight(y);
//		return y;
//	}
//
//	Node* insert(Node* node, const string& word) {
//		if (!node) 
//			return new Node(word);
//		if (word < node->word) {
//			node->left = insert(node->left, word);
//		}
//		else if (word > node->word) {
//			node->right = insert(node->right, word);
//		}
//		else {
//			return node;
//		}
//
//		updateHeight(node);
//		int balance = balanceFactor(node);
//		if (balance > 1 && word < node->left->word) {
//			return rightRotate(node);
//		}
//		if (balance < -1 && word > node->right->word) {
//			return leftRotate(node);
//		}
//		if (balance > 1 && word > node->left->word) {
//			node->left = leftRotate(node->left);
//			return rightRotate(node);
//		}
//		if (balance < -1 && word < node->right->word) {
//			node->right = rightRotate(node->right);
//			return leftRotate(node);
//		}
//		return node;
//	}
//
//	Node* minValueNode(Node* node) {
//		Node* current = node;
//		while (current->left != nullptr) {
//			current = current->left;
//		}
//		return current;
//	}
//
//	Node* deleteNode(Node* root, const string& word) {
//		if (!root) return root;
//
//		if (word < root->word) {
//			root->left = deleteNode(root->left, word);
//		}
//		else if (word > root->word) {
//			root->right = deleteNode(root->right, word);
//		}
//		else {
//			if (!root->left) {
//				Node* temp = root->right;
//				delete root;
//				return temp;
//			}
//			else if (!root->right) {
//				Node* temp = root->left;
//				delete root;
//				return temp;
//			}
//			Node* temp = minValueNode(root->right);
//			root->word = temp->word;
//			root->right = deleteNode(root->right, temp->word);
//		}
//		if (!root) return root;
//		updateHeight(root);
//		int balance = balanceFactor(root);
//		if (balance > 1 && balanceFactor(root->left) >= 0) {
//			return rightRotate(root);
//		}
//		if (balance > 1 && balanceFactor(root->left) < 0) {
//			root->left = leftRotate(root->left);
//			return rightRotate(root);
//		}
//		if (balance < -1 && balanceFactor(root->right) <= 0) {
//			return leftRotate(root);
//		}
//		if (balance < -1 && balanceFactor(root->right) > 0) {
//			root->right = rightRotate(root->right);
//			return leftRotate(root);
//		}
//
//		return root;
//	}
//
//	void inOrder(Node* node) {
//		if (node) {
//			inOrder(node->left);
//			cout << node->word << " ";
//			inOrder(node->right);
//		}
//	}
//
//	bool search(Node* node, const string& word) {
//		if (!node) 
//			return false;
//		if (word == node->word) 
//			return true;
//		if (word < node->word) 
//			return search(node->left, word);
//		return search(node->right, word);
//	}
//
//public:
//	AVLTree() : root(nullptr) {}
//
//	void insert(const string& word) {
//		root = insert(root, word);
//	}
//
//	void deleteWord(const string& word) {
//		root = deleteNode(root, word);
//	}
//
//	bool search(const string& word) {
//		return search(root, word);
//	}
//
//	void display() {
//		inOrder(root);
//		cout << endl;
//	}
//};
//void displayMenu() {
//	cout << "--- AVL Tree Dictionary ---" << endl;
//	cout << "1. Insert a word" << endl;
//	cout << "2. Search for a word" << endl;
//	cout << "3. Delete a word" << endl;
//	cout << "4. Display sorted dictionary" << endl;
//	cout << "0. Exit" << endl;
//	cout << "Choose an option (0-4): ";
//}
//
//int main() {
//	AVLTree tree;
//	string word;
//	int opt;
//	string words[] = { "apple", "banana", "cat", "dog", "elephant", "lion", "hippo", "zebra", "cherry", "lemon", "blueberry" };
//	for (const auto& w : words) {
//		tree.insert(w);
//	}
//	while (true) {
//		displayMenu();
//		cin >> opt;
//		cout << endl;
//
//		switch (opt) {
//		case 1:
//			cout << "Write a word to insert: ";
//			cin >> word;
//			tree.insert(word);
//			cout << word << " is inserted." << endl;
//			break;
//
//		case 2:
//			cout << "Write a word to search: ";
//			cin >> word;
//			if (tree.search(word)) {
//				cout << word << " is found in dictionary." << endl;
//			}
//			else {
//				cout << word << " is not found in dictionary." << endl;
//			}
//			break;
//
//		case 3:
//			cout << "Write a word to delete: ";
//			cin >> word;
//			tree.deleteWord(word);
//			cout << word << " is deleted." << endl;
//			break;
//
//		case 4:
//			cout << "Sorted dictionary (in-order): ";
//			tree.display();
//			break;
//
//		case 0:
//			cout << "Exiting the program." << endl;
//			return 0;
//
//		default:
//			cout << "Invalid option. Please try again." << endl;
//			break;
//		}
//	}
//	system("pause");
//	return 0;
//}