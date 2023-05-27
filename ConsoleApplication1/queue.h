#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include"bst.h"
using namespace std;

#define maxQue 100

typedef node* Itemtype;
class Queue {
	Itemtype items[maxQue];
	int front, rear, count;
public:
	Queue();
	int IsEmpty();
	int IsFull();
	void Insert(Itemtype newItem);
	void Remove();
};
Queue::Queue() {
	count = front = rear = 0;
}
int Queue::IsEmpty() {
	return (count == 0);
}
int Queue::IsFull() {
	return (count == maxQue);
}

void Queue::Insert(Itemtype newitem) {
	if (IsFull()) {
		cout << "Over Flow";
	}
	else {
		items[rear] = newitem;
		rear = (rear + 1) % maxQue;
		++count;
	}
}

 void Queue::Remove() {
	Itemtype item=NULL;
	if (IsEmpty()) {
		cout << "Under Flow";
	}
	else {
		item = items[front];
		front = (front + 1) % maxQue;
		--count;
	}
	cout << (item->data) <<"\t" << item->num;
	cout << endl;
}

