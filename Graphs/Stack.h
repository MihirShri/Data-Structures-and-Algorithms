#pragma once
#include<iostream>
using namespace std;
struct stack
{
	int data;
	struct stack* next;
}*top = NULL;

void push(int x)
{
	struct stack* t;
	t = new stack[sizeof(struct stack)];
	if (t == NULL)
	{
		cout << "Not enough memory";
	}
	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}
}

int pop()
{
	int x = -1;
	struct stack* t;
	if (top == NULL)
		cout << "stack is empty";
	else
	{
		t = top;
		top = top->next;
		x = t->data;
		delete t;
	}
	return x;
}

int isEmpty()
{
	return top == NULL;
}
