#include <iostream>
#include <iomanip>
#include <time.h>
#include <ctime>
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

    cout << "Input\t\t"
         << "TC (Ascending)\t\t"
         << "TC (Descending)\t\t"
         << "TC (Random)" << endl
         << endl;
    for (int i = 0; i < 10; i++)
    {
        int temp[sizes[i]];
        fillArrayAscending(temp, sizes[i]);
        cout << sizes[i] << "\t\t" << fixed << insertionSort(temp, sizes[i]) << setprecision(6);
        fillArrayDescending(temp, sizes[i]);
        cout << "\t\t" << fixed << insertionSort(temp, sizes[i]) << setprecision(6);
        fillArrayRandom(temp, sizes[i]);
        cout << "\t\t" << fixed << insertionSort(temp, sizes[i]) << setprecision(6) << endl;
    }
}

void menu(int arr[], int size)
{
    int choice;
    double temp;

    fillArrayRandom(arr, size);

    cout << "\n0. Quit. \n";
    cout << "1. n Random numbers=> Array\n";
    cout << "2. Display the array. \n";
    cout << "3. Sort the array in Ascending order by using insertion sort. \n";
    cout << "4. Sort the array in descending order by using any sorting method. \n";
    cout << "5. Time complexity to sort ascending of random data. \n";
    cout << "6. Time complexity to sort ascending of data already sorted in ascending order. \n";
    cout << "7. Time complexity to sort ascending of data already sorted in descending order. \n";
    cout << "8. Time complexity to sort ascending data for all cases \n(Data Ascending, Data in descending & Random Data) in Tabular form of values n=5000 to 50000, step=5000\n";
        
    do
    {
        cout << endl << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
            case 0:
                cout << "Quitting.." << endl;
                break;
            case 1:
                fillArrayRandom(arr, size);
                display(arr, size);
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
                cout << "Time complexity(Random): " 
                     << fixed << insertionSort(arr, size) 
                     << setprecision(6) << endl;
                break;

            case 6:
                fillArrayAscending(arr, size);
                cout << "Time complexity(Ascending): " 
                     << fixed << insertionSort(arr, size) 
                     << setprecision(6) << endl;
                break;

            case 7:
                fillArrayDescending(arr, size);
                cout << "Time complexity(Descending): " 
                     << fixed << insertionSort(arr, size) 
                     << setprecision(6) << endl;
                break;

            case 8:
                displayTable();
                break;

            default:
                cout << "Invalid input\n";
                break;
        }
    } while (choice != 0);
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