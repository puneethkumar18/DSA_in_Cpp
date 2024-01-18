#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
       int value = this->data;
       if(next != NULL){
           delete next;
           next = NULL;
       }
    }

};

void insertNode(Node* &tail,int element,int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        temp->next = tail;
    }else{
        Node* temp = new Node(data);
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail,int element){
    if(tail == NULL){
        cout<<"list id empty check again"<<endl;
        return;
    }else{
    Node* curr = tail->next;
    Node* prev = tail;
    while(curr->data != element){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    if(tail==prev){
        tail = NULL;
    }
    else if(tail == curr){
        tail = prev;
    }
    curr->next = NULL;
    delete curr;
    }
}

void printList(Node* &tail){
    Node* temp = tail->next;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != tail);
    cout<<tail->data<<endl;
}

int main(){
    Node* tail = NULL;

    insertNode(tail,2,12);
    insertNode(tail,12,98);
    
    cout<<"Before deleting "<<endl;
    printList(tail);


    cout<<"After deleteing "<<endl;
    deleteNode(tail,12);
    
    
    printList(tail);

    return 0;
}