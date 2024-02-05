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

pair<bool,int> sum(Node* root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true,0);
        return p;
    }
    if(root->left == NULL && root->right == NULL){
        pair<bool,int> q = make_pair(true, root->data);
        return q;
    }

    pair<bool,int> left = sum(root->left);
    pair<bool, int> right = sum(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool sum1 = root->data == left.second+right.second;

    pair<bool,int > ans;
    if(leftAns&&rightAns&&sum1){
        ans.first = true;
        ans.second = 2*root->data;
    }else{
        ans.first = false; 
    }
    return ans;
}


int main()
{
    Node *root;
    buildTree(root);

    pair<bool,int> ans = sum(root);

    cout<<"Answer is -> "<<ans.first<< " "<<ans.second<<endl;
}
