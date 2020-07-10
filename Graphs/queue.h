#pragma once
#include<iostream>
#include <cstddef>
using namespace std;
struct queue
{
	int data;
	struct queue* next;
}*front = NULL, * rear = NULL;

void enqueue(int x)
{
	struct queue* t;
	t = new queue[sizeof(struct queue)];
	if (t == NULL)
	{
		cout << "Memory not available!!!";
	}
	else
	{
		t->data = x;
		t->next = NULL;
		if (front == NULL)
			front = rear = t;
		else
		{
			rear->next = t;
			rear = t;
		}
	}
}

int dequeue()
{
	int x = -1;
	struct queue* t;
	if (front == NULL)
		cout << "queue is empty";
	else
	{
		x = front->data;
		t = front;
		front = front->next;
		delete t;
	}
	return x;
}

int isEmpty()
{
	return front == NULL;
}
