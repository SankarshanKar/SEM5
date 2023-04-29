#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i, int &c)
{

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        c++;
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        c++;
        largest = right;
    }

    if (largest != i)
    {
        c++;
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest, c);
    }
}

void maxHeap(int arr[], int n, int &c)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        c++;
        heapify(arr, n, i, c);
    }
}

int extractMax(int arr[], int n)
{
    int c = 0;
    int ele = arr[0];
    arr[0] = arr[n - 1];
    n = n - 1;
    heapify(arr, n, 0, c);
    return ele;
}

int parent(int n)
{
    return (n - 1) / 2;
}

void shiftUp(int arr[], int i)
{
    while (i > 0 && arr[i] > arr[parent(i)])
    {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

void insertEle(int arr[], int n, int x)
{
    n = n + 1;
    arr[n] = x;
    shiftUp(arr, n);
}

void newValue(int arr[], int i, int x)
{
    int n = sizeof(arr) / sizeof(arr[0]);
    int c = 0;
    if (x < arr[i])
    {
        arr[i] = x;
        heapify(arr, i, n, c);
    }
    else
    {
        arr[i] = x;
        shiftUp(arr, i);
    }
}

void remove(int arr[], int i)
{
    arr[i] = arr[0] + 1;
    shiftUp(arr, i);
    extractMax(arr, sizeof(arr) / sizeof(int));
}

int heapSort(int arr[], int n)
{
    int c = 0;
    maxHeap(arr, n, c);
    for (int i = n - 1; i >= 0; i--)
    {
        c++;
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, c);
    }

    return c;
}

void display8()
{
    srand(time(0));
    int sl = 0;
    cout << "Sl. No \t  Value of n \t TC(Ascending data)    TC(Descending data)  TC(Random data) \n\n";
    for (int n = 5000; n <= 50000; n = n + 5000)
    {
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % 10;
        }
        int countRandom = heapSort(arr, n);
        int countAscending = heapSort(arr, n);
        sort(arr, arr + n, greater<int>());
        int countDescending = heapSort(arr, n);
        cout << ++sl << " \t\t " << n << " \t\t " << countAscending << " \t\t " << countDescending << " \t\t " << countRandom << "\n";
    }
}

int main()
{
    int choice;
    int arr[10];
    int c1, c2;
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << "\n0. Quit. \n";
    cout << "1. n Random numbers=> Array\n";
    cout << "2. Display the array. \n";
    cout << "3. Sort the array in Ascending order by using Max Heap sort. \n";
    cout << "4. Sort the array in descending order by using any sorting method. \n";
    cout << "5. Time complexity to sort ascending of random data. \n";
    cout << "6. Time complexity to sort ascending of data already sorted in ascending order. \n";
    cout << "7. Time complexity to sort ascending of data already sorted in descending order. \n";
    cout << "8. Time complexity to sort ascending data for all cases \n(Data Ascending, Data in descending & Random Data) in Tabular form of values n=5000 to 50000, step=5000\n";
    cout << "\n9. Extract largest Element";
    cout << "\n10. Replace a value of a node with new value";
    cout << "\n11. Insert a new element";
    cout << "\n12. Delete an element";
    do
    {
        cout << "\nEnter a choice: (0-8)\n"
             << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Quiting..\n";
            break;
        case 1:
            cout << "Enter 10 numbers: \n";
            for (int i = 0; i < 10; i++)
            {
                cin >> arr[i];
            }
            break;

        case 2:
            cout << "The array: \n";
            for (int i = 0; i < 10; i++)
            {
                cout << arr[i] << " ";
            }
            break;

        case 3:
            c1 = heapSort(arr, 10);
            break;
        case 4:
            sort(arr, arr + 10, greater<int>());
            break;

        case 5:
            cout << "Time complexity on random data" << c1;
            break;
        case 6:

            cout << "Time complexity on ascending data: " << heapSort(arr1, 10);
            break;
        case 7:

            cout << "Time complexity on descending data: " << heapSort(arr2, 10);
            break;
        case 8:
            display8();
            break;

        case 9:
            cout << "Largest Element is: " << extractMax(arr, 10);
            break;
        case 10:
            cout << "Enter index of value to be replaced with : ";
            int idx;
            cin >> idx;
            cout << "Enter new value: ";
            int val;
            cin >> val;
            newValue(arr, idx, val);
            break;
        case 11:
            cout << "Enter value of new element: ";
            cin >> val;
            insertEle(arr, 10, val);
            break;
        case 12:
            cout << "Enter index of element to be deleted: ";
            cin >> idx;
            remove(arr, idx);
            break;
        }

    } while (choice != 0);
}