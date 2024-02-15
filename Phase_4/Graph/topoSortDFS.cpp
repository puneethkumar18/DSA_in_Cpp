#include<iostream>
#include <list>
#include <unordered_map>
#include<stack>
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
void topoSort (int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj,stack<int> &s){
    visited[node] = true;

    for (auto neighbour:adj[node]){
        if(!visited[neighbour]){
            topoSort(neighbour,visited,adj,s);
        }
    }
    s.push(node);

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

    for (int i = 0; i < nodes; i++)
    {
        int u, v;
        cin >> u >> v;
        g.insert(u, v, 0);
    }
    g.printGraph();

    stack<int> s;
    unordered_map<int,bool> visited;
    for(int i = 0;i < nodes;i++){
        if(!visited[i]){
            topoSort(i,visited,g.adj,s);
        }
    }

    for(int i=0;i<s.size();i++){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
