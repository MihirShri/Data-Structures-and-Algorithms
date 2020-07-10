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
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		int x = a[i];
		while (j > -1 && x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}