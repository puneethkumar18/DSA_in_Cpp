#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data ){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *&root)
{
    cout << "Enter the value of node" << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting left of" << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void printArray(vector<int> in){
    for(int i=0;i<in.size();i++){
        cout<<in[i]<<" ";
    }
    cout<<endl;
}

void inOrder(Node* root,vector<int> &in){
    if(root == NULL){
        return;
    }
    inOrder(root->left,in);
    in.push_back(root->data);
    inOrder(root->right,in);

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

void fillInOrder(Node* &root ,vector<int> in,int &index){
    if(root == NULL){
        return ;
    }
    cout<<in[index]<<endl;
    root->data = in[index++];
    fillInOrder(root->left,in,index);
    fillInOrder(root->right,in,index);
}

void convertBSTtoMinHeap(Node* root){
    vector<int> in;
    inOrder(root,in);
    printArray(in);
    int index = 0;
    fillInOrder(root,in,index);
}
int main(){

    Node* root = buildTree(root);
    printTree(root);
    convertBSTtoMinHeap(root);
    printTree(root);

    return 0;
}