#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;


class Graph{
    public:
    unordered_map<int,list<int>> adj;

    void insert(int u, int v, bool isDirected){
        this->adj[u].push_back(v);
        if(isDirected){
            this->adj[v].push_back(u);
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
int main(){
    Graph G;

    int edges;
    int vertices;
    cout<<"Enter the number of vertices "<<endl;
    cin>>vertices;
    cout<<"Enter the number of Edges "<<endl;
    cin>>edges;

    bool isdirected = false;
    cout<<"Is the grapg is directed or undirected \n if it is directed press 1 \n else if it is undirected press 0 "<<endl;
    cin>>isdirected;
    cout<<"Enter the edges betwwen Vertices"<<endl;
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        G.insert(u,v,isdirected);
    }
    G.printGraph();

    queue<int> q;
    unordered_map<int, int> indegree;
    for(auto node:G.adj){
        for(auto neighbour:node.second){
            indegree[neighbour] += 1;
        }
    }
    for(auto i:indegree){
        if(i.second == 0)
           q.push(i.first);
    }
cout<<"puneeth"<<endl;
    vector<int> ans;
    while (!q.empty()){
        int front =  q.front();
        q.pop();
        ans.push_back(front);
        for(auto i:G.adj[front]){
            indegree[i] --;
            if(indegree[i] == 0){
                q.push(i);
            }
        }

    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<",";
    }
    cout<<endl;
    
    
}