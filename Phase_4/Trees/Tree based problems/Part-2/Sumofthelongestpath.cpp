#include<iostream>
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

void solve(Node* root,int &maxSum,int &maxlen,int len,int sum){
    if(root == NULL){
    if(len > maxlen){
        maxlen = len;
        maxSum = sum;
    }else if(len == maxlen){
        maxSum = max(sum,maxSum);
    }
    return ;ˇ
    }
    sum = sum+root->data;
    solve(root->left, maxSum, maxlen, len, sum);
    solve(root->right, maxSum, maxlen, len, sum);
}

int sumOfTheLongestPath(Node * &root){
    int len = 0;
    int sum = 0;
    int maxlen = 0;
    int maxSum = INT_MIN;
    solve(root,maxSum,maxlen,len,sum);
    return maxSum;
}
int main()
{
    Node* root = buildtree(root);
    printTree(root);
    cout<<"Sum of the longest path of the tree is -> "<< sumOfTheLongestPath(root)<<endl;
    return 0;
}