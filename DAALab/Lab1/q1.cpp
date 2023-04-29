#include<iostream>
using namespace std;

void userInput(int arr[], int size)
{
    cout<<"Enter the elements: "<<endl;
    for(int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
}

void display(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int smallestElement(int arr[], int size)
{
    int smallest = arr[0];
    for(int i = 0; i < size; i++)
    {
        if(arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }
    return smallest;
}

int largestElement(int arr[], int size)
{
    int largest = arr[0];
    for(int i = 0; i < size; i++)
    {
        if(arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int arr[n];
    userInput(arr, n);
    display(arr, n);

    cout<<"Smallest Number = "<<smallestElement(arr, n)<<endl;
    cout<<"Largest Number = "<<largestElement(arr, n)<<endl;

    return 0;
}