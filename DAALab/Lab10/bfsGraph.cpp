#include <bits/stdc++.h>
using namespace std;

vector<string> color;
vector<int> dist;
vector<int> parent;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void BFS(vector<int> adj[], int source, vector<int> &bfs, int &count)
{

    queue<int> q;
    q.push(source);

    color[source] = "grey";
    dist[source] = 0;

    while (q.empty() != true)
    {

        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto i = adj[node].begin(); i < adj[node].end(); i++)
        {
            ++count;
            if (color[*i] == "white")
            {
                color[*i] = "grey";
                dist[*i] = dist[node] + 1;
                parent[*i] = node;

                q.push(*i);
            }
        }

        color[node] = "black";
    }
}

void BFStraversal(vector<int> adj[], int n)
{
    color.assign(n, "white");
    dist.assign(n, 0);
    parent.assign(n, -1);

    vector<int> bfs;

    int count = 0;

    BFS(adj, 6, bfs, count);

    for (auto it : bfs)
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

    BFStraversal(adj, n);

    return 0;
}