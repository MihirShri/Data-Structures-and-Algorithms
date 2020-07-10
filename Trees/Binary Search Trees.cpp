#include<iostream>
using namespace std;

class node
{
public:
	node* left;
	int data;
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
	int height(node* root);
	node* InPre(node* p);
	node* Insucc(node* p);
	node* Delete(node* p, int x);
};

node* tree::Insert(node* p, int x)
{
	node* t;
	if (p == NULL)
	{
		t = new node[sizeof(node)];
		t->data = x;
		t->left = t->right = NULL;
		return t;
	}

	if (x < p->data)
		p->left = Insert(p->left, x);
	else
		p->right = Insert(p->right, x);

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

node* tree::InPre(node* p)
{
	if (p && p->right)
		p = p->right;
	return p;
}

node* tree::Insucc(node* p)
{
	if (p && p->left)
		p = p->left;
	return p;
}

node* tree::Delete(node* p, int x)
{
	node* q;
	if (p == NULL)
		return NULL;
	if (p->left == NULL && p->right == NULL)
	{
		if (p == root)
			root = NULL;
		delete p;
		return NULL;
	}
	if (x < p->data)
		p->left = Delete(p->left, x);
	else if (x > p->data)
		p->right = Delete(p->right, x);
	else
	{
		if (height(p->left) > height(p->right))
		{
			q = InPre(p->left);
			p->data = q->data;
			p->left = Delete(p->left, q->data);
		}
		else
		{
			q = Insucc(p->right);
			p->data = q->data;
			p->right = Delete(p->right, q->data);
		}
	}
	return p;
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