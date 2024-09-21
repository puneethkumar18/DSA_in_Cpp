#include <iostream>
#include <vector>
#include <unordered_map>
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

void dfs(unordered_map<int, bool> &visited, unordered_map<int, vector<int>> &adj, int node, vector<int> &ans)
{
    ans.push_back(node);
    visited[node] = true;

    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!visited[adj[node][i]])
        {
            dfs(visited, adj, adj[node][i], ans);
        }
    }
}

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

    for (int i = 1; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(visited, G->adj, i, ans);
        }
    }
    for (auto i : ans)
    {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}
