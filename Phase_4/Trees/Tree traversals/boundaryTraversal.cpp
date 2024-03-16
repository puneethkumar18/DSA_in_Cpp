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
        left = NULL;
        right = NULL;
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

void leftNode(Node* root,vector<int> &ans){
    if((root==NULL) || (root->left == NULL && root->right == NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        leftNode(root->left,ans);
    }else{
        leftNode(root->right, ans);
    }
}

void leafNode(Node *root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    if (root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
    }
    leafNode(root->left,ans);
    leafNode(root->right,ans);
}

void rightNode(Node* root,vector<int> &ans){
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if(root->right){
        rightNode(root->right,ans);
    }else{
        rightNode(root->left,ans);
    }

    ans.push_back(root->data);
}

    vector<int> boundary(Node *&root)
{
    vector<int> ans;

    if(root == NULL){
        return ans;
    }
    leftNode(root,ans);
    leafNode(root,ans);
    rightNode(root,ans);

    return ans;
}

int main(){
    Node* root = buildtree(root);
    printTree(root);

    cout<<"Boundary traversal :"<<endl;
    vector<int> result = boundary(root);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}