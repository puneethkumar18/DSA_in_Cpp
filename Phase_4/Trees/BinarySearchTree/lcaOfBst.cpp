#include<iostream>
#include<queue>
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
//lowest ancestor of two node
int lca(Node* root,int p,int q){
    while(root != NULL){
        if(root->data > p && root->data > q){
            root = root->left;
        }
        else if (root->data < p && root->data < q)
        {
            root = root->right;
        }
        else{
            return root->data;
        }
    }
    return 0;
}

int main(){
    Node* root = buildtree(root);
    int p ,q;
    cout<<"Enter the first node -> ";
    cin>>p;
    cout<<endl;
    cout << "Enter the Second node -> ";
    cin >> q;
    cout << endl;
    printTree(root);
    cout<<"Lowest common ancester is -> "<<lca(root,p,q)<<endl;
    return 0;
}