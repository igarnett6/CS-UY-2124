/*
  functions for use with CS2124 rec11
  -jbs
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Node to be used a part of linked list
struct Node {
	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;
};

// listAddHead: adds a data item to the beginning of a [possibly empty] list
void listAddHead(Node*& headPtr, int entry) {
	headPtr = new Node(entry, headPtr);
}

// listClear: frees up all the nodes in a list
void listClear(Node*& headPtr) {
    while (headPtr) {
        Node* next = headPtr->next;
        delete headPtr;
        headPtr = next;
    }
}

// listBuild: constructs a list from a vector of data items. Note that
// you can use a curly-braced sequence.
// This may be useful for setting up test cases. Feel free to use it
// or not as you like. 
// Example of using would be:
//    Node* myList = listBuild({1, 4, 9, 16}); // builds a list of: 1 4 9 16
Node* listBuild(const vector<int>& vals) {
    Node* result = nullptr;
    for (size_t index = vals.size(); index > 0; --index) {
        listAddHead(result, vals[index-1]);
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

Node* getLastNode(Node* headPtr) {
	Node* currNode = headPtr;
	while (currNode->next) {
		currNode = currNode->next;
	}
	return currNode;
}

void splice(Node* headPtr, Node* addAfter) {
	//cout << endl << "Testing splice:" << endl;
	Node* trailingNodes = addAfter->next;
	Node* l1LastNode = getLastNode(headPtr);
	addAfter->next = headPtr;
	/*headPtr->next = nullptr;*/
	l1LastNode->next = trailingNodes;
	//cout << "Leaving splice" << endl;
}


bool compareLists(Node* find, Node* start) {
	
	while (find) {
		if (!start) { return false; }
		if (find->data != start->data) {
			return false;
		}
		else {
			find = find->next;
			start = start->next;
		}
	}
	return true;
}
Node* isSublist(Node* find, Node* search) {
	//cout << "Entered isSublist." << endl;
	Node* res = nullptr;
	while (search->next) {
		if (compareLists(find, search)) {
			res = search;
		}
		search = search->next;
	}
	//cout << "leaving isSublist." << endl;
	return res;
}


void displayLists(Node* list1, Node* list2) {
	cout << "Part One: " << endl;
	cout << "List 1: ";
	displayList(list1);
	cout << endl;
	cout << "List 2: ";
	displayList(list2);
	cout << endl;
}

void testP2(Node* check) {
	if (check == nullptr) {
		cout << "Failed to match" << endl << endl;
	}
	else {
		displayList(check);
	}
}

int main() {
	Node* list1 = listBuild({ 1,2,3,4,8,9,10 });
	Node* list2 = listBuild({ 5,6,7});
	Node* addAfter = list1;
	for (int i = 0; i < 3; i++) {
		addAfter = addAfter->next;
	}
	displayLists(list1, list2);
	splice(list2, addAfter);
	displayList(list1);


	cout << endl << "Part Two: " << endl;
	Node* list3 = listBuild({ 1,2,3,2,3,2,4,5,6 });
	Node* list4 = listBuild({ 1 });
	cout << "Target: ";
	displayList(list3);
	cout << "Attempt match: 1" << endl;
	Node* check = isSublist(list4, list3);
	testP2(check);

	cout << "Attempt match: 3 9" << endl;
	Node* list5 = listBuild({ 3,9 });
	check = isSublist(list5, list3);
	testP2(check);

	cout << "Attempt match: 2 3" << endl;
	Node* list6 = listBuild({ 2,3 });
	check = isSublist(list6, list3);
	testP2(check);

	cout << "Attempt match: 2 4 5 6" << endl;
	Node* list7 = listBuild({ 2,4,5,6 });
	check = isSublist(list7, list3);
	testP2(check);

	cout << "Attempt match: 2 3 2 4" << endl;
	Node* list8 = listBuild({ 2,3,2,4 });
	check = isSublist(list8, list3);
	testP2(check);

	cout << "Attempt match: 5 6 7" << endl;
	Node* list9 = listBuild({ 5,6,7 });
	check = isSublist(list9, list3);
	testP2(check);
}