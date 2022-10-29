#include <bits/stdc++.h>
using namespace std;

void activitySelect(int startTimes[], int finishTimes[], int n)
{

    int curr = 0;
    cout << curr << " ";
    for (int j = 1; j < n; j++)
    {
        if (startTimes[j] >= finishTimes[curr])
        {
            cout << j << " ";
            curr = j;
        }
    }
}

int main()
{

    int s[6] = {1, 3, 0, 5, 8, 5};
    int f[6] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(f) / sizeof(int);
    activitySelect(s, f, n);
    cout << endl;
}