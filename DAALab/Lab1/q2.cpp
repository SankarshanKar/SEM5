#include <iostream>
using namespace std;

int duplicate(int arr[], int n)
{
    int d = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                d++;
                break;
            }
        }
    }
    return d;
}

int mostDuplicate(int arr[], int n)
{
    int d;
    int maxEle;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        d = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                d++;
                if (d > max)
                {
                    max = d;
                    maxEle = i;
                }
            }
        }
    }
    cout << "Most repeated element is: " << arr[maxEle] << endl;
}

int main()
{
    int n;
    cout << "Enter value of n:" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter array elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "total number of duplicates=" << duplicate(arr, n) << endl;
    mostDuplicate(arr, n);
    return 0;
}