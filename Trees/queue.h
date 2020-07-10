#pragma once
#include <cstddef>
#include<iostream>
using namespace std;

class node
{
public:
	node* left;
	int data;
	node* right;
};

class queue
{
private:
	int front;
	int rear;
	int size;
	node** Q;

public:
	queue()
	{
		size = 10;
		front = rear = -1;
		Q = new node * [size];
	}

	queue(int size)
	{
		this->size = size;
		front = rear = -1;
		Q = new node * [this->size];
	}

	void enqueue(node* p)
	{
		if (rear == size-1)
			cout << "Queue is full";
		else
		{
			rear++;
			Q[rear] = p;
		}
	}

	node* dequeue()
	{
		node* x = NULL;
		if (front == rear)
			cout << "Queue is empty";
		else
		{
			front++;
			x = Q[front];
		}
		return x;
	}

	int isEmpty()
	{
		if (front == rear)
			return 1;
		return 0;
	}
};