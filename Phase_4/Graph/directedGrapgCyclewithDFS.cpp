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

bool cycleWithDirectedGraphUsingDFS(unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, int node, map<int, vector<int>> adj)
{

    visited[node] = true;
    dfsvisited[node] = true;

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            bool iscycle = cycleWithDirectedGraphUsingDFS(visited, dfsvisited, i, adj);
            if (iscycle)
            {
                return true;
            }
        }
        else if (dfsvisited[i])
        {
            return true;
        }
    }
    dfsvisited[node] = false;
    return false;
}
int main()
{
    vector<vector<int>> list = {
        {1, 2},
        {2, 3},
        {2, 4},
        {4, 5},
        {5, 6},
        {6, 4},
        {3, 4},
        {3, 8},
        {8, 4},
    };
    // vector<vector<int>> list = {{1, 2}, {5, 1}, {1, 3}, {1, 4}};
    Graph g;
    for (int i = 0; i < list.size(); i++)
    {
        int s = list[i][0];
        int e = list[i][1];
        g.insertEdge(s, e, true);
    }
    g.printGraph();
    int start;
    cout << "Enter the starting Node : " << endl;
    cin >> start;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    bool res = cycleWithDirectedGraphUsingDFS(visited, dfsVisited, start, g.adj);
    cout << "Graph is having cycle -> " << res << endl;
    return 0;
}