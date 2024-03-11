#include<iostream>
#include<queue>
using namespace std;

class Node {
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

Node* buildtree(Node* &root){
    cout<<"Enter the data of the node"<<endl;
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    }
    root = new Node(data);

    cout<<"Enter the left node of "<<data<<" ?"<<endl;
    root->left = buildtree(root->left);
    cout << "Enter the right node of " << data << " ?" << endl;
    root->right = buildtree(root->right);

    return root;
}

int height(Node* &root){
    if(root == NULL){
        return 0;
    }

    int left  =  height(root->left);
    int right = height(root->right);

    return max(left,right)+1;
}

void printTree(Node* &root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

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

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        
    }
    
}

int main(){
    cout<<"Tree build"<<endl;
    Node* root = buildtree(root);

    cout<<"Height of the tree is "<<height(root)<<endl;

    printTree(root);
    
    return 0;
}