#include<iostream>
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
        int flag = 0;
		for(int j = 0; j < size - i - 1; j++)
		{
			stepCount++;
			if(arr[j] > arr[j + 1])
			{
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
		}
        if (flag == 0)
            return stepCount;
	}
	return stepCount;
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
    cout<<bubbleSort(arr, size)<<endl;
    display(arr, size);

    fillArrayWorstCase(arr, size);
    cout<<bubbleSort(arr, size)<<endl;
    display(arr, size);

    fillArrayBestCase(arr, size);
    cout<<bubbleSortOptimized(arr, size)<<endl;
    display(arr, size);

    fillArrayWorstCase(arr, size);
    cout<<bubbleSortOptimized(arr, size)<<endl;
    display(arr, size);

	return 0; 
}