#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high, int &count)
{
    int size1 = mid - low + 1, size2 = high - mid;
    int left[size1], right[size2];

    for (int i = 0; i < size1; i++)
    {
        count++;
        left[i] = arr[low + i];
    }
    for (int j = 0; j < size2; j++)
    {
        count++;
        right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;

    while (i < size1 && j < size2)
    {
        count++;
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = right[j];
            k++;
            j++;
        }
    }
    while (i < size1)
    {
        count++;
        arr[k] = left[i];
        k++;
        i++;
    }
    while (j < size2)
    {
        count++;
        arr[k] = right[j];
        k++;
        j++;
    }
}

int mergeSort(int arr[], int low, int high)
{
    int count = 0;
    if (high > low)
    {
        count++;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high, count);
    }
    return count;
}

void display()
{
    srand(time(0));
    int sl = 0;
    cout << "Sl. No \t  Value of n \t TC(Best case)    TC(Worst Case)    TC(Avg Case)  \n\n";
    for (int n = 1000; n <= 10000; n = n + 1000)
    {
        int arr1[n];
        for (int i = 0; i < n; i++)
        {
            arr1[i] = i+1;
        }
        int bestCase = mergeSort(arr1, 0,n);
        int arr2[n];
        for (int i = n; i >=1; i--)
        {
            arr2[i] = i;
        }
        int worstCase = mergeSort(arr2,0, n);
        int arr3[n];
        for (int i = n; i >=1; i--)
        {
            arr3[i] = rand()%10;
        }
        int avgcase=mergeSort(arr3, 0, n);

        
        cout << ++sl << " \t " << n << "\t\t" << bestCase<< "\t\t"<< worstCase<< "\t\t\t"<<avgcase<<"\n";
    }
}

int main()
{
    // // int arr[] = {10, 15, 20, 11, 30};
    // int arr[] = {6, 5, 12, 10, 9, 1};
    // int size = sizeof(arr) / sizeof(arr[0]);

    // mergeSort(arr, 0, size - 1);

    display();

    return 0;
}