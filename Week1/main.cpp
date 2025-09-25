#include <iostream>
#include "list.h"
#include "linkedlist.h"
using namespace std;

int main() {
    cout << "=== List (Array-based) Demo ===" << endl;
    List A;
    init(A);
    insertLast(A, 1);
    insertLast(A, 2);
    insertLast(A, 3);
    traverseForward(A);

    cout << "=== LinkedList Demo ===" << endl;
    LinkedList L;
    initList(L);
    insertLastList(L, 10);
    insertLastList(L, 20);
    insertLastList(L, 30);
    traverseForwardList(L);

    return 0;
}
