// Prim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define I 32767;
using namespace std;

void Prim(int** G, int n)
{
	int min = I;
	int i, j, u, v, k;
	int near[10];
	int t[2][10];
	for (i = 1; i < 10; i++)
	{
		near[i] = I;
	}
	for (i = 1; i <= n; i++)
	{
		for (j = i; j <= n; j++)
		{
			if (G[i][j] < min)
			{
				min = G[i][j];
				u = i;
				v = j;
			}
		}
	}
	t[0][0] = u;
	t[1][0] = v;
	near[u] = near[v] = 0;
	for (i = 1; i <= n; i++)
	{
		if (near[i] != 0)
		{
			if (G[i][u] < G[i][v])
			{
				near[i] = u;
			}
			else
			{
				near[i] = v;
			}
		}	
	}

	for (i = 1; i < n - 1; i++)
	{
		min = I;
		for (j = 1; j <= n; j++)
		{
			if (near[j] != 0 && G[j][near[j]] < min)
			{
				min = G[j][near[j]];
				k = j;
			}
		}
		t[0][i] = k;
		t[1][i] = near[k];
		near[k] = 0;

		for (j = 1; j <= n; j++)
		{
			if (near[j] != 0 && G[j][k] < G[j][near[j]])
			{
				near[j] = k;
			}
		}
	}
	cout << "The minimun cost spanning tree is : \n";
	for (i = 0; i < n - 1; i++)
	{
		cout << "(" << t[0][i] << ", " << t[1][i] << ")" << endl;
	}
}

int main()
{
	int** G, n, start;
	cout << "Enter the number of nodes : ";
	cin >> n;
	G = new int* [n + 1];
	for (int i = 0; i <= n; i++)
	{
		G[i] = new int[n + 1];
	}
	cout << "\nEnter the cost adjacency matrix of G : ";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << "(" << i << ", " << j << ") : ";
			cin >> G[i][j];
			if (G[i][j] == 0)
			{
				G[i][j] = I;
			}
		}
	}
	Prim(G, n);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
