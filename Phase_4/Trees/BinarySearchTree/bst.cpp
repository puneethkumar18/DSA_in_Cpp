#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    
};
void insertNode(Node* &root,int data){
    if(root ==  NULL){
        Node* temp = new Node(data);
        root = temp;
        return;
    }
    if(root->data < data){
        insertNode(root->right,data);
    }
    else{
        insertNode(root->left,data);
    }
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
void takeInput(Node* &root){
    int data;
    cout<<"Enter the first data -> ";
    cin>>data;
    
    while (data != -1)
    {
        insertNode(root,data);
        cout << "Enter the next data -> ";
        cin >> data;
        
    }
    
}
bool searchInBST(Node* &root,int search){
    if(root == NULL){
        return false;
    }
    if(root->data == search){
        return true;
    }
    if(root->data > search){
        bool left = searchInBST(root->left,search);
        return left;
    }
    bool right = searchInBST(root->right, search);
    return right;
}

Node* minValue(Node* root){
    Node* temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left ; 
    }
    return temp;
}
Node* maxValue(Node* root){
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
void deleteInBST(Node* &root, int value)
{
    if (root == NULL)
    {
        return ;
    }
    if(root->data == value){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return ;
        }
        //One child
        if(root->left != NULL && root->right == NULL){
            root = root->left;
            delete root->left ;
            return;
        }
        if (root->left == NULL && root->right != NULL)
        {
            root = root->right;
            delete root->right;
            return;
        }

        //Two child
        if(root->left != NULL && root->right != NULL){
            int mini = minValue(root->right)->data;
            root->data = mini;
            deleteInBST(root->right,mini);
            return;
        }
    }else{
        if(root->data > value){
            deleteInBST(root->left,value);
        }else{
            deleteInBST(root->right,value);
        }
    }
}

void inOrderPrint(Node* root){
    if(root == NULL){
        return ;
    }
    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);
}
int main(){
    vector<int> list = {10,7,5,8,15,17,16,20};
    int size = list.size();
    Node* root = NULL;
    for(int i=0;i<size;i++){
        insertNode(root,list[i]);
    }
    // takeInput(root);
    cout<<"Enter the element to search and delete -> ";
    int search;
    cin>>search;
    cout<<"The element present in tree get 1 else 0 :"<<endl<<searchInBST(root,search)<<endl;

    cout<<"The minimum element of the binary serach tree is -> "<<minValue(root)->data<<endl;
    cout << "The maximum element of the binary serach tree is -> " << maxValue(root)->data << endl;
    // printTree(root);
    cout<<"Before deletion -> "<<endl;
    inOrderPrint(root);
    cout << endl;
    deleteInBST(root,search);
    cout<<"After deletion -> "<<endl;
    inOrderPrint(root);
    cout<<endl;
    return 0;
}