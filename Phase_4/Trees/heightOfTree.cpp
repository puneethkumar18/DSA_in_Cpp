#include<iostream>
#include<queue>

using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* &root){
    cout<<"Enter the vaule of the node"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
   

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the value for inserting left node of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the value for inserting right node of "<<root->data<<endl;
     cout<<root->data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }

    }
}

int heightOfTree(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftHeight =  heightOfTree(root->left)+1;
    int rightHeight = heightOfTree(root->right)+1;
    return max(leftHeight,rightHeight);
}

int main(){
    Node* root;

    buildTree(root);
    levelOrderTraversal(root);
    cout<<"Height of the tree is -> "<<heightOfTree(root)<<endl;
}