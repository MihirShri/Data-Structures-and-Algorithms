#include <iostream>
using namespace std;

struct node
{
    int col;
    int data;
    struct node* next;
}*A[5];

void create(struct node* A[], int a[5][6], int m, int n)
{
    struct node* p, *last;
    for (int i = 0; i < m; i++)
    {
        last = A[i];
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                p = new node[sizeof(struct node)];
                p->col = j;
                p->data = a[i][j];
                p->next = NULL;
                last->next = p;
                last = p;
            }
        }
    }
}

void display(struct node* A[], int a[5][6], int m, int n)
{
    struct node* t;
    for (int i = 0; i < m; i++)
    {
        t = A[i]->next;
        for (int j = 0; j < n; j++)
        {
            if (t != NULL)
            {
                if (j == t->col)
                {
                    cout << t->data << " ";
                    t = t->next;
                }
                else
                    cout << "0 ";
            }
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{
    struct node* A[5];
    for (int i = 0; i < 5; i++)
    {
        A[i] = new node[sizeof(struct node)];
    }
    int a[5][6] = { { 0, 0, 0, 0, 8, 0 },
                    { 0, 0, 0, 7, 0, 0 },
                    { 5, 0, 0, 0, 0, 9 },
                    { 0, 3, 0, 0, 0, 0 },
                    { 6, 4, 0, 0, 0, 0 } };
    create(A, a, 5, 6);
    display(A, a, 5, 6);
    return 0;
}
