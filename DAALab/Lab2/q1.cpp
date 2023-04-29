#include<iostream>
#include<cmath>
using namespace std;

#define size 10

void userInput(int arr[])
{
    cout<<"Enter 10 numbers: "<<endl;
    for(int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
}

int checkPrimeOne(int num)
{
    int count = 0;
    for(int i = 2; i < num; i++)
    {
        count++;
        if(num % i == 0)
        {
            return count;
        }
    }
    return count;
}

int checkPrimeTwo(int num)
{
    int count = 0;
    for(int i = 2; i <= num / 2; i++)
    {
        count++;
        if(num % i == 0)
        {
            return count;
        }
    }
    return count;
}

int checkPrimeThree(int num)
{
    int count = 0;
    for(int i = 2; i <= sqrt(num); i++)
    {
        count++;
        if(num % i == 0)
        {
            return count;
        }
    }
    return count;
}

void display(int arr[])
{
    cout << "Input\t\t"<<"Algo 1\t\t"<<"Algo 2\t\t"<<"Algo 3"<<endl<< endl;
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t\t" << checkPrimeOne(arr[i]) << "\t\t" << checkPrimeTwo(arr[i]) << "\t\t" << checkPrimeThree(arr[i]) << endl;
    }
}

int main()
{
    int arr[size];

    userInput(arr);
    display(arr);

    return 0;
}