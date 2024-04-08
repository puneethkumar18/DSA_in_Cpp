#include<iostream>
#include<queue>
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

void inOrderBST(Node* root,vector<int> &ans){
    if(root == NULL){
        return ;
    }
    inOrderBST(root->left,ans);
    ans.push_back(root->data);
    inOrderBST(root->right,ans);
}

pair<int,int> twoSumOfBST(Node* root,int target){
    vector<int> ans;
    pair<int,int> result;
    inOrderBST(root,ans);
    int i=0;
    int j=ans.size()-1;
    while(i<j){
        int sum = (ans[i]+ans[j]);
        if(sum == target){
            result = make_pair(ans[i],ans[j]);
            break;
        }
        else if (sum < target)
        {
            i++;
        }else{
            j--;
        }
    }
    return result;
}
int main(){
    Node* root = buildtree(root);
    printTree(root);
    int target;
    cout<<"Enter the target -> ";
    cin>>target;
    cout<<endl;
    pair<int,int> result = twoSumOfBST(root,target);
    cout<<"Two Nodes that gives ths sum of the target "<<target<<" -> "<<result.first<<" and "<<result.second<<endl;
    return 0;
}