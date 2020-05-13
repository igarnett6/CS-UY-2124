#include <iostream>
using namespace std;

struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

/*
  length/size
  display
  add, remove at front / back / etc.
  clear
  duplicate
 */

// void listDisplay(Node* hp) {
//     //while (hp->next != nullptr) {
//     while (hp != nullptr) {
//         cout << hp->data << ' ';
//         hp = hp->next;
//     }
//     cout << endl;
// }
Node* listDuplicate(Node* hp) {
    // Initialization code
    if (hp == nullptr) return nullptr;

    Node* result = new Node(hp->data);
    Node* p = hp->next;
    Node* last = result;
    // ..

    while (p != nullptr) {
        //Node* next = new Node(p->data);
        //listAddTail(result, p->data);
        last->next = new Node(p->data);
        p = p->next;
        last = last->next;
    }
    return result;
}

Node* listDuplicate2(Node* hp) {
    if (hp == nullptr) return nullptr;
    // Node* rest = listDuplicate2(hp->next);
    // return new Node(hp->data, rest);
    return new Node(hp->data, listDuplicate2(hp->next));
}

void listDisplay(Node* hp) {
    Node* p = hp;
    while (p != nullptr) {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

//int listLength
int listLength(Node* hp) {
    Node* p = hp;
    int count = 0;
    while (p != nullptr) {
        ++count;
        p = p->next;
    }
    return count;
}

void listAddHead(Node*& hp, int data) {
    // // 1. create a node for the data
    // //Node* newNode = new Node(data);
    // Node* p = new Node(data);
    // // 2. make that node point to the original head node
    // p->next = hp;
    // Node* p = new Node(data, hp);
    // // 3. make head pointer point to the new node
    // hp = p;
    hp = new Node(data, hp);
}



//void listAddTail
//bool listRemoveHead(Node* hp) {
bool listRemoveHead(Node*& hp) {
    if (hp == nullptr) return false;
    // 0. keep a temporary to ...
    //Node* second = hp->next;
    Node* victim = hp;
    // 1. make the head pointer point to the second node
    hp = hp->next;
    // 2. get rid of the old head node
    delete victim;
    return true;
 }

//bool listRemoveTail
//void listAdd
//void listRemove
//void listClear
//Node* listDuplicate

Node* listFindTail(Node* hp) {
    if (hp == nullptr) return nullptr;
    Node* p = hp;
    while (p->next != nullptr) {
        p = p->next;
    }
    return p;
}

void listAddTail(Node*& hp, int data) {
    if (hp == nullptr) {
        hp = new Node(data);
    } else {
        Node* tail = listFindTail(hp);
        tail->next = new Node(data);
    }
}

int main() {
    Node* myList = nullptr;
    listDisplay(myList);

    listAddHead(myList, 17);
    myList->next = new Node(28);
    listDisplay(myList);


    listAddHead(myList, 6);
    listDisplay(myList);
}

