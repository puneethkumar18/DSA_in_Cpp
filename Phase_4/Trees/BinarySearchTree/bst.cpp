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
int main(){
    vector<int> list = {10,7,5,8,15,17,16,20};
    int size = list.size();
    Node* root;
    // for(int i=0;i<size;i++){
    //     insertNode(root,list[i]);
    // }
    takeInput(root);
    printTree(root);
    return 0;
}