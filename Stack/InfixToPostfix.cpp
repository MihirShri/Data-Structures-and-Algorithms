#include "stack.h"
#include<string.h>

int isOperand(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')' || x == '^')
		return 0;
	else
		return 1;
}

int pre(char x)
{
	if (x == '+' || x == '-')
		return 1;
	else if (x == '*' || x == '/')
		return 2;
	return 0;
}

int Opre(char x)
{
	if (x == '+' || x == '-')
		return 1;
	if (x == '*' || x == '/')
		return 3;
	if (x == '^')
		return 6;
	if (x == '(')
		return 7;
	if (x == ')')
		return 0;
	return -1;
}

int Ipre(char x)
{
	if (x == '+' || x == '-')
		return 2;
	if (x == '*' || x == '/')
		return 4;
	if (x == '^')
		return 5;
	if (x == '(')
		return 0;
	return -1;
}

char* InToPost(char infix[])
{
	char* postfix = new char[strlen(infix) + 1];
	int i = 0, j = 0;

	while (infix[i] != '\0')
	{
		if (isOperand(infix[i]))
			postfix[j++] = infix[i++];
		else
		{
			if (pre(infix[i]) > pre(stacktop()))
				push(infix[i++]);
			else
				postfix[j++] = pop();
		}
	}

	while(!isEmpty())
		postfix[j++] = pop();

	postfix[j] = '\0';

	return postfix;
}

char* InToPostAdvanced(char infix[])
{
	char* postfix = new char[strlen(infix) + 1];
	int i = 0, j = 0;

	while (infix[i] != '\0')
	{
		if (isOperand(infix[i]))
			postfix[j++] = infix[i++];
		else
		{
			if (Opre(infix[i]) > Ipre(stacktop()))
				push(infix[i++]);
			else if (Opre(infix[i]) == Ipre(stacktop()))
				pop();
			else
				postfix[j++] = pop();
		}
	}

	while (!isEmpty())
		postfix[j++] = pop();

	postfix[j] = '\0';

	return postfix;
}

int main()
{
	char infix[] = "((a+b)*c)-d^e^f";
	push('#');
	char* postfix = InToPostAdvanced(infix);
	for (int i = 0; postfix[i] != ')'; i++)
		printf("%c", postfix[i]);
	return 0;
}