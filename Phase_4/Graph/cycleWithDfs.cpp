#include <iostream>
#include <unordered_map>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class Graph
{
public:
    map<int, vector<int>> adj;

    void insertEdge(int s, int edge, bool isDirected)
    {
        adj[s].push_back(edge);
        if (!isDirected)
        {
            adj[edge].push_back(s);
        }
    }

    void printGraph()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
};

bool dfs(map<int, vector<int>> adj, int node, int parent, unordered_map<int, bool> &visited)
{
    visited[node] = true;

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            return dfs(adj, i, node, visited);
        }
        else
        {
            if (i != parent)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> list = {{1, 2}, {5, 1}, {1, 3}, {1, 4}};
    Graph g;
    for (int i = 0; i < list.size(); i++)
    {
        int s = list[i][0];
        int e = list[i][1];
        g.insertEdge(s, e, false);
    }
    g.printGraph();
    int start;
    cout << "Enter the starting Node : " << endl;
    cin >> start;
    unordered_map<int, bool> visited;
    bool res = dfs(g.adj, start, -1, visited);
    cout << "Graph is having cycle -> " << res << endl;
    return 0;
}