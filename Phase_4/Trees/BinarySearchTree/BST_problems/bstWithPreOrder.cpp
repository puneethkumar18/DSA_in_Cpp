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

void insertIntoBst(Node* &root,int data){
    if(root == NULL){
        Node* temp = new Node(data);
        root = temp;
        return;
    }
    if(root->data > data){
        insertIntoBst(root->left,data);
    }else{
        insertIntoBst(root->right,data);
    }
}

void takeInput(Node* &root){
    int data;
    cout<<"Enter the data -> ";
    cin>>data;
    while (data != -1)
    {
        insertIntoBst(root,data);
        cout << "Enter the data -> ";
        cin >> data;

    }
    
}
void  pretoinVector(vector<int> &pre){
    int size = pre.size();
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            if(pre[j] > pre[j+1]){
                int temp = pre[j];
                pre[j] = pre[j+1];
                pre[j+1] = temp;
            }
        }
    }
    for(int i=0;i<size;i++){
        cout<<pre[i]<<endl;
    }
}
//1st approch with O(n) time complexcity
void bstFromPreOrder(Node* &root,vector<int> pre){
    int size = pre.size();
    for(int i=0;i<size;i++){
        insertIntoBst(root,pre[i]);
    }
    
}
//2nd aprroch is converting preOrder into inorder  gives T.C of O(NlogN)
Node* byInOrder(Node* &root,vector<int> pre,int s,int e){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    Node* temp = new Node(pre[mid]);
    root = temp;
    byInOrder(root->left,pre,s,mid-1);
    byInOrder(root->right,pre,mid+1,e);

    return root;
}
//3rd approch is using preOrder only T.C of O(N)

Node* solve(vector<int> pre, int min, int max, int &index)
{
    if (index >= pre.size())
    {
        return NULL;
    }

    if (pre[index] > max || pre[index] < min)
    {
        return NULL;
    }

    Node *root = new Node(pre[index++]);
    root->left = solve( pre, min, root->data, index);
    root->right = solve( pre, root->data, max, index);

    return root;
}
Node* usingPreBST( vector<int> pre){
    int max = INT_MAX;
    int min = INT_MIN;
    int index = 0;
     return solve(pre,min,max,index);
}


int main(){
    vector<int> preOrder = {20,10,5,15,13,35,30,42};
    Node* root = NULL;
    // bstFromPreOrder(root,preOrder);
    // printTree(root);
    // pretoinVector(preOrder);
    // byInOrder(root,preOrder,0,preOrder.size()-1);
    // printTree(root);

    root = usingPreBST(preOrder);
    printTree(root);
    return 0;
}