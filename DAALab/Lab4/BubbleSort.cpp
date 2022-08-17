#include<iostream>
using namespace std;

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

void printBubbleSort()
{
	int sl = 0;
    cout << "Sl. No \t  Value of n \t TC(Best case)    TC(Worst Case)  \n\n";
    for (int n = 100; n <= 1000; n = n + 100)
    {
        int arr1[n];
        for (int i = 0; i < n; i++)
        {
            arr1[i] = i+1;
        }
        int bestCase = bubbleSort(arr1, n);
        int arr2[n];
        for (int i = n; i >=1; i--)
        {
            arr2[i] = i;
        }
        int worstCase = bubbleSort(arr2, n);
        
        cout << ++sl << " \t " << n << "\t\t" << bestCase<< "\t\t"<< worstCase<< "\n";
    }
}

void printBubbleSortOptimized()
{
	int sl = 0;
    cout << "Sl. No \t  Value of n \t TC(Best case)    TC(Worst Case)  \n\n";
    for (int n = 100; n <= 1000; n = n + 100)
    {
        int arr1[n];
        for (int i = 0; i < n; i++)
        {
            arr1[i] = i+1;
        }
        int bestCase = bubbleSortOptimized(arr1, n);
        int arr2[n];
        for (int i = n; i >=1; i--)
        {
            arr2[i] = i;
        }
        int worstCase = bubbleSortOptimized(arr2, n);
        
        cout << ++sl << " \t " << n << "\t\t" << bestCase<< "\t\t"<< worstCase<< "\n";
    }
}

int main()
{
	cout<<"Bubble Sort: "<<endl;
	printBubbleSort();

	cout<<"Bubble Sort Optimised: "<<endl;
	printBubbleSortOptimized();

	return 0; 
}