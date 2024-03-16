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
        left = NULL;
        right = NULL;
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
void zigzag(Node* &root){
    if(root == NULL){
        return;
    }
    vector<int> result;
    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);


        for(int i=0;i<size;i++){
            Node* front = q.front();
            q.pop();
            int index = leftToRight ? i : size - i - 1;
            temp[index] = front->data;

            if(front->left){
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }

        cout << leftToRight << endl;
        leftToRight = !leftToRight;
        cout << leftToRight << endl;
        for(auto i:temp){
            result.push_back(i);
        }
        

    }

    for(int i = 0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    
}
int main(){
    Node* root = buildtree(root);
    printTree(root);

    cout<<endl;
    cout<<"ZIG-ZAG TRAVERSAL : "<<endl;
    zigzag(root);
    return 0;
}