#include<iostream>
#include<queue>
using namespace std;

class LinkedList{
    public:
    int data;
    LinkedList* next;

    LinkedList(int data){
        this->data = data;
        this->next = NULL;
    }
};

class compare
{
public:
    bool operator()(LinkedList *a, LinkedList *b)
    {
        return a->data > b->data;
    }
};

void buildList(LinkedList* &head){
    while (true)
    {
       int data;
       cout<<"Enter the node data"<<endl;
       cin>> data;
       if(data != -1){
           LinkedList *temp = new LinkedList(data);
           if (head == NULL)
           {
               head = temp;
            }else{
                head->next  = temp;
            }
       }else{
        return;
       }
    }
    
}   

LinkedList* mergekSortedList(vector<LinkedList*> &listArray){
    priority_queue<LinkedList*, vector<LinkedList*>, compare> pq;

    int k = listArray.size(); 
    if(k == 0){
        return NULL;
    }
    for(int i=0;i<k;i++){
       if(listArray[i] != NULL){
           pq.push(listArray[i]);
       }
    }

    LinkedList* head = NULL;
    LinkedList* tail = NULL;

    while(!pq.empty()){
        LinkedList* temp = pq.top();
        pq.pop();

        if (head == NULL){
            head = temp;
            tail = temp;
            if(tail->next != NULL){
                pq.push(temp->next);
            }
        }else{
            tail->next = temp;
            tail = tail->next;
            if(temp->next != NULL){
                pq.push(tail->next);
            }
        }
    }
    return head;

}   

void printList(LinkedList* head){
    while (head != NULL)
    {
       cout<<head->data<<" ";
       head = head->next;
    }
    cout<<endl;
}

int main(){
    vector<LinkedList*> listList;

    for(int i=0;i<6;i++){
        cout<<i+1<<endl;
        LinkedList* temp = NULL;
        buildList(temp);
        listList.push_back(temp);
    }
    LinkedList* res = mergekSortedList(listList);
    printList(res);
    return 0;
}