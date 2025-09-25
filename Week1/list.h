#ifndef LIST_H
#define LIST_H

struct List {
    int data[100];
    int size;
};

// Khởi tạo
void init(List& L);

// Truy cập
int get(List& L, int i);

// Chèn
void insertFirst(List& L, int x);
void insertLast(List& L, int x);
void insertAt(List& L, int i, int x);

// Xóa
void removeFirst(List& L);
void removeLast(List& L);
void removeAt(List& L, int i);

// Duyệt
void traverseForward(List& L);
void traverseBackward(List& L);

#endif