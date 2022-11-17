#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFS(vector<int> adj[], int node, int vis[], vector<int> &dfs, int &count)
{
    vis[node] = 1;
    dfs.push_back(node);

    for (auto it : adj[node])
    {
        count++;
        if (vis[it] != 1)
        {
            DFS(adj, it, vis, dfs, count);
        }
    }
}

void DFStraversal(vector<int> adj[], int n)
{
    int vis[n] = {0};
    int start = 6;
    vector<int> dfs;

    int count = 0;

    DFS(adj, start, vis, dfs, count);

    for (auto it : dfs)
    {
        cout << it << " ";
    }

    cout << endl
         << "Time complexity: " << count << endl;
}

int main()
{
    int n = 7;

    vector<int> adj[n];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 2, 6);

    DFStraversal(adj, n);

    return 0;
}