#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
template <typename T>

class Node
{
public:
    unordered_map<T, list<T>> adjList;

    void insert(int u, int v, bool direction)
    {
        adjList[u].push_back(v);
        if (!direction)
        {
            adjList[v].push_back(u);
        }
    }

    void printGraph()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

bool isCycleInDirecyedGraphByDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, unordered_map<int ,bool> &dfsVisited )
{
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            bool isdirected = isCycleInDirecyedGraphByDFS(neighbour,visited,adj,dfsVisited);
            if(isdirected){
                return true;
            }
        }else if(dfsVisited[neighbour]){
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

int main()
{
    Node<int> g;

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
        g.insert(u, v, 1);
    }
    g.printGraph();

    cout << "Is Graph is Cycle ->  ";

    unordered_map<int,bool> visited;
    unordered_map<int, bool> dfsVisited;

    for(int i=0;i<nodes;i++){
        if(!visited[i]){
            bool directed = isCycleInDirecyedGraphByDFS(i,visited,g.adjList,dfsVisited);
            if (directed){
                cout<<"Yes!"<<endl;
            }else{
                cout<<"NO!"<<endl;
            }
        }
    }
}