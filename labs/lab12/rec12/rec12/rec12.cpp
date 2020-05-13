// Doubly linked list
//  Test code

#include <cstdlib>
#include <iostream>
using namespace std;




class List {
	friend ostream& operator<<(ostream& os, const List& rhs) {
		Node* cursor = rhs.header->next;
		while (cursor != rhs.trailer) {
			os << cursor->data << " ";
			cursor = cursor->next;
		}
		os << endl;
		return os;
	}
private:
	struct Node {
		Node(int data = -1, Node* prev = nullptr, Node* next = nullptr) : next(next), prev(prev), data(data) { }
		Node* next;
		Node* prev;
		int data;
	};
	
public:
	List() : numElems(0), header(new Node()), trailer(new Node()) {
		header->next = trailer;
		trailer->prev = header;
	}
	void push_back(int data) {
		Node* newNode = new Node(data);
		newNode->next = trailer;
		newNode->prev = trailer->prev;
		trailer->prev->next = newNode;
		trailer->prev = newNode;
		numElems += 1;
	}
	void push_front(int data) {
		Node* newNode = new Node(data);
		newNode->next = header->next;
		newNode->prev = header;
		header->next->prev = newNode;
		header->next = newNode;
		numElems += 1;
	}
	int front() const {
		if (header->next != trailer) {
			return header->next->data;
		}
		cerr << "The list is empty. ";
		exit(1);
	}
	int& front() {
		if (header->next != trailer) {
			return header->next->data;
		}
		cerr << "The list is empty. ";
		exit(2);
	}
	int back() const {
		if (numElems != 0) {
			return trailer->prev->data;
		}
		cerr << "The list is empty. ";
		exit(3);
	}
	int& back() {
		if (numElems != 0) {
			return trailer->prev->data;
		}
		cerr << "The list is empty.";
		exit(4);
	}
	int pop_back() {
		if (numElems != 0) {
			const int res = back();
			Node* removing = trailer->prev;
			removing->prev->next = trailer;
			trailer->prev = removing->prev;
			delete removing;
			numElems -= 1;
			return res;
		}
		cerr << "The list is empty. ";
		exit(5);
	}
	int pop_front() {
		if (numElems != 0) {
			const int res = front();
			Node* removing = header->next;
			removing->next->prev = header;
			header->next = removing->next;
			delete removing;
			numElems -= 1;
			return res;
		}
		cerr << "The list is empty. ";
		exit(6);
	}
	void clear() {
		while (numElems != 0) {
			pop_back();
		}
	}
	size_t size() const { return numElems; }
	int operator[](size_t i) const {
		if (i > numElems) { cerr << "Index out of range."; exit(7); }
		Node* cursor = header->next;
		while (i != 0) {
			cursor = cursor->next;
			i--;
		}
		return cursor->data;
	}
	int& operator[](size_t i)  {
		if (i > numElems) { cerr << "Index out of range."; exit(8); }
		Node* cursor = header->next;
		while (i != 0) {
			cursor = cursor->next;
			i--;
		}
		return cursor->data;
	}
	class iterator {
		friend class List;
		friend bool operator==(const iterator& lhs, const iterator& rhs) {
			if (lhs.currNode == rhs.currNode) {
				return true;
			}
			return false;
		}
		friend bool operator!=(const iterator& lhs, const iterator& rhs) {
			return !(rhs==lhs);
		}
	public:
		iterator(Node* currNode = nullptr) : currNode(currNode) {}
		iterator& operator++() {
			if (currNode->next) {
				currNode = currNode->next;
				return *this;
			}
			cerr << "Index out of bounds.";
			exit(7);
		}
		iterator& operator--() {
			if (currNode->prev) {
				currNode = currNode->prev;
				return *this;
			}
			cerr << "Index out of bounds";
			exit(8);
		}
		int operator*() {
			return currNode->data;
		}
	private:
		Node* currNode;
	};
	iterator erase(iterator thisNode) {
		thisNode.currNode->prev->next = thisNode.currNode->next;
		thisNode.currNode->next->prev = thisNode.currNode->prev;
		delete thisNode.currNode;
		return ++thisNode;
	}
	iterator insert(iterator addBefore, int data) {
		Node* newNode;
		newNode = new Node(data);
		newNode->next = addBefore.currNode;
		newNode->prev = addBefore.currNode->prev;
		addBefore.currNode->prev = newNode;
		newNode->prev->next = newNode;
		++numElems;
		return addBefore;
	}
	iterator begin() {
		iterator res = iterator(header->next);
		return res;
	}
	iterator end() {
		iterator res = iterator(trailer);
		return res;
	}

private:
	Node* header;
	Node* trailer;
	size_t numElems;
	iterator iter;
};




// Task 1
void printListInfo(const List& myList) {
        cout << "size: " << myList.size()
             << ", front: " << myList.front()
             << ", back(): " << myList.back()
             << ", list: " << myList << endl;
}

// The following should not compile. Check that it does not.
 //void changefrontandbackconst(const list& thelist){
 //    thelist.front() = 17;
 //    thelist.back() = 42;
 //}

void changeFrontAndBack(List& theList){
    theList.front() = 17;
    theList.back() = 42;
}

//// Task 4
void printListSlow(const List& myList) {
    for (size_t i = 0; i < myList.size(); ++i) {
        cout << myList[i] << ' ';
    }
    cout << endl;
}
//
//// Task 8
//void doNothing(List aList) {
//    cout << "In doNothing\n";
//    printListInfo(aList);
//    cout << endl;
//    cout << "Leaving doNothing\n";
//}    
//
int main() {

    // Task 1
    cout << "\n------Task One------\n";
    List myList;
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList.push_back(" << i*i << ");\n";
        myList.push_back(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    
    cout << "Modify the first and last items, and display the results\n";
    changeFrontAndBack(myList);
    printListInfo(myList);
    cout << "===================\n";

    cout << "Remove the items with pop_back\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_back();
    }
    cout << "===================\n";
//
//    // Task 2
    cout << "\n------Task Two------\n";
    cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList2.push_front(" << i*i << ");\n";
        myList.push_front(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_front\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_front();
    }
    cout << "===================\n";
//
//    // Task 3
    cout << "\n------Task Three------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        myList.push_back(i*i);
    }
    printListInfo(myList);
    cout << "Now clear\n";
    myList.clear();
    cout << "Size: " << myList.size() << ", list: " << myList << endl;
    cout << "===================\n";

//    // Task 4
    cout << "\n------Task Four------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    cout << "Display elements with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Add one to each element with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
    cout << "And print it out again with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Now calling a function, printListSlow, to do the same thing\n";
    printListSlow(myList);
    cout << "Finally, for this task, using the index operator to modify\n"
         << "the data in the third item in the list\n"
         << "and then using printListSlow to display it again\n";
    myList[2] = 42;
    printListSlow(myList);
    

//    // Task 5
    cout << "\n------Task Five------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    printListInfo(myList);
    cout << "Now display the elements in a ranged for\n";
    for (int x : myList) cout << x << ' ';
    cout << endl;
    cout << "And again using the iterator type directly:\n";
    // Note you can choose to nest the iterator class or not, your choice.
    //for (iterator iter = myList.begin(); iter != myList.end(); ++iter) {
    for (List::iterator iter = myList.begin(); iter != myList.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
    cout << "WOW!!! (I thought it was cool.)\n";
//    
//    // Task 6
    cout << "\n------Task Six------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Filling an empty list with insert at begin(): "
         << "i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
    printListInfo(myList);
    // ***Need test for insert other than begin/end***
    cout << "===================\n";
//
//    // Task 7
    cout << "\n------Task Seven------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    cout << "Erasing the elements in the list, starting from the beginning\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.erase(myList.begin());
    }
    // ***Need test for erase other than begin/end***
    cout << "===================\n";
//
//    // Task 8
//    cout << "\n------Task Eight------\n";
//    cout << "Copy control\n";
//    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
//    myList.clear();
//    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
//    printListInfo(myList);
//    cout << "Calling doNothing(myList)\n";
//    doNothing(myList);
//    cout << "Back from doNothing(myList)\n";
//    printListInfo(myList);
//
//    cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
//    List listTwo;
//    for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i*i);
//    printListInfo(listTwo);
//    cout << "listTwo = myList\n";
//    listTwo = myList;
//    cout << "myList: ";
//    printListInfo(myList);
//    cout << "listTwo: ";
//    printListInfo(listTwo);
//    cout << "===================\n";
}
