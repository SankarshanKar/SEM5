#include <iostream>
using namespace std;

void fillArrayBestCase(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        arr[i] = (i + 1);
    }
}
void fillArrayWorstCase(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        arr[i] = (size - i);
    }
}

int selectionSort(int arr[], int size)
{
    int stepCount = 0;
    for (int i = 0; i < size - 1; i++)
    {
        stepCount++;
        int min_ind = i;
        for (int j = i + 1; j < size; j++)
        {
            stepCount++;
            if (arr[j] < arr[min_ind])
            {
                min_ind = j;
            }
        }
        swap(arr[min_ind], arr[i]);
    }
    return stepCount;
}

int selectionSortOptimized(int arr[], int size)
{
    int stepCount = 0;
    for (int i = 0, j = size - 1; i < j; i++, j--)
    {
        stepCount++;
        int min = arr[i], max = arr[i];
        int min_i = i, max_i = i;
        for (int k = i; k <= j; k++)
        {
            stepCount++;
            if (arr[k] > max)
            {
                max = arr[k];
                max_i = k;
            }
            else if (arr[k] < min)
            {
                min = arr[k];
                min_i = k;
            }
        }

        swap(arr[i], arr[min_i]);

        if (arr[min_i] == max)
            swap(arr[j], arr[min_i]);
        else
            swap(arr[j], arr[max_i]);
    }
    return stepCount;
}

void displaySelectionSort()
{
    int sl = 0;
    cout << "Sl. No \t  Value of n \t TC(Best case)    TC(Worst Case)  \n\n";
    for (int n = 1000; n <= 10000; n = n + 1000)
    {
        int arr1[n];
        for (int i = 0; i < n; i++)
        {
            arr1[i] = i+1;
        }
        int bestCase = selectionSort(arr1, n);
        int arr2[n];
        for (int i = n; i >=1; i--)
        {
            arr2[i] = i;
        }
        int worstCase = selectionSort(arr2, n);
        
        cout << ++sl << " \t " << n << "\t\t" << bestCase<< "\t\t"<< worstCase<< "\n";
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
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    int arr[size];

    fillArrayBestCase(arr, size);
    cout<<selectionSort(arr, size)<<endl;
    display(arr, size);

    fillArrayWorstCase(arr, size);
    cout<<selectionSort(arr, size)<<endl;
    display(arr, size);

    fillArrayBestCase(arr, size);
    cout<<selectionSortOptimized(arr, size)<<endl;
    display(arr, size);

    fillArrayWorstCase(arr, size);
    cout<<selectionSortOptimized(arr, size)<<endl;
    display(arr, size);

    return 0;
}