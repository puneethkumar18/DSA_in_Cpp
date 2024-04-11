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

pair<int,int> checkBalancedBST(Node* root){
    if(root == NULL){
        pair<int,bool> p = make_pair(0,true);
        return p;
    }
    pair<int,bool> leftAns = checkBalancedBST(root->left);
    pair<int,bool> rightAns = checkBalancedBST(root->right);
    
    pair<int,bool> ans;
    int left = leftAns.first;
    int right = rightAns.first;

    if(abs(left - right) <= 1){
        ans.second = true;
    }else{
        ans.second = false;
    }
    if(left >= right){
        ans.first = left+1;
    }else{
        ans.first = right+1;
    }

    
    return ans;
}

void inOrderTree(Node* root,vector<int> &ans){
    if(root == NULL){
        return ;
    }

    inOrderTree(root->left,ans);
    ans.push_back(root->data);
    inOrderTree(root->right,ans);
}

Node* inOrderToBST(int s,int e,vector<int> ans){
    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2;
    Node* root = new Node(ans[mid]);
    root->left = inOrderToBST(s,mid-1,ans);
    root->right = inOrderToBST(mid+1,e,ans);

    return root;
}

Node* normalToBalancedBST(Node* root){
    vector<int> ans; 
    inOrderTree(root,ans);

    return inOrderToBST(0,ans.size()-1,ans);
}

int main(){
    Node* root = buildtree(root);
    pair<int, bool> result = checkBalancedBST(root);
    cout << "The tree is balanced or not :" << result.second << endl;
    printTree(root);
    

    Node* balancedTree = normalToBalancedBST(root);
    pair<int, bool> result1 = checkBalancedBST(balancedTree);
    cout << "The tree is balanced or not  after balanced -> :" << result1.second << endl;
    printTree(balancedTree);
    return 0;
}