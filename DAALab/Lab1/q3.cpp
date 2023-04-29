#include<iostream>
using namespace std;

void rearangeEvenOdd(int arr[], int size)
{
    int temp[size];
    for(int i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }
    int left = 0, right = size - 1;
    for(int i = 0; i < size; i++)
    {
        if(temp[i] % 2 == 0)
        {
            arr[left] = temp[i];
            left++;
        }
        else
        {
            arr[right] = temp[i];
            right--;
        }
    }
}

void display(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);

    rearangeEvenOdd(arr, size);
    display(arr, size);

    return 0;
}