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

void solve(Node* &root,int &count,int k,vector<int> path){
    if(root==NULL){
        return ;
    }

    path.push_back(root->data);

    solve(root->left,count,k,path);
    solve(root->right,count,k,path);

    int size = path.size();
    int sum = 0;
    for(int i=0;i<size;i++){
        sum = sum+path[i];
    }
    if(sum == k){
        count++;
    }

}

int sumK(Node* &root, int k){
    vector<int> path;
    int count = 0;
    solve(root,count,k,path);
    return count; 
}

int main(){
    Node* root = buildtree(root);
    printTree(root);

    int k;
    cout<<"Enter the K -> ";
    cin>>k;
    cout<<endl;
    cout<<"Number of paths that have sum of k is -> "<<sumK(root,k)<<endl;
    return 0;
}