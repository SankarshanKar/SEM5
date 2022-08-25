#include <iostream>
using namespace std;

// void merge(int arr[], int low, int mid, int high)
// {
//     int size1 = mid - low + 1, size2 = high - mid;
//     int left[size1], right[size2];
    
//     for(int i = 0; i < size1; i++)
//     {
//         left[i] = arr[low + i];
//     }
//     for(int i = 0; i < size2; i++)
//     {
//         right[i] = arr[mid + 1 + i];
//     }

//     int i = 0, j = 0, k = 0;
    
//     while(i < size1 && j < size2)
//     {
//         if(left[i] <= right[j])
//         {
//             arr[k] = left[i];
//             i++;
//             k++;
//         }
//         else
//         {
//             arr[k] = right[j];
//             j++;
//             k++;
//         }
//     }
//     while(i < size1)
//     {
//         arr[k] = left[i];
//         i++;
//         k++;
//     }
//     while(j < size2)
//     {
//         arr[k] = right[j];
//         j++;
//         k++;
//     }
// }

void merge(int arr[], int low, int mid, int high)
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

// void merge(int arr[], int p, int q, int r)
// {
//     int n1 = q - p + 1;
//     int n2 = r - q;
//     int L[n1], R[n2];
//     for (int i = 0; i < n1; i++){
//         L[i] = arr[p + i];
//     }
//     for (int j = 0; j < n2; j++){
//         R[j] = arr[q + 1 + j];
//     }

//     int i = 0;
//     int j = 0;
//     int k = p;
//     while (i < n1 && j < n2)
//     {
//         if (L[i] < R[j])
//         {
//             arr[k++] = L[i++];
//         }
//         else
//         {
//             arr[k++] = R[j++];
//         }
//     }

//     while (i < n1)
//     {
//         arr[k++] = L[i++];
//     }
//     while (j < n2)
//     {
//         arr[k++] = R[j++];
//     }
// }

void mergeSort(int arr[], int low, int high)
{
    if(high > low)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// int mergeSort(int arr[], int p, int r)
// {
//     int count=0;
//     if (p < r)
//     {
//         count++;
//         int q = (p + r) / 2;
//         mergeSort(arr, p, q);
//         mergeSort(arr, q + 1, r);
//         merge(arr, p, q, r);
//     }
//     return count;
// }

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
    int arr[] = {10, 15, 20, 11, 30};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    display(arr, size);

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// void merge(int arr[], int p, int q, int r, int &count)
// {
//     int n1 = q - p + 1;
//     int n2 = r - q;
//     int L[n1], R[n2];
//     for (int i = 0; i < n1; i++){
//         count++;
//         L[i] = arr[p + i];
//     }
//     for (int j = 0; j < n2; j++){
//         count++;
//         R[j] = arr[q + 1 + j];
//     }

//     int i = 0;
//     int j = 0;
//     int k = p;
//     while (i < n1 && j < n2)
//     {
//         count++;
//         if (L[i] < R[j])
//         {
//             arr[k++] = L[i++];
//         }
//         else
//         {
//             arr[k++] = R[j++];
//         }
//     }

//     while (i < n1)
//     {
//         count++;
//         arr[k++] = L[i++];
//     }
//     while (j < n2)
//     {
//         count++;
//         arr[k++] = R[j++];
//     }
// }

// int mergeSort(int arr[], int p, int r)
// {
//     int count=0;
//     if (p < r)
//     {
//         count++;
//         int q = (p + r) / 2;
//         mergeSort(arr, p, q);
//         mergeSort(arr, q + 1, r);
//         merge(arr, p, q, r,count);
//     }
//     return count;
// }

// void display(int arr[], int size)
// {
//     for(int i = 0; i < size; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

// int main()
// {
//     int arr[] = {10, 15, 20, 11, 30};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     mergeSort(arr, 0, 4);

//     display(arr, size);

//     return 0;
// }