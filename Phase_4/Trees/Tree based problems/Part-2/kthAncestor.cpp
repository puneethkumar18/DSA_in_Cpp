#include <iostream>
#include <queue>
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

void printTree(Node *&root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data <<" ";

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

Node* solve(Node* root,int &k,int node){
    if(root == NULL){
        return NULL;
    }
    if(root->data == node){
        return root;
    }
    Node* left = solve(root->left,k,node);
    Node* right = solve(root->right,k,node);

    if(left != NULL && right == NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return left;
    }
    else if (left == NULL && right != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return left;
    }
    return NULL;
}

int kthAncestor(Node* root,int k,int node){
    Node* ans = solve(root,k,node);
    return ans->data;
}

int main(){
    Node* root =  buildtree(root);
    printTree(root);
    int k;
    cout<<"Enter k value -> ";
    cin>>k;
    cout<<endl;
    int node;
    cout<<"Enter the Node data -> ";
    cin>>node;
    cout<<endl;
    cout<<"K th ancestor of the node -> "<<kthAncestor(root,k,node)<<endl;

    return 0;
}