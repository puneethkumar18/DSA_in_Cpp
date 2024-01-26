#include<iostream>
using namespace std;

class Queue{
    public:
    int* arr;
    int front;
    int back;
    int size;


    Queue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        back = -1;
    }


    void push(int element){
        if(back==-1 && front==-1){
            front++;
            back++;
            arr[front] = element;
        }else{
            if(back < size-1){
            back++;
            arr[back] = element;
        }else{
            cout<<"Queue has no space to push the element"<<endl;
        }
        }
    }

    void pop(){
        if(front == back){
            front = -1;
            back  = -1;
        }
        else if (front < size-1 && front > -1){
            front++;
        }else{
            cout<<"Queue is empty"<<endl;
        }
    }

    int size1(){
        return back-front+1;
    }

    int front1(){
        if(front < size-1 && front > -1){
            return arr[front];
        }else{
            cout<<"Queue is Empty"<<endl;
        }
        return 0;
    }
     int back1(){
        if(front < size-1 && front > -1){
            return arr[back];
        }else{
            cout<<"Queue is Empty"<<endl;
        }
        return 0;
    }

    bool empty(){
        if(back < size-1 && back > -1){
            return true;
        }else{
            return false;
        }
    }
};

int main(){

    Queue q(4);

    q.push(12);
    q.push(24);
    q.push(36);
    q.push(48);
    cout<<"size of the queue is "<<q.size1()<<endl;

    cout<<"before pop"<<endl;
    cout<<"front element of the queue is ";
    cout<<q.front1()<<endl;
    cout<<"back element of the queue is ";
    cout<<q.back1()<<endl;

    q.pop();

    cout<<"After pop"<<endl;
    cout<<"front element of the queue is ";
    cout<<q.front1()<<endl;
    cout<<"back element of the queue is  ";
    cout<<q.back1()<<endl;

    if(q.empty()){
        cout<< "Queue is empty "<<endl;
    }else{
        cout<<"Queue is Not Empty "<<endl;
    }


    cout<<"size of the queue is "<<q.size1()<<endl;


    return 0;
}