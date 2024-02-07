#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;

template <typename T>
// graph implementation by adjacency list
class Graph
{
public:
    unordered_map<T, set<T>> adj;

    void insert(int u, int v, bool direction)
    {
        // direction shows -> whether the graph if directed or not
        //  direction =  1 means directed, 0 for UnDirected
        adj[u].insert(v);
        if (!direction)
            adj[v].insert(u);
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

vector<int> bfs(unordered_map<int,set<int>> adjlist,int node){
    unordered_map<int, bool> visited;
    vector<int> ans;
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        for(auto i:adjlist[temp]){
            if(!visited[i]){
                q.push(i);
                visited[temp] = 1;
            }
        }
    }
    return ans;
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

    vector<int> ans = bfs(g.adj,0);

    for(auto i:ans){
        cout<<"->  "<<i<<" ";
    }
    cout<<endl;
}