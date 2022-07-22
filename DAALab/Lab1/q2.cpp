#include <iostream>
using namespace std;
 int main()
{
    int arr[100];
    int i, j, n, count = 0;
    cout<<"Enter size of the array : ";
    cin>>n;
    cout<<"Enter elements in array : <"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
        if(arr[i] == arr[j])
            {
                count++;
                break;
            }
        }
    }
    cout<<"\nTotal number of duplicate elements found in array: "<<count<<endl;
 
    return 0;
}