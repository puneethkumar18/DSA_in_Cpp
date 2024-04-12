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


void inOrderOfBST(Node* root,vector<int> &ans){
    if(root == NULL){
        return;
    }
    inOrderOfBST(root->left ,ans);
    ans.push_back(root->data);
    inOrderOfBST(root->right, ans);
}

vector<int> merge2ArrayInSorted(vector<int> a1,vector<int> a2){
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < a1.size() && j < a2.size())
    {
        if(a1[i] <= a2[j]){
            ans.push_back(a1[i]);
            i++;
        }else{
            ans.push_back(a2[j]);
            j++;
        }
    }
    while (i < a1.size())
    {
        ans.push_back(a1[i]);
        i++;
    }
    while (j < a2.size())
    {
        ans.push_back(a2[j]);
        j++;
    }
    
    return ans;
}
Node* BSTbyInOrder(int s,int e,vector<int> in){
    if(s > e){
        return NULL;
    }

    int mid = (s+e)/2;
    Node* root = new Node(in[mid]);
    root->left = BSTbyInOrder(s,mid-1,in);
    root->right = BSTbyInOrder(mid+1,e,in);

    return root;
    
}

Node* merge2BST(Node* bst1,Node* bst2){
    vector<int> in1,in2;

    inOrderOfBST(bst1,in1);
    inOrderOfBST(bst2, in2);

    vector<int> mergedArray =  merge2ArrayInSorted(in1,in2);

    Node* root = BSTbyInOrder(0,mergedArray.size()-1,mergedArray);

    return root;
}

int main(){
    cout<<"Enter the first bst data ->"<<endl;
    Node* root1 = buildtree(root1);
    cout << "Enter the Second bst data ->" << endl;
    Node* root2 = buildtree(root2);

    Node* mergedBST =  merge2BST(root1,root2);
    // printTree(root1);
    // printTree(root2);
    printTree(mergedBST);
    return 0;
}