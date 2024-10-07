#include <iostream>
#include <unordered_map>
#include <map>
#include <queue>
#include <vector>
#include <stack>
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

void topoSortUsingDFS(int node, map<int, vector<int>> adj, stack<int> &st, unordered_map<int, bool> &visited)
{
    visited[node] = true;

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            topoSortUsingDFS(i, adj, st, visited);
        }
    }
    st.push(node);
}
int main()
{
    // vector<vector<int>> list = {
    //     {1, 2},
    //     {2, 3},
    //     {2, 4},
    //     {4, 5},
    //     {5, 6},
    //     {6, 4},
    //     {3, 4},
    //     {3, 8},
    //     {8, 4},
    // };
    // vector<vector<int>> list = {{1, 2}, {5, 1}, {1, 3}, {1, 4}};
    vector<vector<int>> list = {
        {0, 3},
        {0, 1},
        {1, 2},
        {3, 2},
    };
    Graph g;
    for (int i = 0; i < list.size(); i++)
    {
        int s = list[i][0];
        int e = list[i][1];
        g.insertEdge(s, e, true);
    }
    g.printGraph();

    int start;
    cout << "Enter the starting node of the graph " << endl;
    cin >> start;
    stack<int> st;
    unordered_map<int, bool> visited;
    topoSortUsingDFS(start, g.adj, st, visited);
    while (!st.empty())
    {
        cout << st.top() << ",";
        st.pop();
    }
    cout << endl;
    return 0;
}