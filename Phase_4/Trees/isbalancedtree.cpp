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

int heightOfTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = heightOfTree(root->left) + 1;
    int rightHeight = heightOfTree(root->right) + 1;
    return max(leftHeight, rightHeight);
}

pair<bool,int> balanceCheckWithoutHeight(Node* root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true,1);
        return p;
    }

    pair<bool,int> left = balanceCheckWithoutHeight(root->left);
    pair<bool,int> right = balanceCheckWithoutHeight(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;
     pair<bool,int> ans;
     ans.second = max(left.second,right.second)+1;

     if(leftAns && rightAns && diff){
        ans.first = true;
     }else{
        ans.first = false;
     }
     return ans;
}

bool isBalacedTree(Node *root)
{
    if (root == NULL)
    {
        return true;
    }

    bool left = isBalacedTree(root->left);
    bool right = isBalacedTree(root->right);

    bool diff = abs(heightOfTree(root->left) - heightOfTree(root->right)) <= 1;

    if(left && right && diff){
        return true;
    }else{
        return false;
    }
}

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

int main()
{
    Node *root;

    buildTree(root);
    levelOrderTraversel(root);

    cout << "Tree is Balanced ->" << isBalacedTree(root)<<endl;
    cout << "Tree is Balanced  without using Height function ->" << isBalacedTree(root) << endl;
    return 0;
}