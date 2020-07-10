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
	int n = 9, k;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = k = i; j < n; j++)
		{
			if (a[k] > a[j])
				k = j;
		}
		swap(&a[k], &a[i]);
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}