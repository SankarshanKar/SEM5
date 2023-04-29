#include <bits/stdc++.h>
using namespace std;

void printPar(int *s, int i, int j, int n, char &name)
{
    if (i == j)
    {
        cout << name;
        name++;
        return;
    }
    cout << "(";
    printPar(s, i, *((s + i * n) + j), n, name);
    printPar(s, *((s + i * n) + j) + 1, j, n, name);
    cout << ")";
}

void MatrixChainOrder(int p[], int n)
{

    int m[n][n] = {0};
    int s[n][n] = {0};

    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (int d = 1; d < n; d++)
    {
        for (i = 1; i < n - d; i++)
        {
            j = i + d;
            int min = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {

                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < min)
                {
                    min = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = min;
        }
    }
    char name = 'A';

    cout << "Optimal Parenthesization is : ";
    printPar((int *)s, 1, n - 1, n, name);
    cout << "\nOptimal Cost is : " << m[1][n - 1]<<endl;
}

int main()
{
    int arr[] = {5, 4, 6, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    MatrixChainOrder(arr, size);

        return 0;
}