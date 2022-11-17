#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int v1, int v2, int wt)
{

    adj[v1].push_back(make_pair(v2, wt));
    adj[v2].push_back(make_pair(v1, wt));
}

void primMST(vector<pair<int, int>> adj[], int V)
{
    int parent[V];
    int dist[V];
    char mst[V];

    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
        dist[i] = INT_MAX;
        mst[i] = 'F';
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[0] = 0;
    parent[0] = -1;

    pq.push({0, 0});
    for (int i = 0; i < V - 1; i++)
    {
        int curridx = pq.top().second;
        pq.pop();

        mst[curridx] = 'T';

        for (auto itr : adj[curridx])
        {
            int neighIDX = itr.first;
            int wt = itr.second;
            if (mst[neighIDX] == 'F' && wt < dist[neighIDX])
            {
                parent[neighIDX] = curridx;
                dist[neighIDX] = wt;
                pq.push({dist[neighIDX], neighIDX});
            }
        }
    }

    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << "\n";
    }
}

int main()
{
    int V = 14;
    vector<pair<int, int>> adj[V];
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);
    primMST(adj, V);

    return 0;
}