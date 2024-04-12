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

bool checkBalancedTree(Node* &root){
    if(root == NULL){
        return true;
    }
    bool left = checkBalancedTree(root->left);
    bool right = checkBalancedTree(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;
    
    if(left && right && diff){
        return true;
    }else{
        return false;
    }
//     return diff;
 }

pair<int,bool> optimizedBalancedCheck(Node* root){
    if(root == NULL){
        pair<int,bool> p = make_pair(0,true);
        return p;
    }

    pair<int,bool> left = optimizedBalancedCheck(root->left);
    pair<int,bool> right = optimizedBalancedCheck(root->right);

    bool leftAns = left.second;
    bool rightAns = right.second;

    pair<int,bool> ans;
    ans.first = max(left.first, right.first) + 1;
    bool diff = abs(left.first - right.first) <= 1;
    if(leftAns &&  rightAns && diff){
        ans.second = true;
    }else{
        ans.second = false;
    }

    return ans;
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

int main(){

    Node* root = buildtree(root);
    printTree(root);

    cout<<"The following tree is balanced -> "<<checkBalancedTree(root)<<endl;

    cout<<"OptimizedCheck -> "<<endl;
    pair<int,bool> ans = optimizedBalancedCheck(root);
    cout<<"Height of the tree -> "<<ans.first<<endl;
    cout<<"Balance of the tree -> "<<ans.second<<endl;

    cout<<height(root)<<endl;
    return 0;
}