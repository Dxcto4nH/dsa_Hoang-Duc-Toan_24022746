#include <iostream>
#include "linkedlist.h"
using namespace std;

void initList(LinkedList& L) { //O(1)
    L.head = nullptr;
    L.size = 0;
}

int getList(LinkedList& L, int i) {    //O(n)
    if (i < 0 || i >= L.size) {
        return -1;
    }
    Node* p = L.head;
    for (int k = 0; k < i; k++) {
        p = p->next;
    }
    return p->data;
}

void insertFirstList(LinkedList& L, int value) {    //O(1)
    Node* node = new Node{ value, L.head };
    L.head = node;
    L.size++;
}

void insertLastList(LinkedList& L, int value) {    //O(n)
    Node* node = new Node{ value, nullptr };
    if (L.head == nullptr) {
        L.head = node;
    }
    else {
        Node* p = L.head;
        while (p->next != nullptr) p = p->next;
        p->next = node;
    }
    L.size++;
}

void insertAtList(LinkedList& L, int i, int value) {   //O(n)
    if (i < 0 || i > L.size) {
        return;
    }
    if (i == 0) { 
        insertFirstList(L, value);
        return; 
    } 
    Node* p = L.head;
    for (int k = 0; k < i - 1; k++) {
        p = p->next;
        Node* node = new Node{ value, p->next };
        p->next = node;
        L.size++;
    }
}

void removeFirstList(LinkedList& L) {    //O(1)
    if (L.size == 0) {
        return;
    }
    Node* p = L.head;
    L.head = L.head->next;
    delete p;
    L.size--;
}

void removeLastList(LinkedList& L) {     //O(n)
    if (L.size == 0) {
        return;
    }
    if (L.size == 1) {
        delete L.head;
        L.head = nullptr;
        L.size--;
        return;
    }
    Node* p = L.head;
    while (p->next->next != nullptr) {
        p = p->next;
        delete p->next;
        p->next = nullptr;
        L.size--;
    }
}

void removeAtList(LinkedList& L, int i) {     //0(n)
    if (i < 0 || i >= L.size) {
        return;
    }
    if (i == 0) {
        removeFirstList(L); return;
    }
    Node* p = L.head;
    for (int k = 0; k < i - 1; k++) {
        p = p->next;
        Node* q = p->next;
        p->next = q->next;
        delete q;
        L.size--;
    }
}

void traverseForwardList(LinkedList& L) {     //O(n)
    Node* p = L.head;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void traverseBackwardList(Node* p) {      //O(n)
    if (p == nullptr) {
        return;
    }
    traverseBackwardList(p->next);
    cout << p->data << " ";
}