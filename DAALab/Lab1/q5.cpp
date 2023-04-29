#include<iostream>
using namespace std;

#define R 3
#define C 3

void userInput(int arr[][C])
{
    cout<<"Enter the elements:"<<endl;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin>>arr[i][j];
        }
    }
}

void display(int arr[][C])
{
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cout<<arr[i][j]<<" ";
        }
    }
    cout<<endl;
}

int countNonZero(int arr[][C])
{
    int count = 0;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(arr[i][j] != 0)
            {
                count++;
            }
        }
    }
    return count;
}

int sumAboveLeadingDiagonal(int arr[][C])
{
    int sum = 0;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(i < j)
            {
                sum += arr[i][j];
            }
        }
    }
    return sum;
}

void elementsBelowMinorDiagonal(int arr[][C])
{
    cout<<"Elements below Minor diagonal: ";
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(i > j)
            {
                cout<<arr[i][j]<<" ";
            }
        }
    }
    cout<<endl;
}

void productDiagonalElements(int arr[][C])
{
    int prod_Major = 1, prod_Minor = 1;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(i == j)
            {
                prod_Major *= arr[i][j];
            }
            else if(i == C - j)
            {
                prod_Minor *= arr[i][j];
            }
        }
    }
    cout<<"Product of elements in Major diagonal: "<<prod_Major<<endl;
    cout<<"Product of elements in Minor diagonal: "<<prod_Minor<<endl;
}

int main()
{
    int arr[R][C];
    userInput(arr);
    display(arr);

    cout<<"No. of nonzero elements: "<<countNonZero(arr)<<endl;
    cout<<"Sum of elements above leading diagonal: "<<sumAboveLeadingDiagonal(arr)<<endl;
    elementsBelowMinorDiagonal(arr);
    productDiagonalElements(arr);

    return 0;
}