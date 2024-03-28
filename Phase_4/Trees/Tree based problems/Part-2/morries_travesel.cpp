#include <iostream>
#include <queue>
using namespace std;


//morries traversel take space of -> O(1) while other travesels takes -> O(n)
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
Node *findPred(Node* current){
    Node* pred = current->left;
    while(pred->right != NULL && pred->right != current){
        pred = pred->right;
    }
    return pred;
}

void morriesTravesel(Node* &root)
{
    Node* current = root;
    while (current != NULL)
    {
       if(current->left == NULL){
        cout<<current->data<<" ";
        current = current->right; 
       }
       else{
        Node* pred = findPred(current);
        if(pred->right == NULL){
            pred->right = current;
            current = current->left;
            
        }
        else{
            pred->right = NULL;
            cout<<current->data<<" ";
            current = current->right;
        }
       }
    }
}
int main(){
    Node* root = buildtree(root);
    cout<<"Morries Travesel ->"<<endl;
    morriesTravesel(root);
    cout<<endl;
    return 0;
}