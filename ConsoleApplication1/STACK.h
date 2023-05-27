#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include <iostream>
#include"bst.h"
using namespace std;

template <class ItemType>
class stack {
private:
	int top;
	int maxstack;
	ItemType* items;
public:
	stack();
	stack(int max);
	~stack();
	char stacktop();
	int isFull() const;
	int isEmpty() const;
	void Push(ItemType);
	void Pop(ItemType&);
};
template <class ItemType>
stack<ItemType>::stack()
{
	maxstack = 500;
	top = -1;
	items = new ItemType[500];
}
template <class ItemType>
stack<ItemType>::stack(int max)
{
	maxstack = max;
	top = -1;
	items = new ItemType[max];
}
template <class ItemType>
stack<ItemType>::~stack()
{
	delete[]items;
}
template <class ItemType>
char stack<ItemType>::stacktop()
{
	char x = items[top];
	return (x);
}
template <class ItemType>
int stack<ItemType>::isFull() const
{
	return(top == maxstack - 1);
}
template <class ItemType>
int stack<ItemType>::isEmpty() const
{
	return(top == -1);
}
template <class ItemType>
void stack<ItemType>::Push(ItemType item)
{
	if (isFull())
	{
		cout << "stack overflow" << endl;
		exit(1);
	}
	top++;
	items[top] = item;
}
template <class ItemType>
void stack<ItemType>::Pop(ItemType& item)
{
	if (isEmpty())
	{
		cout << "stack underflow" << endl;
		exit(1);
	}
	else {

		item = items[top];
		top--;
		
	}
}

