#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

unordered_map<int,int> OrderMap;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void printTree(Node* &root){
    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    
}
void printInOrder(Node* &root){
    if(root == NULL){
        return ;
    }
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}

void inOrderMap(vector<int> inOrder,int n){
    for(int i=0;i<n;i++){
        OrderMap[inOrder[i]] = i;
    }
}

Node* buildWithPostAndInOder(vector<int> in,vector<int> post,int& postIndex,int inStartIndex,int inEndIndex,int n){
    if(postIndex < 0 || inStartIndex > inEndIndex){
        return NULL;
    }
    int ele = post[postIndex--];
    Node* root = new Node(ele);
    int position = OrderMap[ele];

    root->right = buildWithPostAndInOder(in, post, postIndex, position, inEndIndex, n);
    root->left = buildWithPostAndInOder(in,post,postIndex,inStartIndex,position-1,n);
    
    return root;
}

int main()
{
    vector<int> in = {4,8,2,5,1,6,3,7};
    vector<int> post = {8,4,5,2,6,7,3,1};
    int n = in.size();
    inOrderMap(in,n);
    int postIndex = n-1;
    Node* root = buildWithPostAndInOder(in,post,postIndex,0,n-1,n);
    printInOrder(root);
    return 0;
}