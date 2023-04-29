#include <bits/stdc++.h>
using namespace std;

struct Activity
{
    int activtyNumber;
    int startTime;
    int finishTime;
};

bool comparator(Activity a, Activity b)
{
    return (a.finishTime < b.finishTime);
}

void fillVector(vector<Activity>& arr)
{
    int s[6] = {1, 3, 0, 5, 8, 5};
    int f[6] = {2, 4, 6, 7, 9, 9};
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i].activtyNumber = i;
        arr[i].startTime = s[i];
        arr[i].finishTime = f[i];
    }
}

vector<Activity> activitySelection(vector<Activity> arr)
{
    sort(arr.begin(), arr.end(), comparator);
    vector<Activity> ans;

    int prev = 0;
    ans.push_back(arr[0]);

    for (int curr = 1; curr < arr.size(); curr++)
    {
        if (arr[curr].startTime >= arr[prev].finishTime)
        {
            ans.push_back(arr[curr]);
            prev = curr;
        }
    }
    
    return ans;
}

void display(vector<Activity> arr)
{
    for (auto i : arr)
    {
        cout << i.activtyNumber << " ";
        cout << i.startTime << " ";
        cout << i.finishTime << " ";
        cout << endl;
    }
}

int main()
{
    vector<Activity> arr(6);
    vector<Activity> ans;

    fillVector(arr);
    ans = activitySelection(arr);

    display(ans);

    return 0;
}