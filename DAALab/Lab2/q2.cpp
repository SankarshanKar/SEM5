#include<iostream>
#include<cmath>
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
    int t = min(a, b);
    int ans = 1;
    for(int i = 0; i < t; i++)
    {
        if(a % i == 0 && b % i == 0)
        {
            ans *= i;
        }
        if(a % i == 0)
        {
            a /= 2;
        }
        if(b % i == 0)
        {
            b /= 2;
        }
    }
        return ans;
}

int main()
{
    int a, b;
    for(int i = 0; i < 6; i++)
    {
        cout<<"Enter two numbers: ";
        cin>>a>>b;

        cout<<"GCD using Euclid's algorithm: "<<euclidAlgoGCD(a, b)<<endl;
        cout<<"GCD using consecutive integers: "<<consecutiveInteger(a, b)<<endl;
        cout<<"GCD using middleschool method: "<<middleSchool(a, b)<<endl;
    }
    return 0;
}