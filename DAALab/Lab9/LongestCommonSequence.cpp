#include <bits/stdc++.h>
using namespace std;



void lcsLength(char *s1, char *s2, int m, int n)
{

    char b[m + 1][n + 1];
    int c[m + 1][n + 1];

    for (int i = 1; i <= m; i++)
    {
        c[i][0] = 0;
        b[i][0] = 'A';
    }
    for (int j = 0; j <= n; j++)
    {
        c[0][j] = 0;
        b[0][j] = 'A';
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i] == s2[j])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'D';
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'U';
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'L';
            }
        }
    }

    cout << "Length of the LCS is: " << c[m][n] << endl;

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    string lcs ="";

    int i = m, j = n;
    while (i >= 0 || j >= 0)
    {
        if (b[i][j] == 'D')
        {
            lcs += s1[i];
            i--;
            j--;
        }
        else if (b[i][j] == 'U')
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    cout << lcs;
    cout << endl;

}

int main()
{
    char s1[] = "HUMAN";
    char s2[] = "CHIMPANZEE";
    int m = strlen(s1);
    int n = strlen(s2);

    lcsLength(s1, s2, m, n);
}