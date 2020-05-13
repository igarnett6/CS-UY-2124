#include <string>
#include <iostream>
#include <vector>
using namespace std;

//task 1
bool hasEven(int num) {
	if (num == 0) { return true; }
	bool res = hasEven(num / 2);
	if (num % 2 == 1) { return !res; }
	else { return res; }
}


//task 2
struct Node {
	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;
};
// listClear: frees up all the nodes in a list
void listClear(Node*& headPtr) {
	while (headPtr) {
		Node* next = headPtr->next;
		delete headPtr;
		headPtr = next;
	}
}
void listAddHead(Node*& headPtr, int entry) {
	headPtr = new Node(entry, headPtr);
}
Node* listBuild(const vector<int>& vals) {
	Node* result = nullptr;
	for (size_t index = vals.size(); index > 0; --index) {
		listAddHead(result, vals[index - 1]);
	}
	return result;
}
void displayList(Node* headPtr) {
	Node* currNode = headPtr;
	while (currNode) {
		cout << currNode->data << " ";
		currNode = currNode->next;
	}
	cout << endl;
}
Node* sumLists(Node* l1, Node* l2) {
	Node* rest;
	if (!l1 && !l2) {
		return nullptr;
	}
	else if (l1 && !l2) { 
		return new Node(l1->data, sumLists(l1->next, l2));
	}
	else if (!l1 && l2) { 
		return new Node(l2->data, sumLists(l2->next, l1));
	}
	else  { 
		rest = sumLists(l1->next, l2->next); 
		return new Node(l1->data + l2->data, rest);
	}
	
}

//task 4
bool palindrome(char arr[], int size) {
	if (size == 0 || size == 1) { return true; }
	else if(arr[0] != arr[size-1]) { return false; }
	return palindrome(++arr, size-2);
}


//task 5
int towers(int n , char start, char target, char spare, int count = 0){
	if (n == 0) return count;
	towers(n - 1, start, spare, target);
	towers(n - 1, spare, target, start, count);

}


int main() {
	//task 1
	cout << "hasEven(4) (100): " << boolalpha << hasEven(4) << endl; //100 false
	cout << "hasEven(6) (110): " << boolalpha << hasEven(6) << endl; //110 true

	//task 2
	Node* l1 = listBuild({ 1,1,1,1,2,1,1,1,1 });
	Node* l2 = listBuild({ 1,1,1,1,1,1,1 });
	Node* l3 = sumLists(l1, l2);
	cout << "List 1: ";
	displayList(l1);
	cout << endl << "List 2: ";
	displayList(l2);
	cout << endl << "List 3 (summed): ";
	displayList(l3);
	listClear(l1);
	listClear(l2);
	listClear(l3);
	cout << endl;


	//task 4
	char s[] = "racecar";
	if (palindrome(s, 7)) { cout << "Yes!\n"; }
	else { cout << "No.\n"; }

	char t[] = "notPalin";
	if(palindrome(t, 8)) { cout << "Yes!\n"; }
	else { cout << "No.\n"; }

	//task 5
	cout << "Testing towers: " << endl;
	cout << "towers(1, 'a', 'b', 'c'): " << towers(1, 'a', 'b', 'c') << endl;
	cout << "towers(10, 'a', 'b', 'c'): " << towers(10, 'a', 'b', 'c') << endl;
}