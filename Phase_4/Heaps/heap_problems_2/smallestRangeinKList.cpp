#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    int row;
    int col;

    node(int data,int row,int col){
        this->col = col;
        this->data = data;
        this->row = row;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

int smallestrangeinlist(vector<vector<int>> list,int k,int n){
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<node*, vector<node*> , compare> pq;

    
    if(k == 0){
        return 0;
    }
    for(int i=0;i<k;i++){
        node* temp  = new node(list[i][0],i,0);
        pq.push(temp);
        mini = min(mini,temp->data);
        maxi = max(maxi, temp->data);
    }

    int start = mini;
    int end = maxi;

    while (!pq.empty())
    {
        node* temp  = pq.top();
        pq.pop();

        mini = temp->data;

        
        if(temp->col+1 < n){
            maxi = max(maxi,list[temp->row][temp->col+1]);
            pq.push(new node(list[temp->row][temp->col+1], temp->row, temp->col+1));
            if (maxi - mini < end - start)
            {
                start = mini;
                end = maxi;
            }
        }else{
            break;
        }
    }
    return (end - start + 1);
}

int main(){
    vector<vector<int>> list = {
        {1,3,11},
        {2,3,20},
        {5,6,12}
    };
    int res = smallestrangeinlist(list,3,3);
    cout<<"Smallest Range between -> "<<res<<endl;
    return 0;
}