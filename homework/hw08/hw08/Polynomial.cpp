// Doubly linked list

#include <cstdlib>
#include <iostream>
#include <vector>
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
		for (iterator iter = begin(); iter != end(); ++iter) {
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
	friend ostream& operator<<(ostream& os, Polynomial rhs){
		List::iterator iter = --rhs.poly.end();
		int deg = rhs.degree;
		if (deg != 0) {
			for (iter; iter == rhs.poly.begin(); --iter) {
				os << *iter << "x^" << deg--;
				if (iter != rhs.poly.begin()) { os << " + "; }
			}
		}
		else { os << 0; }
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
	Polynomial(vector<int> coeffs) : poly(List()), degree(coeffs.size()-1) {
		if (coeffs.size() == 1 && coeffs.back() == 0) {
			poly.push_back(0);
			degree = 0;
		}
		else {
			for (size_t i = 0; i < coeffs.size(); ++i) {
				poly.push_back(coeffs.back());
				coeffs.pop_back();
			}
		}
	}
	Polynomial(const Polynomial& existingPoly) : poly(List()), 
	degree(existingPoly.degree) {
		for (size_t i = 0; i < existingPoly.poly.size(); ++i) {
			poly[i] = existingPoly.poly[i];
		}
	}
	Polynomial operator+=(const Polynomial& rhs) {
		if (rhs != *this) {
			List::iterator thisIter = poly.begin();
			List::iterator rhsIter = rhs.poly.begin();
			size_t cursor = 0;
			while ((thisIter != poly.end()) && (rhsIter != rhs.poly.end())) {
				poly[cursor] += rhs.poly[cursor];
			}
		}
		return *this;
	}
	Polynomial operator=(const Polynomial& rhs) {
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

	~Polynomial(){}
private:
	List poly;
	int degree;
};

Polynomial operator+(Polynomial& lhs, Polynomial& rhs) {
	return lhs += rhs;
}
