#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Graph
{

public:
    unordered_map<int, vector<int>> adj;

    void insert(int a, int b, bool isDirected)
    {
        adj[a].push_back(b);
        if (!isDirected)
        {
            adj[b].push_back(a);
        }
    }

    void print()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{

    Graph *G = new Graph();

    vector<vector<int>> arr = {{1, 2}, {1, 0}, {0, 2}, {2, 3}, {2, 4}};

    for (auto i : arr)
    {
        int a = i[0];
        int b = i[1];

        G->insert(a, b, 0);
    }

    int n = G->adj.size();

    unordered_map<int, bool> visited;

    vector<int> ans;

    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (int i = 0; i < G->adj[node].size(); i++)
        {
            if (!visited[G->adj[node][i]])
            {
                visited[G->adj[node][i]] = true;
                q.push(G->adj[node][i]);
            }
        }
    }

    for (auto i : ans)
    {
        cout << i << " ,";
    }
    cout << endl;
    return 0;
}
