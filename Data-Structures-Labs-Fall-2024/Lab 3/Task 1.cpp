//#include<iostream>
//using namespace std;
//
//struct Node {
//	int data;
//	Node* next;
//};
//
//class SinglyLinkedList {
//public:
//	SinglyLinkedList();
//	void Insert_at_front(int val);
//	void Insert_at_end(int val);
//	void Insert_at_index(int index, int val);
//	void Delete_at_front();
//	void Delete_at_end();
//	void Delete_at_index(int index);
//	bool Isempty();
//	void Print();
//	~SinglyLinkedList();
//
//private:
//	Node* head;
//};
//
//SinglyLinkedList::SinglyLinkedList() {
//	head = NULL;
//}
//
//bool SinglyLinkedList::Isempty() {
//	return head == NULL;
//}
//
//void SinglyLinkedList::Insert_at_front(int val) {
//	if (Isempty()) {
//		head = new Node;
//		head->data = val;
//		head->next = NULL;
//	}
//	else {
//		Node* temp = new Node;
//		temp->data = val;
//		temp->next = head;
//		head = temp;
//	}
//}
//
//void SinglyLinkedList::Insert_at_end(int val) {
//	if (Isempty()) {
//		head = new Node;
//		head->data = val;
//		head->next = NULL;
//	}
//	else {
//		Node* current = head;
//		while (current->next != NULL) {
//			current = current->next;
//		}
//		Node* temp = new Node;
//		temp->data = val;
//		temp->next = NULL;
//		current->next = temp;
//	}
//}
//
//void SinglyLinkedList::Insert_at_index(int index, int val) {
//	if (Isempty()) {
//		if (index == 0) {
//			head = new Node;
//			head->data = val;
//			head->next = NULL;
//		}
//		else {
//			cout << "Index out of bounds" << endl;
//			return;
//		}
//	}
//	else {
//		Node* current = head;
//		int currentIndex = 0;
//		while (current->next != NULL && currentIndex < index - 1) {
//			current = current->next;
//			currentIndex++;
//		}
//		if (currentIndex == index - 1) {
//			Node* newNode = new Node;
//			newNode->data = val;
//			newNode->next = current->next;
//			current->next = newNode;
//		}
//		else {
//			cout << "Index out of bounds" << endl;
//		}
//	}
//}
//
//void SinglyLinkedList::Delete_at_front() {
//	if (Isempty()) {
//		cout << "List is empty" << endl;
//		return;
//	}
//	else {
//		Node* temp = head;
//		head = head->next;
//		delete temp;
//	}
//}
//
//void SinglyLinkedList::Delete_at_end() {
//	if (Isempty()) {
//		cout << "List is empty" << endl;
//		return;
//	}
//	else if (head->next == NULL) {
//		delete head;
//		head = NULL;
//	}
//	else {
//		Node* current = head;
//		while (current->next->next != NULL) {
//			current = current->next;
//		}
//		delete current->next;
//		current->next = NULL;
//	}
//}
//
//void SinglyLinkedList::Delete_at_index(int index) {
//	if (Isempty()) {
//		cout << "List is empty" << endl;
//		return;
//	}
//	else if (index == 0) {
//		Node* temp = head;
//		head = head->next;
//		delete temp;
//	}
//	else {
//		Node* current = head;
//		int currentIndex = 0;
//		while (current->next != NULL && currentIndex < index - 1) {
//			current = current->next;
//			currentIndex++;
//		}
//		if (currentIndex == index - 1) {
//			Node* temp = current->next;
//			current->next = current->next->next;
//			delete temp;
//		}
//		else {
//			cout << "Index out of bounds" << endl;
//		}
//	}
//}
//
//void SinglyLinkedList::Print() {
//	Node* current = head;
//	while (current != NULL) {
//		cout << current->data << " ";
//		current = current->next;
//	}
//	cout << endl;
//}
//
//SinglyLinkedList::~SinglyLinkedList() {
//	Node* current = head;
//	while (current != NULL) {
//		Node* next = current->next;
//		delete current;
//		current = next;
//	}
//}
//
//int main() {
//	SinglyLinkedList SSL;
//	int choice, val, index;
//
//	while (true) {
//		cout << "------------------------Menu--------------------------" << endl;
//		cout << "1. Insert at front" << endl;
//		cout << "2. Insert at end" << endl;
//		cout << "3. Insert at index" << endl;
//		cout << "4. Delete at front" << endl;
//		cout << "5. Delete at end" << endl;
//		cout << "6. Delete at index" << endl;
//		cout << "7. Print list" << endl;
//		cout << "0. Exit" << endl;
//		cout << "Enter your choice: ";
//		cin >> choice;
//
//		switch (choice) {
//		case 1:
//			cout << "Enter value to insert at front: ";
//			cin >> val;
//			SSL.Insert_at_front(val);
//			break;
//		case 2:
//			cout << "Enter value to insert at end: ";
//			cin >> val;
//			SSL.Insert_at_end(val);
//			break;
//		case 3:
//			cout << "Enter index: ";
//			cin >> index;
//			cout << "Enter value to insert: ";
//			cin >> val;
//			SSL.Insert_at_index(index, val);
//			break;
//		case 4:
//			SSL.Delete_at_front();
//			break;
//		case 5:
//			SSL.Delete_at_end();
//			break;
//		case 6:
//			cout << "Enter index: ";
//			cin >> index;
//			SSL.Delete_at_index(index);
//			break;
//		case 7:
//			SSL.Print();
//			break;
//		case 0:
//			return 0;
//		default:
//			cout << "Invalid choice. Try again." << endl;
//		}
//	}
//
//	return 0;
//}