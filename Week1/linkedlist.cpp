#include <iostream>
using namespace std;

// ---------------- STACK với LIST ----------------
struct Stack {
    int data[100]; // mảng chứa dữ liệu
    int size;      // số phần tử hiện tại
};

// Khởi tạo stack rỗng
void initStack(Stack& s) {
    s.size = 0;
}

bool isEmpty(Stack& s) {
    return s.size == 0;
}

void push(Stack& s, int x) {
    if (s.size < 100) {
        s.data[s.size++] = x;
    }
    else {
        cout << "Stack day!\n";
    }
}

int pop(Stack& s) {
    if (!isEmpty(s)) {
        return s.data[--s.size];
    }
    cout << "Stack rong!\n";
    return -1;
}

int top(Stack& s) {
    if (!isEmpty(s)) {
        return s.data[s.size - 1];
    }
    cout << "Stack rong!\n";
    return -1;
}

int size(Stack& s) {
    return s.size;
}

// ---------------- STACK với LINKED LIST ----------------
struct Node {
    int data;
    Node* next;
};

// Stack
struct Stack {
    Node* top;
    int size;
};

void initStack(Stack& s) {
    s.top = nullptr;
    s.size = 0;
}

bool isEmpty(Stack& s) {
    return s.top == nullptr;
}

void push(Stack& s, int x) {
    Node* p = new Node{ x, s.top };
    s.top = p;
    s.size++;
}

int pop(Stack& s) {
    if (!isEmpty(s)) {
        Node* p = s.top;
        int x = p->data;
        s.top = p->next;
        delete p;
        s.size--;
        return x;
    }
    cout << "Stack rong!\n";
    return -1;
}

int top(Stack& s) {
    if (!isEmpty(s)) return s.top->data;
    cout << "Stack rong!\n";
    return -1;
}

int size(Stack& s) {
    return s.size;
}