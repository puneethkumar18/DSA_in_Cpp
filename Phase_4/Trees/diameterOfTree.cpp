#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(Node* &root){
    cout<<"Enter the data of the root node"<< endl;
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the value to insert into left of node -> "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the value to insert into right of node -> "<<data<<endl;
    cout<<root->data<<endl;
    root->right = buildTree(root->right);
    return root;
   // 2 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
}


int heightOfTree(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    return max(leftHeight,rightHeight);    
}

int Diameter(Node* root){
    if(root == NULL){
        return 0;
    }

    int op1 = Diameter(root->left);
    int op2 = Diameter(root->right);
    int op3 = heightOfTree(root->left)+heightOfTree(root->right)+1;

    int ans = max(op1,max(op2,op3));
    return ans;
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

int main(){
    Node* root;

    buildTree(root);
    levelOrderTraversal(root);

    cout<<"Diameter of the Tree is -> "<<Diameter(root)<<endl;

}