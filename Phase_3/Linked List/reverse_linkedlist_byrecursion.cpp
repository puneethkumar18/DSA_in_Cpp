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
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"the memory is free for the node with data "<<value<<endl;
    }
};

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail , int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void insertAtPosition(Node* &head,Node* &tail,int data,int position){
    if(position == 1){
        insertAtHead(head,data);
        return ;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    if(temp == NULL){
        insertAtTail(tail,18);
        return ;
    }
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert; 

}

void printList(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void revereseByRecursion(Node* &head, Node* curr,Node* prev){
    if(curr == NULL){
        head = prev;
        return ;
    }
    
    Node* fwd = curr->next;
    curr->next = prev;
    prev = curr;

    revereseByRecursion(head,fwd,prev);
}


int main(){
    Node* node1 = new Node(12);
    Node* head = node1;
    Node* tail = node1;

    //insert at head
    insertAtHead(head, 72);
    insertAtHead(head, 200);

    //insert at tail
    insertAtTail(tail,420);
    insertAtTail(tail,540);

    //insert at given position
    insertAtPosition(head,tail,80,3);
    insertAtPosition(head,tail,192,1);

    cout<<"Before Reverse "<<endl;
    printList(head);
    cout<<"Head of list "<<head->data<<endl;
    cout<<"tail of list "<<tail->data<<endl;

    tail = head;
    revereseByRecursion(head,head,NULL);

    cout<<"After Reverse "<<endl;
    printList(head);
    cout<<"Head of list "<<head->data<<endl;
    cout<<"tail of list "<<tail->data<<endl;

}