#include <iostream>
using namespace std;

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int a[], int l, int h)
{
	int i = l;
	int j = h;
	int pivot = a[l];
	do
	{
		do { i++; } while (a[i] <= pivot);
		do { j--; } while (a[j] > pivot);
		if (i < j)
			swap(&a[i], &a[j]);
	} while (i < j);
	swap(&a[l], &a[j]);
	return j;
}

void Quick(int a[], int l, int h)
{
	int j;
	if (l < h)
	{
		j = partition(a, l, h);
		Quick(a, l, j);
		Quick(a, j + 1, h);
	}
}

void main()
{
	int a[] = { 9, 5, 2, 7, 6, 4, 8, 1, 3, INT32_MAX };
	int n = 10;
	Quick(a, 0, 9);
	for (int i = 0; i < n - 1; i++)
		cout << a[i] << " ";
}