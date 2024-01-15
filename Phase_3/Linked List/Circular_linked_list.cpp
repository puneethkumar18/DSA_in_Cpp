#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
        
        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        ~Node(){
            int value = this->data;
            if(this->next !=  NULL){
                delete next;
                this->next = NULL;
            }
            cout<<"Memory free for node with data "<<value<<endl;
        }
    
};

void insertNode(Node* &tail,int element,int data){
    if(tail == NULL){
        //Empty list
        Node* newNode = new Node(data);
        newNode = tail;
        tail->next = tail;
    }else{
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }
        Node* temp= new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void printList(Node* &tail){
    Node* temp = tail->next;
    while(temp->next != tail){
        cout<<temp->data<<" "<<endl;
        temp = temp->next;
    }
}


int main(){
    Node* tail = NULL;

    //insert node to linked list
    insertNode(tail,9,9);
    insertNode(tail,9,18);


    //print linked list
    //printList(tail);

}