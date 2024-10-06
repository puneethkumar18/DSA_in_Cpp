#include <iostream>
#include <unordered_map>
#include<map>
#include<queue>
#include <vector>
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

bool bfs(map<int,vector<int>> adj,int node){
    unordered_map<int, bool> visited;
    unordered_map<int,int> parent;
    visited[node] = true;
    parent[node] = -1;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto i:adj[front]){
            if(visited[i] == true && parent[front] != i){
                return true;
            }else if(!visited[i]){
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }
    return false;

}

int main()
{
    vector<vector<int>> list = {{1,2},{5,1},{1,3},{1,4}};
    Graph g;
    for(int i=0;i<list.size();i++){
        int s = list[i][0];
        int e = list[i][1];
        g.insertEdge(s,e,false);
    }
    g.printGraph();
    int start ;
    cout<<"Enter the starting Node : "<<endl;
    cin>> start;
    bool res =  bfs(g.adj,start);
    cout<<"Graph is having cycle -> "<<res<<endl;
    return 0;
}