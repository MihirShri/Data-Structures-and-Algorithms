#pragma once
#include <cstddef>
#include <iostream>
using namespace std;

class stack
{
private:
	int top;
	int size;
	node** Q;

public:
	stack()
	{
		size = 10;
		top = -1;
		Q = new node * [size];
	}

	stack(int size)
	{
		this->size = size;
		top = -1;
		Q = new node * [this->size];
	}

	void push(node* p)
	{
		if (top == size - 1)
			cout << "stack is full";
		else
		{
			top++;
			Q[top] = p;
		}
	}

	node* pop()
	{
		node* x = NULL;
		if (top == -1)
			cout << "";
		else
		{
			x = Q[top--];
		}
		return x;
	}

	int isEmpty()
	{
		if (top == -1)
			return 1;
		return 0;
	}
};