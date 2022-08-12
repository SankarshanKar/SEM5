#include<iostream>
using namespace std;

void bubbleSort(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size - 1; j++)
		{
			if(arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

void bubbleSortOptimized(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size - i - 1; j++)
		{
			if(arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

void display(int arr[], int size)
{
	for(int i = 0; i < size; i++)
		cout<<arr[i]<<" ";

	cout<<endl;
}

int main()
{
	int arr[] = {5, 2, 7, 3, 8, 1, 4, 6};
	int size = sizeof(arr) / sizeof(arr[0]);

	// bubbleSort(arr, size);
	// display(arr, size);

	bubbleSortOptimized(arr, size);
	display(arr, size);

	return 0; 
}
