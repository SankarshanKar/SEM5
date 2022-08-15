#include<iostream>
using namespace std;

void fillArrayRandom(int arr[], int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() / 10000000;
    }
}

int bubbleSort(int arr[], int size)
{
	int stepCount = 0;
	for(int i = 0; i < size; i++)
	{
		stepCount++;
		for(int j = 0; j < size - 1; j++)
		{
			stepCount++;
			if(arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
	return stepCount;
}

int bubbleSortOptimized(int arr[], int size)
{
	int stepCount = 0;
	for(int i = 0; i < size; i++)
	{
		stepCount++;
		for(int j = 0; j < size - i - 1; j++)
		{
			stepCount++;
			if(arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
	return stepCount;
}

void display(int arr[], int size)
{
	for(int i = 0; i < size; i++)
		cout<<arr[i]<<" ";

	cout<<endl;
}

void printTable(int size)
{
	int arr1[size];
	int arr2[size];


	cout << "Sl No.\t\tBubble Sort\t\tBubble Sort (Optimized)" << endl;

	for(int i = 0; i < 10; i++)
	{
		fillArrayRandom(arr1, size);
		for(int j = 0; j < size; j++)
		{
			arr2[j] = arr1[j];
		}
		
		cout << "    " << i << "\t\t\t" << bubbleSort(arr1, size) << "\t\t\t" << bubbleSortOptimized(arr2, size) << endl;
	}

	cout<<endl;
}

int main()
{
	int size;
	cout<<"Enter the size of the array: ";
	cin>>size;

	printTable(size);

	return 0; 
}