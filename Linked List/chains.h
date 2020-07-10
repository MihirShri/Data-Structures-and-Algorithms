#pragma once
#include<iostream>
using namespace std;

struct node
{
	int coeff;
	int exp;
	struct node* next;
}*root1 = NULL, *root2 = NULL;

void create1()
{
	struct node* t, * last = NULL;
	int num;
	cout << "Enter the number of terms : ";
	cin >> num;
	cout << "Enter the coefficient and exponent of each term : ";
	for (int i = 0; i < num; i++)
	{
		t = new node[sizeof(struct node)];
		cout << "\nTerm " << i + 1 << " : ";
		cin >> t->coeff >> t->exp;
		t->next = NULL;
		if (root1 == NULL)
			last = root1 = t;
		else
		{
			last->next = t;
			last = t;
		}
	}
}

void create2()
{
	struct node* t, * last = NULL;
	int num;
	cout << "Enter the number of terms : ";
	cin >> num;
	cout << "Enter the coefficient and exponent of each term : ";
	for (int i = 0; i < num; i++)
	{
		t = new node[sizeof(struct node)];
		cout << "\nTerm " << i + 1 << " : ";
		cin >> t->coeff >> t->exp;
		t->next = NULL;
		if (root2 == NULL)
			last = root2 = t;
		else
		{
			last->next = t;
			last = t;
		}
	}
}

void display(struct node* p)
{
	while (p)
	{
		if (p->next != NULL)
			cout << p->coeff << "x" << p->exp << " + ";
		else
			cout << p->coeff << "x" << p->exp;
		p = p->next;
	}
	cout << endl;
}


