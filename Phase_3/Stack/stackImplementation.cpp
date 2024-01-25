#include<iostream>
using namespace std;

class Stack{
    public:
    int* arr;
    int size;
    int top;

    Stack(int size){
        this->size = size;
        arr = new arr[size];
        this->top = -1;
    }

    void push(int element){
        if(size-top > 1){
            this->top++;
            arr[top] = element;
        }else{
            cout<<"Stack overflow"<<endl;
        }
    }

    void pop(){
        if(top < 0){
            cout<<"Stack has no element to pop"
        }
    }

    bool empty(){
        if(this->top == -1){
            return true;
        }else{
            return false;
        }
    }

    int top(){
        return arr[this->top];
    }

    int size(){

    }
}

int main(){
    Stack* s = new Stack(10);
}