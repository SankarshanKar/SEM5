#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int val;
    int weight;
};

bool comp(Item p1, Item p2)
{
    double r1 = (double)p1.val / (double)p1.weight;
    double r2 = (double)p2.val / (double)p2.weight;
    return r1 > r2;
}

double fractionalKnapsack(Item arr[], int C, int n)
{

    sort(arr, arr + n, comp);

    double maxProfit=0.0;
    int currWeight=0;

    for(int i=0; i<n; i++)
    {
        if(currWeight+arr[i].weight<=C)
        {
            currWeight+=arr[i].weight;
            maxProfit+=arr[i].val;
        }
        else
        {
            int remainWeight= C- currWeight;
            maxProfit += (arr[i].val/(double)arr[i].weight) * (double)remainWeight;
            break; //knapsack full
        }
    }

    return maxProfit;
}

int main()
{   
    struct Item arr[4];
    arr[0].val = 4;
    arr[0].weight = 10;
    arr[1].val = 14;
    arr[1].weight = 5;
    arr[2].val = 5;
    arr[2].weight = 3;
    arr[3].val = 12;
    arr[3].weight = 15;
    int cap = 20;
    cout<<"MAX profit possible: " <<fractionalKnapsack(arr, cap, 4)<<endl;
}