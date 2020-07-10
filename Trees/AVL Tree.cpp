#include<iostream>
using namespace std;

class node
{
public:
	node* left;
	int data;
	int height;
	node* right;
};

class tree
{
public:
	node* root;
	tree() { root = NULL; }
	node* Insert(node* p, int x);
	void Preorder(node* p);
	void Inorder(node* p);
	void Postorder(node* p);
	int height(node* p);
	int BF(node* p);
	node* LLrotation(node* x);
	node* RRrotation(node* x);
	node* LRrotation(node* x);
	node* RLrotation(node* x);
};

node* tree::Insert(node* p, int x)
{
	node* t;
	if (p == NULL)
	{
		t = new node[sizeof(node)];
		t->data = x;
		t->height = 1;
		t->left = t->right = NULL;
		return t;
	}

	if (x < p->data)
		p->left = Insert(p->left, x);
	else
		p->right = Insert(p->right, x);

	p->height = height(p);
	if (BF(p) == 2 && BF(p->left) == 1)
		return LLrotation(p);
	else if (BF(p) == 2 && BF(p->left) == -1)
		return LRrotation(p);
	else if (BF(p) == -2 && BF(p->right) == -1)
		return RRrotation(p);
	else if (BF(p) == -2 && BF(p->right) == 1)
		return RLrotation(p);
	return p;
}

void tree::Preorder(node* p)
{
	if (p)
	{
		cout << p->data << " ";
		Preorder(p->left);
		Preorder(p->right);
	}
}

void tree::Inorder(node* p)
{
	if (p)
	{
		Inorder(p->left);
		cout << p->data << " ";
		Inorder(p->right);
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

int tree::height(node* p)
{
	int x, y;
	x = p && p->left ? p->left->height : 0;
	y = p && p->right ? p->right->height : 0;
	return x > y ? x + 1 : y + 1;
}

int tree::BF(node* p)
{
	int x, y;
	x = p && p->left ? p->left->height : 0;
	y = p && p->right ? p->right->height : 0;
	return x - y;
}

node* tree::LLrotation(node* x)
{
	node* y = x->left;
	x->left = y->right;
	y->right = x;
	x->height = height(x);
	y->height = height(y);
	if (x == root)
		root = y;

	return y;
}

node* tree::RRrotation(node* x)
{
	node* y = x->right;
	x->right = y->left;
	y->left = x;
	x->height = height(x);
	y->height = height(y);
	if (x == root)
		root = y;

	return y;
}

node* tree::LRrotation(node* x)
{
	x->left = RRrotation(x->left);
	return LLrotation(x);
}

node* tree::RLrotation(node* x)
{
	x->right = LLrotation(x->right);
	return RRrotation(x);
}

int main()
{
	tree t;
	t.root = t.Insert(t.root, 10);
	t.Insert(t.root, 20);
	t.Insert(t.root, 30);
	t.Insert(t.root, 25);
	t.Insert(t.root, 28);
	t.Insert(t.root, 27);
	t.Insert(t.root, 5);
	t.Postorder(t.root);
	cout << endl;
	cout << t.height(t.root);
	return 0;
}