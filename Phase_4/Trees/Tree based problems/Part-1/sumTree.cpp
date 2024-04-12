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

//sum of the left and right tree is equal to root
pair<bool,int> sumOfTree(Node* &root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }
    
    pair<bool, int> left = sumOfTree(root->left);
    pair<bool, int> right = sumOfTree(root->right);

    bool isLeftAns = left.first;
    bool isRightAns = right.first;

    bool condition = left.second+right.second == root->data;
    pair<bool,int> ans;
    if (isLeftAns && isRightAns && condition){
        ans.first = true;
        ans.second = 2 * root->data;
    }else{
        ans.first = false;
    }
    return ans;
}

int main()
{
    cout << "Tree build" << endl;
    Node *root = buildtree(root);


    printTree(root);

    cout<<"Sum of the tree is balanced -> "<<sumOfTree(root).first<<endl;

    return 0;
}