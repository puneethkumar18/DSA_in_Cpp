#include<iostream>
using namespace std;

class CircularQueue{
    public:
    int* arr;
    int front;
    int back;
    int size;

    CircularQueue(int size){
        this->size = size;
        arr = new int[size];
        front = back = -1;
    }

    void push(int element){
        if((front == 0 && back == size-1) || back == front-1){
            cout<<"Queue is full unable to add element "<<element<<endl;
            return;
        }else if(front == -1 && back == -1){
            front = back = 0;
            arr[back] = element;
        }
        else if (back == size-1 && front != 0){
            back = 0;
            arr[back] = element;
        }else{
            back++;
            arr[back] = element;
        }
    }

    void pop(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
        }else if(front == back ){
            front = back = -1;
        }
        else if(front == size-1 && back < front){
            front = 0;
        }else{
            front++;
        }
    }


    int front1(){
        return arr[front];
    }

    int back1(){
        return arr[back];
    }

    bool empty(){
        if (front == -1 && back == -1){
            return  true;
        }else{
            return false;
        }
    }
};

int main(){

    CircularQueue cq(3);

    cq.push(10);
    cq.push(30);
    cq.push(45);
    cq.pop();
    cq.push(100);
    cq.push(120);

    cout<<"front of queue is "<<cq.front1()<<endl;

    if(cq.empty()){
        cout<<"Queue id empty"<<endl;
    }else{
        cout<<"Queue is not Empty"<<endl;
    }

    
    return 0;
}