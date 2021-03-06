// BFS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "queue.h"
using namespace std;

int n;

void BFS(int** G, int start, int n)
{
    int i = start, u, v;
    int visited[10] = { 0 };
    cout << i << endl;
    visited[i] = 1;
    enqueue(i);
    while (!isEmpty())
    {
        u = dequeue();
        for (v = 1; v <= n; v++)
        {
            if (G[u][v] == 1 && visited[v] == 0)
            {
                cout << v << endl;
                visited[v] = 1;
                enqueue(v);
            }
        }
    }
}

void cycle(int** G, int start, int n)
{
    int i = start, u, v, flag = 0;
    int visited[10] = { 0 };
    visited[i] = 1;
    enqueue(i);
    while (!isEmpty())
    {
        u = dequeue();
        for (v = 1; v <= n; v++)
        {
            if (G[u][v] == 1 && visited[v] == 1 && visited[u] == 1)
            {
                cout << "Cycle is present";
                flag = 1;
                break;
            }
            if (G[u][v] == 1 && visited[v] == 0)
            {
                cout << v << endl;
                visited[v] = 1;
                enqueue(v);
            }
        }
        if (flag == 1)
            break;
    }
    if (flag == 0)
        cout << "No cycle";
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
    cout << "\nEnter the adjacency matrix of G : ";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << "(" << i << ", " << j << ") : ";
            cin >> G[i][j];
        }
    }
    cout << "Enter the starting vertex : ";
    cin >> start;
    cycle(G, start, n);
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
