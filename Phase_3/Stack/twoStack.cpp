#include<iostream>
using namespace std;

class TwoStack{
    public:
    int* arr;
    int top1;
    int top2;
    int size;

    TwoStack(int size){
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int num){
        if(top2-top1 >= 1){
            top1++;
            arr[top1] = num;
        }else{
            cout<<"Stack overflow"<<endl;
        }
    }

    void push2(int num){
        if(top2-top1 >= 1){
            top2--;
            arr[top2] = num;
        }else{
            cout<<"Stack overflow"<<endl;
        }
    }

    void pop1(){
        if(top1 < 0){
            cout<<"stack is Empty"<<endl;
        }else{
            top1--;
        }
    }


    void pop2(){
        if(top2 < 0){
            cout<<"stack is Empty"<<endl;
        }else{
            top2++;
        }
    }

    int peak1(){
        if(top1 >= 0){
            return arr[top1];
        }else{
            cout<<"Stack is empty"<<endl;
        }

        return 0;
    }
      int peak2(){
        if(top2 == size){
            cout<<"Stack is empty"<<endl;
        }else{
            return arr[top2];
        }
        return 0;
    }

};

int main(){

    TwoStack st(4);

    st.push1(1);
    st.push1(2);
    st.push2(10);
    st.push2(20);

    cout<<"Before pop "<<endl;
    cout<<"first top of the stack is "<< endl;
    cout<<st.peak1()<<endl;
    cout<<"Second top of the stack is "<< endl;
    cout<<st.peak2()<<endl;

    st.pop1();
    st.pop2();

    cout<<"first top of the stack is "<< endl;
    cout<<st.peak1()<<endl;
    cout<<"Second top of the stack is "<< endl;
    cout<<st.peak2()<<endl;

}
