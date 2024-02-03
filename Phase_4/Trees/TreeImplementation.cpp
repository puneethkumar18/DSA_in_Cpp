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

Node* buildTree(Node* root){
    cout<<"Enter the value of node"<<endl;
    int data;
    cin>>data;
    root = new Node(data);


   if(data == -1){
    return NULL;
   }

    cout<<"Enter data for inserting left of"<< data<<endl;
    root->left =  buildTree(root->left);
    cout<<"Enter data for inserting right of "<<data<<endl;
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
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        }
    }
}

void  levelOrderBuild(Node* &root){
    queue<Node*> q;
    cout<<"Enter the root "<<endl;
    int data ;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        cout<<"Enter data for inserting left of"<< temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1){
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }
        cout<<"Enter data for inserting right of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata != -1){
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
        
    }
}

//LNR -> Left, node , right
void inOrderTraversal(Node* root){
    if(root == NULL){
        return ;
    }

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

//NLR => node,left,right
void preOrderTraversal(Node* root){
    if(root == NULL){
        return ;
    }

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

//LRN -> left right node
void postOrderTraversal(Node* root){
    if(root == NULL){
        return ;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* root = NULL;

    cout<<"Tree build using level order"<<endl;
    levelOrderBuild(root);

    cout<<"printting level order traversal output"<<endl;
    levelOrderTraversal(root);
    cout<<endl;

    cout<<"printting in order traversal output"<<endl;
    inOrderTraversal(root);
    cout<<endl;

    cout<<"printting pre order traversal output"<<endl;
    preOrderTraversal(root);
    cout<<endl;

    cout<<"printting post order traversal output"<<endl;
    postOrderTraversal(root);
    cout<<endl;

    // 2 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    return 0;
}