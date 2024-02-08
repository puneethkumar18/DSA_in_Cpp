#include <iostream>
#include <list>
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

bool isCyclicDFS(int node , int parent, unordered_map<int,bool> &visited,unordered_map<int,list<int> > &adj){
    visited[node] = true;

    for(auto i:adj[node]){
        if(!visited[i]){
            bool cycleCheck = isCyclicDFS(i,node,visited,adj);
            if(cycleCheck)
                return true;
        }else if(i != parent){
            return true;
        }
    }
    return false;
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

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        g.insert(u, v, 0);
    }
    g.printGraph();

    unordered_map<int, bool> visited;
    visited[0] = true;

    for(int i=0;i<nodes;i++){
        if(!visited[i]){
            bool ans = isCyclicDFS(i,-1,visited,g.adj);
            if(ans == 1){
                cout<<"Yes"<<endl;
                break;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
}