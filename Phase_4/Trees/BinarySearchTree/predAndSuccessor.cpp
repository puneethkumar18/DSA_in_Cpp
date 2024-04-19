#include<iostream>
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


pair<int,int> predessorAndSuccessorOfNode(Node* root, int k){
    Node* temp = root;
    int pred = -1;
    int sucs = -1;

    while (temp->data != k)
    {
        if(temp->data > k){
            sucs = temp->data;
            temp = root->left;
        }else
        {
            pred = temp->data;
            temp = root->right;
        }
    }

    Node* leftTree = temp->left;

    while (leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->left;
    }
    Node* rightTree = temp->right;
    while (rightTree != NULL)
    {
        sucs = rightTree->data;
        rightTree = rightTree->right;
    }
    
    pair<int,int> ans = make_pair(pred,sucs);
    //Node's leftsubtree's maxValue is Predessor
    //Node's rigtSubtree's minvalue is Successor
    return 
    
}


int main(){
    vector<int> list = {10, 7, 5, 8, 15, 17, 16, 20};
    int size = list.size();
    Node *root = NULL;
    for (int i = 0; i < size; i++)
    {
        insertNode(root, list[i]);
    }
    inOrderPrint(root);
    cout << endl;
    int k;
    cout<<"Enter the k value -> ";
    cin>>k;
    cout<<endl;
    
    cout<<"Predessor of the "<<k <<" is -> "<<predessorOfNode(root,k)->data<<endl;
    cout << "Successor of the " << k << " is -> " << successorOfNode(root, k)->data << endl;
    return 0;
}