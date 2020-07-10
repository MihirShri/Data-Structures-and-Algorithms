#include "queue.h"
#include "stack.h"
using namespace std;

class tree
{
public:
	node* root;
	tree()
	{
		root = NULL;
	}
	void CreateTree();
	void Preorder(node* p);
	void Inorder(node* p);
	void Postorder(node* p);
	void Levelorder(node* p);
	int height(node* root);
	int count(node* root);
};

void tree::CreateTree()
{
	int x;
	node* p, * t;
	queue q(100);
	cout << "Enter root value : ";
	cin >> x;
	root = new node[sizeof(node)];
	root->data = x;
	root->left = root->right = NULL;
	q.enqueue(root);
	while (!q.isEmpty())
	{
		p = q.dequeue();
		cout << "Enter left child of " << p->data << " : ";
		cin >> x;
		if (x != -1)
		{
			t = new node[sizeof(node)];
			t->data = x;
			t->left = t->right = NULL;
			p->left = t;
			q.enqueue(t);
		}
		cout << "Enter right child of " << p->data << " : ";
		cin >> x;
		if (x != -1)
		{
			t = new node[sizeof(node)];
			t->data = x;
			t->left = t->right = NULL;
			p->right = t;
			q.enqueue(t);
		}
	}
}

void tree::Preorder(node* p)
{
	stack st;
	if (p == NULL)
		cout << "Empty";
	else
	{
		while (p != NULL || !st.isEmpty())
		{
			if (p != NULL)
			{
				cout << p->data << " ";
				st.push(p);
				p = p->left;
			}
			else
			{
				p = st.pop();
				p = p->right;
			}
		}
	}
}

void tree::Inorder(node* p)
{
	stack st;
	if (p == NULL)
		cout << "empty";
	else
	{
		while (p != NULL || !st.isEmpty())
		{
			if (p != NULL)
			{
				st.push(p);
				p = p->left;
			}
			else
			{
				p = st.pop();
				cout << p->data << " ";
				p = p->right;
			}
		}
	}
}

void tree::Postorder(node* p)
{
	if (p)
	{
		Postorder(p->left);
		Postorder(p->right);
		cout << p->data << " ";
	}
}

void tree::Levelorder(node* p)
{
	queue q;
	q.enqueue(p);
	cout << p->data;
	while (!q.isEmpty())
	{
		p = q.dequeue();
		if (p->left != NULL)
		{
			cout << p->left->data;
			q.enqueue(p->left);
		}
		if (p->right != NULL)
		{
			cout << p->right->data;
			q.enqueue(p->right);
		}
	}
}

int tree::height(node* root)
{
	int x, y;
	if (root)
	{
		x = height(root->left);
		y = height(root->right);
		if (x > y)
			return x + 1;
		else
			return y + 1;
	}
	return 0;
}

int tree::count(node* root)
{
	int x, y;
	if (root)
	{
		x = count(root->left);
		y = count(root->right);
		return x + y + 1;
	}
	return 0;
}

int main()
{
	tree t;
	t.CreateTree();
	t.Preorder(t.root);
	cout << endl;
	t.Inorder(t.root);
	cout << endl;
	t.Postorder(t.root);
	cout << endl;
	cout << "height = " << t.height(t.root);
	cout << endl;
	cout << "count = " << t.count(t.root);
	return 0;
}