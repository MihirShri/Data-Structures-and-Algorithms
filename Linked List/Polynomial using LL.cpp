#include "chains.h"

int evaluate(struct node* p, int x)
{
	int sum = 0;
	while (p)
	{
		sum += p->coeff * pow(x, p->exp);
		p = p->next;
	}
	return sum;
}

struct node* sum(struct node* p, struct node* q)
{
	struct node* root3 = NULL, * last = NULL;
	while (p && q)
	{
		if (p->exp > q->exp)
		{
			if (root3 == NULL)
			{
				struct node* t = new node[sizeof(struct node)];
				t->coeff = p->coeff;
				t->exp = p->exp;
				t->next = NULL;
				last = root3 = t;
				p = p->next;
			}
			else
			{
				struct node* t = new node[sizeof(struct node)];
				t->coeff = p->coeff;
				t->exp = p->exp;
				t->next = NULL;
				last->next = t;
				last = t;
				p = p->next;
			}
		}
		
		else if (p->exp < q->exp)
		{
			if (root3 == NULL)
			{
				struct node* t = new node[sizeof(struct node)];
				t->coeff = q->coeff;
				t->exp = q->exp;
				t->next = NULL;
				last = root3 = t;
				q = q->next;
			}
			else
			{
				struct node* t = new node[sizeof(struct node)];
				t->coeff = q->coeff;
				t->exp = q->exp;
				t->next = NULL;
				last->next = t;
				last = t;
				q = q->next;
			}
		}

		else
		{
			if (root3 == NULL)
			{
				struct node* t = new node[sizeof(struct node)];
				t->coeff = p->coeff + q->coeff;
				t->exp = p->exp;
				t->next = NULL;
				last = root3 = t;
				p = p->next;
				q = q->next;
			}
			else
			{
				struct node* t = new node[sizeof(struct node)];
				t->coeff = p->coeff + q->coeff;
				t->exp = p->exp;
				t->next = NULL;
				last->next = t;
				last = t;
				p = p->next;
				q = q->next;
			}
		}
	}

	while (p)
	{
		if (root3 == NULL)
		{
			struct node* t = new node[sizeof(struct node)];
			t->coeff = p->coeff;
			t->exp = p->exp;
			t->next = NULL;
			last = root3 = t;
			p = p->next;
		}
		else
		{
			struct node* t = new node[sizeof(struct node)];
			t->coeff = p->coeff;
			t->exp = p->exp;
			t->next = NULL;
			last->next = t;
			last = t;
			p = p->next;
		}
	}

	while (q)
	{
		if (root3 == NULL)
		{
			struct node* t = new node[sizeof(struct node)];
			t->coeff = q->coeff;
			t->exp = q->exp;
			t->next = NULL;
			last = root3 = t;
			q = q->next;
		}
		else
		{
			struct node* t = new node[sizeof(struct node)];
			t->coeff = q->coeff;
			t->exp = q->exp;
			t->next = NULL;
			last->next = t;
			last = t;
			q = q->next;
		}
	}

	return root3;
}

int main()
{
	struct node* temp;
	create1();
	create2();
	display(root1);
	display(root2);
	temp = sum(root1, root2);
	cout << endl;
	while (temp)
	{
		if (temp->next != NULL)
			cout << temp->coeff << "x" << temp->exp << " + ";
		else
			cout << temp->coeff << "x" << temp->exp;
		temp = temp->next;
	}

	return 0;
}