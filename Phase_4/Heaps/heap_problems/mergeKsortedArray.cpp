#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    int i;
    int j;

    Node(int data,int i,int j){
        this->data = data;
        this->i = i;
        this->j = j;
    }
};

class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArray(vector<vector<int>> &arr,int k){
    priority_queue<Node* ,vector<Node*>, compare> pq;

    vector<int> ans;

    for(int i=0;i < k;i++){
        Node* temp = new Node(arr[i][0],i,0);
        pq.push(temp);
    }

    while (pq.size() > 0)
    {
        Node* top = pq.top();
        pq.pop();
        ans.push_back(top->data);
        int row = top->i;
        int col = top->j;
        

        col++;
        if(col < arr[row].size()){
            Node* temp = new Node(arr[row][col],row,col);
            pq.push(temp);
        }
    }
    return ans;
}

void printArray(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<vector<int>> karray = {
        {1},
        {2},
        {3},
        {3, 5, 9},
        {4},
        {1, 2, 3, 4}
    };
    vector<int> result = mergeKSortedArray(karray,karray.size());
    printArray(result);
    return 0;
}