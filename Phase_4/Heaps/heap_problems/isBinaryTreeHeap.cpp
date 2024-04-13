#include <iostream>
#include<queue>
using namespace std;

class Heap
{
public:
    int data;
    Heap* left;
    Heap* right;

    Heap(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

void printHeap(Heap* root)
{
    queue<Heap*> q;
    q.push(root);

    while (!q.empty())
    {
        Heap* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    cout<<endl;

}
Heap* buildHeap(Heap* root)
{
    int data;
    cout << "Enter the Node data" << endl;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    root = new Heap(data);
    cout << "Enter the left child of " << data << " Node" << endl;
    root->left = buildHeap(root->left);
    cout << "Enter the right child of " << data << " Node" << endl;
    root->right = buildHeap(root->right);

    return root;
}
bool isCBT(Heap* root,int i,int n){
    if(root == NULL){
        return true;
    }
    if(i > n){
        return false;
    }else{
        bool left = isCBT(root->left,2*i+1,n);
        bool right = isCBT(root->right,2*i+2,n);
        return left && right;
    }
}

bool isMaxOrder(Heap* root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }

    if(root->right == NULL ){
        return (root->data > root->left->data);
    }else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right && root->data > root->left->data && root->data > root->right->data);
    }
}

bool isHeap(Heap* root,int size){
    if (isCBT(root,0,size) && isMaxOrder(root))
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    Heap* heap = buildHeap(heap);
    cout<<"Heap is binary tree -> "<<isHeap(heap,6)<<" \n 1-> indicates yes \n 0 -> indicates No-> "<<endl;

    return 0;
}