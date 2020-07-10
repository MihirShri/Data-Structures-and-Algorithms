#pragma once
#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
};

class stack
{
private:
	node* top;
public:
	stack()
	{
		top == NULL;
	}

	void push(int x)
	{
		node* t = new node[sizeof(node)];
		if (t == NULL)
			cout << "Stack is full";
		else
		{
			t->data = x;
			t->next = top;
			top = t;
		}
	}

	int pop()
	{
		int x;
		node* p = NULL;
		if (top == NULL)
			cout << "Stack is empty";
		else
		{
			p = top;
			top = top->next;
			x = p->data;
			delete p;
		}
		return x;
	}

	void display()
	{
		node* p = top;
		while (p)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}

	int isEmpty()
	{
		if (top == NULL)
			return 1;
		return 0;
	}
};