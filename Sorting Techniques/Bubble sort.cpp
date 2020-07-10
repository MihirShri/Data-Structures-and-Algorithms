#include <iostream>
using namespace std;

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void main()
{
	int a[] = { 9, 5, 2, 7, 6, 4, 8, 1, 3 };
	int n = 9;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
				swap(&a[j], &a[j + 1]);
		}
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}