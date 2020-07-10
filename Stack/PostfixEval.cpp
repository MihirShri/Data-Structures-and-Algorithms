#include "stack.h"

int isOperand(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/')
		return 0;
	else
		return 1;
}

int PostEval(char postfix[])
{
	int i, op1, op2, r;
	for (int i = 0; postfix[i] != '\0'; i++)
	{
		if (isOperand(postfix[i]))
			push(postfix[i] - '0');
		else
		{
			op2 = pop();
			op1 = pop();
			switch (postfix[i])
			{
			case '+': r = op1 + op2;
				break;
			case '-': r = op1 - op2;
				break;
			case '*': r = op1 * op2;
				break;
			case '/': r = op1 / op2;
				break;
			}
			push(r);
		}
	}
	return pop();
}

int main()
{
	char postfix[] = "35*62/+4+";
	printf("%d", PostEval(postfix));
	return 0;
}