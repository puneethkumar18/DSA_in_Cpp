#include<iostream>
using namespace std;

class Stack{
    public:
    int* arr;
    int size;
    int top;

    Stack(int size){
        this->size = size;
        arr = new int[size];
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
            cout<<"Stack has no element to pop"<<endl;
        }else{
            top--;
        }
    }

    bool empty(){
        if(this->top == -1){
            return true;
        }else{
            return false;
        }
    }

    int peak(){
        if(top<size && top>=0){
            return arr[this->top];
        }else{
            cout<<"there is no element on the top of stack"<<endl;
        }
        return -1;
    }

    int length(){
        return top+1;
    }
};

int main(){
    Stack s(3);

    s.push(20);
    s.push(30);
    s.push(50);
    s.push(100);

    cout<<"Top of the stack is "<<endl;
    cout<<s.peak()<<endl;

    cout<<"berfore pop top of the stack is"<<endl;
    cout<<s.peak()<<endl;

    s.pop();

    
    cout<<"after pop topm of stack is "<<endl;
    cout<<s.peak()<<endl;

    cout<<endl<<"checking whether stack is empty "<<endl;
    if(s.empty()){
        cout<<"yes stack is empty" << endl;
    }else{
        cout<<"No stack is not empty"<< endl;
    }
}