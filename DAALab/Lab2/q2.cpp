#include<iostream>
#include<cmath>
using namespace std;

#define size 6

void userInput(int a[], int b[])
{
    cout<<"Enter 6 test cases: "<<endl;
    for(int i = 0; i < size; i++)
    {
        cout<<"Test case "<<(i + 1)<<": "<<endl;
        cin>>a[i]>>b[i];
    }
    cout<<endl;
}

int min(int a, int b)
{
    if(a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int euclidAlgoGCD(int a, int b)
{
    int rem;
    int count = 1;
    while(a % b != 0)
    {
        count++;
        rem = a % b;
        a = b;
        b = rem;
    }
    return count;
}

int consecutiveInteger(int a, int b)
{
    int t = min(a, b);
    int count = 1;
    while(t != 0)
    {
        count++;
        if(a % t == 0 && b % t == 0)
        {
            break;
        }
        t--;
    }
    return count;
}

int middleSchool(int a, int b)
{
    int ans = 1, m = 0, n = 0, count = 1;
    int t = min(a, b);
    for(int i = 2; i <= t; i++)
    {
        count++;
        n = 0;
        m = 0;
        if(a % i == 0)
        {
            n = 1;
            a /= i;
        }
        if(b % i == 0)
        {
            m = 1;
            b /= i;
        }
        if(n == 1 && m == 1)
        {
            ans *= i;
        }
        if(n == 1 || m == 1)
        {
            i--;
        }
    }
    return count;
}

void display(int a[], int b[])
{
    cout << "Input\t"<<"Euclid's Algo\t"<<"Consecutive Integer\t"<<"Middle School"<<endl<< endl;
    for(int i = 0; i < size; i++)
    {
        cout << a[i] << "\t\t" << euclidAlgoGCD(a[i], b[i]) << "\t\t" << consecutiveInteger(a[i], b[i]) << "\t\t" << middleSchool(a[i], b[i]) << endl;
    }
}

int main()
{
    int a[size], b[size];

    userInput(a, b);
    display(a, b);

    return 0;
}