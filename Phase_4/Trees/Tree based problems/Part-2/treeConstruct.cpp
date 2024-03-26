#include <iostream>
#include <queue>
using namespace std;


//Tree consruct using Inorder and preOrder list/array
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
int findPosition(vector<int> in, int ele,int n){
    for(int i=0;i<n;i++){
        if(in[i] == ele)
            return i;
    }
    return -1;
}
Node* solve(vector<int> in,vector<int> pre,int &preIndex,int inOrderstart,int inOrderEnd,int n){
    if(preIndex >= n || inOrderstart > inOrderEnd){
        return NULL;
    }
    int element = pre[preIndex++];
    Node* root = new Node(element);
    int position = findPosition(in,element,n);

    root->left = solve(in,pre,preIndex,inOrderstart,position-1,n);
    root->right = solve(in,pre,preIndex,position,inOrderEnd,n);

    return root;
}
Node* buildTree(vector<int> in ,vector<int> pre,int n){
    int preIndex = 0;
    Node* result = solve(in,pre,preIndex,0,n-1,n);
    return result;
}
void printPost(Node* root){
    if(root == NULL){
        return;
    }
    printPost(root->left);
    cout << root->data << " ";
    printPost(root->left);
}

int main(){
    vector<int> inOrder = {3,1,4,0,5,2};
    vector<int> preOrder = {0,1,3,4,2,5};
    Node* root = buildTree(inOrder,preOrder,6);
    printPost(root);
    return 0;
}