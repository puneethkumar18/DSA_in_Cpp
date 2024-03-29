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
void insertNode(Node *&root, int data)
{
    if (root == NULL)
    {
        Node *temp = new Node(data);
        root = temp;
        return;
    }
    if (root->data < data)
    {
        insertNode(root->right, data);
    }
    else
    {
        insertNode(root->left, data);
    }
}
void inOrderPrint(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderPrint(root->left);
    cout << root->data << " ";
    inOrderPrint(root->right);
}
bool validteBST(Node* root ,int max , int min){
    if(root == NULL){
        return true;
    }
    if(root->data > min && root->data < max){
        bool left = validteBST(root->left,root->data,min);
        bool right = validteBST(root->right,max,root->data);

        return left && right;
    }
    return false;
}
void inOrderValidate(Node* root,vector<int> &ans){
    if(root == NULL){
        return ;
    }
    
    inOrderValidate(root->left,ans);
    ans.push_back(root->data);
    inOrderValidate(root->right,ans);

    
}
int main()
{
    vector<int> list = {10, 7, 5, 8, 15, 17, 16, 20};
    int size = list.size();
    Node *root = NULL;
    for (int i = 0; i < size; i++)
    {
        insertNode(root, list[i]);
    }
    vector<int> ans ;
    inOrderValidate(root,ans);
    cout<<"Checking tree inOrder method ->"<<endl;
    bool res = true;
    for(auto j:ans){
        cout<<j<< " ";
    }
    cout<<endl;
    for(int i=0 ;i<7;i++){
        if(ans[i] > ans[i+1]){
            res = false;
        }
    }
    cout<<res<<endl;
    cout<<"Checking whether the tree is valid(1) or not(0) -> "<<validteBST(root,INT_MAX,INT_MIN)<<endl;
}