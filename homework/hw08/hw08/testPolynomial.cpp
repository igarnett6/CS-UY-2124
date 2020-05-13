//#include "polynomial.h"
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


// Doubly linked list


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
		Node(int data = 0, Node* prev = nullptr, Node* next = nullptr) : next(next), prev(prev), data(data) { }
		Node* next;
		Node* prev;
		int data;
	};
public:
	List() : numElems(0), header(new Node()), trailer(new Node()) {
		header->next = trailer;
		trailer->prev = header;
	}
	List(vector<int> data) : numElems(0), header(new Node()), trailer(new Node) {
		header->next = trailer;
		trailer->prev = header;
		for (size_t i = 0; i < data.size(); i++) {
			push_back(data[i]);
			//cout << "in constructor loop" << endl;
		}
		//cout << "New list created: " << *this << endl;
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
	int& operator[](size_t i) {
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
			return !(rhs == lhs);
		}
	public:
		iterator(Node * currNode = nullptr) : currNode(currNode) {}
		iterator& operator++() {
			if (currNode->next) {
				currNode = currNode->next;
				return *this;
			}
			std::cerr << "Index out of bounds.";
			exit(7);
		}
		iterator& operator--() {
			if (currNode->prev) {
				currNode = currNode->prev;
				return *this;
			}
			std::cerr << "Index out of bounds";
			exit(23);
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
	iterator begin() const {
		iterator res = iterator(header->next);
		return res;
	}
	iterator end() const {
		iterator res = iterator(trailer);
		return res;
	}
	size_t size() { return numElems; }
	List& operator=(const List& rhs) {
		if (this != &rhs) {
			for (iterator iter = begin(); iter != end(); ++iter) {
				delete iter.currNode;
			}
			for (iterator iter = rhs.begin(); iter != rhs.end(); ++iter) {
				push_back(*iter);
			}
		}
		return *this;
	}
	List(const List& oldList) :
		numElems(oldList.numElems), header(oldList.header), trailer(oldList.trailer) {
		for (iterator iter = oldList.begin(); iter != oldList.end(); ++iter) {
			push_back(*iter);
		}
	}
	~List() {
		for (iterator iter = begin(); iter == end(); ++iter) {
			delete iter.currNode;
		}
	}
private:
	Node* header;
	Node* trailer;
	size_t numElems;
	iterator iter;
};

class Polynomial {
	friend ostream& operator<<(ostream& os, Polynomial rhs) {
		List::iterator iter = rhs.poly.begin();
		int deg = rhs.degree;
		if (deg != 0) {
			for (iter; iter != rhs.poly.end(); ++iter) {
				if (deg != 0 && *iter != 0) {
					if (deg != 1) {
						os << *iter << "x^" << deg--;
					}
					else if(*iter != 1) { os << *iter << "x"; deg--; }
					else { os << "x"; deg--; }
				}
				else if(*iter != 0){ 
					os << *iter; 
				}
				else { deg--; }
				if (iter != --rhs.poly.end()) { os << " + "; }
			}
		}
		else { os << *rhs.poly.begin(); }
		os << endl;
		return os;
	}
	friend bool operator==(const Polynomial& lhs, const Polynomial& rhs) {
		if (lhs.degree != rhs.degree) { return false; }
		List::iterator lhsCursor = lhs.poly.begin();
		List::iterator rhsCursor = rhs.poly.begin();
		for (lhsCursor; lhsCursor != lhs.poly.end(); ++lhsCursor) {
			if (*lhsCursor != *rhsCursor) {
				return false;
			}
			++rhsCursor;
		}
		return true;
	}
	friend bool operator!=(const Polynomial& lhs, const Polynomial& rhs) {
		return !(lhs == rhs);
	}
public:
	Polynomial() : poly(List()), degree(0) {}
	Polynomial(vector<int> coeffs) : poly(List(coeffs)), degree(coeffs.size() - 1) {}
	Polynomial(const Polynomial& existingPoly) : poly(List()),
		degree(existingPoly.degree) {
		for (size_t i = 0; i < existingPoly.poly.size(); i++) {
			poly.push_back(existingPoly.poly[i]);
		}
	}
	Polynomial operator+=(const Polynomial & rhs) {
		if (rhs != *this) {
		/*	List::iterator thisIter = --poly.end();
			List::iterator rhsIter = --rhs.poly.end();*/
			size_t cursor;
			if (poly.size() < rhs.poly.size()) {
				cursor = poly.size();
			}
			else {
				cursor = rhs.poly.size();
			}
			while (cursor != 0) {
				poly[poly.size()-cursor] += rhs.poly[rhs.poly.size()-cursor];
				--cursor;
			}
		}
		return *this;
	}
	Polynomial operator=(const Polynomial & rhs) {
		return (*this += rhs);
	}
	int evaluate(int x) {
		if (degree == 0) { return *poly.begin(); }
		int res = 0;
		int currDeg = 1;
		List::iterator iter = poly.begin();
		for (iter; iter != poly.end(); ++iter) {
			for (int i = 1; i <= currDeg; ++i) {
				res += currDeg * *iter;
			}
		}
		return res;
	}

	~Polynomial() {}
private:
	List poly;
	int degree;
};

Polynomial operator+(Polynomial & lhs, Polynomial & rhs) {
	return lhs += rhs;
}


void doNothing(Polynomial temp) {}

int main() {
	
    //test constructor
    Polynomial p1({17});                 // 17
    Polynomial p2({1, 2});               // x + 2
    Polynomial p3({-1, 5});              // -1x + 5
    Polynomial p4({5, 4, 3, 2, 1});      // 5x^4 + 4x^3 + 3x^2 + 2x + 1
    Polynomial has_a_zero({4, 0, 1, 7}); // 4x^3 + x + 7
	
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p3: " << p3 << endl;
    cout << "p4: " << p4 << endl;
    cout << "has_a_zero: " << has_a_zero << endl;
    cout << "p2 + p3: " << (p2+p3) << endl; 
    cout << "p2 + p4: " << (p2+p4) << endl; 
    cout << "p4 + p2: " << (p4+p2) << endl;


    //test copy constructor - the statement below uses the copy constructor
    //to initialize poly3 with the same values as poly4
    Polynomial p5(p4);
    p5 += p3;
    cout << "Polynomial p5(p4);\n"
         << "p5 += p3;\n";

    cout << "p4: " << p4 << endl;  
    cout << "p5: " << p5 << endl;  

    cout << "Calling doNothing(p5)\n";
    doNothing(p5);
    cout << "p5: " << p5 << endl;

    //tests the assignment operator
    Polynomial p6;
    cout << "p6: " << p6 << endl;
    cout << boolalpha;  // Causes bools true and false to be printed that way.
    cout << "(p4 == p6) is " << (p4 == p6) << endl;
    p6 = p4;
    cout << "p6: " << p6 << endl;
    cout << boolalpha;
    cout << "(p4 == p6) is " << (p4 == p6) << endl;

    //test the evaluaton
    int x = 5;
    cout << "Evaluating p1 at " << x << " yields: " << p1.evaluate(5) << endl;
    cout << "Evaluating p2 at " << x << " yields: " << p2.evaluate(5) << endl;
	
    Polynomial p7({3, 2, 1});           // 3x^2 + 2x + 1
    cout << "p7: " << p7 << endl;
    cout << "Evaluating p7 at " << x << " yields: " << p7.evaluate(5) << endl;

    cout << boolalpha;
    cout << "(p1 == p2) is " << (p1 == p2) << endl;
    cout << "(p1 != p2) is " << (p1 != p2) << endl;

	/*=================================================================
	NEW TEST CODE - test if cleaning the leading 0s
	===================================================================*/

	Polynomial p8({ 1, 1 });
	Polynomial p9({ -1, 1 });
	Polynomial p10({ 0, 0, 2 });
	//p8 + p9 tests if += does the cleanup()
	//p10 tests if constructor does the cleanup()
	cout << "((p8 + p9) == p10) is " << ((p8 + p9) == p10) << endl;

    
}


