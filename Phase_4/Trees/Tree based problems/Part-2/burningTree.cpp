#include <iostream>
#include <queue>
#include<map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildtree(Node *&root)
{
    cout << "Enter the data of the node" << endl;
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);

    cout << "Enter the left node of " << data << " ?" << endl;
    root->left = buildtree(root->left);
    cout << "Enter the right node of " << data << " ?" << endl;
    root->right = buildtree(root->right);

    return root;
}


//create mapping with parent
//return parent node
Node* createParentMapping(Node* root,int target,map<Node*,Node*> &nodeToParent){

    Node* result = NULL;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp->data == target){
            result = temp;
        }
        if(temp->left){
            nodeToParent[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right){
            nodeToParent[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return result;
}

int burnTree(Node* root ,map<Node*,Node*> &nodeToParent){
    map<Node*,bool> visited;
    queue<Node*> q;

    q.push(root);
    visited[root] = true;

    int ans = 0;

    while(!q.empty()){
        bool flag = false;
        int size = q.size();
        for(int i=0;i<size;i++){
            Node* front = q.front();
            q.pop();

            if(front->left && !visited[front->left]){
                flag = true;
                q.push(front->left);
                visited[front->left] = true;
            }
            if(front->right && !visited[front->right]){
                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }
            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                flag = true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }
        if(flag == true)
        {
            ans++;
        }
    }
    return ans;
}

int main(){
    Node* root = buildtree(root);

    int target2;
    cout<<"Enter the Traget ->";
    cin>>target2;
    cout<<endl;
    map<Node*,Node*> nodeToParent;
    Node* target = createParentMapping(root, target2, nodeToParent);

    int ans = burnTree(target,nodeToParent);

    cout<<"Time taken to Burn the tree is ->"<<ans<<endl;
}