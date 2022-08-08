#include<iostream>
using namespace std;

int squareRoot(int num)
{
    if(num == 0 || num == 1)
    {
        return num;
    }

    int start = 0, end = num / 2, ans;
    while(start <= end)
    {
        int mid = (start + end) / 2;
        int sqr = mid * mid;

        if(sqr == num)
        {
            return mid;
        }

        if(sqr <= num)
        {
            start = mid + 1;
            ans = mid;
        }

        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int num;
    cout<<"Enter a number: ";
    cin>>num;

    cout<<squareRoot(num)<<endl;

    return 0;
}