#include <iostream>
#include <list>
#include<queue>
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

bool isCyclicByBFS(int node, unordered_map<int ,bool> &visited,unordered_map<int, list<int>> adj){
    unordered_map<int,int> parent;

    parent[node] = -1;
    visited[node] = true;
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbour:adj[front]){
            if(visited[neighbour] == true && neighbour != parent[front]){
                return true;
            }else if(!visited[neighbour]){
                q.push(neighbour);
                parent[neighbour] = front;
                visited[neighbour] = true;
            }
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


    cout<<"Is Graph is Cycle ->  ";

    for(int i=0;i<nodes;i++){
        if(!visited[i]){
            bool ans = isCyclicByBFS(i, visited, g.adj);
            if (ans == 1)
            {
                cout<<" Yes"<<endl;
                break;
            }else{
                cout<<"No!"<<endl;
            }
            
        }
    }
}