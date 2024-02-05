#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        left = NULL;
        right = NULL;
    }
};



Node *buildTree(Node *&root)
{
    cout << "Enter the value of the  Node" << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    else
    {
        root = new Node(data);

        cout << "Enter the value to insert into left Node -> " << data << endl;
        root->left = buildTree(root->left);
        cout << "Enter the val to insert into Right Node -> " << data << endl;
        root->right = buildTree(root->right);
        return root;
    }
}

void levelOrderTraversel(Node *root)
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
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

bool isidentical(Node* r1,Node* r2){
    if (r1 == NULL && r1 == NULL)
    {
        return true;
    }

    if (r1 == NULL && r1 != NULL)
    {
        return false;
    }

    if (r1 != NULL && r1 == NULL)
    {
        return false;
    }

    if(r1->data != r2->data){
        return false;
    }
    bool left = isidentical(r1->left,r2->left);
    bool right = isidentical(r1->right,r2->right);

    if(right && left){
        return true;
    }else{
        return false;
    }

}

bool isIdentical(Node* root1,Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }

    if (root1 == NULL && root2 != NULL)
    {
        return false;
    }

    if (root1 != NULL && root2 == NULL)
    {
        return false;
    }

    
    bool left = isIdentical(root1->left,root2->left);
    bool right =  isIdentical(root1->right,root2->right);

    bool value = root1->data == root2->data;

    if(left && right && value){
        return true;
    }else{
        return false;
    }

}

int main()
{
    Node *root1;
    Node* root2;

    cout<<"Creating first tree >>"<<endl;
    buildTree(root1);
    cout << "Creating Second tree >>" << endl;
    buildTree(root2);
    levelOrderTraversel(root1);
    levelOrderTraversel(root2);

    cout<<"1 for ture"<<endl<<"0 for false"<<endl<<isIdentical(root1,root2)<<endl;
    cout<<"Second approch -> "<<isidentical(root1,root2)<<endl;
    return 0;
}
