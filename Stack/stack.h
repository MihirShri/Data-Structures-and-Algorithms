#pragma once
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    char data;
    struct Node* next;
}*top = NULL;

void push(char x)
{
    struct Node* t;
    t = (struct Node*)malloc(sizeof(struct Node));

    if (t == NULL)
        printf("stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }

}
char pop()
{
    struct Node* t;
    char x = -1;

    if (top == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}
void Display()
{
    struct Node* p;
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

char stacktop()
{
    return top->data;
}

int isEmpty()
{
    if (top == NULL)
        return 1;
    return 0;
}