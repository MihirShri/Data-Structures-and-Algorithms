#include <iostream>
using namespace std;

struct node
{
    struct node* prev;
    int data;
    struct node* next;
}*head = NULL;

void create(int a[], int n)
{
    struct node* t,*last;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = a[0];
    head->next = head;
    head->prev = head;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = (struct node*)malloc(sizeof(struct node));
        t->data = a[i];
        t->prev = last;
        last->next = t;
        t->next = head;
        head->prev = t;
        last = t;
    }
}

void display(struct node* p)
{
    struct node* q = p;
    if (q)
    {
        do
        {
            cout << q->data << " ";
            q = q->next;
        } while (q != p);
    }
    else
        cout << "Empty!!!";
}

void insert(struct node* p, int pos, int x)
{
    struct node* t, *q = p;
    int i;
    if (pos == 0)
    {
        t = new struct node[sizeof(struct node)];
        t->data = x;
        if (head)
        {
            t->next = head;
            t->prev = head->prev;
            head->prev->next = t;
            head->prev = t;
        }
        else
        {
            head = t;
            head->next = head;
            head->prev = head;
        }
        head = t;
    }
    else
    {
        t = new struct node[sizeof(struct node)];
        t->data = x;
        for (i = 0; i < pos - 1; i++)
            q = q->next;
        t->next = q->next;
        t->prev = q;
        if (q->next)
            q->next->prev = t;
        q->next = t;
    }
}

int Delete(struct node* p, int pos)
{
    struct node* q = p;
    int x;
    if (pos == 1)
    {
        head = head->next;
        if (head)
        {
            head->prev = p->prev;
            p->prev->next = head;
        }
        x = p->data;
        delete p;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
            p = p->next;
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}

int main()
{
    int a[] = { 2, 5, 18, 7, 3 };
    int n = 5;
    //create(a, n);
    insert(head, 0, 2);
    insert(head, 1, 5);
    insert(head, 2, 18);
    insert(head, 1, 3);
    display(head);
    //cout << "\n";
    //Delete(head, 5);
    //cout << "\n";
    //display(head);
    return 0;
}

