#include<iostream>
#include<queue>
using namespace std;

class Node{
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

pair<int,int> diameterOfTree(Node* root){
    if(!root){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int, int> left = diameterOfTree(root->left);
    pair<int,int> right = diameterOfTree(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.first+right.first+1;

    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second  = max(left.second,right.second)+1;

    return ans;
}

int main()
{
    Node *root = buildtree(root);

    printTree(root);

    pair<int,int> ans = diameterOfTree(root);

    cout << "Diameter of the tree " << ans.first << endl;
    cout<< "Height of the Tree "<< ans.second<<endl;
    return 0;
}