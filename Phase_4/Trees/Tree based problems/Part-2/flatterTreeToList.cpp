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

class LinkedList{
    public:
    int data;
    LinkedList* next;

    LinkedList(int data){
        this->data = data;
        this->next = NULL;
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

void flatterTreeToList(Node *&root)
{
    Node* current = root;
    
    while (current != NULL)
    {
        
        if(current->left){
            Node* pred = current->left;
            while(pred->right != NULL){
                pred = pred->right;
            }
            pred->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        current = current->right;
    }
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
int main(){
   
    Node* root = buildtree(root);
    flatterTreeToList(root);
    printTree(root);
    
    return 0;
}