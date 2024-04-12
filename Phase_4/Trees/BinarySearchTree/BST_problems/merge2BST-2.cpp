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

void bstToSortedLinkedList(Node* root,Node* &head){
    if(root == NULL){
        return ;
    }

    bstToSortedLinkedList(root->right,head);
    root->right = head;
    if(head != NULL){
        head->left = root;
    }
    head = root;

    bstToSortedLinkedList(root->left,head);
}
Node* mergeLinkedList(Node* head1,Node* head2){
    Node* head = NULL; 
    Node* tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if(head1->data < head2->data){
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }else{
            if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }else{
                tail = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL)
    {
        tail = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    
    while (head2 != NULL)
    {
        tail = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    
    return head;
}



int main(){
    Node* bst1 ;
    Node* bst2 ;
    return 0;
}