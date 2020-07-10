#include"StackClass.h"

stack stk1, stk2;

void enqueue(int x)
{
	stk1.push(x);
}

int dequeue()
{
	if (stk2.isEmpty())
	{
		if (stk1.isEmpty())
			cout << "Queue is empty";
		else
		{
			while (!stk1.isEmpty())
				stk2.push(stk1.pop());
		}
	}
	return stk2.pop();
}

int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	cout << dequeue() << endl;
	enqueue(50);
	enqueue(60);
	cout << dequeue() << endl;
	cout << dequeue() << endl;

	return 0;
}