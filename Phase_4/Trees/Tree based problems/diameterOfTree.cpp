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
void printTree(Node *&root)
{
    queue<Node* > q;
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

int height(Node *&root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;
}

int diameterOfTree(Node* &root){
    if(root == NULL){
        return 0;
    }

    int op1 = diameterOfTree(root->left);
    int op2 = diameterOfTree(root->right);
    int op3 = height(root->left)+1+height(root->right);

    return max(op1,max(op2,op3));
}

Node* buildtree(Node* &root){
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


int main(){
    Node* root = buildtree(root);

    printTree(root);

    cout<<"Height of the tree "<<height(root)<<endl;

    cout<<"Diameter of the tree "<<diameterOfTree(root)<<endl;
    return 0;
}