#include<iostream>
using namespace std;

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

    cout<<elementCount(arr, size)<<endl;

    cout<<elementCountTwo(arr, size)<<endl;
    
    return 0;
}