#include<iostream>
using namespace std;

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
    int count = 0;
    while(a % b != 0)
    {
        rem = a % b;
        a = b;
        b = rem;
    }
    cout<<"No. of steps: "<<count<<endl;
    return rem;
}

int consecutiveInteger(int a, int b)
{
    int t = min(a, b);
    int count = 0;
    while(t != 0)
    {
        count++;
        if(a % t == 0 || b % t == 0)
        {
            break;
            t--;
        }
    }
    cout<<"No. of steps: "<<count<<endl;
    return t;
}

int middleSchool(int a, int b)
{
    
}

int main()
{
    int a, b;
}