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
    G->print();
    int n = G->adj.size();

    int t;
    cout << "Enter the Target Node" << endl;
    cin >> t;

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    queue<int> q;
    q.push(0);
    visited[0] = true;
    parent[0] = -1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        vector<int> temp = G->adj[node];
        for (int i = 0; i < temp.size(); i++)
        {
            if (!visited[temp[i]])
            {
                visited[temp[i]] = true;
                parent[temp[i]] = node;
                q.push(temp[i]);
            }
        }
    }
    vector<int> ans;
    int currentNode = t;
    ans.push_back(t);
    while (currentNode != 0)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i << " ,";
    }
    cout << endl;
    return 0;
}
