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

void topoSortUsingDFS(map<int, vector<int>> adj, vector<int> &st)
{
    queue<int> q;

    unordered_map<int, int> indegree;
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }
    for (auto i : adj)
    {
        if (indegree[i.first] == 0)
        {
            q.push(i.first);
        }
    }
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        st.push_back(front);
        for (auto i : adj[front])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }
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
    vector<vector<int>> list = {{1, 2}, {2, 5}, {1, 3}, {3, 5}, {5, 4}};
    // vector<vector<int>> list = {
    //     {0, 3},
    //     {0, 1},
    //     {1, 2},
    //     {3, 2},
    // };
    Graph g;
    for (int i = 0; i < list.size(); i++)
    {
        int s = list[i][0];
        int e = list[i][1];
        g.insertEdge(s, e, true);
    }
    g.printGraph();

    // int start;
    // cout << "Enter the starting node of the graph " << endl;
    // cin >> start;
    vector<int> st;
    ;
    topoSortUsingDFS(g.adj, st);
    for (auto i : st)
    {
        cout << i << ",";
    }
    cout << endl;
    return 0;
}