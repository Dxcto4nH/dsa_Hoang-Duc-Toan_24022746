#include <iostream>
#include "list.h"
using namespace std;

void init(List& L) { L.size = 0; }

int get(List& L, int i) {
    if (i < 0 || i >= L.size) return -1;
    return L.data[i];
}

void insertFirst(List& L, int x) {
    for (int j = L.size; j > 0; j--)
        L.data[j] = L.data[j - 1];
    L.data[0] = x;
    L.size++;
}

void insertLast(List& L, int x) {
    L.data[L.size++] = x;
}

void insertAt(List& L, int i, int x) {
    if (i < 0 || i > L.size) return;
    for (int j = L.size; j > i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i] = x;
    L.size++;
}

void removeFirst(List& L) {
    if (L.size == 0) return;
    for (int j = 0; j < L.size - 1; j++)
        L.data[j] = L.data[j + 1];
    L.size--;
}

void removeLast(List& L) {
    if (L.size == 0) return;
    L.size--;
}

void removeAt(List& L, int i) {
    if (i < 0 || i >= L.size) return;
    for (int j = i; j < L.size - 1; j++)
        L.data[j] = L.data[j + 1];
    L.size--;
}

void traverseForward(List& L) {
    for (int j = 0; j < L.size; j++)
        cout << L.data[j] << " ";
    cout << endl;
}

void traverseBackward(List& L) {
    for (int j = L.size - 1; j >= 0; j--)
        cout << L.data[j] << " ";
    cout << endl;
}