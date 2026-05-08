//#include<iostream>
//using namespace std;
//
//struct Node {
//	int data;
//	Node* next;
//	Node* prev;
//};
//
//class DoublyLinkedList {
//public:
//	DoublyLinkedList();
//	void Insert_at_front(int val);
//	void Insert_at_end(int val);
//	void Insert_at_index(int index, int val);
//	void Delete_at_front();
//	void Delete_at_end();
//	void Delete_at_index(int index);
//	bool Isempty();
//	void Print();
//	~DoublyLinkedList();
//
//private:
//	Node* head;
//	Node* tail;
//};
//
//DoublyLinkedList::DoublyLinkedList() {
//	head = NULL;
//	tail = NULL;
//}
//
//bool DoublyLinkedList::Isempty() {
//	return head == NULL;
//}
//
//void DoublyLinkedList::Insert_at_front(int val) {
//	if (Isempty()) {
//		head = new Node;
//		head->data = val;
//		head->next = NULL;
//		head->prev = NULL;
//		tail = head;
//	}
//	else {
//		Node* temp = new Node;
//		temp->data = val;
//		temp->next = head;
//		head->prev = temp;
//		temp->prev = NULL;
//		head = temp;
//	}
//}
//
//void DoublyLinkedList::Insert_at_end(int val) {
//	if (Isempty()) {
//		head = new Node;
//		head->data = val;
//		head->next = NULL;
//		head->prev = NULL;
//		tail = head;
//	}
//	else {
//		Node* temp = new Node;
//		temp->data = val;
//		temp->next = NULL;
//		temp->prev = tail;
//		tail->next = temp;
//		tail = temp;
//	}
//}
//
//void DoublyLinkedList::Insert_at_index(int index, int val) {
//	if (Isempty()) {
//		if (index == 0) {
//			head = new Node;
//			head->data = val;
//			head->next = NULL;
//			head->prev = NULL;
//			tail = head;
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
//			newNode->prev = current;
//			current->next = newNode;
//			if (newNode->next != NULL) {
//				newNode->next->prev = newNode;
//			}
//			else {
//				tail = newNode;
//			}
//		}
//		else {
//			cout << "Index out of bounds" << endl;
//		}
//	}
//}
//
//void DoublyLinkedList::Delete_at_front() {
//	if (Isempty()) {
//		cout << "List is empty" << endl;
//		return;
//	}
//	else {
//		Node* temp = head;
//		head = head->next;
//		if (head != NULL) {
//			head->prev = NULL;
//		}
//		else {
//			tail = NULL;
//		}
//		delete temp;
//	}
//}
//
//void DoublyLinkedList::Delete_at_end() {
//	if (Isempty()) {
//		cout << "List is empty" << endl;
//		return;
//	}
//	else if (head->next == NULL) {
//		delete head;
//		head = NULL;
//		tail = NULL;
//	}
//	else {
//		Node* current = head;
//		while (current->next->next != NULL) {
//			current = current->next;
//		}
//		Node* temp = current->next;
//		current->next = NULL;
//		tail = current;
//		delete temp;
//	}
//}
//
//void DoublyLinkedList::Delete_at_index(int index) {
//	if (Isempty()) {
//		cout << "List is empty" << endl;
//		return;
//	}
//
//	if (index < 0) {
//		cout << "Index cannot be negative" << endl;
//		return;
//	}
//
//	if (index == 0) {
//		Node* temp = head;
//		head = head->next;
//		if (head != nullptr) {
//			head->prev = nullptr;
//		}
//		else {
//			tail = nullptr;
//		}
//		delete temp;
//	}
//	else {
//		Node* current = head;
//		int currentIndex = 0;
//
//		while (current != nullptr && currentIndex < index - 1) {
//			current = current->next;
//			currentIndex++;
//		}
//
//		if (current == nullptr || current->next == nullptr) {
//			cout << "Index out of bounds" << endl;
//			return;
//		}
//		Node* temp = current->next;
//		current->next = temp->next;
//		if (temp->next != nullptr) {
//			temp->next->prev = current;
//		}
//		else {
//			tail = current;
//		}
//		delete temp;
//	}
//}
//
//
//void DoublyLinkedList::Print() {
//	Node* current = head;
//	while (current != NULL) {
//		cout << current->data << " ";
//		current = current->next;
//	}
//	cout << endl;
//}
//
//DoublyLinkedList::~DoublyLinkedList() {
//	Node* current = head;
//	while (current != NULL) {
//		Node* next = current->next;
//		delete current;
//		current = next;
//	}
//}
//
//int main() {
//	DoublyLinkedList DLL;
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
//			DLL.Insert_at_front(val);
//			break;
//		case 2:
//			cout << "Enter value to insert at end: ";
//			cin >> val;
//			DLL.Insert_at_end(val);
//			break;
//		case 3:
//			cout << "Enter index: ";
//			cin >> index;
//			cout << "Enter value to insert: ";
//			cin >> val;
//			DLL.Insert_at_index(index, val);
//			break;
//		case 4:
//			DLL.Delete_at_front();
//			break;
//		case 5:
//			DLL.Delete_at_end();
//			break;
//		case 6:
//			cout << "Enter index: ";
//			cin >> index;
//			DLL.Delete_at_index(index);
//			break;
//		case 7:
//			DLL.Print();
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