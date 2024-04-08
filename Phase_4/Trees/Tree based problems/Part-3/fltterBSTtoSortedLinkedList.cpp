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

void inOrderBST(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inOrderBST(root->left, ans);
    ans.push_back(root->data);
    inOrderBST(root->right, ans);
}

Node* flatterBSTtoSortedlist(Node* root){
    vector<int> ans;
    inOrderBST(root,ans);

    Node* result = new Node(ans[0]);
    Node* current = result;

    for(int i=1;i<ans.size();i++){
        Node* temp = new Node(ans[i]);
        current->right = temp;
        current = temp;
    }
    current->left = NULL;
    current->right = NULL;

    return result;
    
}

int main(){
    Node* root = buildtree(root);
    printTree(root);
    Node* ans = flatterBSTtoSortedlist(root);
    return 0;
}