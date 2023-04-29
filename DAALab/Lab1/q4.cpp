#include<iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void display(int a, int b, int c)
{
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;
}

int main()
{
    int a = 10;
    int b = 20;
    int c = 30;

    cout<<"Before rotating:"<<endl;
    display(a, b, c);

    swap(b, c);
    swap(a, b);

    cout<<"After rotating:"<<endl;
    display(a, b, c);

    return 0;
}