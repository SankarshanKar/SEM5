#include<iostream>
using namespace std;

// void insertionSort(int arr[], int size)
// {
//     for(int i = 0; i < size; i++)
//     {
//         int key = arr[i];
//         int j = i - 1;
//         while(j >= 0 && arr[j] > key)
//         {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = key;
//     }
// }

// int elementCount(int arr[], int size)
// {
//     insertionSort(arr, size);
//     int count = 1, stepCount = 0;
//     for(int i = 1; i < size; i++)
//     {
//         stepCount++;
//         if(arr[i] == arr[i - 1])
//         {
//             count++;
//         }
//         else
//         {
//             count = 1;
//         }
//         if(count > (size / 2))
//         {
//             cout<<arr[i]<<endl;
//             return stepCount;
//         }
//     }
//     return stepCount;
// }

int elementCount(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int count = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] == arr[i])
                count++;
        }
        if (count > size / 2)
            return arr[i];
    }
    return -1;
}

int elementCountTwo(int arr[], int size)
{
    int highest = arr[0], count = 0;
    for(int i = 1; i < size; i++)
    {
        if(arr[i] != arr[i - 1])
        {
            count--;
        }
        if(count == 0)
        {
            highest = arr[i];
        }
        if(arr[i] == arr[i - 1])
        {
            count++;
        }
        
    }
    if(count > 0)
        return highest;
    
    return highest;
}

int main()
{
    int arr[] = {2, 5, 2, 2, 9, 1, 2, 2, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout<<elementCount(arr, size)<<endl<<endl;

    cout<<elementCountTwo(arr, size)<<endl;
    
    return 0;
}