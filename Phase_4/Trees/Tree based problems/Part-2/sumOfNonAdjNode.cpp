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
pair<int,int> solve(Node* root){
    if(root == NULL){
        pair<int,int > p = make_pair(0,0);
        return p;
    }
    pair<int, int> leftAns = solve(root->left);
    pair<int,int> rightAns = solve(root->right);

    pair<int,int> res;
    res.first = root->data+leftAns.second+rightAns.second;
    res.second = max(leftAns.first,leftAns.second) + max(rightAns.first,rightAns.second);

    return res;
}

int sumofnonadjnode(Node* &root){
    pair<int,int> result = solve(root);
    return max(result.first,result.second);
}
int main(){
    Node* root = buildtree(root);
    printTree(root);
     cout<<"Max Sum of the Non Adjacent Node is -> "<<sumofnonadjnode(root)<<endl;
    return 0;
}