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
//kth element means if k = 3 3rd element of the inOrderTravesel
int kthSmallestElement(Node* root, int &i,int k){
    if(root == NULL){
        return -1;
    }
    int left = kthSmallestElement(root->left,i,k);
    if(left != -1){
        return left;
    }
    i++;
    if(i == k){
        return root->data;
    }
    return kthSmallestElement(root->right,i,k);
}
int kthBiggestElement(Node* root,int &i,int k){
    if(root == NULL){
        return -1;
    }
    int right = kthBiggestElement(root->right,i,k);
    if(right != -1){
        return right;
    }
    i++;
    if(i == k){
        return root->data;
    }
    return kthBiggestElement(root->left,i,k);
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
    int k;
    int i = 0;
    cout<<"InOrder ->"<<endl;
    inOrderPrint(root);
    cout<<endl;
    cout<< "enter the k value for smallest element -> ";
    cin>>k;
    cout<<endl;
    cout<<"Kth smallest elemet of the tree is ->"<<kthSmallestElement(root,i,k)<<endl;
    int j;
    int m = 0; 
    cout<<"Enter the k value for biggest element ->";
    cin>>j;
    cout<<endl;
    cout << "Kth Biggest elemet of the tree is ->" << kthBiggestElement(root, m, j) << endl;
    return 0;
}