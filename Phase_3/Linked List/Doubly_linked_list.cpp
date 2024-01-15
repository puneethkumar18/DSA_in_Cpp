#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory free for node with data "<<value<<endl;
    }
};

void printList(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtHead(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }else{
        Node* temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

}

void insertAtTail(Node* &head,Node* &tail,int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        head = temp; 
    }else{
        Node* temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;    
    }
}

void deleteNode(int position, Node* &head){
    if(position == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
           prev = curr;
           curr = curr->next;
           cnt++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next->prev = prev;
        curr->next = NULL;
        delete curr;
    }
}

void insertAtPosition(Node* &head,Node* &tail,int data, int position){
    if(position == 1){
        insertAtHead(head,tail,data);
    }else{
        Node* temp = head;
        int cnt = 1;
        while(cnt < position-1){
            temp = temp->next;
            cnt++;
        }
        if(temp->next == NULL){
            insertAtTail(head,tail,data);
        }
        Node* nodeToBeInsert = new Node(data);
        nodeToBeInsert->prev = temp;
        nodeToBeInsert->next = temp->next;
        temp->next = nodeToBeInsert;
        temp->next->prev = nodeToBeInsert;

    }
}


int getLength(Node* &head){
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}


int main(){
    //Doubly_linked_list
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    //insertion node at head
    insertAtHead(head,tail,21);
    insertAtHead(head,tail,29);

    //insertion node at tail
    insertAtTail(head,tail,77);
    insertAtTail(head,tail,88);

    //insertion at position
    insertAtPosition(head,tail,420,2);
    insertAtPosition(head,tail,120,1);

    cout<<"Before Delete "<<endl;
    printList(head);
    //delete Node
    deleteNode(6,head);
    
    cout<<"After delete "<<endl;
    printList(head);
    cout<<"Length of linked List is "<<getLength(head)<<endl;;
}