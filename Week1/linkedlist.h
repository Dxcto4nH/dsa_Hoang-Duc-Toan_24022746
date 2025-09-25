#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head;
    int size;
};

void initList(LinkedList& L);
int getList(LinkedList& L, int i);
void insertFirstList(LinkedList& L, int value);
void insertLastList(LinkedList& L, int value);
void insertAtList(LinkedList& L, int i, int value);
void removeFirstList(LinkedList& L);
void removeLastList(LinkedList& L);
void removeAtList(LinkedList& L, int i);
void traverseForwardList(LinkedList& L);
void traverseBackwardList(Node* p);

#endif