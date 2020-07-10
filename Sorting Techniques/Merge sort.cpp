#include <iostream>
using namespace std;

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void merge(int a[], int l, int mid, int h)
{
	int i = l, j = mid + 1, k = l;
	int b[10];
	while (i <= mid && j <= h)
	{
		if (a[i] < a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}

	for (; i <= mid; i++)
		b[k++] = a[i];
	for (; j <= h; j++)
		b[k++] = a[j];

	for (i = l; i <= h; i++)
		a[i] = b[i];
}

void MergeSort(int a[], int l, int h)
{
	if (l < h)
	{
		int mid = (l + h) / 2;
		MergeSort(a, l, mid);
		MergeSort(a, mid + 1, h);
		merge(a, l, mid, h);
	}
}

void IMergeSort(int a[], int n)
{
	int p, i, l, mid, h;
	for (p = 2; p <= n; p *= 2)
	{
		for (i = 0; i + p - 1 < n; i = i + p)
		{
			l = i;
			h = i + p - 1;
			mid = (l + h) / 2;
			merge(a, l, mid, h);
		}
	}
	if (p / 2 < n)
		merge(a, 0, p / 2 - 1, n - 1);
}

void main()
{
	int a[100] = { 9, 5, 2, 7, 6, 4,10 , 8, 1, 3 };
	int n = 10;
	IMergeSort(a, 10);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}