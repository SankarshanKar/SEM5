#include<iostream>
using namespace std;

void display(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selectionSort(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int min_ind = i;
        for(int j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[min_ind])
            {
                min_ind = j;
            }
        }
        swap(arr[min_ind], arr[i]);
    }
}

void selectionSortModified(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int min_ind = i;
        for(int j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[min_ind])
            {
                min_ind = j;
            }
        }
        swap(arr[min_ind], arr[i]);
    }
}

int main()
{
    int arr[] = {10, 5, 8, 20, 2, 18};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);

    selectionSort(arr, size);

    display(arr, size);

    return 0;
}