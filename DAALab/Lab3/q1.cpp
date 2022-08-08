#include <iostream>
#include<iomanip>
#include <time.h>
#include<ctime>
using namespace std;

void fillArrayAscending(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = (i + 1) * 10;
    }
}

void fillArrayDescending(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = (size - i) * 10;
    }
}

void fillArrayRandom(int arr[], int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() / 10000000;
    }
}

double insertionSort(int arr[], int size)
{
    clock_t start, end;
    start = clock();
    for (int i = 0; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    return time_taken;
}

void insertionSortDescending(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key > arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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

void displayTable()
{
    int sizes[10] = {5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000};

    // for(int i = 0; i < 10; i++)
    // {
    //     int temp[sizes[i]];
    //     cout<<"Sl No: "<<i + 1<<endl;
        
    //     cout<<"Time Complexity(Ascending array): ";
    //     fillArrayAscending(temp, sizes[i]);
    //     cout<<fixed<<insertionSort(temp, sizes[i])<<setprecision(6)<<endl;
        
    //     cout<<"Time Complexity(Descending array): ";
    //     fillArrayDescending(temp, sizes[i]);
    //     cout<<fixed<<insertionSort(temp, sizes[i])<<setprecision(6)<<endl;
        
    //     cout<<"Time Complexity(Random array): ";
    //     fillArrayRandom(temp, sizes[i]);
    //     cout<<fixed<<insertionSort(temp, sizes[i])<<setprecision(6)<<endl;
    // }
    cout << "Input\t\t"<<"Algo 1\t\t"<<"Algo 2\t\t"<<"Algo 3"<<endl<< endl;
    for(int i = 0; i < 10; i++)
    {
        int temp[sizes[i]];
        cout << sizes[i] << "\t\t" << fixed << insertionSort(temp, sizes[i]) << setprecision(6) << "\t\t" << fixed << insertionSort(temp, sizes[i]) << setprecision(6) << "\t\t" << fixed << insertionSort(temp, sizes[i]) << setprecision(6) << endl;
    }
}

void menu(int arr[], int size)
{
    int choice;
    double temp;

    while (choice != 0)
    {
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                fillArrayRandom(arr, size);
                break;

            case 2:
                display(arr, size);
                break;

            case 3:
                temp = insertionSort(arr, size);
                display(arr, size);
                break;

            case 4:
                insertionSortDescending(arr, size);
                display(arr, size);
                break;
            
            case 5:
                fillArrayRandom(arr, size);
                cout<<"Time complexity(Random array): "<<fixed<<insertionSort(arr, size)<<setprecision(6)<<endl;
                break;

            case 6:
                fillArrayAscending(arr, size);
                cout<<"Time complexity(Ascending array): "<<fixed<<insertionSort(arr, size)<<setprecision(6)<<endl;
                break;

            case 7:
                fillArrayDescending(arr, size);
                cout<<"Time complexity(Descending array): "<<fixed<<insertionSort(arr, size)<<setprecision(6)<<endl;
                break;

            case 8:
                displayTable();
                break;

            default:
                break;
        }
    }
}

int main()
{
    int size;

    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size];

    menu(arr, size);

    return 0;
}