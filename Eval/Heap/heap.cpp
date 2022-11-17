#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    vector<int> arr;
    
    int left(int i)
    {
        return(2 * i + 1);
    }
    int right(int i)
    {
        return(2 * i + 2);
    }
    int parent(int i)
    {
        return((i - 1) / 2);
    }

    public:
        void insertElement(int x)
        {
            arr.push_back(x);
            for (int i = arr.size() - 1; i != 0 && arr[parent(i)] > arr[i];)
            {
                swap(arr[i], arr[parent(i)]);
                i = parent(i);
            }
        }
        void minHeapify(int i)
        {
            int smallest = i;
            if (left(i) < arr.size() && arr[left(i)] < arr[i])
            {
                smallest = left(i);
            }
            if (right(i) < arr.size() && arr[right(i)] < arr[smallest])
            {
                smallest = right(i);
            }
            if (smallest != i)
            {
                swap(arr[i], arr[smallest]);
                minHeapify(smallest);
            }
        }
        int extractMin()
        {
            if (arr.size() == 0)
            {
                return INT_MAX;
            }
            if (arr.size() == 1)
            {
                int temp = arr[0];
                arr.pop_back();
                return temp;
            }
            
            int temp = arr[0];
            swap(arr[0], arr[arr.size() - 1]);
            arr.pop_back();
            minHeapify(0);
            return temp;
        }
        void decreaseKey(int i, int x)
        {
            swap(arr[i], x);
            while ( i != 0 && arr[parent(i)] > arr[i])
            {
                swap(arr[i], arr[parent(i)]);
                i = parent(i);
            }
        }
        void deleteKey(int i)
        {
            decreaseKey(i, INT_MIN);
            extractMin();
        }
        void display()
        {
            for (int i : arr)
            {
                cout << i << " ";
            }
            cout << endl;
        }
};

int main()
{
    MinHeap h;
    h.insertElement(20);
    h.insertElement(25);
    h.insertElement(30);
    h.insertElement(35);
    h.insertElement(40);
    h.insertElement(80);
    h.insertElement(32);
    h.insertElement(100);
    h.insertElement(70);
    h.insertElement(60);

    h.display();

    h.deleteKey(3);
    h.display();

    return 0;
}