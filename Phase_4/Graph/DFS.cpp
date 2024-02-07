#include <iostream>
#include <list>
#include<set>
#include <unordered_map>
using namespace std;

template <typename T>
// graph implementation by adjacency list
class Graph
{
public:
    unordered_map<T, list<T>> adj;

    void insert(int u, int v, bool direction)
    {
        // direction shows -> whether the graph if directed or not
        //  direction =  1 means directed, 0 for UnDirected
        adj[u].push_back(v);
        if (!direction)
            adj[v].push_back(u);
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

vector<int> dfs(
    unordered_map<int, list<int>> adjList, 
    unordered_map<int, bool> &visited, vector<int> &component,int node)
{
    component.push_back(node);
    visited[node] = true;

    for(auto i:adjList[node]){
        if(!visited[i]){
            dfs(adjList,visited,component,i);
        }
    }
    return component;
}

int main()
{
    Graph<int> g;

    int nodes;

    cout << "Enter the number of nodes" << endl;
    cin >> nodes;

    cout << "Enter the number of edges" << endl;
    int edges;
    cin >> edges;

    cout << "Enter the Edges Between the Nodes );" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        g.insert(u, v, 0);
    }
    g.printGraph();

    unordered_map<int, bool> visited;
    vector<vector<int>> ans;

    for (int i = 0; i < edges; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(g.adj,visited,component,i);
            ans.push_back(component);
        }
    }

    for(auto i:ans){
        for(auto j:i){

            cout<<j<<" ";
        }
    }
}