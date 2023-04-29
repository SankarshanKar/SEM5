#include <iostream>
using namespace std;

void userInput(int arr[], int n)
{
    cout << "Enter array elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

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

void mostDuplicate(int arr[], int n)
{
    if(duplicate(arr, n) == 0)
    {
        cout<<"Most repeated element is: None"<<endl;
        return;
    }
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
    userInput(arr, n);

    cout << "total number of duplicates=" << duplicate(arr, n) << endl;
    mostDuplicate(arr, n);
    return 0;
}