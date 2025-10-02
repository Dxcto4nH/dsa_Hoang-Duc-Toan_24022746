#include <iostream>
using namespace std;

// ---------------- QUEUE với LIST ----------------
struct Queue {
    int data[100];
    int front, rear, size;
};

// Khởi tạo queue rỗng
void initQueue(Queue& q) {  //O(1)
    q.front = 0;
    q.rear = -1;
    q.size = 0;
}

bool isEmpty(Queue& q) {  //O(1)
    return q.size == 0;
}

void enqueue(Queue& q, int x) { //O(1)
    if (q.size < 100) {
        q.rear = (q.rear + 1) % 100;
        q.data[q.rear] = x;
        q.size++;
    }
    else {
        cout << "Queue day!\n";
    }
}

int dequeue(Queue& q) { //O(1)
    if (!isEmpty(q)) {
        int x = q.data[q.front];
        q.front = (q.front + 1) % 100;
        q.size--;
        return x;
    }
    cout << "Queue rong!\n";
    return -1;
}

int front(Queue& q) { //O(1)
    if (!isEmpty(q)) {
        return q.data[q.front];
    }
    cout << "Queue rong!\n";
    return -1;
}

int size(Queue& q) { //O(1)
    return q.size;
}

// ---------------- QUEUE với LINKED LIST ----------------
struct Node {
	int data;
	Node* next;
};
struct Queue {
	Node* front;
	Node* rear;
	int size;
};
void initQueue(Queue& q) { //O(1)
	q.front = nullptr;
	q.rear = nullptr;
	q.size = 0;
}
bool isEmpty(Queue& q) { //O(1)
	return q.size == 0;
}
void enqueue(Queue& q, int x) {	//O(1)
	Node* newNode = new Node();
	newNode->data = x;
	newNode->next = nullptr;
	if (isEmpty(q)) {
		q.front = newNode;
		q.rear = newNode;
	}
	else {
		q.rear->next = newNode;
		q.rear = newNode;
	}
	q.size++;
}
int dequeue(Queue& q) { //O(1)
	if (!isEmpty(q)) {
		int x = q.front->data;
		Node* temp = q.front;
		q.front = q.front->next;
		delete temp;
		q.size--;
		if (q.size == 0) {
			q.rear = nullptr;
		}
		return x;
	}
	cout << "Queue rong!\n";
	return -1;
}
int top(Queue& q) {	//O(1)
	if (!isEmpty(q)) {
		return q.front->data;
	}
	cout << "Queue rong!\n";
	return -1;
}
int size(Queue& q) { //0(1)
	return q.size;
}