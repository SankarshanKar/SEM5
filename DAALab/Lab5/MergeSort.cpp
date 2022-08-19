#include<iostream>
using namespace std;

void mergeSort(int arr[], int low, int mid, int high)
{
    int leftIndex = mid - low + 1;
    int rightIndex = high - mid;
    int arr1[leftIndex], arr2[rightIndex];
    
    
    for (int i = 0; i < leftIndex; i++)
    {
        arr1[i] = arr[low + i];
    }
    
    for (int i = 0; i < rightIndex; i++)
    {
        arr2[i] = arr[leftIndex + i];
    }
    
    
    int i = 0, j = 0, k = 0;
    while (i < leftIndex && j < rightIndex)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }
    
    while (i < leftIndex)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    
    while (j < rightIndex)
    {
        arr[k] = arr2[j];
        j++;
        k++;
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
    int arr[] = {10, 20, 40, 20, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    int low = 0;
    int mid = 2;
    int high = size - 1;
    display(arr, size);

    mergeSort(arr, low, mid, high);
    display(arr, size);

    return 0;
}