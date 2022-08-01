#include<iostream>
#include<cmath>
using namespace std;

void checkPrimeOne(int num)
{
    if(num == 0 || num == 1)
    {
        return;
    }
    int flag = 0;
    int count = 0;
    for(int i = 2; i < num; i++)
    {
        count++;
        if(num % i == 0)
        {
            flag = 1;
            cout<<num<<" is Non prime"<<endl;
            break;
        }
    }
    if(flag == 0)
    {
        cout<<num<<" is Prime"<<endl;
    }
    cout<<"No. of steps: "<<count<<endl;
}

void checkPrimeTwo(int num)
{
    if(num == 0 || num == 1)
    {
        return;
    }
    int flag = 0;
    int count = 0;
    for(int i = 2; i <= num / 2; i++)
    {
        count++;
        if(num % i == 0)
        {
            flag = 1;
            cout<<num<<" is Non prime"<<endl;
            break;
        }
    }
    if(flag == 0)
    {
        cout<<num<<" is Prime"<<endl;
    }
    cout<<"No. of steps: "<<count<<endl;

}

void checkPrimeThree(int num)
{
    if(num == 0 || num == 1)
    {
        return;
    }
    int flag = 0;
    int count = 0;
    for(int i = 2; i <= sqrt(num); i++)
    {
        count++;
        if(num % i == 0)
        {
            flag = 1;
            cout<<num<<" is Non prime"<<endl;
            break;
        }
    }
    if(flag == 0)
    {
        cout<<num<<" is Prime"<<endl;
    }
    cout<<"No. of steps: "<<count<<endl;
}

int main()
{
    int num;
    for(int i = 0; i < 10; i++)
    {
        cout<<"Enter number: ";
        cin>>num;

        checkPrimeOne(num);
        checkPrimeTwo(num);
        checkPrimeThree(num);
        cout<<endl;
    }

    return 0;
}