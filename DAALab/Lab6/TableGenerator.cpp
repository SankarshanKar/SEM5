#include <iostream>
#include <time.h>
using namespace std;

int partition(int arr[], int low, int high, int &count)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        count++;
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int randomPartition(int arr[], int low, int high, int &count)
{
    count++;
    srand(time(0));
    int random = low + rand() % (high - low);

    swap(arr[random], arr[high]);
    return partition(arr, low, high, count);
}

void quickSort(int arr[], int low, int high, int &count)
{
    if (low < high)
    {
        count++;
        int p = partition(arr, low, high, count);
        quickSort(arr, low, p - 1, count);
        quickSort(arr, p + 1, high, count);
    }
}

void randomisedQuickSort(int arr[], int low, int high, int &count)
{
    if (low < high)
    {
        count++;
        int p = randomPartition(arr, low, high, count);
        randomisedQuickSort(arr, low, p - 1, count);
        randomisedQuickSort(arr, p + 1, high, count);
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

void printTable1()
{
    srand(time(0));
    int sl = 0;
    // cout << "Sl. No \t  Value of n \t TC(Ascending case)    TC(Desc Case)    TC(Random Case)  \n\n";

    for (int n = 1000; n <= 10000; n = n + 1000)
    {
        int count = 0;
        int arr1[n];
        for (int i = 0; i < n; i++)
        {
            arr1[i] = i + 1;
        }
        quickSort(arr1, 0, n, count);
        int bestCase = count;

        count = 0;
        int arr2[n];
        for (int i = n; i >= 1; i--)
        {
            arr2[i] = i;
        }
        quickSort(arr2, 0, n, count);
        int worstCase = count;

        count = 0;
        int arr3[n];
        for (int i = 0; i < n; i++)
        {
            arr3[i] = rand() % 10;
        }
        quickSort(arr3, 0, n, count);
        int avgcase = count;

        cout << bestCase << "\t\t" << worstCase << "\t\t\t" << avgcase << "\n";
    }
}

void printTable2()
{
    srand(time(0));
    int sl = 0;
    // cout << "Sl. No \t  Value of n \t TC(Ascending case)    TC(Desc Case)    TC(Random Case)  \n\n";

    for (int n = 1000; n <= 10000; n = n + 1000)
    {
        int count = 0;
        int arr1[n];
        for (int i = 0; i < n; i++)
        {
            arr1[i] = i + 1;
        }
        randomisedQuickSort(arr1, 0, n, count);
        int bestCase = count;

        count = 0;
        int arr2[n];
        for (int i = n; i >= 1; i--)
        {
            arr2[i] = i;
        }
        randomisedQuickSort(arr2, 0, n, count);
        int worstCase = count;

        count = 0;
        int arr3[n];
        for (int i = 0; i < n; i++)
        {
            arr3[i] = rand() % 10;
        }
        randomisedQuickSort(arr3, 0, n, count);
        int avgcase = count;

        cout << bestCase << "\t\t" << worstCase << "\t\t\t" << avgcase << "\n";
    }
}

int main()
{
    printTable1();
    cout << endl
         << endl
         << endl;
    printTable2();

    return 0;
}