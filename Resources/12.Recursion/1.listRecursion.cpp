// 1.listRecursion
// -jbs
//   - A "few' list functions implemented recursively.
//   - listDup may have been done eariler in the semester, but if not,
//     then definitely do it now.


#include <iostream>
#include <vector>
using namespace std;

struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};
Node* buildList(const vector<int>& vals);

//
// recursive list functions
//

// listPrint
void listPrint(Node* p) {
    if (p->next == nullptr) return;
    cout << p->data << ' ';
    listPrint(p->next);
} // listPrint


// listDup
Node* listDup(Node* p) {
    if (p == nullptr) return nullptr;
    // Node* rest = listDup(p->next);
    // Node* first = new Node(p->data);
    // first->next = rest;
    // Node* result = new Node(p->data, listDup(p->next));
    // return first;
    return new Node(p->data, listDup(p->next));
} // listDup

// End of recursive list functions


int main() {
    Node* myList = buildList({1, 1, 2, 3, 5, 8, 13, 21, 34, 55});

    //listPrint(myList);
    //Node* otherList = listDup(myList);
    //listPrint(myList);
    //listPrint(otherList);
}

Node* buildList(const vector<int>& vals) {
    Node* head = nullptr;
    for (size_t i = vals.size(); i > 0; --i) {
        head = new Node(vals[i-1], head);
    }
    return head;
}
