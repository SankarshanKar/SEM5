#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int size1 = mid - low + 1, size2 = high - mid;
    int left[size1], right[size2];

    for (int i = 0; i < size1; i++)
    {
        left[i] = arr[low + i];
    }
    for (int j = 0; j < size2; j++)
    {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;

    while (i < size1 && j < size2)
    {
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
        arr[k] = left[i];
        k++;
        i++;
    }
    while (j < size2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (high > low)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    display(arr, size);

    return 0;
}