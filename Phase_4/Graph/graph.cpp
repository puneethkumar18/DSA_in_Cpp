#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

template <typename T>
//graph implementation by adjacency list
class Graph{
    public:
    unordered_map<T , list<T>> adj;

    void insert(int u , int v, bool direction){
        //direction shows -> whether the graph if directed or not
        // direction =  1 means directed, 0 for UnDirected
        adj[u].push_back(v);
        if(!direction)
        adj[v].push_back(u);
    }

    void printGraph(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph<T> g;

    int nodes;

    cout<<"Enter the number of nodes"<<endl;
    cin>>nodes;

    cout<<"Enter the number of edges"<<endl;
    int edges;
    cin>>edges;

    for(int i=0; i<nodes; i++){
        int u, v;
        cin>>u>>v;
        g.insert(u,v,0);
    }
    g.printGraph();
}